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
        this->content = new int[this->capacity]; //allocate the memoru
        for (int i = 0; i < size; i++) {
            this->content[i] = other.content[i]; //copy each element from other.content to this.content
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

    //void add(int element)
    Array &operator+=(int element) {
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
        return *this;
    }

    void replaceAll(int a, int b) {
        for (int i = 0; i < size; i++) {
            if (content[i] == a) {
                content[i] = b;
            }
        }
    }

//    void deleteAll(int number)
    Array &operator-=(int number) {
        int j = 0;
        for (int i = 0; i < size; i++) {
            if (content[i] != number) {
                content[j++] = content[i];
            }
        }

        size = j;
        //additional request
        if (size <= capacity / 2) {
            int *tmp = new int[capacity / 2];
            for (int i = 0; i < size; i++) {
                tmp[i] = content[i];
            }
            delete[] content;
            content = tmp;
            capacity /= 2;
        }
        return *this;
    }

    friend ostream &operator<<(ostream &out, const Array &a) {
        out << "Capacity: " << a.capacity << endl;
        out << "Size: " << a.size << endl;
        out << "Filled capacity %: " << (100.0 * a.size / a.capacity) << endl;
        if (a.size != 0) {
            out << "Elements: [";
            for (int i = 0; i < a.size; i++) {
                if (i != a.size - 1) {
                    out << a.content[i] << ", ";
                } else {
                    out << a.content[i] << "]" << endl;
                }
            }
        }

        return out;
    }

    friend istream &operator>>(istream &in, Array &a) {
        in >> a.capacity;
        int n;
        in >> n;
        for (int i = 0; i < n; i++) {
            int number;
            in >> number;
            a += number;
        }
        return in;
    }

    int &operator[](int idx) {
        return content[idx];
    }

    bool operator==(const Array & other) {
        if (this->size!=other.size){
            return false;
        }
        for (int i=0;i<this->size;i++){
            if (this->content[i]!=other.content[i]){
                return false;
            }
        }

        return true;
    }


};

int main() {
    Array a;
    cout << a;
    cout << "-----------" << endl;
    for (int i = 1; i <= 9; i++) {
        a += i;
    }
    cout << a;
    cout << "-----------" << endl;
    a += 1;
    a += 2;
    cout << a;
    cout << "-----------" << endl;
    a.replaceAll(2, 1);
    cout << a;
    cout << "-----------" << endl;
    a -= 1; //a.operator-=(1);
    cout << a;
    cout << "-----------" << endl;
    for (int i = 1; i <= 100; i++) {
        a += (i % 10);
    }
    cout << a;
    cout << "-----------" << endl;
    a -= 1;
    a -= 2;
    a -= 3;
    cout << a;
    cout << "-----------" << endl;
    a[0] = 100;
    cout << a;
    cout << "-----------" << endl;
    Array copyA = a; //copy-constructor invocation
    cout << (a==copyA) << endl;
    copyA-=0;
    cout<<copyA;
    cout << (a==copyA) << endl;
    return 0;
}