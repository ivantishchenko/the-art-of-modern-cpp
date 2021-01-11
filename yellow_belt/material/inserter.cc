#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>

using namespace std;

int main() {
    set<int> a = {1, 3, 6};
    set<int> b = {1, 6, 2};

    set<int> res;

    set_intersection(a.begin(), a.end(), b.begin(), b.end(), inserter(res, end(res)));

    for(auto i : res) {
        cout << i << " " << endl;
    }

    vector<string> langs = {"A", "B", "C"};

    auto it_find = find(begin(langs), end(langs), "B");

    cout << *it_find << " " << it_find - begin(langs) << endl;

    return 0;
}
