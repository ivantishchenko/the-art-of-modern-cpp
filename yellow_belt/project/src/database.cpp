#include "database.h"

#include <utility>


void Database::Add(const Date& date, const string& event) {

}

void Database::Print(ostream& out) const {

}
void Database::Print() const {

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

}

ostream& operator<<(ostream& out, const Database& db) {
    db.Print(out);
    return out;
}