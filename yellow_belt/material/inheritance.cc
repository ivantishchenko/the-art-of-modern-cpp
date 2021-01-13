#include <iostream>

using namespace std;

struct Log {
    Log(string name) : n(name) {
        cout << "+ " << n << endl;
    }
    ~Log() {
        cout << "- " << n << endl;
    }
    string n;
};

struct Fruit {
    Fruit(const string& t) : l(t + "(Fruit)") {}
    const Log l;
};

struct Apple : public Fruit {
    Apple(const string& t) : Fruit(t), l(t) {}
    const Log l;
};

class AppleTree {
public:
    AppleTree(const string& t) : type(t), a1(type + "a1"), a2(type + "a2") {}
    string type;
    Apple a1;
    Apple a2;
};

//struct Orange : public Fruit {
//    Orange() {
//        health = 5;
//        type = "orange";
//    }
//};

//struct PineApple : public Fruit {
//    PineApple() {
//        health = 15;
//        type = "pineapple";
//    }
//};

//class Animal {
//public:
//    Animal(const string& t = "animal") : type(t) {}
//    void Eat(const Fruit& f) {
//        cout << type << " eats an" << f.type << " " << f.health << " hp." << endl; 
//    }
//protected:
//    const string type;
//};

//class Cat : public Animal{
//public:
//    Cat() : Animal("Cat") {}
//    void Meow() const {
//        cout << "meow! " << endl;        
//    }
//};

//class Dog : public Animal {
//public:
//    Dog() : Animal("Dog") {}
//};

//void DoMeal(Animal& a, Fruit& f) {
//    a.Eat(f);
//}

int main() {
    AppleTree at("AppleTree");
    return 0;
}
