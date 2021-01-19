#include <algorithm>
#include <iostream>

using namespace std;

#define MAX(a, b) (a > b ? a : b)
#define SQR(x) ((x) * (x))

int main() {
    int x = 4;
    int y = 2;
    int z = MAX(x, y) + 5;
    cout << z;
    cout << SQR(4);

    cout << endl;
    
    int a = 3;
    cout << (a++) * (a++);

}
