//
// Created by Stefan Andonov on 2/23/22.
//

#include<stdio.h>

struct President {
    char name[100];
    char party[50];
};
typedef struct President President;

struct City {
    char name[100];
    int population;
};
typedef struct City City;

struct Country {
    char name[100];
    President president;
    City capital;
    int population;
};

typedef struct Country Country;

void readPresident(President *p) {
    scanf("%s %s", p->name, p->party);
}

void printPresident(President p) {
    printf("President: %s %s ", p.name, p.party);
}

void readCity(City *c) {
    scanf("%s %d", c->name, &c->population);
}

void printCity(City c) {
    printf("Capital: %s %d ", c.name, c.population);
}

void readCountry(Country *c) {
    scanf("%s", c->name);
    readPresident(&c->president);
    readCity(&c->capital);
    scanf("%d", &c->population);
}

void printCountry(Country c) {
    printf("%s ", c.name);
    printPresident(c.president);
    printCity(c.capital);
    printf("Country population :%d\n", c.population);
}

int compare(Country c1, Country c2) {
    if (c1.capital.population > c2.capital.population) {
        return 1;
    } else if (c1.capital.population < c2.capital.population) {
        return -1;
    } else {
        return 0;
    }
}

int max(int *niza, int n) {
    int max = niza[0];
    for (int i = 0; i < n; i++) {
        if (niza[i] > max) {
            max = niza[i];
        }
    }
    return max;
}

void printCountryWithLargestCapital(Country *countries, int n) {
    Country maxCountry = countries[0];
    for (int i = 1; i < n; i++) {
        if (compare(countries[i], maxCountry) > 0) {
            maxCountry = countries[i];
        }
    }
    printCountry(maxCountry);
}


int main() {
//    Country c;
//    readCountry(&c);
//    printCountry(c);

    Country countries[100];
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        readCountry(&countries[i]); //readCountry(countries + i);
//        printCountry(countries[i]);
    }

    printCountryWithLargestCapital(countries, n);

    return 0;
}