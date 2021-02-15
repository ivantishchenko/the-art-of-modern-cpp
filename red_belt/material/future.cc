#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>
#include <future>

using namespace std;

int SumVectors(const vector<int>& one, const vector<int>& two) {
    future<int> f = async([&one]() {
        return accumulate(begin(one), end(one), 0); 
    }); 
    int result = accumulate(begin(two), end(two), 0);
    return result + f.get(); 
}

int main() {
    cout << SumVectors({1, 1, 1, 1}, {3, 3, 3}); 
    return 0;
}
