//
// Created by Stefan Andonov on 3/2/22.
//

#include<iostream>

using namespace std;

void swapNumbers (int & a, int & b) {
    int tmp = a;
    a = b;
    b = tmp;
}

int main () {
    int a = 10;
    int b = 7;
    swapNumbers(a,b);
    cout<<a<<" "<<b<<endl;


    int x = 10;
    int & xRef = x; //xRef ke ja referencira promenlivata x;

    xRef++;

    cout<<x;
}