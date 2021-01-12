#include <iostream>
#include <deque>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    queue<int> q;

    q.push(1);
    q.pop();

    vector<int> vec = {1, 12, 2, 52, 334};
    sort(begin(vec), end(vec));

    bool is_found = binary_search(begin(vec), end(vec), 2); 
    cout << is_found << endl;

    auto it = lower_bound(begin(vec), end(vec), 3);
    cout << *it << endl;

    it = upper_bound(begin(vec), end(vec), 3);
    cout << *it << endl;

    return 0;
}
