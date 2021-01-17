#pragma once

#include "date.h"

#include <string>
#include <set>
#include <map>
#include <iostream>
#include <vector>
#include <stack>

class Database {
public:
    void Add(const Date& date, const string& event);
    void Print(ostream& out) const;
    void Print() const;
    template <typename Predicate> 
    size_t RemoveIf(const Predicate& pred);
    template <typename Predicate> 
    map<Date, string> FindIf(const Predicate& pred) const;
    pair<Date, string> Last(const Date& date) const;
    map<Date, set<string>> GetStorage() const;
private:
    map<Date, set<string>> date_to_sorted;
    map<Date, stack<string>> date_to_stack;
};

ostream& operator<<(ostream& out, const Database& db);

template <typename Predicate>
size_t Database::RemoveIf(const Predicate& pred) {
    size_t removed_count = 0; 
    for(const auto& [date, events] : date_to_sorted) {
        for(const string& event: events) {
            if(pred(date, event)) {
                date_to_sorted.at(date).erase(event);
                removed_count++;
            }
        }
    }
    return removed_count;
}

template <typename Predicate>
map<Date, string> Database::FindIf(const Predicate& pred) const {
    map<Date, string> res;
    for(const auto& [date, events] : date_to_sorted) {
        for(const auto& event: events) {
            if(pred(date, event)) {
                res.insert(make_pair(date, event));
            }
        }
    }
    return res;
}