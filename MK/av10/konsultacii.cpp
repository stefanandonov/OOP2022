//
// Created by Stefan Andonov on 5/10/22.
//

#include<iostream>
using namespace std;

class Base {
protected:
    int x;
public:
    Base (int x = 0) {
        this->x = x;
    }

    virtual Base & operator--() {
        x--;
        return *this;
    }

    virtual void print () {
        cout<<"Base"<<" "<<x<<endl;
    }
};

class Derived : public Base {
public:
    Derived(int x = 0) : Base(x) {
        //do nothing
    }

    //override na implementacijata od klasata Base
    Base & operator--() {
        x-=2;
        return *this;
    }

    void print () {
        cout<<"Derived"<<" "<<x<<endl;
    }
};

int main () {
    Base * base = new Base(5);
    Base * derived = new Derived(5);

    --(*base);
    --(*derived);

    base->print();
    derived->print();
}


