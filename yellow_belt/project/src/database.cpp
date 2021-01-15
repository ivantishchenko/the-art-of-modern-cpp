#include "database.h"

#include <utility>

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

}

map<Date, set<string>> Database::GetEvents() const {
    return events_;
}

ostream& operator<<(ostream& out, const Database& db) {
    db.Print(out);
    return out;
}