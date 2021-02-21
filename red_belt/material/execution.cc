// g++ -ggdb3 -O3 -std=c++17 -Wall -Wextra -pedantic execution.cc -ltbb

#include <vector>
#include <execution>
#include <mutex>
#include <algorithm>
#include <iostream>

int main() {
    int sum = 0;
    std::mutex m; 
    std::vector<int> vec = {1, 2, 3};
    std::for_each(std::execution::par, std::begin(vec), std::end(vec), [&](int i) {
        std::lock_guard<std::mutex> lock(m);        
        sum += i * i; 
    });
    std::cout << sum << std::endl; 
    return 0;
}
