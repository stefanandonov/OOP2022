//
// Created by Stefan Andonov on 3/4/22.
//

#include<stdio.h>

struct SkiLift {
    char name [15];
    int capacity;
    int isActive;
};

typedef struct SkiLift SkiLift;

void readSkiLift (SkiLift * lift) {
    scanf("%s %d %d", lift->name, &lift->capacity, &lift->isActive);
}

struct SkiCenter {
    char name [20];
    char country [20];
    SkiLift lifts[20];
    int nOfLifts;
};

typedef struct SkiCenter SkiCenter;

void readSkiCenter (SkiCenter * center) {
    scanf("%s %s", center->name, center->country);
    scanf("%d", &center->nOfLifts);
    for (int i=0;i<center->nOfLifts;i++) {
        readSkiLift(&center->lifts[i]);
    }

}

int skiCenterCapacity (SkiCenter sc) {
    int sum = 0;
    for (int i=0;i<sc.nOfLifts;i++) {
        if (sc.lifts[i].isActive) {
            sum+=sc.lifts[i].capacity;
        }
    }
    return sum;
}

void printSkiCenter (SkiCenter sc) {
    printf("%s\n%s\n%d", sc.name, sc.country, skiCenterCapacity(sc));
}

int cmpSkiCenter (SkiCenter left, SkiCenter right){
    int leftCapacity = skiCenterCapacity(left);
    int rightCapacity = skiCenterCapacity(right);
    if (leftCapacity==rightCapacity) {
        if (left.nOfLifts > right.nOfLifts) {
            return 1;
        } else if (left.nOfLifts < right.nOfLifts) {
            return -1;
        } else {
            return 0;
        }
    } else {
        if (leftCapacity>rightCapacity) {
            return 1;
        } else {
            return -1;
        }
    }
}

void biggestCapacity(SkiCenter *sc, int n) {
    SkiCenter max = sc[0];
    for (int i=1;i<n;i++) {
        if (cmpSkiCenter(sc[i], max)>0) {
            max = sc[i];
        }
    }

    printSkiCenter(max);
}

int main () {

    int n;
    scanf("%d", &n);

    SkiCenter centers [20];

    for (int i=0;i<n;i++) {
        readSkiCenter(centers + i);
    }

    biggestCapacity(centers, n);

    return 0;
}