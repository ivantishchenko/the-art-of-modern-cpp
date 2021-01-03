#include <iostream>
#include <string>
#include <sstream>
#include <exception>

using namespace std;

struct Date {
    int year;
    int month;
    int day;
};

Date ParseDate(const string& s) {
    stringstream stream(s);
    Date date;
    stream >> date.year;
    if(stream.peek() != '/') {
        throw runtime_error("Wrong format");
    }
    stream.ignore(1);
    stream >> date.month;
    stream.ignore(1);
    stream >> date.day;
    return date;
}

int main() {
    string date_str = "2017.01/25"; 
    try {
        Date d = ParseDate(date_str);
        cout << d.day << '.' << d.month << '.' << d.year << endl;
    } catch(exception& ex) {
        cout << ex.what();    
    }
    return 0;
}
