#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Day {
    int val;
    explicit Day(int new_val) : val(new_val) {}
};

struct Month {
    int val;
    explicit Month(int new_val) : val(new_val) {}
};

struct Year {
    int val;
    explicit Year(int new_value) : val(new_value) {}
};

struct Date {
    int day;
    int month;
    int year;
    Date(Day new_day, Month new_month, Year new_year) : day(new_day.val), month(new_month.val), year(new_year.val) {}
};

void PrintDate(const Date& date) {
    cout << date.day << "." << date.month <<"." << date.year << endl;
}

int main() {
   Date d = {Day{1}, Month{2}, Year{2018}};
   PrintDate(d);
   return 0;
}
