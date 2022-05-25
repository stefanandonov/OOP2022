//
// Created by Stefan Andonov on 5/13/22.
//

#include<iostream>
using namespace std;

class InsufficientAmountException {
public:
    void showMessage() {
        cout << "You don't have sufficient assets to make that withdraw" << endl;
    }
};

class Card {
protected:
    char ID [16];
    double balance;
    double limit;
public:
    Card (char * ID = "111111111111111", double limit = 1000, double balance = 0) {
        strcpy(this->ID, ID);
        this->limit = limit;
        this->balance = balance;
    }

    virtual void withdraw (double amount) { //virtual - because it varies depending on the credit card type
        //balance = 0 limit = 20000 amount = 18000 --OK--> balance = -18000 limit = 20000
        //balance = -18000 limit = 20000 amount = 4000
        if (balance+limit >= amount) {
            balance-=amount;
        } else {
            throw InsufficientAmountException();
        }
    }

    void deposit (double amount) { //not virtual - because deposition is same for all kinds of credit cards
        balance+=amount;
    }

    void print () {
        cout << ID <<" Balance: " << balance << " Limit: " << limit << endl;
    }


};


class MasterCard : public Card {
    static float PREMIUM_DISCOUNT; //changeable --> we need a set method for this variable
    const static float STANDARD_DISCOUNT;
public:
    MasterCard (char * ID = "111111111111111", double limit = 1000, double balance = 0) : Card(ID, limit, balance) {

    }

    void withdraw(double amount) {
        if (limit>6000) {
            amount*=(1-PREMIUM_DISCOUNT); //*0.9
        } else {
            amount*=(1-STANDARD_DISCOUNT); //0.97
        }
        return Card::withdraw(amount);
    }

    static void setPremiumDiscount (double newDiscount) { //MasterCard::setPremiumDiscount(..)
        PREMIUM_DISCOUNT = newDiscount;
    }

};

class MaestroCard : public Card {
    const static float DISCOUNT;
public:
    MaestroCard (char * ID = "111111111111111", double limit = 1000, double balance = 0) : Card(ID, limit, balance) {

    }

    void withdraw(double amount) {
        amount*=(1-DISCOUNT);
        return Card::withdraw(amount);
    }
};

const float MaestroCard::DISCOUNT = 0.05; //5%
float MasterCard::PREMIUM_DISCOUNT = 0.1; //10%
const float MasterCard::STANDARD_DISCOUNT = 0.03; //3%

int main () {
    int n=4;
    Card ** cards = new Card * [n];

    cards[0] = new MasterCard("111111111111112", 8000, 1000);
    cards[1] = new MasterCard("111111111111113", 4000, 1000);
    cards[2] = new MaestroCard("111111111111114", 2000, 2000);
    cards[3] = new MaestroCard("111111111111114", 0, 4000);

    for (int i=0;i<n;i++){
        cards[i]->print();
    }

    double amount = 4500;
    for (int i=0;i<n;i++) {
        try {
            cards[i]->withdraw(amount); //1 0
            cards[i]->print();
        }
        catch (InsufficientAmountException e) {
            e.showMessage();
        }

    }
}