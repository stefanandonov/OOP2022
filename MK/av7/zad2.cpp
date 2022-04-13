//
// Created by Stefan Andonov on 4/13/22.
//

#include<iostream>

using namespace std;

class Student {
    char *name;
    int *grades;
    int nGrades;
    int year;

    void copy(const Student &s) {
        this->name = new char[strlen(s.name) + 1];
        strcpy(this->name, s.name);
        this->nGrades = s.nGrades;
        grades = new int[this->nGrades];
        for (int i = 0; i < this->nGrades; i++) {
            this->grades[i] = s.grades[i];
        }
        this->year = s.year;
    }

public:
    Student(char *name = "", int year = 2001) { //2in1
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        nGrades = 0;
        grades = new int[0];
        this->year = year;
    }

    Student(const Student &other) {
        copy(other);
    }

    Student &operator=(const Student &other) {
        if (this != &other) {
            delete[] name;
            delete[] grades;
            copy(other);
        }
        return *this;
    }

    ~Student() {
        delete[] name;
        delete[] grades;
    }

    Student &operator++() { //prefix ++
        ++year;
        return *this;
    }

    Student operator++(int) { //postfix ++
        Student result(*this); //ista kopija so this objektot
        ++year;
        return result;
    }

    Student &operator+=(int grade) {
        int *tmp = new int[nGrades + 1];
        for (int i = 0; i < nGrades; i++) {
            tmp[i] = grades[i];
        }
        tmp[nGrades++] = grade;
        delete[] grades;
        grades = tmp;
        return *this;
    }

    double getAverage() const {
        if (nGrades == 0) {
            return 5.0;
        }
        int sum = 0;
        for (int i = 0; i < nGrades; i++) {
            sum += grades[i];
        }
        return (double) sum / nGrades;
    }

    friend ostream &operator<<(ostream &out, const Student &student) {
        out << student.name << " " << student.year << " " << student.getAverage() << endl;
        return out;
    }

    bool operator>(Student &student) {
        return this->getAverage() > student.getAverage();
    }
};

class Faculty {
    Student *students;
    int n;

    void copy(const Faculty &other) {
        this->n = other.n;
        students = new Student[this->n];
        for (int i = 0; i < this->n; i++) {
            students[i] = other.students[i];
        }
    }

public:
    Faculty() {
        n = 0;
        students = new Student[0];
    }

    Faculty(const Faculty &other) {
        copy(other);
    }

    Faculty &operator=(const Faculty &other) {
        if (this != &other) {
            delete[] students;
            copy(other);
        }
        return *this;
    }

    ~Faculty() {
        delete[] students;
    }

    Faculty &operator+=(const Student &newStudent) {
        Student *tmp = new Student[n + 1];
        for (int i = 0; i < n; i++) {
            tmp[i] = students[i];
        }
        tmp[n++] = newStudent;
        delete[] students;
        students = tmp;
        return *this;
    }

    Faculty &operator++() {
        for (int i = 0; i < n; i++) {
            ++students[i];
        }
        return *this;
    }

    friend ostream &operator<<(ostream &out, const Faculty &faculty) {
        for (int i = 0; i < faculty.n; i++) {
            out << faculty.students[i];
        }
        return out;
    }

    void prize() {
        for (int i = 0; i < n; i++) {
            if (students[i].getAverage() == 10.0) {
                cout << students[i];
            }
        }
    }

    void highestAverage() {
        Student max = students[0];
        for (int i = 1; i < n; i++) {
            if (students[i] > max) {
                max = students[i]; //tuka ke padne ako nemate operator =
            }
        }
        cout << max;
    }
};

int main() {
    Student s("Stefan", 1);
    //cout << s;
    s += 6;
    s += 8;
    s += 10;
    s += 7;
    Faculty faculty;
    Student t("trajce", 2);
    t += 10;
    t += 10;
    t += 10;
    t += 10;
    Student r("riste", 2);
    r += 10;
    r += 9;
    r += 10;
    r += 8;
    faculty += s;
    faculty += t;
    faculty += r;
    cout << faculty;
    cout <<"---------"<<endl;
    ++faculty;
    cout<<faculty;
    cout <<"---------"<<endl;
    faculty.prize();
    cout <<"---------"<<endl;
    faculty.highestAverage();
//    cout << "------" << endl;
//    cout << s;
//    cout << "------" << endl;
//    cout << ++s;
//    cout << "------" << endl;
//    cout << s++;
//    cout << s;
//    cout << "------" << endl;
//    Student sCopy(s);
//    sCopy += 10;
//    sCopy += 10;
//    sCopy += 9;
//    cout << s;
//    cout << sCopy;
//    cout << (sCopy > s);
    return 0;
}
