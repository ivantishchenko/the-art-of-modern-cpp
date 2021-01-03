#include <iostream>
#include <limits>

using namespace std;

int main() {
    int x = 2'000'000'000;
    cout << x * 2 << endl;

    cout << numeric_limits<size_t>::min() << " " << numeric_limits<size_t>::max() << endl;

    return 0;
}
