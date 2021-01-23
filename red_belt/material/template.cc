#include <iostream>
#include <vector>

using namespace std;

template <typename Iterator>
struct IteratorRange {
    Iterator first, second;

    Iterator end() const {
        return second;
    }

    Iterator begin() const {
        return first;
    }
};

template <typename T>
IteratorRange<typename vector<T>::iterator> Head(vector<T>& v, size_t top) {
    return {begin(v), next(begin(v), min(top, v.size()))};
}

int main() {
    vector<int> v = {1, 2, 3, 4, 5, 6, 7};
    for(int i : Head(v, 3)) {
        cout << i << ' ';
    }
    return 0;
}
