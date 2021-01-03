#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

struct Duration {
    int hour;
    int minute;

    Duration(int h = 0, int m = 0) : hour(h), minute(m) {}
};

Duration ReadDuration(istream& stream) {
    int h = 0;
    int m = 0;
    stream >> h;
    stream.ignore(1);
    stream >> m;
    return {h, m};
}

void PrintDuration(ostream& stream, const Duration& duration) {
    stream << setfill('0');
    stream << setw(2) << duration.hour << ':' << setw(2) << duration.minute;
}

ostream& operator<<(ostream& stream, const Duration& duration) {
    stream << setfill('0');
    stream << setw(2) << duration.hour << ':' << setw(2) << duration.minute;
    return stream;
}

istream& operator>>(istream& stream, Duration& duration) {
    stream >> duration.hour;
    stream.ignore(1);
    stream >> duration.minute;
    return stream;
}

Duration operator+(const Duration& lhs, const Duration& rhs) {
    return {lhs.hour + rhs.hour, lhs.minute + rhs.minute};
}

int main() { 
    stringstream dur_ss("01:50");
    Duration dur1;
    dur_ss >> dur1;    
    cout << dur1 << endl;
    operator<<(operator<<(cout, "hello"), " world\n");
    Duration dur2 = {0, 5};

    cout << dur1 + dur2 << endl;
    cout << operator+(dur1, dur2) << endl;

    return 0;
}
