#include "database.h"

#include <utility>
#include <algorithm>
#include <iterator>

void Database::Add(const Date& date, const string& event) {
    date_to_sorted[date].insert(event);
    date_to_stack[date].push(event);
}

void Database::Print(ostream& out) const {
    for(const auto& [date, event_set]: date_to_sorted) {
        for(const auto& event: event_set) {
            out << date << ' ' << event << endl;
        }
    }
}
void Database::Print() const {
    Print(cout);
}

pair<Date, string> Database::Last(const Date& date) const {
    auto upper_bound_it = date_to_sorted.upper_bound(date);
    if(upper_bound_it == begin(date_to_sorted)) {
        throw invalid_argument("No entries");
    }
    upper_bound_it = prev(upper_bound_it);
    
    Date last_date = upper_bound_it->first;
    string last_event = date_to_stack.at(last_date).top();

    return make_pair(last_date, last_event);
}

map<Date, set<string>> Database::GetStorage() const {
    return date_to_sorted;
}

ostream& operator<<(ostream& out, const Database& db) {
    db.Print(out);
    return out;
}