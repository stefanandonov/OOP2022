//
// Created by Stefan Andonov on 2/25/22.
//

#include<stdio.h>

struct President {
    char name[100];
    char party[100];
};

typedef struct President President;

struct City {
    char name[100];
    long population;
};

typedef struct City City;

struct Country {
    char name[50];
    President president;
    City capital;
    long population;
};

typedef struct Country Country;

void readCity(City *c) {
    scanf("%s %ld", c->name, &c->population);
}

void printCity(City c) {
    printf("%s with population of %ld ", c.name, c.population);
}

void readPresident(President *p) {
    scanf("%s %s", p->name, p->party);
}

void printPresident(President p) {
    printf("%s from party %s ", p.name, p.party);
}

void readCountry(Country *c) {
    scanf("%s", c->name);
    readPresident(&c->president);
    readCity(&c->capital);
    scanf("%ld", &c->population);
}

void printCountry(Country c) {
    printf("Country: %s ", c.name);
    printf("President: ");
    printPresident(c.president);
    printf("Capital: ");
    printCity(c.capital);
    printf("Total population of country: %ld\n", c.population);
}

int cmpCountry(Country left, Country right) {
    if (left.capital.population > right.capital.population) {
        return 1;
    } else if (left.capital.population < right.capital.population) {
        return -1;
    } else {
        return 0;
    }
}

void findCountryWithLargestCapital(Country *countries, int n) {
    Country max = countries[0];
    for (int i = 1; i < n; i++) {
        if (cmpCountry(countries[i], max)>0) {
            max = countries[i];
        }
    }
    printPresident(max.president);
}

int findMax (int * array, int n) {
    int max = array[0];
    for (int i=1;i<n;i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
}


int main() {
    int n;
    scanf("%d", &n);

    Country countries[100];

    for (int i = 0; i < n; i++) {
        readCountry(countries + i);
//        printCountry(countries[i]);
    }

    findCountryWithLargestCapital(countries, n);
}