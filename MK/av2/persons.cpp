//
// Created by Stefan Andonov on 3/2/22.
//

#include<iostream>
#include<string.h>

using namespace std;

struct Employee {
    char name[100];
    char position[100];
    double baseSalary;

    void read() {
        cin >> name >> position >> baseSalary;
    }

    void print() {
        cout << "Name: " << name << " Position: " << position << " Salary: " << calculateSalary() << endl;
    }

    double calculateSalary() {
        if (strcmp(position, "TA") == 0) {
            return 1.10 * baseSalary;
        } else if (strcmp(position, "Assistant Professor") == 0) {
            return 1.50 * baseSalary;
        } else if (strcmp(position, "Associate Professor") == 0) {
            return 1.90 * baseSalary;
        } else {
            return 2.4 * baseSalary;
        }
    }
};

int main() {
    Employee employee;
    employee.read();
    employee.print();
    return 0;
}