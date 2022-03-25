//
// Created by Stefan Andonov on 3/25/22.
//

#include<iostream>

using namespace std;

class Array {
private:
    int size; //initially zero
    int capacity;
    int *content; //initially empty

    void copy(const Array &other) {
        this->size = other.size;
        this->capacity = other.capacity;
        this->content = new int[this->capacity];
        for (int i = 0; i < size; i++) {
            this->content[i] = other.content[i];
        }
    }

public:
    //default constructor and constructor with argument
    Array(int capacity = 10) {
        size = 0;
        this->capacity = capacity;
        content = new int[capacity];
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

    void add(int element) {
        if (size < capacity) {
            content[size++] = element;
        } else {
            int *tmp = new int[2 * capacity];
            for (int i = 0; i < size; i++) {
                tmp[i] = content[i];
            }
            tmp[size++] = element;
            delete[] content;
            content = tmp;
            capacity *= 2;
        }
    }

    void replaceAll(int a, int b) {
        for (int i = 0; i < size; i++) {
            if (content[i] == a) {
                content[i] = b;
            }
        }
    }

    void deleteAll(int number) {
        int j = 0;
        for (int i = 0; i < size; i++) {
            if (content[i] != number) {
                content[j++] = content[i];
            }
        }

        size = j;

        if (size <= capacity/2) {
            int * tmp = new int [capacity/2];
            for (int i=0;i<size;i++){
                tmp[i] = content[i];
            }
            delete [] content;
            content = tmp;
            capacity/=2;
        }
    }

    void print() {
        cout << "Capacity: " << capacity << endl;
        cout << "Size: " << size << endl;
        cout << "Filled capacity %: " << (100.0 * size / capacity) << endl;
        if (size != 0) {
            cout << "Elements: [";
            for (int i = 0; i < size; i++) {
                if (i != size - 1) {
                    cout << content[i] << ", ";
                } else {
                    cout << content[i] << "]" << endl;
                }
            }
        }
    }

};

int main() {
    Array a;
    a.print();
    cout << "-----------" << endl;
    for (int i = 1; i <= 9; i++) {
        a.add(i);
    }
    a.print();
    cout << "-----------" << endl;
    a.add(1);
    a.add(2);
    a.print();
    cout << "-----------" << endl;
    a.replaceAll(2,1);
    a.print();
    cout << "-----------" << endl;
    a.deleteAll(1);
    a.print();
    cout << "-----------" << endl;
    for (int i=1;i<=100;i++) {
        a.add(i%10);
    }
    a.print();
    cout << "-----------" << endl;
    a.deleteAll(1);
    a.deleteAll(2);
    a.deleteAll(3);
    a.print();
    cout << "-----------" << endl;
    return 0;
}