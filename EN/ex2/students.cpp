//
// Created by Stefan Andonov on 3/4/22.
//

#include<iostream>

using namespace std;

void normalizeName(char *name) {
    name[0] = toupper(name[0]);
    for (int i = 1; i < strlen(name); i++) {
        name[i] = tolower(name[i]);
    }
}

struct Student {
    char firstName[50];
    char lastName[50];
    char ID[10];
    int cntGrades;
    int grades[40];

    void read() {
        cin >> firstName >> lastName >> ID >> cntGrades;
        for (int i = 0; i < cntGrades; i++) {
            cin >> grades[i];
        }
    }

    float averageGrade() {
        float sum = 0;
        for (int i = 0; i < cntGrades; i++) {
            sum += ((float) grades[i]);
        }
        return sum / cntGrades;
    }

    void print() {
        normalizeName(firstName);
        normalizeName(lastName);
        cout << lastName << " " << firstName << " " << ID << " " << averageGrade() << endl;
    }

    bool hasLargerAverage (Student right) {
        return averageGrade() >= right.averageGrade();
    }
};

void sortStudents(Student *students, int n) {
    int i, j;
    Student tmp;
    for (i = 0; i < n; i++)
        for (j = 0; j < n - i - 1; j++)
            if (!students[j].hasLargerAverage(students[j + 1])) {
                tmp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = tmp;
            }
}

int main() {

//    Student s;
//    readStudent(&s);
//    printStudent(s);

    int n;
    cin>>n;
    Student students[100];
    for (int i = 0; i < n; i++) {
        students[i].read();
    }

    sortStudents(students, n);

    for (int i = 0; i < n; i++) {
        students[i].print();
    }


    return 0;
}