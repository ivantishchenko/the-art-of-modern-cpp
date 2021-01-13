#include <iostream>
#include <string>
#include <memory>
#include <vector>

using namespace std;

class Animal {
public:
    Animal(const string& type) : type_(type) {}
    void Eat(const string& fruit) {
        cout << type_ << "eats " << fruit << endl;
    }
    virtual void Sound() const = 0; 
private:
    const string type_;
};

class Parrot : public Animal {
public:
    Parrot(const string& name) : Animal("parrot"), name_(name) {}
    void Sound() const override {
        cout << name_ << " is good" << endl;
    }
private:
    const string name_;
};

class Cat : public Animal {
public:
    Cat() : Animal("cat") {}
    void Sound() const override {
        cout << "Meow!" << endl;
    }
};

class Dog : public Animal {
public:
    Dog() : Animal("dog") {}
    void Sound() const override {
        cout << "Whoof!" << endl;
    }
};

class Horse : public Animal {
public:
    Horse() : Animal("horse") {}
    void Sound() const override {
        cout << "Brrr!" << endl;
    }
};

void MakeSound(const Animal& a) {
    a.Sound();
}

int main() {
    Animal* a = new Parrot("Kesha");
    a->Sound();

    vector<shared_ptr<Animal>> animals = {
        make_shared<Cat>(),
        make_shared<Dog>(),
        make_shared<Parrot>("Ivan")
    };

    for(const auto a : animals) {
        MakeSound(*a);
    }

    return 0;
}
