#include <iostream>
#include <string>
#include <memory>

using namespace std;

class Node {
public:
    virtual int Evaluate() {
        return 0;
    }
};

class Digit : public Node {
public:
    Digit(int d) : d_(d) {}
    int Evaluate() override {
        return d_;
    }
private:
    const int d_;
};

class Variable : public Node {
public:
    Variable(const int& x) : x_(x) {}
    int Evaluate() override {
        return x_;
    }
private:
    const int& x_;
};

class Operation : public Node {
public:
    Operation(char op, shared_ptr<Node> left, shared_ptr<Node> right) 
        : op_(op), left_(left), right_(right) {}
    int Evaluate() override {
        if(op_ == '*') {
            return left_->Evaluate() * right_->Evaluate();
        } else if (op_ == '+') {
            return left_->Evaluate() + right_->Evaluate();
        } else if (op_ == '-') {
            return left_->Evaluate() - right_->Evaluate();
        }
        return 0;
    }
private:
    const char op_;
    shared_ptr<Node> left_, right_;
};


int main() {
    string tokens = "5+7-x*x+x";
   // cout << "Enter expression: ";
   // getline(cin, tokens);
    
    int x;
   // auto expr = Parse(begin(tokens), end(tokens), x); 
   
    shared_ptr<Node> var1 = make_shared<Variable>(x);
    shared_ptr<Node> var2 = make_shared<Variable>(x);
    shared_ptr<Node> mul1 = make_shared<Operation>('*', var1, var2);

    shared_ptr<Node> dig1 = make_shared<Digit>(5);
    shared_ptr<Node> dig2 = make_shared<Digit>(7);

    shared_ptr<Node> var3 = make_shared<Variable>(x);

    shared_ptr<Node> plus1 = make_shared<Operation>('+', dig1, dig2);
    shared_ptr<Node> minus1 = make_shared<Operation>('-', plus1, mul1);
    shared_ptr<Node> plus2 = make_shared<Operation>('+', minus1, var3);

    cout << "Enter x: ";
    while (cin >> x) {
        cout << plus2->Evaluate() << endl;
        cout << "Enter x: ";
    }

    return 0;
}
