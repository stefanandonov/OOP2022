//
// Created by Stefan Andonov on 3/30/22.
//

#include<iostream>
#include<cstring>
#include<cmath>

using namespace std;

enum type {
    DENARS = 1,
    EUROS,
    DOLLARS
};

class Deposit {
private:
    double amount;
    type type;
    double interest;
    int duration;
public:
    Deposit(double amount = 0.0, enum type type = DENARS, double interest = 0.1, int duration = 1) {
        this->amount = amount;
        this->type = type;
        this->interest = interest;
        this->duration = duration;
    }

    Deposit(const Deposit &d) {
        this->amount = d.amount;
        this->type = d.type;
        this->interest = d.interest;
        this->duration = d.duration;
    }

    double totalValue() {
        return amount * pow(1 + interest, duration);
    }

    double interestAmount() {
        return totalValue() - amount;
    }

    void print() {
        /*
         * [тип на депозит]
            Total Principal:  [почетен влог]
            Total Value: [вкупен износ по истекот на времетраењето]
            Total Interest: [износ на каматата која се заработува]
         * */
        switch (type) {
            case DENARS:
                cout << "Denarski depozit" << endl;
                break;
            case EUROS:
                cout << "Devizen depozit vo EUR" << endl;
                break;
            default:
                cout << "Devizen depozit vo USD" << endl;
                break;
        }
        cout << "Total Principal: " << amount << endl;
        cout << "Total Value: " << totalValue() << endl;
        cout << "Total Interest: " << interestAmount() << endl;
    }

    enum type getType() {
        return type;
    }

};

class Branch {
private:
    char address[100];
    Deposit *deposits;
    int count;

    void copy(const Branch &other) {
        strcpy(this->address, other.address);
        this->count = other.count;
        this->deposits = new Deposit[this->count];
        for (int i = 0; i < this->count; i++) {
            this->deposits[i] = other.deposits[i];
        }
    }

public:
    Branch(char *address = "") {
        strcpy(this->address, address);
        count = 0;
        deposits = new Deposit[count];
    }

    Branch(const Branch &b) {
        copy(b);
    }

    Branch &operator=(const Branch &b) {
        if (this != &b) {
            delete[] deposits;
            copy(b);
        }
        return *this;
    }

    ~Branch() {
        delete[] deposits;
    }

    void newDeposit(const Deposit &newOne) {
        Deposit *tmp = new Deposit[count + 1];
        for (int i = 0; i < count; i++) {
            tmp[i] = deposits[i];
        }
        tmp[count++] = newOne;
        delete[] deposits;
        deposits = tmp;
    }

    int countAllFromType(type type) {
        int counter = 0;
        for (int i = 0; i < count; i++) {
            if (deposits[i].getType() == type) {
                ++counter;
            }
        }
        return counter;
    }

    void removeAllDepositsFromType(type type) {
        Deposit *tmp = new Deposit[count - countAllFromType(type)];
        int j = 0;
        for (int i = 0; i < count; i++) {
            if (deposits[i].getType() != type) {
                tmp[j++] = deposits[i];
            }
        }
        count = j;
        delete[] deposits;
        deposits = tmp;
    }

    void depositAnalysis(int v) {
        if (v < 0 || v > 3) {
            cout << "Error!" << endl;
            return;
        }
        bool found = false;
        Deposit max;
        for (int i = 0; i < count; i++) {
            if (deposits[i].getType() == (type) v) {
                if (!found) {
                    max = deposits[i];
                    found = true;
                } else {
                    if (deposits[i].interestAmount() > max.interestAmount()) {
                        max = deposits[i];
                    }
                }
            }
        }

        if (found) {
            max.print();
        } else {
            cout << "Ne postoi aktiven depozit vo ";
            switch (v) {
                case 1:
                    cout << "MKD!" << endl;
                    break;
                case 2:
                    cout << "EUR!" << endl;
                    break;
                default:
                    cout << "USD!" << endl;
                    break;

            }
        }
    }

    void print() {
        cout << address << endl;
        for (int i = 0; i < count; i++) {
            cout << i + 1 << ". ";
            deposits[i].print();
        }
    }
};

int main() {
    // se testira zadacata modularno
    int testCase;
    cin >> testCase;

    int n, tip, godini;
    double iznos, kamata;
    char adresa[100];

    if (testCase == 1) {
        cout << "===== Testiranje na klasata Deposit ======" << endl;
        cin >> iznos >> kamata >> godini;
        cin >> tip; // 1-MKD, 2-EUR, 3-USD
        Deposit l(iznos, (type) tip, kamata, godini);
        cout << "Deposit constructor OK" << endl;
    } else if (testCase == 2) {
        cout << "===== Testiranje na klasata Deposit so dopolnitelni metodi ======" << endl;
        cin >> iznos >> kamata >> godini;
        cin >> tip; // 1-MKD, 2-EUR, 3-USD
        Deposit l(iznos, (type) tip, kamata, godini);
        l.print();

    } else if (testCase == 3) {
        cout << "===== Testiranje na klasata Branch so metodot print() ======" << endl;
//        Branch b("Strumica");
//        b.print();
    } else if (testCase == 4) {
        cout << "===== Testiranje na klasata Branch so metodot newDeposit() ======" << endl;
        Branch b("Strumica");
        cin >> n;
        for (int i = 0; i < n; i++) {
            //cin.get();
            cin >> iznos >> kamata >> godini;
            cin >> tip; // 1-MKD, 2-EUR, 3-USD
            Deposit l(iznos, (type) tip, kamata, godini);
            b.newDeposit(l);
        }
        b.print();
    } else if (testCase == 5) {
        cout << "===== Testiranje na metodot depositAnalysis() od klasata Branch ======" << endl;
        Branch b("Gevgelija");
        cin >> n;
        for (int i = 0; i < n; i++) {
            //cin.get();
            cin >> iznos >> kamata >> godini;
            cin >> tip; // 1-MKD, 2-EUR, 3-USD
            Deposit l(iznos, (type) tip, kamata, godini);
            b.newDeposit(l);
        }
        b.depositAnalysis(1);
        b.depositAnalysis(2);
        b.removeAllDepositsFromType((type) 2);
        b.depositAnalysis(2);
        b.depositAnalysis(3);
        b.depositAnalysis(4);
    } else if (testCase == 6) {
        cout << "===== Testiranje kompletna funkcionalnost ======" << endl;
        Branch b("Kavadarci");
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin.get();
            cin >> iznos >> kamata >> godini;
            cin >> tip; // 1-MKD, 2-EUR, 3-USD
            Deposit l(iznos, (type) tip, kamata, godini);
            b.newDeposit(l);
        }
        b.depositAnalysis(3);
        Branch b_new = b;
        b.print();
        b_new.print();

        //cin.get();
        cin >> iznos >> kamata >> godini;
        cin >> tip; // 1-MKD, 2-EUR, 3-USD
        Deposit l(iznos, (type) tip, kamata, godini);
        b.newDeposit(l);

        b.depositAnalysis(3);

        b.print();
        b_new.print();
    }
    return 0;
}