#include <map>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <limits>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <set>
#include <iomanip>

using namespace std;

class Date {
public:
    Date() : year_(0), month_(0), day_(0) {}
    Date(int new_year, int new_month, int new_day) : year_(new_year), month_(new_month), day_(new_day) {}
    int GetYear() const {
        return year_;
    }
    int GetMonth() const {
        return month_;
    }
    int GetDay() const {
        return day_;
    }
    void SetYear(int new_year) {
        year_ = new_year;
    }
    void SetMonth(int new_month) {
        month_ = new_month;
    }
    void SetDay(int new_day) {
        day_ = new_day;
    }
private:
    int year_;
    int month_;
    int day_;
};

istream& operator>>(istream& stream, Date& date) {
    char delimiter;
    int day, month, year;
    if(stream >> year >> delimiter >> month >> delimiter >> day) {
        if(month < 1 || month > 12) throw invalid_argument("Month value is invalid: " + to_string(month));
        if(day < 1 || day > 31) throw invalid_argument("Day value is invalid: " + to_string(day));

        date.SetDay(abs(day));
        date.SetMonth(abs(month));
        date.SetYear(abs(year));
    } else {
        throw invalid_argument("Invalid date");
    }
    return stream;
}

ostream& operator<<(ostream& stream, const Date& date) {
    stream << setfill('0') << setw(4) << date.GetYear() << '-' << setw(2) << date.GetMonth() << '-' << setw(2) << date.GetDay();
    return stream;
}

bool operator<(const Date& lhs, const Date& rhs){
    int total_lhs = lhs.GetYear() * 365 + lhs.GetMonth() * 31 + lhs.GetDay();
    int total_rhs = rhs.GetYear() * 365 + rhs.GetMonth() * 31 + rhs.GetDay(); 
    return total_lhs < total_rhs;
}

class Database {
public:
    void AddEvent(const Date& date, const string& event) {
        events_[date].insert(event);    
    }
    bool DeleteEvent(const Date& date, const string& event) {
        if(events_.find(date) == events_.end() || events_[date].find(event) == events_[date].end()) {
            cout << "Event not found" << endl;
            return false;
        }
        events_[date].erase(event);
        cout << "Deleted successfully" << endl;
        return true;
    }
    int DeleteDate(const Date& date) {
        int N = events_[date].size();
        events_.erase(date);
        cout << "Deleted " << to_string(N) << " events" << endl;
        return N;
    }
    set<string> Find(const Date& date) const {
        if(events_.find(date) == events_.end()) {
            throw out_of_range("Date not found");
        }
        set<string> res = events_.at(date);
        for(const string& event: res) {
            cout << event << endl;
        }
        return res;
    }
    void Print(ostream& stream) const {
        for(const auto& [date, event_set]: events_) {
            for(const auto& event: event_set) {
                stream << date << ' ' << event << endl; 
            }
        }
    }

    void Print() const {
        Print(cout);
    }

    map<Date, set<string>> GetEvents() const {
        return events_;
    }
private:
    map<Date, set<string>> events_;
};

ostream& operator<<(ostream& stream, const Database& db) {
    db.Print(stream);
    return stream;
}

enum Operation {
    ADD,
    DEL,
    FIND,
    PRINT
};

Operation ParseOperation(const string& str) {
    if(str == "Add") return Operation::ADD;
    if(str == "Del") return Operation::DEL;
    if(str == "Find") return Operation::FIND;
    if(str == "Print") return Operation::PRINT;
    throw invalid_argument("Unknown command: " + str);
}

istream& operator>>(istream& stream, Operation& operation) {
    string op_str;
    stream >> op_str;
    operation = ParseOperation(op_str);
    return stream;
}

int main() {  
    Database db;
    ifstream input("input1.txt");
    if(!input) throw runtime_error("Could not open file");
    ofstream output("output.txt");
    string command;
    while(getline(input, command)) {
        if(command.empty()) continue;
        istringstream tokens(command);
        Operation op; Date d; string event;
        tokens >> op;
        switch(op) {
            case Operation::ADD:
                tokens >> d >> event;
                db.AddEvent(d, event);
                break;
            case Operation::DEL:
                tokens >> d >> event;
                event.empty() ? db.DeleteDate(d) : db.DeleteEvent(d, event);
                break;
            case Operation::FIND:
                tokens >> d;
                db.Find(d);
                break;
            case Operation::PRINT:
                cout << db;
                break;
            default:
                break;
        }
    }
    return 0;
}
