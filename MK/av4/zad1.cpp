//
// Created by Stefan Andonov on 3/16/22.
//

#include<cstring>
#include<iostream>

using namespace std;

class Boy {
private:
    char fullName[100];
    int age;

public:
    //default constructor
    Boy() {
        strcpy(fullName, "Trajce");
        age = 18;
    }

    //constructor with arguments
    Boy(char *_fullName, int _age) {
        strcpy(fullName, _fullName);
        age = _age;
    }

    ~Boy() {
        //do nothing
    }

    //copy constructor
    Boy(const Boy &boy) {
        cout<<"Copy constructor for Boy is called"<<endl;
        strcpy(fullName, boy.fullName);
        age = boy.age;
    }

    void print() {
        //Momche: Ime Prezime Godini.
        cout << "Boy: " << fullName << " Age: " << age << endl;
    }

    int getAge() {
        return age;
    }

    void setAge(int i) {
        age = i;
    }
};

class Girl {
private:
    char fullName[100];
    int age;

public:
    //default constructor
    Girl() {
        strcpy(fullName, "Trajanka");
        age = 30;
    }

    //constructor with arguments
    Girl(char *_fullName, int _age) {
        strcpy(fullName, _fullName);
        age = _age;
    }

    ~Girl() {
        //do nothing
    }

    //copy constructor
    Girl(const Girl &boy) {
        cout<<"Copy constructor for Girl is called"<<endl;
        strcpy(fullName, boy.fullName);
        age = boy.age;
    }

    void print() {
        //Momche: Ime Prezime Godini.
        cout << "Girl: " << fullName << " Age: " << age << endl;
    }

    int getAge() {
        return age;
    }

};

class Date {
private:
    Boy boy;
    Girl girl;

public:
    Date() {

    }

    Date(Boy _boy, Girl _girl) {
        boy = _boy;
        girl = _girl;
    }

    Date(const Date &date) {
        boy = date.boy;
        girl = date.girl;
    }

    void print() {
        cout << "Date between ";
        boy.print();
        cout << " and ";
        girl.print();
    }

    void isMatch() {
        int diff = abs(boy.getAge() - girl.getAge());
        if (diff <= 5) {
            cout << "Match" << endl;
        } else {
            cout << "Not a match. Swipe left" << endl;
        }
    }
};

int main() {
    //default constructor
    Boy b;
//    b.print();

//    explicit call to the copy-constructor
    Boy b1(b);
    Boy b2 = b;
    b1.print();

    Girl g;

    //usage of default constructor with array
//    Girl girls[100];
//
//    for (int i=0;i<100;i++){
//        girls[i].print();
//    }

    //copy-constructor is called implicitly
    //se kreira kopija od b i od g koja sto se prakja vo konstruktorot na Date

    Date date(b, g);
    b.setAge(25);
    date.print();
    date.isMatch();


    date.print();

    return 0;
}