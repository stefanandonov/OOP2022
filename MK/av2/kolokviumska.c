//
// Created by Stefan Andonov on 3/2/22.
//

#include<stdio.h>
#include<string.h>

struct Call {
    int day;
    int month;
    int year;
    char caller [10];
    char receiver [10];
    int duration;
};

typedef struct Call Call;

void readCall (Call * c) {
    scanf("%d/%d/%d %s %s %d", &c->day, &c->month, &c->year, c->caller, c->receiver, &c->duration);
}

void printCall (Call c) {
    printf("%02d/%02d/%d %s %s %d\n", c.day, c.month, c.year, c.caller, c.receiver, c.duration);
}

int main () {
    int N;
    scanf("%d", &N);

    Call calls [500];
    int totalDuration = 0;
    for (int i=0;i<N;i++) {
        readCall(calls + i);
        if (strcmp(calls[i].caller, "070214011")==0 && (calls[i].year==2019 || calls[i].year==2020)) {
            printCall(calls[i]);
            totalDuration+=calls[i].duration;
        }
    }
    printf("Total: %d sec.", totalDuration);

}