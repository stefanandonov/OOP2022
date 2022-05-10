//
// Created by Stefan Andonov on 5/4/22.
//

#include<iostream>

using namespace std;

class Product {
protected:
    char name[50];
    float price;

public:
    Product(char *name = "", float price = 0.0) {
        strcpy(this->name, name);
        this->price = price;
    }
};

class Discountable {  //interface
public:
    virtual float getPrice() = 0;

    virtual float getPriceWithDiscount() = 0;

    virtual void print() = 0;
};

class FoodProduct : public Product, public Discountable {
private:
    int calories;
public:
    FoodProduct(char *name = "", float price = 0.0, int calories = 0) : Product(name, price) {
        this->calories = calories;
    }

    float getPrice() {
        return price;
    }

    float getPriceWithDiscount() {
        if (calories > 500) {
            return 0.8 * price;
        } else if (calories > 100) {
            return 0.9 * price;
        } else {
            return 0.95 * price;
        }
    }

    void print() {
        cout << "FoodProduct " << name << " with # of calories: " << calories << " Price: " << getPrice()
             << " Price with discount: " << getPriceWithDiscount() << endl;
    }
};

class DigitalProduct : public Product, public Discountable {
    float sizeInMb;

public:
    DigitalProduct(char *name = "", float price = 0.0, float sizeInMb = 1.0) : Product(name, price) {
        this->sizeInMb = sizeInMb;
    }

    float getPrice() {
        return price;
    }

    float getPriceWithDiscount() {
        if (sizeInMb > 1024) {
            return 0.7 * price;
        } else if (sizeInMb > 512) {
            return 0.85 * price;
        } else {
            return 0.925 * price;
        }
    }

    void print() {
        cout << "DigitalProduct " << name << " with size in MBs: " << sizeInMb << " Price: " << getPrice()
             << " Price with discount: " << getPriceWithDiscount() << endl;
    }

};

float totalDiscount(Discountable **discountableProducts, int n) {
    float totalDiscount = 0.0;
    for (int i=0;i<n;i++) {
        totalDiscount+=(discountableProducts[i]->getPrice()-discountableProducts[i]->getPriceWithDiscount());
    }
    return totalDiscount;
}

int countFoodProducts(Discountable **discountableProducts, int n) {
    int counter = 0;
    for (int i=0;i<n;i++) {
        FoodProduct * casted = dynamic_cast<FoodProduct *>(discountableProducts[i]);
        if (casted!=0) {
            ++counter;
        }
    }
    return counter;
}


int main() {
    int n;
    cin >> n;

    Discountable **discountableProducts = new Discountable *[n];

    for (int i = 0; i < n; i++) {
        int type; //1 food 2 = digital
        char name[50];
        float price;
        float sizeInMb;
        int calories;
        cin >> type;
        if (type == 1) { //FoodProduct
            cin >> name >> price >> calories;
            discountableProducts[i] = new FoodProduct(name, price, calories);
        } else { // Digital Product
            cin >> name >> price >> sizeInMb;
            discountableProducts[i] = new DigitalProduct(name, price, sizeInMb);
        }
    }


    for (int i = 0; i < n; i++) {
        discountableProducts[i]->print();
    }

    cout << "Total discount for the products is: " << totalDiscount(discountableProducts, n) << endl;

    cout << "Total number of food products" << countFoodProducts(discountableProducts, n);
    cout << "Total number of digital products" << n - countFoodProducts(discountableProducts, n);

    return 0;

}