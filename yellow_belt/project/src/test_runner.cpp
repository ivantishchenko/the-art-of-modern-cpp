#include "test_runner.h"

template <typename Collection>
string Join(const Collection& c, char d) {
  stringstream ss;
  bool first = true;
  for (const auto& i : c) {
    if (!first) {
      ss << d;
    }
    first = false;
    ss << i;
  }
  return ss.str();
}

template <typename First, typename Second>
ostream& operator<<(ostream& out, const pair<First, Second>& p) {
  return out << '(' << p.first << ',' << p.second << ')';
}

template <typename T>
ostream& operator<<(ostream& out, const vector<T>& vi) {
  return out << '[' << Join(vi, ',') << ']';
}

template <typename Key, typename Value>
ostream& operator<<(ostream& out, const map<Key, Value>& m) {
  return out << '{' << Join(m, ',') << '}';
}

template <typename T>
ostream& operator<<(ostream& out, const set<T>& s) {
    return out << '{' << Join(s, ',') << '}';
}