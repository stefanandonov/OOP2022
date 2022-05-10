//
// Created by Stefan Andonov on 4/27/22.
//

#include<iostream>
#include<cstring>

using namespace std;

class Animal { //abstract class
protected:
    char name[30];
public:
    Animal(char *name) {
        strcpy(this->name, name);
    }

    virtual void makeSound() = 0;
};

class Dog : public Animal {
public:
    Dog (char * name) : Animal(name) {

    }

    void makeSound() {
        cout << name << " is making the sound afafaf"<<endl;
    }
};

class Cat : public Animal {
public:
    Cat (char * name) : Animal(name) {

    }

    void makeSound() {
        cout << name << " is making the sound mjau mjau mjau"<<endl;
    }
};


int main() {
//    Animal ** animals = new Animal * [3];
//
//
//    animals[0] = new Animal("simba");
//    animals[1] = new Dog("kuci");
//    animals[2] = new Cat("luna");
//
//    for (int i=0;i<3;i++) {
//        animals[i]->makeSound();
//    }

    int n;
    cin >> n;

    Animal ** animals = new Animal * [n];

//    Animal * animal1 = new Animal("test"); ne moze da se deklarira objekt od apstraktna klasa

    for (int i=0;i<n;i++) {
        int type; //1=cat 2=dog
        char name [30];
        cin >> type >> name;
        if (type==1) {
            animals[i] = new Cat(name);
        } else {
            animals[i] = new Dog(name);
        }
    }

    for (int i=0;i<n;i++) {
        animals[i]->makeSound();
    }

    return 0;
}