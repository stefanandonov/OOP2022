//
// Created by Stefan Andonov on 4/27/22.
//

#include<iostream>

using namespace std;

class HotelReservation {
protected:
    int days;
    int guests;
    char contact[50];

public:
    HotelReservation(char *contact, int days, int guests) {
        strcpy(this->contact, contact);
        this->guests = guests;
        this->days = days;
    }

    virtual double price() {
        return guests * days * 25;
    }

    double price(double deposit) {
        return deposit - price();
    }

};

class HalfBoardHotelReservation : public HotelReservation {
public:
    HalfBoardHotelReservation(char *contact, int days, int guests) : HotelReservation(contact, days, guests) {

    }

    double price() {
        return HotelReservation::price() * 1.2;
    }
};


class Hotel {
    char name[20];
    double balance;

public:
    Hotel(char *name = "balkan", double balance = 0) {
        strcpy(this->name, name);
        this->balance = balance;
    }

    double depositReservation(HotelReservation * hr, double deposit) {
        double totalPrice = hr->price();
        balance += totalPrice;
        return hr->price(deposit);
    }

    friend ostream &operator<<(ostream &out, const Hotel &h) {
        return out << h.name << " " << h.balance;
    }
};

int main() {
    Hotel hotel("FINKI hotel", 0);

    int n; //broj na rezervacii
    cin >> n;

    HotelReservation **reservations = new HotelReservation *[n];

    for (int i = 0; i < n; i++) {
        int type; //1 = obicna, 2 = polupansion
        char name[30];
        int days, guests;
        double deposit;
        cin >> type >> name >> days >> guests >> deposit;
        if (type == 1) {
            reservations[i] = new HotelReservation(name, days, guests);
        } else {
            reservations[i] = new HalfBoardHotelReservation(name, days, guests);
        }
        cout << name << " Days: " << days << " Guests: " << guests << " Price: " << reservations[i]->price();
        cout << "Change from payment: " << hotel.depositReservation(reservations[i], deposit);
    }

    cout << "Hotel state after all the reservations were payed" << endl;
    cout << hotel;

    return 0;

}

