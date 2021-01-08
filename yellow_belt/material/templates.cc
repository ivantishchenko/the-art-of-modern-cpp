#include <iostream>
#include <utility>

using namespace std;

template <typename First, typename Second>
pair<First, Second> operator*(const pair<First, Second>& lhs, const pair<First, Second>& rhs) {
    First f = lhs.first * rhs.first;
    Second s = lhs.second * rhs.second;
    return {f, s};
}

template <typename T>
T Sqr(T x) {
    return x * x;
}

int main() {
    pair p(2.5, 3);
    auto [x, y] = Sqr(p);
    cout << x << " " << y << endl;
    return 0;
}
