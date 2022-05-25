//
// Created by Stefan Andonov on 5/11/22.
//

#include<iostream>
#include<cstring>

using namespace std;

class NegativeValueException {
private:
    char productName[50];
public:
    NegativeValueException(char *name) {
        strcpy(this->productName, name);
    }

    void showMessage() {
        cout << "The product" << productName << " cannot have a negative value for the getPrice" << endl;
    }
};

class Discount { //abstract class
public:
    virtual float discount_price() = 0;

    virtual float getPrice() = 0;

    virtual void print_rule() = 0;

    static float EUR_TO_MKD;
    static float USD_TO_MKD;
};

float Discount::EUR_TO_MKD = 61.5;
float Discount::USD_TO_MKD = 58.4;

class Product {
protected:
    char name[50];
    float price; //getPrice is in EUR

public:
    Product(char *name = "", float price = 0.0) {
        strcpy(this->name, name);
        this->price = price;
    }

    void changePrice(float newPrice) {
//        if (newPrice < 0) {
//            throw NegativeValueException(this->name);
//        }
        this->price = newPrice;
    }
};

class FoodProduct : public Product, public Discount {
public:
    FoodProduct(char *name = "", float price = 0.0) : Product(name, price) {

    }

    float discountPrice() {
        return getPrice();
    }

    float getPrice() {
        return price * Discount::EUR_TO_MKD;
    }

    void print_rule() {
        cout << "No discount for food products" << endl;
    }
};

class Drinks : public Product, public Discount {
    bool isAlcohol;
public:
    Drinks(char *name = "", float price = 0.0, bool isAlcohol = false) : Product(name, price) {
        this->isAlcohol = isAlcohol;
    }

    float discount_price() {
        if (isAlcohol && price > 20.0) {
            return getPrice() * 0.95;
        }
        if (!isAlcohol && strcmp(name, "coca-cola") == 0) {
            return getPrice() * 0.9;
        }
        return getPrice();
    }

    float getPrice() {
        return price * Discount::EUR_TO_MKD;
    }

    void print_rule() {
        cout << "Alcohol product with getPrice larger than 20EUR -> 5%; Coca-cola 10%;" << endl;
    }
};

class Cosmetics : public Product, public Discount {
public:
    Cosmetics(char *name = "", float price = 0.0) : Product(name, price) {

    }

    float discount_price() {
        float priceInUSD = price * Discount::EUR_TO_MKD / Discount::USD_TO_MKD;
        if (priceInUSD > 20.0) {
            return getPrice() * 0.86;
        }
        if (price > 5.0) {
            return getPrice() * 0.88;
        }
        return getPrice();
    }

    float getPrice() {
        return price * Discount::EUR_TO_MKD;
    }

    void print_rule() {
        cout << "price is USD > 20$ -> 14%; getPrice in EUR > 5EUR -> 12%" << endl;
    }
};

int main() {
//    Product * p = new FoodProduct("leb", 0.5);
//    try {
//        p->changePrice(10);
//    } catch (NegativeValueException e) {
//        e.showMessage();
//    }
    int n = 0;
    Discount **d = new Discount *[10];
    d[n++] = new FoodProduct("leb", 0.5);
    d[n++] = new Drinks("viski", 22, true);
    d[n++] = new FoodProduct("sirenje", 6.2);
    d[n++] = new Drinks("votka", 10, true);
    d[n++] = new Cosmetics("krema", 12);
    d[n++] = new Drinks("coca-cola", 1.2, false);
    d[n++] = new Cosmetics("parfem", 60);

    for (int i = 0; i < n; i++) {
        cout << i + 1 << endl;
        cout << d[i]->getPrice() << endl;
        cout << d[i]->discount_price() << endl;
        d[i]->print_rule();
    }

    //Cosmetic products set getPrice to negative value
    for (int i = 0; i < n; i++) {
        Cosmetics *cosmeticsTrial = dynamic_cast<Cosmetics *>(d[i]);
        if (cosmeticsTrial != 0) {
            int newPrice;
            cin >> newPrice;
            try {
                cosmeticsTrial->changePrice(newPrice);
            }
            catch (NegativeValueException e) {
                e.showMessage();
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << i + 1 << endl;
        cout << d[i]->getPrice() << endl;
        cout << d[i]->discount_price() << endl;
        d[i]->print_rule();
    }


    return 0;
}