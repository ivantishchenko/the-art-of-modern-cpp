#include <iostream>
#include <cassert>

using namespace std;

int Sum(int x, int y) {
    return x + y;
}

void TestSum() {
    assert(Sum(2, 3) == 5);
    assert(Sum(-2, -3) == -5);
    cout << "TestSum OK" << endl;
}

int main() {
    TestSum();
    return 0;
}
