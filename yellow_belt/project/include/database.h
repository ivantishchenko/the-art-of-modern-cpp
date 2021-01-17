#pragma once

#include "date.h"

#include <string>
#include <set>
#include <map>
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

class Database {
public:
    void Add(const Date& date, const string& event);
    void Print(ostream& out) const;
    void Print() const;
    template <typename Predicate> 
    size_t RemoveIf(const Predicate& pred);
    template <typename Predicate> 
    multimap<Date, string> FindIf(const Predicate& pred) const;
    pair<Date, string> Last(const Date& date) const;
    map<Date, set<string>> GetStorage() const;
private:
    map<Date, set<string>> date_to_sorted;
    map<Date, vector<string>> date_to_vector;
};

ostream& operator<<(ostream& out, const Database& db);

template <typename Predicate>
size_t Database::RemoveIf(const Predicate& pred) {
    size_t result = 0;
    map<Date, vector<string>> new_storage;
    map<Date, set<string>> new_checker;

    for (auto& pair_ : date_to_vector) {
        const auto border = stable_partition(pair_.second.begin(), pair_.second.end(), 
            [pred, pair_](const auto& item) {
                return pred(pair_.first, item);
            }
        );

        const size_t tmp = pair_.second.size();

        if (border == pair_.second.end()) {
            result += tmp;
        } else {
            new_storage[pair_.first] = vector<string>(border, pair_.second.end());
            new_checker[pair_.first] = set<string>(border, pair_.second.end());
            result += tmp - new_storage.at(pair_.first).size();
        }
    }

    date_to_vector = new_storage;
    date_to_sorted = new_checker;

    return result;
}

template <typename Predicate>
multimap<Date, string> Database::FindIf(const Predicate& pred) const {
    multimap<Date, string> res;
    for(const auto& [date, events] : date_to_vector) {
        for(const auto& event: events) {
            if(pred(date, event)) {
                res.insert(make_pair(date, event));
            }
        }
    }
    return res;
}