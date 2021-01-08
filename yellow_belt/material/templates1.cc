#include <iostream>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

template <typename Collection>
string Join(const Collection& c, char d) {
    stringstream ss;
    bool first = true;
    for(const auto& i : c) {
        if(!first) {
            ss << d;
        }
        first = false;
        ss << i;
    }
    return ss.str();
}

template <typename First, typename Second>
ostream& operator<<(ostream& stream, const pair<First, Second>& p) {
    return stream << '(' << p.first << "," << p.second << ')';
}

template <typename T>
ostream& operator<<(ostream& stream, const vector<T>& vec) {
    return stream << '[' << Join(vec, ',') << ']';
}

template <typename Key, typename Val>
ostream& operator<<(ostream& stream, const map<Key, Val>& map) {
    return stream << '{' << Join(map, ',') << '}';
}

int main() {
    vector<double> vi = {1, 2, 3};
    map<int, double> m = {{1, 3.5}, {2, 4.5}};
    
    vector<vector<int>> vv = {{1, 2}, {3, 4}};
    cout << vv << endl << m << endl << vi << endl;
}
