#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Lang {
    string name;
    int age;
};

ostream& operator<<(ostream& out, const Lang& lang);

using LangIt = vector<Lang>::iterator;

template <typename It>
void PrintRange(It range_beg, It range_end) {
    for(auto it = range_beg; it != range_end; ++it) {
        cout << *it << " ";
    }
}

ostream& operator<<(ostream& out, const Lang& lang) {
    out << '{' << lang.name << ',' << lang.age << '}';
    return out;
}

int main() {
    vector<Lang> langs = {{"Python", 26}, {"C++", 34}, {"C#", 17}, {"Java", 22}, {"C", 45}};
    auto res = find_if(begin(langs), end(langs), [](const Lang& lang) {
        return lang.name[0] == 'C';
    });

    //if(res == end(langs)) {
    //    cout << "Not found" << endl;
    //} else {
    //    cout << res->age << endl;
    //}

    //cout << begin(langs)->name << " " << begin(langs)->age << endl;
    //cout << langs.begin()->name << " " << langs.begin()->age << endl;

    string lang = langs[1].name;
    auto it = lang.begin();
    //cout << *it << endl;
    ++it;
    //cout << *it << endl;
    for(vector<Lang>::iterator it = langs.begin(); it != langs.end(); ++it) {
        //cout << it->name << " ";
    }
    //PrintRange(langs.begin(), langs.end());
    //PrintRange(langs[0].name.begin(), langs[0].name.end());
    
    auto border = find_if(langs.begin(), langs.end(), [](const Lang& lang) {
        return lang.name == "C#";
    });
    
    //PrintRange(langs.begin(), border);
    //PrintRange(border, langs.end()); 

    langs.insert(langs.begin(), {"Erlang", 15});

    auto rem_it = remove_if(langs.begin(), langs.end(), [](const Lang& lang) {
        return lang.name[0] == 'C';
    });

    langs.erase(rem_it, langs.end());

    //PrintRange(langs.begin(), langs.end());
  
    vector<string> langs_str = {"Python", "C++", "C", "Java", "C#"};
    auto [min_el, max_el] = minmax_element(langs_str.begin(), langs_str.end());
    cout << *min_el << " " << *max_el << endl;

    PrintRange(langs.rbegin(), langs.rend());

    return 0;
}
