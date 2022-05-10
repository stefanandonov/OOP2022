//
// Created by Stefan Andonov on 4/15/22.
//

#include<iostream>
#include<cstring>

using namespace std;

class Student {
    char *name;
    int *grades;
    int nGrades;
    int year;

    void copy(const Student &student) {
        this->name = new char[strlen(student.name) + 1];
        strcpy(this->name, student.name);
        this->year = student.year;
        this->nGrades = student.nGrades;
        this->grades = new int[this->nGrades];
        for (int i = 0; i < this->nGrades; i++) {
            this->grades[i] = student.grades[i];
        }
    }

public:
    Student(char *name = "Finkash", int year = 1) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        this->year = year;
        this->nGrades = 0;
        this->grades = new int[0];
    }

    Student(const Student &s) {
        copy(s);
    }

    Student &operator=(const Student &s) {
        if (this != &s) {
            delete[] name;
            delete[] grades;
            copy(s);
        }
        return *this;
    }

    ~Student() {
        delete[] name;
        delete[] grades;
    }

    friend istream &operator>>(istream &in, Student &student) {
        return in >> student.name >> student.year;
    }

    double getAverage() const {
        if (nGrades == 0) {
            return 5.0;
        }
        double sum = 0;
        for (int i = 0; i < nGrades; i++) {
            sum += grades[i];
        }
        return (double) sum / nGrades;
    }


    friend ostream &operator<<(ostream &out, const Student &student) {
        //name - year (avearge)
        return out << student.name << " - " << student.year << " (" << student.getAverage() << ")" << endl;
    }

    //prefix++
    Student &operator++() {
        ++year;
        return *this;
    }

    //postfix
    Student operator++(int) {
        Student copy(*this);
        ++year;
        return copy;
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

    bool operator>(Student &other) {
        return this->getAverage() > other.getAverage();
    }
};

class Faculty {
    Student *students;
    int n;

public:
    Faculty() {
        students = new Student[0];
        n = 0;
    }

    Faculty &operator+=(const Student &s) {
        Student *tmp = new Student[n + 1];
        for (int i = 0; i < n; i++) {
            tmp[i] = students[i];
        }
        tmp[n++] = s;
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

    friend ostream &operator<<(ostream &out, const Faculty &f) {
        for (int i = 0; i < f.n; i++) {
            out << f.students[i];
        }
        return out;
    }

    void reward() {
        for (int i = 0; i < n; i++) {
            if (students[i].getAverage() >= 9.0) {
                cout << students[i];
            }
        }
    }

    void highestAverage() {
        double maxAverage = students[0].getAverage();
        for (int i = 1; i < n; i++) {
            //5.0 6.0 7.0 8.0 8.5 9.6
            double studentAverage = students[i].getAverage();
            if (studentAverage > maxAverage) {
                maxAverage = studentAverage;
            }
        }

        cout<<maxAverage;
    }

    Student & operator[](int idx) {
        return students[idx];
    }
};

int main() {
    Faculty f;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        Student s;
        cin >> s;
        int nGrades;
        cin >> nGrades;
        for (int j = 0; j < nGrades; j++) {
            int grade;
            cin>>grade;
            s+=grade;
        }
        f += s;
    }

    cout << f;

    ++f;
    cout<<"FACULTY AFTER AUGUST"<<endl;
    cout<<f;
    cout<<"REWARD"<<endl;
    f.reward();
    cout<<"HIGHEST AVERAGE"<<endl;
    f.highestAverage();

    f[0]+=10;
    f[0]+=10;
    f[0]+=10;
    f[0]+=10;
    f[0]+=10;

    cout<<f;
    cout<<"REWARD"<<endl;
    f.reward();
    cout<<"HIGHEST AVERAGE"<<endl;
    f.highestAverage();




//    cout<<++s;
//    cout<<s++;
//    cout<<s;

//    s += 6;
//    s += 7;
//    cout << s;
    return 0;
}

