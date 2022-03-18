//
// Created by Stefan Andonov on 3/18/22.
//

#include<iostream>
#include<cstring>

using namespace std;

enum COLOR {
    RED,
    GREEN,
    BLUE
};


class Shape {
private:
    COLOR color;
    char ID[6];
    double area;

public:
    //2in1
    Shape(char *_id = "11111", COLOR _color = RED, double _area = 0.0) {
        strcpy(ID, _id);
        color = _color;
        area = _area;
    }

    Shape(const Shape &s) {
        strcpy(ID, s.ID);
        color = s.color;
        area = s.area;
    }

    ~Shape() {

    }

    void printColor() {
        switch (color) {
            case RED:
                cout << "RED";
                break;
            case GREEN:
                cout << "GREEN";
                break;
            default :
                cout << "BLUE";
                break;
        }
    };

    void draw() {
        cout << ID << " ";
        printColor();
        cout << " " << area << endl;
    }

    COLOR getColor() {
        return color;
    }

    double getArea() {
        return area;
    }

    void reduceArea() {
        area /= 2;
    }
};

class Canvas {
private:
    Shape shapes[100];
    int n;

public:
    Canvas() {
        n = 0;
    }

    Canvas(const Canvas &other) {
        n = other.n;
        for (int i = 0; i < n; i++) {
            shapes[i] = other.shapes[i];
        }
    }

    ~Canvas() {

    }

    void addShape(Shape s) {
        shapes[n++] = s;
    }

    void drawAll() {
        for (int i = 0; i < n; i++) {
            shapes[i].draw();
        }
    }

    void drawOnly(COLOR color) {
        for (int i = 0; i < n; i++) {
            if (shapes[i].getColor() == color) {
                shapes[i].draw();
            }
        }
    }

    double totalArea() {
        double sum = 0;
        for (int i = 0; i < n; i++) {
            sum += shapes[i].getArea();
        }
        return sum;
    }

    Canvas getHalfCanvas() {
        Canvas copy(*this);
        for (int i = 0; i < copy.n; i++) {
            copy.shapes[i].reduceArea();
        }
        return copy;
    }
};

int main() {

    int n;
    cin >> n;
    cout << "ADITION OF SHAPES IN THE CANVAS" << endl;
    Canvas canvas;

    for (int i = 0; i < n; i++) {
        char id[5];
        int color;
        double area;

        cin >> id >> color >> area;
        Shape s(id, (COLOR) color, area);
        canvas.addShape(s);
    }

    cout << "TESTING DRAW ALL" << endl;

    canvas.drawAll();

    cout << "TESTING DRAW RED SHAPES" << endl;

    canvas.drawOnly(RED);

    cout << "TESTING TOTAL AREA" << endl;

    cout << canvas.totalArea() << endl;

    cout << "TESTING HALF CANVAS" << endl;
    Canvas reducedCanvas = canvas.getHalfCanvas();
    cout << canvas.totalArea() << " " << reducedCanvas.totalArea() << endl;

    if (reducedCanvas.totalArea() == canvas.totalArea()) {
        cout << "DO NOT CHANGE THE AREA OF THE OBJECT IN THE CURRENT CANVAS. JUST IN THE NEW CANVAS" << endl;
    }

    return 0;
}

