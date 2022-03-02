//
// Created by Stefan Andonov on 2/25/22.
//

#include<stdio.h>
#include<string.h>
#include<ctype.h>

struct Student {
    char firstName[50];
    char lastName[50];
    char ID[10];
    int cntGrades;
    int grades[40];
};

typedef struct Student Student;

void readStudent(Student *student) {
    scanf("%s %s %s ", student->firstName, student->lastName, student->ID);
    scanf("%d", &student->cntGrades);
    for (int i = 0; i < student->cntGrades; i++) {
        scanf("%d", &student->grades[i]);
    }
}

float averageGrade(Student s) {
    float sum = 0;
    for (int i = 0; i < s.cntGrades; i++) {
        sum += ((float) s.grades[i]);
    }
    return sum / s.cntGrades;
}

float compareStudent(Student left, Student right) {
    return averageGrade(left) - averageGrade(right); //same == 0, left>right >0, left<right <0
//    if (averageGrade(left) > averageGrade(right)) {
//        return 1;
//    } else if (averageGrade(left) < averageGrade(right)) {
//        return -1;
//    } else {
//        return 0;
//    }
}

void normalizeName(char *name) {
    name[0] = toupper(name[0]);
    for (int i = 1; i < strlen(name); i++) {
        name[i] = tolower(name[i]);
    }
}

void printStudent(Student student) {
    normalizeName(student.firstName);
    normalizeName(student.lastName);
    printf("%s %s %s %.2f\n", student.lastName, student.firstName, student.ID, averageGrade(student));
}

void sortStudents (Student * students, int n) {
    int i, j;
    Student tmp;
    for (i = 0; i < n; i++)
        for (j = 0; j < n - i - 1; j++)
            if (compareStudent(students[j], students[j+1])<0) {
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
    scanf("%d", &n);
    Student students[100];
    for (int i = 0; i < n; i++) {
        readStudent(students + i); //readStudent(&students[i]);
//        printStudent(students[i]);
    }

    sortStudents(students, n);

    for (int i = 0; i < n; i++) {
        printStudent(students[i]);
    }




    return 0;
}