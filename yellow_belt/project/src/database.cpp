#include "database.h"

#include <utility>
#include <algorithm>
#include <iterator>

void Database::Add(const Date& date, const string& event) {
    events_[date].insert(event);
}

void Database::Print(ostream& out) const {
    for(const auto& [date, event_set]: events_) {
        for(const auto& event: event_set) {
            out << date << ' ' << event << endl;
        }
    }
}
void Database::Print() const {
    Print(cout);
}

template <typename Predicate>
int Database::RemoveIf(const Predicate& pred) {

}

template <typename Predicate>
set<string> Database::FindIf(const Predicate& pred) const {

}

pair<Date, string> Database::Last(const Date& date) const {
    auto upper_bound_it = events_.upper_bound(date);
    if(upper_bound_it == begin(events_)) {
        throw invalid_argument("No entries");
    }
    upper_bound_it = prev(upper_bound_it);
    // TODO: Improve the event with timestamp or a queue
    return make_pair(upper_bound_it->first, *begin(upper_bound_it->second));
}

map<Date, set<string>> Database::GetEvents() const {
    return events_;
}

ostream& operator<<(ostream& out, const Database& db) {
    db.Print(out);
    return out;
}