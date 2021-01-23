#include <iostream>
#include <string>
#include <memory>

using namespace std;

class Animal {
public:
    Animal(const string& name) : name_(name) {}
    virtual void MakeSound() const {
        cout << name_ << " says generic Hello" << endl;
    }
protected:
    string name_;
};

class Dog : public Animal {
public:
    Dog(const string& name) : Animal(name) {}
    void MakeSound() const override {
        cout << name_ << " says bow" << endl; 
    }
};

class Cat : public Animal {
public:
   Cat(const string& name) : Animal(name) {}
   void MakeSound() const override {
       cout << name_ << " says meow" << endl;
   }
};

int main() {
    unique_ptr<Animal> d = make_unique<Dog>("Dog");
    unique_ptr<Animal> c = make_unique<Cat>("Cat");
    d->MakeSound();
    c->MakeSound();

    Animal a("Animal");
    a.MakeSound();

    Cat c1("Cat 1");
    Dog d1("Dog 1");

    c1.MakeSound();
    d1.MakeSound();

    return 0;
}
