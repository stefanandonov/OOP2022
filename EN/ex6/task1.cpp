#include<iostream>
#include<cstring>

using namespace std;

class Product {
private:
    char *name;
    int price;
    int discountPercent;
    int quantity;

    void copy(const Product &p) {
        this->name = new char[strlen(p.name) + 1];
        strcpy(this->name, p.name);
        this->price = p.price;
        this->discountPercent = p.discountPercent;
        this->quantity = p.quantity;
    }

public:
    Product(char *name = "", int price = 100, int discountPercent = 0, int quantity = 0) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        this->price = price;
        this->discountPercent = discountPercent;
        this->quantity = quantity;
    }

    Product(const Product &p) {
        copy(p);
    }

    Product &operator=(const Product &p) {
        if (this != &p) {
            delete[] name;
            copy(p);
        }
        return *this;
    }

    void print() {
        //[name] Regular price: [price] Price with discount: [price_with_discount] Quantity: [quantity]
        cout << name << " Regular price: " << price << " Price with discount: "
             << price - int(price * (discountPercent / 100.0));
        cout << " Quantity: " << (int)quantity << endl;
    }

    void increaseDiscount(int p) {
        discountPercent+=p;
        if (discountPercent>=99){
            discountPercent=99;
        }
    }

    Product & increaseQuantity() {
        quantity++;
        return *this;
    }

    int getQuantity () {
        return quantity;
    }
};

class Store {
private:
    char name [50];
    Product * products;
    int count;

    void copy (const Store & store) {
        strcpy(this->name, store.name);
        this->count = store.count;
        products = new Product[this->count];
        for (int i=0;i<this->count;i++) {
            products[i] = store.products[i]; //operator = for Product is called
        }
    }
public:
    Store (char * name = "FINKI") { //2in1 constructor
        strcpy(this->name, name);
        products = new Product[0];
        count = 0;
    }

    Store (const Store & s) {
        copy(s);
    }

    Store & operator = (const Store & s) {
        if (this!=&s){
            delete [] products;
            copy(s);
        }
        return *this;
    }

    ~Store () {
        delete [] products;
    }

    void addProduct(const Product & p) {
        Product * temp = new Product[count+1];
        for (int i=0;i<count;i++) {
            temp[i] = products[i];
        }
        temp[count]=p;
        count++;
        delete [] products;
        products = temp;
    }

    void increaseDiscount(int quantity) {
        for (int i=0;i<count;i++) {
            if (products[i].getQuantity() < quantity) {
                products[i].increaseDiscount(20);
            }
        }
    }

    void print () {
        cout << name << endl;
        for (int i=0;i<count;i++) {
            products[i].print();
        }
    }
};

int main() {
    int testCase;
    cin >> testCase;


    if (testCase == 1) {
        cout << "TESTING CONSTRUCTOR FOR PRODUCT" << endl;
        Product p;
        cout << "TEST FOR DEFAULT CONSTRUCTOR PASSED" << endl;
        Product p1("pizza", 250, 10);
        cout << "TEST FOR CONSTRUCTOR WITH 3 ARGUMENTS PASSED" << endl;
        Product p2("pizza", 250, 10, 100);
        cout << "TEST FOR CONSTRUCTOR WITH 4 ARGUMENTS PASSED" << endl;
    } else if (testCase == 2) {
        cout << "TESTING COPY-CONSTRUCTOR AND OPERATOR = (ASSIGNMENT) FOR PRODUCT" << endl;
        Product p("pizza", 250, 10, 100);
        Product p1(p);
        cout << "TEST FOR COPY CONSTRUCTOR PASSED" << endl;
        Product p2;
        p2 = p;
        cout << "TEST FOR OPERATOR = (ASSIGNMENT) PASSED" << endl;
    } else if (testCase == 3) {
        cout << "TESTING OPERATOR << FOR PRODUCT" << endl;
        Product p("pizza", 250, 10, 100);
        p.print();
    } else if (testCase == 4) {
        cout << "TESTING OPERATORs << FOR PRODUCT" << endl;
        char name[100];
        int price, discount, quantity;
        cin >> name >> price >> discount >> quantity;
        Product p(name, price, discount, quantity);
        p.print();
    } else if (testCase == 5) {
        cout << "TESTING OPERATOR ++ (POSTFIX) FOR PRODUCT" << endl;
        Product p("pizza", 250, 10, 100);
        int quantity = p.getQuantity();
        if ((quantity + 1) == (p.increaseQuantity()).getQuantity()) {
            cout << "CHECK PASSED" << endl;
        } else {
            cout << "CHECK FAILED" << endl;
        }
    } else if (testCase == 6) {
        cout << "TESTING OPERATOR += FOR PRODUCT" << endl;
        Product p("pizza", 250, 10, 100);
        p.increaseDiscount(10);
        p.print();
        p.increaseDiscount(20);
        p.print();
        p.increaseDiscount(59);
        p.print();
        p.increaseDiscount(10);
        p.print();
    } else if (testCase == 7) {
        cout << "TESTING CONSTRUCTOR FOR STORE" << endl;
        Store s("FINKI STORE");
        cout << "TEST PASSED" << endl;
    } else if (testCase == 8) {
        cout << "TESTING OPERATORS += AND << FOR STORE" << endl;
        Store s("FINKI STORE");
        Product p("pizza", 250, 10, 100);
        s.addProduct(p);
        Product p1("shampoo", 289, 15, 150);
        s.addProduct(p1);
        s.print();
    } else if (testCase == 9) {
        cout << "TESTING OPERATORS += AND << FOR STORE" << endl;
        Store s("MYFINKI_STORE");
        int n;
        cin >> n;
        while (n) {
            char name[100];
            int price, discount, quantity;
            cin >> name >> price >> discount >> quantity;
            Product p(name, price, discount, quantity);
            s.addProduct(p);
            --n;
        }
        s.print();
    } else if (testCase == 10) {
        cout << "TESTING OPERATORS +=, << AND -= FOR STORE" << endl;
        Store s("FINKI STORE");
        Product p("pizza", 250, 10, 100);
        s.addProduct(p);
        Product p1("shampoo", 289, 15, 150);
        s.addProduct(p1);
        s.print();
        s.increaseDiscount(110);
        s.print();
    } else if (testCase == 11) {
        cout << "TESTING OPERATORS +=, << AND -= FOR STORE" << endl;
        Store s("MYFINKI_STORE");
        int n;
        cin >> n;
        while (n) {
            char name[100];
            int price, discount, quantity;
            cin >> name >> price >> discount >> quantity;
            Product p(name, price, discount, quantity);
            s.addProduct(p);
            --n;
        }
        s.print();
        int maxDiscount;
        cin >> maxDiscount;
        s.increaseDiscount(maxDiscount);
        s.print();
    } else if (testCase == 12) {
        cout << "TESTING COPY CONSTRUCTOR AND OPERATOR = FOR STORE" << endl;
        Store s("FINKI STORE");
        Product p("pizza", 250, 10, 100);
        s.addProduct(p);
        Product p1("shampoo", 289, 15, 150);
        s.addProduct(p1);

        Store s1 = s; //copy constructor
        Store s2;
        s2 = s1; //operator =
        s1.print();
        s2.print();
        cout << "TEST PASSED" << endl;
    }
    return 0;
}