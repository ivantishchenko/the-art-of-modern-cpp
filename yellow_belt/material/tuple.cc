#include <iostream>
#include <tuple>
#include <utility>
#include <map>
#include <set>

using namespace std;

struct Date {
    int year;
    int month;
    int day;
};

auto GetRank(const Date& d) {
    return tie(d.year, d.month, d.day);
}

bool operator<(const Date& lhs, const Date& rhs) {
    return GetRank(lhs) < GetRank(rhs);
}

class Cities {
public:
    tuple<bool, string> FindCountry(const string& city) const {
        return {true, "Sweden"};
    }
private:
    map<string, string> city_to_country_;
    set<string> ambig_cities;
};

int main() {
    pair p(7, "C++");
    tuple t(4, "C++", true);
    //auto t = make_tuple(1, 2, 3, "C++", true);
    cout << get<1>(t) << endl;
    cout << p.first << endl;

    Cities c;
    auto [status, msg] = c.FindCountry("hello");
    cout << status << " " << msg;

    return 0; 
}
