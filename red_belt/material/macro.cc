#include <iostream>
#include <string>

#define AS_KV(x) #x << " = " << x

using namespace std;

int main() {
    int x = 4;
    string l = "hello";
    bool is_true = false;

    cerr << AS_KV(x) << endl << AS_KV(l) << endl << AS_KV(is_true) << endl;

    const string file = __FILE__;
    const int line = __LINE__;

    cout << AS_KV(file) << endl << AS_KV(line) << endl;
}


