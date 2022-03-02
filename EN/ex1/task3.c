//
// Created by Stefan Andonov on 2/25/22.
//

#include<stdio.h>

struct President {
    char name [100];
    char party [100];
};

typedef struct President President;

struct City {
    char name[100];
    long population;
};

typedef struct City City;

struct Country {
    char name [50];
    President president;
    City capital;
    long population;
};

typedef struct Country Country;

void readCity (City * c){
    scanf("%s %ld", c->name, &c->population);
}

void printCity (City c) {
    printf("%s with population of %ld ", c.name, c.population);
}

void readPresident (President * p) {
    scanf("%s %s", p->name, p->party);
}

void printPresident (President p) {
    printf("%s from party %s ", p.name, p.party);
}

void readCountry (Country * c) {
    scanf("%s", c->name);
    readPresident(&c->president);
    readCity(&c->capital);
    scanf("%ld", &c->population);
}

void printCountry (Country c) {
    printf("Country: %s ", c.name);
    printf("President: ");
    printPresident(c.president);
    printf("Capital: ");
    printCity(c.capital);
    printf("Total population of country: %ld", c.population);
}



int main () {

    Country c;

    readCountry(&c);
    printCountry(c);

}