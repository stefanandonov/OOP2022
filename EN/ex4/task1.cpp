//
// Created by Stefan Andonov on 3/18/22.
//

#include<iostream>
#include<cstring>

using namespace std;

enum GENDER {
    MALE,  //0
    FEMALE, //1
    OTHER //2
};

class Mate {
private:
    char name[50];
    int age;
    GENDER gender;

public:
    //default constructor
    Mate() {
        strcpy(name, "");
        age = 18;
        gender = (GENDER) 2;
    }

    //constructor with arguments
    Mate(char *_name, int _age, GENDER _gender) {
        strcpy(name, _name);
        age = _age;
        gender = _gender;
    }

    //copy-constructor
    Mate(const Mate &other) {
        cout << "Copy constructor for Mate is called" << endl;
        strcpy(name, other.name);
        age = other.age;
        gender = other.gender;
    }

    ~Mate() {

    }

    void printGender() {
        switch (gender) {
            case MALE:
                cout << "MALE";
                break;
            case FEMALE:
                cout << "FEMALE";
                break;
            default:
                cout << "OTHER";
                break;
        }
    }

    void print() {
        cout << name << " " << age << " ";
        printGender();
        cout << endl;
    }

    int getAge() {
        return age;
    }
};

class Date {
private:
    Mate mate1;
    Mate mate2;
public:
    //default constructor
    Date() {
        //do nothing, as mate1 and mate2 have their own default constructor
    }

    //constructor with arguments
    Date(Mate &_mate1, Mate &_mate2) {
        mate1 = _mate1;
        mate2 = _mate2;
    }

    //copy-constructor
    Date(const Date &other) {
        mate1 = other.mate1;
        mate2 = other.mate2;
    }

    //destructor
    ~Date() {

    }

    void print() {
        cout << "Date between: " << endl;
        mate1.print();
        mate2.print();
        cout << (isSuccess() ? "Successful" : "Not Successful");
    }

    bool isSuccess() {
        int diff = abs(mate1.getAge() - mate2.getAge());
        return diff >= 2 && diff <= 5;
    }
};

int main() {
    Mate m("A", 25, MALE);
    Mate m1("B", 24, FEMALE);

    //where the copy-constructor for Mate is called implicitly
    Date date(m, m1);
    date.print();
    //explicit call of the copy-constructor
    //first way
//    Mate copy (m);
    //second way
//    Mate copy1 = m;
    //this is not a copy constructor call!!!
//    Mate copy2;
//    copy2 = m;

    return 0;
}
