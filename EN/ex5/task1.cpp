//
// Created by Stefan Andonov on 3/25/22.
//

#include<iostream>
#include<cstring>

using namespace std;

class Team {
private:
    char *name;
    char *city;
    char *stadium;

    void copy(const Team &other) {
        this->name = new char[strlen(other.name) + 1];
        strcpy(this->name, other.name);

        this->city = new char[strlen(other.city) + 1];
        strcpy(this->city, other.city);

        this->stadium = new char[strlen(other.stadium) + 1];
        strcpy(this->stadium, other.stadium);
    }

public:
    //default constructor and constructor with arguments 2in1
//    Team() {}
    Team(char *name = "" , char *city = "", char *stadium = "") {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);

        this->city = new char[strlen(city) + 1];
        strcpy(this->city, city);

        this->stadium = new char[strlen(stadium) + 1];
        strcpy(this->stadium, stadium);
    }

    Team(const Team &other) {
        copy(other);
    }

//    Team &operator=(const Team &t) {
//        if (this != &t) {
//            delete[] name;
//            delete[] city;
//            delete[] stadium;
//            copy(t);
//        }
//        return *this;
//    }

    ~Team() {
        delete[] name;
        delete[] city;
        delete[] stadium;
    }

    void print() {
        cout << "Team name: " << name << " from city: " << city << " plays on the stadium: " << stadium << endl;
    }
};


int main() {
    int N; //number of teams

    cin >> N;

    Team * teams = new Team [N]; //default constructor is called N times

    char name [100];
    char city [100];
    char stadium [100];

    for (int i=0;i<N;i++) {
        cin >> name >> city >> stadium;
        teams[i] = Team(name, city, stadium); //WHERE OPERATOR = COMES
    }

    for (int i=0;i<N;i++) {
        teams[i].print();
    }



    return 0;
}