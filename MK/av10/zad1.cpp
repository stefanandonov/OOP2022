//
// Created by Stefan Andonov on 5/4/22.
//

#include<iostream>

using namespace std;

class Vehicle {
protected:
    int acceleration;
public:
    Vehicle() {
        acceleration = 0;
        cout << "Vehicle constructor called" << endl;
    }

    virtual void accelerate() {
        cout << "Vehicle acceleration called" << endl;
        acceleration++;
    }

    ~Vehicle() {
        cout << "Vehicle destructor called" << endl;
    }

    int getAcceleration() {
        return acceleration;
    }
};

class Car : virtual public Vehicle {
public:
    Car() {
        cout << "Car constructor called" << endl;
    }

//    virtual void accelerate () {
//        cout << "Car acceleration called" << endl;
////        acceleration+=2;
//        Vehicle::accelerate();
//        Vehicle::accelerate();
//    }

    virtual void drive() {
        cout << "Car is driving" << endl;
    }

    ~Car() {
        cout << "Car destructor called" << endl;
    }
};

class Jet : virtual public Vehicle {
public:
    Jet() {
        cout << "Jet constructor called" << endl;
    }

    virtual void accelerate() {
        cout << "Jet acceleration called" << endl;
        acceleration += 50;
    }

    virtual void fly() {
        cout << "Jet is flying" << endl;
    }

    ~Jet() {
        cout << "Jet destructor called" << endl;
    }
};

class JetCar : public Car, public Jet {
public:
    JetCar() {
        cout << "JetCar constructor called" << endl;
    }

    ~JetCar() {
        cout << "JetCar destructor called" << endl;
    }

    void drive() {
        cout << "JetCar is driving" << endl;
    }

    void fly() {
        cout << "JetCar is flying" << endl;
    }
};


int main() {
    JetCar jetCar;
    jetCar.fly();
    jetCar.drive();
    jetCar.accelerate();
    cout << jetCar.getAcceleration() << endl;
    return 0;
}
