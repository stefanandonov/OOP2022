//
// Created by Stefan Andonov on 3/4/22.
//

struct test {
    int x;
};

typedef struct test test;


int main () {
    test tests [100];

    test temp = tests[1];
    tests[1]=tests[5];
    tests[5]=temp;
}



