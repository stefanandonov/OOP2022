//
// Created by Stefan Andonov on 2/25/22.
//1.1. Date
//Write a program that will compare two dates (day, month, year). Define a struct date.
//

#include<stdio.h>
#include<string.h>
struct Date {
    int day;
    int month;
    int year;
};

typedef struct Date Date;

void readDate (Date * date){
    scanf("%d %d %d", &date->day, &date->month, &date->year);
}

void printDate (Date date){
    printf("%02d.%02d.%d ", date.day, date.month, date.year);
}

int dateCompare (Date left, Date right){ //-1 left is smaller, 0 if equal, 1 if larger
    if (left.year>right.year){
        return 1;
    } else if (left.year<right.year){
        return -1;
    } else { //left.year == right.year
        if (left.month>right.month){
            return 1;
        } else if (left.month < right.month){
            return -1;
        } else { //left.month == right.month
            if (left.day>right.day) {
                return 1;
            } else if (left.day < right.day) {
                return -1;
            } else {
                return 0;
            }
        }
    }
}

int main () {
    Date date;
    Date date1;
    Date * datePtr = &date;

    readDate(datePtr);
    readDate(&date1);

    int result = dateCompare(date, date1);

    if (result==0){
        printf("They are the same");
    } else if (result==1) {
        printDate(date);
        printf("is larger than ");
        printDate(date1);
    } else { //result == -1
        printDate(date);
        printf("is smaller than ");
        printDate(date1);
    }

//    char * date1 = "20210101";
//    char * date2 = "20210101";
//
//    printf("%d", strcmp(date1,date2));


//    printDate(date);
//    printDate(date1);

    return 0;
}