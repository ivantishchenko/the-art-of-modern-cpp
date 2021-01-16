#include "database.h"

#include <utility>
#include <algorithm>
#include <iterator>

void Database::Add(const Date& date, const string& event) {
    storage_[date].insert(event);
}

void Database::Print(ostream& out) const {
    for(const auto& [date, event_set]: storage_) {
        for(const auto& event: event_set) {
            out << date << ' ' << event << endl;
        }
    }
}
void Database::Print() const {
    Print(cout);
}

pair<Date, string> Database::Last(const Date& date) const {
    auto upper_bound_it = storage_.upper_bound(date);
    if(upper_bound_it == begin(storage_)) {
        throw invalid_argument("No entries");
    }
    upper_bound_it = prev(upper_bound_it);
    // TODO: Improve the event with timestamp or a queue
    return make_pair(upper_bound_it->first, *begin(upper_bound_it->second));
}

map<Date, set<string>> Database::GetStorage() const {
    return storage_;
}

ostream& operator<<(ostream& out, const Database& db) {
    db.Print(out);
    return out;
}