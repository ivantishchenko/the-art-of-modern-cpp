#pragma once

#include "date.h"

#include <string>
#include <set>
#include <map>
#include <iostream>
#include <vector>

class Database {
public:
    void Add(const Date& date, const string& event);
    void Print(ostream& out) const;
    void Print() const;
    template <typename Predicate> 
    int RemoveIf(const Predicate& pred);
    template <typename Predicate>
    set<string> FindIf(const Predicate& pred) const;
    pair<Date, string> Last(const Date& date) const;
    map<Date, set<string>> GetEvents() const;
private:
    map<Date, set<string>> events_;
};

ostream& operator<<(ostream& out, const Database& db);