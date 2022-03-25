//
// Created by Stefan Andonov on 3/23/22.
//

#include<iostream>
#include<cstring>

using namespace std;

class Team {
private:
    char *name;
    char *stadium;
    char *city;

    void copy (const Team & other) {
        this->name = new char[strlen(other.name) + 1];
        strcpy(this->name, other.name);
        this->stadium = new char[strlen(other.stadium) + 1];
        strcpy(this->stadium, other.stadium);
        this->city = new char[strlen(other.city) + 1];
        strcpy(this->city, other.city);
    }

    void freeMemory () {
        delete[] name;
        delete[] stadium;
        delete[] city;
    }
public:
    //constructor with args and default

    Team() {

    }
    Team(char *name, char *stadium, char *city) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        this->stadium = new char[strlen(stadium) + 1];
        strcpy(this->stadium, stadium);
        this->city = new char[strlen(city) + 1];
        strcpy(this->city, city);
    }

    //copy-constructor
    Team(const Team &other) {
        copy(other);
    }

    Team &operator=(const Team &other) {
        if (this != &other) {
            freeMemory();
            copy(other);
        }
        return *this;
    }

    ~Team() {
        freeMemory();
    }

    void print () {
        cout<<"Team name: "<<name<<" which plays on stadium: "<<stadium<<" in the city: "<<city<<endl;
    }
};

int main() {
    int n;
    cin>>n;
    Team * teams = new Team[n]; //ako nema default constructor, tuka ke padne

    char name[100];
    char stadium[100];
    char city[100];
    for (int i=0;i<n;i++) {
        cin>>name>>stadium>>city;
        teams[i] = Team(name, stadium, city); //bez operator =, tuka ke padne programata
    }

    for (int i=0;i<n;i++){
        teams[i].print();
    }





}