//
// Created by Stefan Andonov on 4/29/22.
//

#include<iostream>

using namespace std;

class Shape {
protected:
    double height;
    double base;
public:
    Shape(double height = 1.0, double base = 1.0) {
        this->height = height;
        this->base = base;
    }

    virtual void print() = 0;

    virtual double volume() = 0;

    double getHeight() {
        return height;
    }
};

class Cylinder : public Shape {
public:
    Cylinder(double height = 1.0, double base = 1.0) : Shape(height, base) {

    }

    double volume() {
        return base * base * height * 3.14;
    }

    void print() {
        cout << "Cylinder with base " << base << ", height " << height << " and volume of " << volume() << endl;
    }
};

class Cone : public Shape {
public:
    Cone(double height = 1.0, double base = 1.0) : Shape(height, base) {

    }

    double volume() {
        return base * base * height * 3.14 / 3;
    }

    void print() {
        cout << "Cone with base " << base << ", height " << height << " and volume of " << volume() << endl;

    }
};

class Cuboid : public Shape {
private:
    double secondBase;
public:
    Cuboid(double height = 1.0, double base = 1.0, double secondBase = 1.0) : Shape(height, base) {
        this->secondBase = secondBase;
    }

    double volume() {
        return base * secondBase * height;
    }

    void print() {
        cout << "Cuboid with bases " << base << " and " << secondBase << ", height " << height << " and volume of "
             << volume() << endl;

    }

};

void maxVolume(Shape **shapes, int n) {
    Shape *max = shapes[0];
    for (int i = 1; i < n; i++) {
        if (shapes[i]->volume() > max->volume()) {
            max = shapes[i];
        }
    }

    max->print();
}

int countShapesWithoutCircleBasis(Shape **shapes, int n) {
    int counter = 0;
    for (int i = 0; i < n; i++) {
        Cuboid *casted = dynamic_cast<Cuboid *>(shapes[i]);
        if (casted != nullptr) { //the casting was successful
            counter++;
        }
    }
    return counter;
}

int main() {
    int n;
    cin >> n;

    Shape **shapes = new Shape *[n];

    for (int i = 0; i < n; i++) {
        int type; //1=cylinder, 2=cone, 3=cuboid
        double height, base, secondBase;
        cin >> type >> height >> base;
        if (type == 1) { //cylinder
            shapes[i] = new Cylinder(height, base);
        } else if (type == 2) { // cone
            shapes[i] = new Cone(height, base);
        } else { //cuboid
            cin >> secondBase;
            shapes[i] = new Cuboid(height, base, secondBase);
        }
    }

    for (int i = 0; i < n; i++) {
        shapes[i]->print();
    }

    cout << "MAX SHAPE INFORMATION" << endl;
    maxVolume(shapes, n);

    cout <<"SHAPES WITHOUT A CIRCLE BASIS: " <<countShapesWithoutCircleBasis(shapes, n) << endl;

    return 0;
}