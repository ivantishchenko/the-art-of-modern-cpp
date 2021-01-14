#pragma once

#include <sstream>
#include <exception>
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>

using namespace std;

template<class T, class U>
void AssertEqual(const T& t, const U& u,
    const string& hint)
{
  if (t != u) {
    ostringstream os;
    os << "Assertion failed: " << t << " != " << u
       << " hint: " << hint;
    throw runtime_error(os.str());
  }
}

inline void Assert(bool b, const string& hint) {
  AssertEqual(b, true, hint);
}

class TestRunner {
public:
  template <class TestFunc>
  void RunTest(TestFunc func, const string& test_name) {
    try {
	  func();
	  cerr << test_name << " OK" << endl;
	} catch (runtime_error& e) {
	  ++fail_count;
	  cerr << test_name << " fail: " << e.what() << endl;
	}
  }

  ~TestRunner() {
    if (fail_count > 0) {
      cerr << fail_count << " unit tests failed. Terminate" << endl;
      exit(1);
    }
  }

private:
  int fail_count = 0;
};

template <typename First, typename Second>
ostream& operator<<(ostream& out, const pair<First, Second>& p);

template <typename T>
ostream& operator<<(ostream& out, const vector<T>& vi);

template <typename Key, typename Value>
ostream& operator<<(ostream& out, const map<Key, Value>& m);

template <typename T>
ostream& operator<<(ostream& out, const set<T>& s);

template <typename Collection>
string Join(const Collection& c, char d);