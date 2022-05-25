//
// Created by Stefan Andonov on 5/13/22.
//

#include<iostream>
#include<cstring>
using namespace std;

class InvalidEmailException {
private:
    char email [50];
public:
    InvalidEmailException(char * email) {
        strcpy(this->email, email);
    }
    //MUST HAVE
    void showMessage() {
        cout << "The provided email" << email <<" is not in the expected format!" << endl;
    }
};

class User {
    static int ID_TRACKER;
    char username [50]; //TO BE a valid email address
    int id;

    bool verifyEmailAddress (char * email) {
        bool atSignPresent = false;
        bool dotSignPresent = false;
        for (int i=0;i<strlen(email);i++){
            if (email[i]=='@'){
                atSignPresent=true;
            }
            if (atSignPresent) {
                if (email[i]=='.'){
                    dotSignPresent = true;
                }
            }
        }

        return atSignPresent && dotSignPresent;
    }

public:
    User(char *username = "test") { //this is where we create a user
        if (!verifyEmailAddress(username)){
            throw InvalidEmailException(username);
        }
        strcpy(this->username, username);
        this->id = ID_TRACKER++;
    }

    void print () {
        cout << id << "-->" << username << endl;
    }
};

int User::ID_TRACKER = 1; //initialization of a static variable


int main () {
    try {
        User u1 ("Stefan@finki"); //ID = 1  dangerous
        u1.print();
        User u2 ("Endrit@test.com"); //ID = 2  dangerous
        u2.print();
        User u3 ("Martin"); //ID = 3  dangerous
        u3.print();
    } catch (InvalidEmailException e){
        e.showMessage();
    }



}
