//
// Created by Stefan Andonov on 5/13/22.
//

#include<iostream>

using namespace std;

class NegativeValueException {
public:
    void showMessage() {
        cout << "Negative values are not allowed as product prices" << endl;
    }
};

class Product {
protected:
    char name[50];
    double price; // are in MKD
public:
    Product(char *name = "test", double price = 0.0) {
        strcpy(this->name, name);
        this->price = price;
    }

    void changePrice(float price) {
        if (price < 0) {
            throw NegativeValueException();
        }
        this->price = price;
    }
};

class Discountable {
public:
    static float EUR_TO_MKD;

    static float USD_TO_MKD;

    virtual float discountPrice() = 0;

    virtual float getPrice() = 0;
};

float Discountable::EUR_TO_MKD = 61.5;
float Discountable::USD_TO_MKD = 58.4;

class FoodProduct : public Product, public Discountable {
public:
    FoodProduct(char *name = "test", double price = 0.0) : Product(name, price) {
        //do nothing
    }

    float discountPrice() {
        return price;
    }

    float getPrice() {
        return price;
    }

};

class Drink : public Product, public Discountable {
    char brand[50];
    bool hasAlcohol;
public:
    Drink(char *name = "test", double price = 0.0, char *brand = "coca-cola", bool hasAlcohol = false) : Product(name,
                                                                                                                 price) {
        this->hasAlcohol = hasAlcohol;
        strcpy(this->brand, brand);
    }

    float discountPrice() {
        if (hasAlcohol && price / Discountable::EUR_TO_MKD >= 20.0) {
            return price * 0.95;
        }
        if (!hasAlcohol && strcmp(brand, "coca-cola") == 0) {
            return price * 0.9;
        }
        return price;
    }

    float getPrice() {
        return price;
    }
};

class Cosmetic : public Product, public Discountable {
public:
    Cosmetic(char *name = "test", double price = 0.0) : Product(name, price) {
        //do nothing
    }

    float discountPrice() {
        if (price / Discountable::USD_TO_MKD >= 20.0) {
            return price * 0.86;
        }
        if (price / Discountable::EUR_TO_MKD >= 5.0) {
            return price * 0.88;
        }
        return price;
    }

    float getPrice() {
        return price; //The getPrice method has the same definition ALL THE TIME.
    }


};

int main() {
    int n = 0;
    float newPrice;
    Discountable **d = new Discountable *[10];
    d[n++] = new FoodProduct("leb", 30);
    d[n++] = new Drink("viski", 1350, "Jack Daniel's", true);
    d[n++] = new FoodProduct("sirenje", 390);
    d[n++] = new Drink("votka", 850, "Finlandia", true);
    d[n++] = new Cosmetic("krema", 720);
    d[n++] = new Drink("sok", 50, "coca-cola", false);
    d[n++] = new Cosmetic("parfem", 3500);


    double sum = 0;
    for (int i = 0; i < n; i++) {
        cout << d[i]->getPrice() << " " << d[i]->discountPrice() << endl;
        sum += d[i]->discountPrice();
    }
    cout << sum;

    for (int i = 0; i < n; i++) {
        Cosmetic *casted = dynamic_cast<Cosmetic *>(d[i]);
        if (casted != 0) {
            cout << "Old price is "<<casted->getPrice() << endl;
            double newPrice;
            cin >> newPrice;
            try {
                casted->changePrice(newPrice);
            }
            catch (NegativeValueException e) {
                e.showMessage();
            }

        }

    }

    sum = 0;
    for (int i = 0; i < n; i++) {
        cout << d[i]->getPrice() << " " << d[i]->discountPrice() << endl;
        sum += d[i]->discountPrice();
    }
    cout << sum;


    return 0;
}