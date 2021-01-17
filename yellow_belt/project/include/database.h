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
    map<Date, set<string>> GetLookupMap() const;
private:
    map<Date, set<string>> lookup_map_;
    map<Date, vector<string>> order_map_;
};

ostream& operator<<(ostream& out, const Database& db);

template <typename Predicate>
size_t Database::RemoveIf(const Predicate& pred) {
    size_t result = 0;
    map<Date, vector<string>> tmp_date_to_vector;
    map<Date, set<string>> tmp_order_map;

    for (auto& [date, events] : order_map_) {
        const auto border = stable_partition(begin(events), end(events), 
            [pred, date](const auto& event) {
                return pred(date, event);
            }
        );

        if (border == events.end()) {
            result += events.size();
        } else {
            tmp_date_to_vector[date] = vector<string>(border, end(events));
            tmp_order_map[date] = set<string>(border, end(events));
            result += order_map_.size() - tmp_date_to_vector.size();
        }
    }

    order_map_ = tmp_date_to_vector;
    lookup_map_ = tmp_order_map;

    return result;
}

template <typename Predicate>
multimap<Date, string> Database::FindIf(const Predicate& pred) const {
    multimap<Date, string> res;
    for(const auto& [date, events] : order_map_) {
        for(const auto& event: events) {
            if(pred(date, event)) {
                res.insert(make_pair(date, event));
            }
        }
    }
    return res;
}