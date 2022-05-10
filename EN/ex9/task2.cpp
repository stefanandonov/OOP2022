//
// Created by Stefan Andonov on 4/29/22.
//

#include<iostream>
#include<cstring>

using namespace std;

class Animal {
protected:
    char name[30];
public:
    Animal(char *name = "noname") {
        strcpy(this->name, name);
    }

    virtual void makeSound() = 0;
};

class Cat : public Animal {
public:
    Cat (char * name = "noname") : Animal(name) {

    }

    void makeSound() {
        cout << name << " makes the sound mjau mjau" << endl;
    }
};

class Dog : public Animal {
public:
    Dog (char * name = "noname") : Animal(name) {

    }

    void makeSound() {
        cout << name << " makes the sound af af af" << endl;
    }
};

class Parrot: public Animal{ //abstract class until it implements the method makeSound

public:
    Parrot (char * name = "noname") : Animal(name) {

    }

    void makeSound() {

    }
};


int main() {
    Animal ** animals = new Animal * [3];
    animals[0] = new Cat ("Luna");
    animals[1] = new Dog ("Dzheki");
    animals[2] = new Parrot("Kiko");

    for (int i=0;i<2;i++){
        animals[i]->makeSound();
    }

}


