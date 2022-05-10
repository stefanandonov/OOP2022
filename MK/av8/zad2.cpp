//
// Created by Stefan Andonov on 4/20/22.
//

#include<iostream>

using namespace std;

class DebitAccount {
protected:
    char owner[50];
    char accountNumber[16];
    double balance;

public:
    DebitAccount(char *owner = "No owner", char *accountNumber = "111111111111111", double balance = 0.0) {
        strcpy(this->owner, owner);
        strcpy(this->accountNumber, accountNumber);
        this->balance = balance;
    }

    DebitAccount(const DebitAccount &da) {
        strcpy(this->owner, da.owner);
        strcpy(this->accountNumber, da.accountNumber);
        this->balance = da.balance;
    }

    void printReport() { //operator<<
        cout << "Owner: " << owner << endl;
        cout << "Account number: " << accountNumber << endl;
        cout << "Balance:" << balance << endl;
    }

    void deposit(double amount) {
        balance+=amount;
    }

    void withdraw(double amount) {
        if (amount<=balance) {
            balance-=amount;
        } else {
            cout << "You don't have sufficient funds. Withdrawing " << balance << endl;
            balance = 0;
        }
    }

};

class CreditAccount : public DebitAccount {
private:
    double limit;
    const double interest = 0.05;
    double debt;
public:
    CreditAccount (char *owner = "No owner",
                   char *accountNumber = "111111111111111",
                   double balance = 0.0,
                   double limit = 10000) : DebitAccount(owner, accountNumber, balance) {
        this->limit = limit;
        this->debt = 0;
    }

    CreditAccount (const DebitAccount & da, double limit = 10000) : DebitAccount(da) {
        this->limit = limit;
        this->debt = 0;
    }


    //overriding of the methods
    void printReport() {
        DebitAccount::printReport();
        cout << "Debt: " << debt << endl;
        cout << "Limit: "<< limit << endl;
    }

    void deposit (double amount) {  //balance:0 debt: 0 amount:1000
        if (amount<=debt) {
            debt-=amount;
        } else {
            balance+=(amount-debt);
            debt = 0;
        }
    }

    void withdraw (double amount) { //balance: 1000 debt:0 amount:2000 limit:2000 -> balance: 0 debt: 1050
        if (balance>=amount) {
            DebitAccount::withdraw(amount);
        } else { //balance<amount 1000, 2000
            double diff = amount-balance;
            if ((diff + debt) < limit) {
                balance = 0;
                debt+=(diff*(1+interest));
            } else {
                cout << "You have exceeded your credit card limit!" << endl;
            }
        }
    }


};

int main() {
    DebitAccount db("Stefan"); //accountNumber = "111111111111111" , balance = 0;
//    db.printReport();
    DebitAccount db1("Stefan", "123451234512345"); //balance = 0;
//    db1.printReport();
    DebitAccount db2("Stefan", "123451234512345", 1005.45);
//    db2.printReport();
//    db2.withdraw(2000);

    CreditAccount ca (db2, 1000);
    ca.printReport();

    ca.withdraw(900);
    ca.printReport();

    ca.withdraw(300);
    ca.printReport();

    ca.withdraw(300);
    ca.printReport();

    ca.withdraw(300);
    ca.printReport();

    ca.withdraw(300);
    ca.printReport(); //debt = 834.277

    ca.deposit(5000);
    ca.printReport();

    return 0;
}