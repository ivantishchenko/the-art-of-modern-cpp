#include <iostream>

using namespace std;

int main() {
    int x = 5;
    int* px = &x;

    const int* cpx = &x;
    int* const pxc = &x;
    const int* const cpxc = &x;

    cout << *cpxc << endl;
    return 0;
}
