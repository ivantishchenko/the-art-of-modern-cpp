#include <iostream>
#include <future>

using namespace std;

struct Account {
    int balance = 0;
    
    bool Spend(int value) { 
        if(value <= balance) {
            balance -= value; 
            return true;
        }
        return false;
    }
};

int SpendMoney(Account& account) {
    int total_spent = 0;
    for(int i = 0; i < 100'000; ++i) {
        if(account.Spend(1)) {
            ++total_spent;
        }
    }
    return total_spent;
}

int main() {
    Account family_account = {100'000};
    
    future<int> husband = async(SpendMoney, ref(family_account)); 
    future<int> wife = async(SpendMoney, ref(family_account));
    future<int> son = async(SpendMoney, ref(family_account));
    future<int> daughter = async(SpendMoney, ref(family_account));
    
    cout << "Total spent: " << SpendMoney(family_account) << " Balance : " << family_account.balance << endl; 
}
