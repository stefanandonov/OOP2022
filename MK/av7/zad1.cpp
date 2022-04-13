//
// Created by Stefan Andonov on 3/23/22.
//

#include<iostream>

using namespace std;

class Array {
private:
    int *content;
    int capacity;
    int size;

    void copy(const Array &other) {
        this->capacity = other.capacity;
        this->size = other.size;
        this->content = new int[this->capacity];
        //strcpy(this->content, other.content)
        for (int i = 0; i < this->size; i++) {
            this->content[i] = other.content[i];
        }
    }

public:
    Array(int capacity = 10) {
        this->capacity = capacity;
        this->content = new int[capacity];
        this->size = 0;
    }

    Array(const Array &other) {
        copy(other);
    }

    Array &operator=(const Array &other) {
        if (this != &other) {
            delete[] content;
            copy(other);
        }
        return *this;
    }

    ~Array() {
        delete[] content;
    }

    //void addNumber (int number)
    Array &operator+=(int number) {
        if (size < capacity) {
            content[size++] = number;
        } else {
            //1. move all elements and the new element in a temp content
            capacity *= 2;
            int *tmp = new int[capacity];
            for (int i = 0; i < size; i++) {
                tmp[i] = content[i];
            }
            tmp[size++] = number;
            delete[] content;
            content = tmp;
        }
        return *this;
    }

    void change(int a, int b) {
        for (int i = 0; i < size; i++) {
            if (content[i] == a) {
                content[i] = b;
            }
        }
    }

    int countOccurrences(int number) {
        int counter = 0;
        for (int i = 0; i < size; i++) {
            if (content[i] == number) {
                ++counter;
            }
        }
        return counter;
    }

    //void deleteAll(int number)
    Array &operator-=(int number) {
        int j = 0;
        for (int i = 0; i < size; i++) {
            if (content[i] != number) {
                content[j++] = content[i];
            }
        }

        this->size = j;

        return *this;
    }

    friend ostream &operator<<(ostream &out, const Array &a) {
        out << "Capacity: " << a.capacity << endl;
        out << "Size: " << a.size << endl;
        out << "Percentage filled: " << (100.0 * a.size) / a.capacity << "%" << endl;
        for (int i = 0; i < a.size; i++) {
            if (i != a.size - 1) {
                out << a.content[i] << ", ";
            } else {
                out << a.content[i];
            }
        }
        out << endl;
        return out;
    }

    friend istream &operator>>(istream &in, Array &a) {
        in >> a.capacity;
        return in;
    }

    int &operator[](int idx) {
        return content[idx];
    }

    bool operator==(Array &other) {
        if (this->size != other.size) {
            return false;
        }
        for (int i = 0; i < this->size; i++) {
            if (this->content[i] != other.content[i]) {
                return false;
            }
        }
        return true;
    }


};

int main() {
    Array a;
    cin >> a;
    cout << a;

//    Array a;
//    a.print();
    for (int i = 0; i < 10; i++) {
        a += i;
    }
    cout << "--------" << endl;
    cout << a;
    cout << "--------" << endl;
    a += 1;
    cout << a;
    for (int i = 1; i <= 10; i++) {
        a += i;
    }
    cout << "--------" << endl;
    cout << a;
    cout << "--------" << endl;
//    a.change(2, 1);
//    a.print();
//    cout << "--------" << endl;
    a -= 1;
    cout << a;

    cout << "--------" << endl;
    a[3] = 100;
    cout << a;

    cout << "Ednakvost--------" << endl;
    Array a1(a); //copy-constructor
    cout << (a == a1) << endl;
    a1[0] = 1000;
    cout << (a == a1);

    return 0;
}