//
// Created by Stefan Andonov on 3/2/22.
//

/*
 * Да се креира структура SkiLift во која се чуваат податоци за името на ски лифтот (низа од 15 знаци), максимален број на корисници што може да опслужи на едно возење, дали е пуштен во функција.

Потоа да се креирa структура SkiCenter во која се чуваат податоци за името на скијачкиот центар, држава во која се наоѓа (низи од 20 знаци), низа од ски лифтови (макс 20) што ги има и број на ски лифтови.

Треба да се направи функција со потпис

void najgolemKapacitet(SkiCenter *sc, int n)
која што ќе го отпечати ски центарот што има најголем капацитет за опслужување скијачи (вкупниот број на скијачи кои може да се опслужуваат во еден момент вкупно на сите ски лифтови во центарот).
 Доколку два ски центри имаат ист капацитет, тогаш се печати оној кој има поголем број на ски лифтови. Притоа треба да се испечатат во посебен ред името, државата и капацитетот на ски центарот.
 Кога се пресметува капацитет на еден ски центар во предвид се земаат само ски лифтовите кои се поставени дека се во функција.
 * */

#include<stdio.h>

struct SkiLift {
    char name [15];
    int maxUsers;
    int active;
};

typedef struct SkiLift SkiLift;

struct SkiCenter {
    char name [20];
    char country [20];
    SkiLift skiLifts [20];
    int cntLifts;
};

typedef struct SkiCenter SkiCenter;

void readSkiLift (SkiLift * lift) {
    /*
     * Ednosed
     * 30
     * 1
     * */
    scanf("%s %d %d", lift->name, &lift->maxUsers, &lift->active);
}

void readSkiCenter (SkiCenter * center) {
    scanf("%s %s", center->name, center->country);
    scanf("%d", &center->cntLifts);
    for (int i=0;i<center->cntLifts;i++) {
        readSkiLift(center->skiLifts + i);
    }
}

int calculateCapacityForSkiCenter (SkiCenter center){
    int sum = 0;
    for (int i=0;i<center.cntLifts;i++) {
        if (center.skiLifts[i].active) {
            sum+=center.skiLifts[i].maxUsers;
        }
    }
    return sum;
}

void printSkiCenter (SkiCenter center) {
    printf("%s\n%s\n%d\n", center.name, center.country, calculateCapacityForSkiCenter(center));
}

int cmpSkiCenter (SkiCenter s1, SkiCenter s2) {
    if (calculateCapacityForSkiCenter(s1)>calculateCapacityForSkiCenter(s2)) {
        return 1;
    } else if (calculateCapacityForSkiCenter(s1)<calculateCapacityForSkiCenter(s2)){
        return -1;
    } else {
        if (s1.cntLifts > s2.cntLifts){
            return 1;
        } else if (s1.cntLifts < s2.cntLifts) {
            return -1;
        } else {
            return 0;
        }
    }
}

void najgolemKapacitet(SkiCenter *centers, int n) {
    SkiCenter max = centers[0];
    for (int i=1;i<n;i++) {
        if (cmpSkiCenter(centers[i], max)>0) {
            max = centers[i];
        }
    }
    printSkiCenter(max);

}

int main()
{
    int i;
    int n;
    SkiCenter centers [10];
    scanf("%d", &n);
    for (i = 0; i < n; i++){
        readSkiCenter(centers + i);
//        readSkiCenter(&centers[i]);
//        printSkiCenter(centers[i]);
    }

    najgolemKapacitet(centers, n);


    return 0;
}