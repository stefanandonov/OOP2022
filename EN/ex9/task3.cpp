//
// Created by Stefan Andonov on 4/29/22.
//

#include<iostream>
#include<cstring>

using namespace std;

class HotelReservation {
protected:
    int days;
    int guests;
    char name[50];
public:
    HotelReservation(char *name = "NONAME", int days = 1, int guests = 1) {
        strcpy(this->name, name);
        this->days = days;
        this->guests = guests;
    }

    virtual double price() {
        return days * guests * 25.0;
    }

        double price(double payment) {
            return payment - price();
        }

    virtual void print() {
        cout << "HotelReservation on the name " << name << " for " << days << " days for " << guests
             << "persons. Total Price: " << price() << endl;
    }
};

class BBHotelReservation : public HotelReservation {
public:
    BBHotelReservation(char *name = "NONAME", int days = 1, int guests = 1) : HotelReservation(name, days, guests) {

    }

    double price() {
        return HotelReservation::price() * 1.2;
    }

    void print() {
        cout << "BB";
        HotelReservation::print();
    }


};

class Hotel {
    char name [50];
    double balance;

public:
    Hotel(char * name = "NONAME", double balance = 0) {
        strcpy(this->name, name);
        this->balance = balance;
    }

    int reserve(HotelReservation & hr, int payment) {
        this->balance+=hr.price();
        return hr.price(payment);
    }

    void print () {
        cout <<name << " Balance: " << balance <<endl;
    }
};

int main() {
    int n;
    cin>>n;
    Hotel hotel ("EPINAL");
    HotelReservation ** reservations = new HotelReservation * [n];

    for (int i=0;i<n;i++) {
        int type; //1 - regular 2 - BB
        char name [50];
        int days, guests;
        cin >> type >> name >> days >> guests;
        if (type==1) {
            reservations[i] = new HotelReservation(name, days, guests);
        } else {
            reservations[i] = new BBHotelReservation(name, days, guests);
        }
        int amount;
        cin>>amount;
        cout << "Change: " << hotel.reserve(*reservations[i], amount) << endl;
    }

    for (int i=0;i<n;i++) {
        reservations[i]->print();
    }

    hotel.print();
    return 0;
}