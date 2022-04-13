//
// Created by Stefan Andonov on 4/1/22.
//

#include<stdio.h>
#include<string.h>
typedef struct Call {
    int day;
    int month;
    int year;
    int duration;
    char caller [10];
    char receiver [10];
} Call;

void readCall (Call * call) {
    scanf("%d/%d/%d %s %s %d", &call->day, &call->month, &call->year, call->caller, call->receiver, &call->duration);
}

void printCall (Call call) {
    printf("%d/%d/%d %s %s %d\n", call.day, call.month, call.year, call.caller, call.receiver, call.duration);
}

int main () {
    int N;
    scanf("%d", &N);

    for (int i=0;i<N;i++) {
        Call c;
        readCall(&c);
        if ((c.year==2019 || c.year==2020) && strcmp(c.caller,"070214011")==0) {
            printCall(c);
        }
    }
    return 0;
}