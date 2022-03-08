//
// Created by Stefan Andonov on 3/4/22.
//

#include<stdio.h>
#include<iostream>

using namespace std;

inline int cube(int number) {
    return number * number * number;
}

struct Pair {
    int x;
    int y;

    void read () {
        cin >> x >> y;
    }

    void print () {
        cout << x << " " << y <<endl;
    }
};


void swapNumber (int & x, int & y) {
    int tmp = x;
    x = y;
    y = tmp;
}



int main() { //C++
//    int value1, value2;
////    scanf("%d %d", &value1, &value2); in programming language C
////    cin >> value1 >> value2; //in programming language C++
//
////    printf("%d %d", value1, value2); in programming language C
//    cout << value1 << endl << value2 << endl;
//
//    for (int i = 1; i <= 10; i++) {
////        cout << i << " " << cube(i) << endl; //replaced into i*i*i, not into a call to the method
//    }
//
//    Pair pair;
//    pair.read();
//    pair.print();

    int x = 5;
    int y = 10;

//    swapNumber(x,y);
//
//    cout << x << " " << y;

    int & xRef = x;
    xRef++;
    cout << x;




    return 0;
}