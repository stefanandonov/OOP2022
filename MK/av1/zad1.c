//
// Created by Stefan Andonov on 2/23/22.
//

#include<stdio.h>

struct Date {
    int day;
    int month;
    int year;
};
typedef struct Date Date;

int compare(Date d1, Date d2) { //-1 if d1<d2, 0 d1==d2, 1 d1>d2

    //return (d1.year > d2.year) ? 1 : ((d1.year < d2.year) ? -1 : (d1.month>d2.month) ? 1 : (d1.month<d2.month) ? -1 : (d1.day>d2.day) ? 1 : (d1.day<d2.day) ? 1 : 0);

//    int diff = d1.year - d2.year;
//    if (diff == 0) {
//        diff = d1.month - d2.month;
//        if (diff == 0) {
//            if (d1.day>d2.day) {
//                return 1;
//            } else if (d1.day < d2.day) {
//                return -1;
//            } else {
//                return 0;
//            }
//        }
//    }
//
//    if (diff>0){
//        return 1;
//    } else if (diff<0) {
//        return -1;
//    }

    if (d1.year > d2.year) {
        return 1;
    } else if (d1.year < d2.year) {
        return -1;
    } else {
        if (d1.month > d2.month) {
            return 1;
        } else if (d1.month < d2.month) {
            return -1;
        } else {
            if (d1.day > d2.day) {
                return 1;
            } else if (d1.day < d2.day) {
                return -1;
            } else {
                return 0;
            }
        }
    }
}

void readDate(Date *d) {
    scanf("%d %d %d", &d->day, &d->month, &d->year);
}

void printDate(Date d) {
    printf("%02d.%02d.%d", d.day, d.month, d.year);
}

int main() {

    Date date;
    Date date1;
    readDate(&date);
    readDate(&date1);

    int result = compare(date,date1);

    if (result==0) {
        printf("They are the same");
    } else if (result > 0) {
        printDate(date);
        printf(" is larger than ");
        printDate(date1);
    } else { //result < 0
        printDate(date1);
        printf(" is larger than ");
        printDate(date);
    }


//    Date date2;
//    readDate(&date);
//    readDate(&date1);
//    readDate(&date2);
//    printDate(date);
    return 0;
}