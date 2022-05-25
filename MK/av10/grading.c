//
// Created by Stefan Andonov on 5/6/22.
//

#include<stdio.h>
#include<stdlib.h>
double duration(int poagjanjeVr, int pristiganjeVr){
    double departure = poagjanjeVr/100 + poagjanjeVr%100/60.0;
    double arrival = pristiganjeVr/100 + pristiganjeVr%100/60.0;
    printf("%.2f %.2f\n", departure, arrival);
    return arrival-departure;
}

int main () {
    printf("%.2f", duration(958, 1230));
    return 0;
}