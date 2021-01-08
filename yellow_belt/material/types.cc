#include <iostream>
#include <limits>
#include <vector>

using namespace std;

int main() {
    int x = 2'000'000'000;
    cout << x * 2 << endl;

    cout << numeric_limits<size_t>::min() << " " << numeric_limits<size_t>::max() << endl;

    vector<int> vec = {-4, -4, 4};

    int sum = 0;
    for(auto i : vec) {
        sum += i;
    }

    cout << sum / static_cast<int>(vec.size()) << endl;

    return 0;
}
