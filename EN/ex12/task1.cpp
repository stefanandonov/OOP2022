#include<string.h>
#include<iostream>

using namespace std;

class User {
    char *username;
    char *companyName;
    int position;

    void copy(const User &u) {
        this->username = new char[strlen(u.username) + 1];
        strcpy(this->username, u.username);
        this->companyName = new char[strlen(u.companyName) + 1];
        strcpy(this->companyName, u.companyName);
        this->position = u.position;
    }

public:
    User(char *username = "", char *companyName = "", int position = 0) {
        this->username = new char[strlen(username) + 1];
        strcpy(this->username, username);
        this->companyName = new char[strlen(companyName) + 1];
        strcpy(this->companyName, companyName);
        this->position = position;
    }

    User(const User &u) {
        copy(u);
    }

    User &operator=(const User &u) {
        if (this != &u) {
            delete[] username;
            delete[] companyName;
            copy(u);
        }
        return *this;
    }

    ~User() {
        delete[] username;
        delete[] companyName;
    }

    char *getUsername() const {
        return username;
    }

    void setUsername(char *username) {
        this->username = new char[strlen(username) + 1];
        strcpy(this->username, username);
    }

    char *getCompanyName() const {
        return companyName;
    }

    void setCompanyName(char *companyName) {
        this->companyName = new char[strlen(companyName) + 1];
        strcpy(this->companyName, companyName);
    }

    int getPosition() const {
        return position;
    }

    void setPosition(int position) {
        this->position = position;
    }


    friend ostream &operator<<(ostream &os, const User &user) {
        return os << "Username: " << user.username
                  << " Company name: " << user.companyName
                  << " Position: " << user.position;
    }

    friend istream &operator>>(istream &in, User &user) {
        return in >> user.username >> user.companyName >> user.position;
    }

    bool operator==(User &u) {
        return strcmp(this->username, u.username) == 0;
    }
};

class OperationNotSupported {
private:
    char message [50];
public:
    OperationNotSupported(char * message = "Username already exists") {
        strcpy(this->message, message);
    }
    void showMessage() {
        cout << message << endl;
    }
};

class Group {
protected:
    User * users;
    int size;
    char name [50];

    void copy (const Group & g) {
        strcpy(this->name, g.name);
        this->size = g.size;
        users = new User [this->size];
        for (int i=0;i<size;i++){
            this->users[i]=g.users[i];
        }
    }

public:
    Group (char * name = "test") {
        strcpy(this->name, name);
        size = 0;
        users = new User [size];
    }

    Group (const Group & g) {
        copy(g);
    }

    Group & operator = (const Group & g) {
        if (this!=&g){
            delete [] users;
            copy(g);
        }
        return *this;
    }

    ~Group() {
        delete [] users;
    }

    virtual void addMember (User & u) { //dangerous code, make sure to add try catch block where addMember is called
        for (int i=0;i<size;i++){
            if (users[i]==u){
                throw OperationNotSupported();
            }
        }

        User * tmp = new User [size+1];
        for (int i=0;i<size;i++){
            tmp[i] = users[i];
        }
        tmp[size++]=u;
        delete [] users;
        users = tmp;
    }

    double averagePosition() const {
        double sum = 0;
        for (int i=0;i<size;i++){
            sum+=users[i].getPosition();
        }
        if (size==0)
            return 0;
        return sum/size;
    }

    virtual double rating() const {
        //(10 - average_level_of_positions_of_the_members) * number_of_members / 100
        return (10 - averagePosition()) * size / 100.0;
    }

    friend ostream & operator << (ostream & out, const Group & g){
        out << "Group: " << g.name << endl;
        out << "Members: " << g.size << endl;
        out << "Rating: " << g.rating() << endl;
        out << "Members list:" << endl;
        if (g.size==0) {
            return out << "EMPTY";
        } else {
            for (int i=0;i<g.size;i++){
                out << i+1 << ". " << g.users[i] << endl;
            }
            return out;
        }
    }
};

class PrivateGroup : public Group {
    static int CAPACITY;
    const static double COEFFICIENT;
public:
    PrivateGroup(char * name = "test") : Group(name) {

    }

    void addMember(User &u) override {
        if (size == CAPACITY){
            throw OperationNotSupported("The group’s capacity has been exceeded.");
        }
        Group::addMember(u);
    }

    double rating() const override {
        //(10 - average_level_of_positions_of_the_members) * (number_of_members / capacity) * coefficient_for_private_group
        return (10-averagePosition()) * ((float)size/CAPACITY) * COEFFICIENT;
    }

    static void setCapacity (int capacity) {
        CAPACITY = capacity;
    }

    static int getCapacity() {
        return CAPACITY;
    }

    friend ostream & operator << (ostream & out, const PrivateGroup & pg) {
        out << "Private ";
        Group g (pg);
        return out << g;
    }

};

int PrivateGroup::CAPACITY = 10;
const double PrivateGroup::COEFFICIENT = 0.8;


int main() {
    int testCase;
    cin >> testCase;
    if (testCase == 1) {
        cout << "TESTING CLASS GROUP: CONSTRUCTOR AND OPERATOR <<" << endl;
        Group g("test");
        cout << g;
    } else if (testCase == 2) {
        cout << "TESTING CLASS PRIVATE GROUP: CONSTRUCTOR AND OPERATOR <<" << endl;
        PrivateGroup pg("private test");
        cout << pg;
    } else if (testCase == 3) {
        cout << "TESTING CLASS GROUP: CONSTRUCTOR, METHOD ADD_MEMBER AND OPERATOR <<" << endl;
        Group *g = new Group("FINKI students");
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            User u;
            cin >> u;
            g->addMember(u);
        }
        cout << *g;
        delete g;
    } else if (testCase == 4) {
        cout << "TESTING CLASS PRIVATE_GROUP: CONSTRUCTOR, METHOD ADD_MEMBER AND OPERATOR <<" << endl;
        Group *g = new PrivateGroup("FINKI students");
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            User u;
            cin >> u;
            g->addMember(u);
        }
        cout << *g;
        delete g;
    } else if (testCase == 5) {
        cout << "TESTING CLASS GROUP: CONSTRUCTOR, METHOD ADD_MEMBER, EXCEPTION AND OPERATOR <<" << endl;
        Group *g = new Group("FINKI students");
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            User u;
            cin >> u;
            try {
                g->addMember(u);
            } catch (OperationNotSupported e) {
                e.showMessage();
            }

        }
        cout << *g;
        delete g;
    } else if (testCase == 6) {
        cout << "TESTING CLASS PRIVATE GROUP: CONSTRUCTOR, METHOD ADD_MEMBER, EXCEPTION AND OPERATOR <<" << endl;
        Group *g = new PrivateGroup("FINKI");
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            User u;
            cin >> u;
            try {
                g->addMember(u);
            } catch (OperationNotSupported e) {
                e.showMessage();
            }

        }
        cout << *g;
        delete g;
    } else if (testCase == 7) {
        cout << "TESTING CLASS PRIVATE GROUP: CONSTRUCTOR, METHOD ADD_MEMBER AND CHANGE OF STATIC MEMBER"
             << endl;
        Group *g = new PrivateGroup("DevOps");
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            User u;
            cin >> u;
            g->addMember(u);
        }
        cout << "RATING BEFORE CHANGE" << endl;
        cout << g->rating();
        PrivateGroup::setCapacity(20);
        cout << "RATING AFTER CHANGE" << endl;
        cout << g->rating();
        delete g;
    } else if (testCase == 8) {
        cout << "TESTING CLASS PRIVATE GROUP: CONSTRUCTOR, METHOD ADD_MEMBER, EXCEPTION AND CHANGE OF STATIC MEMBER"
             << endl;

        Group *g = new PrivateGroup("FINKI");
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            User u;
            cin >> u;

            try {
                g->addMember(u);
            } catch (OperationNotSupported e) {
                e.showMessage();
            }

            int capacity = PrivateGroup::getCapacity();
            cout << "Increasing capacity from " << capacity << " to " << capacity + 1 << endl;
            PrivateGroup::setCapacity(capacity + 1);

            g->addMember(u);

            cout << g->rating() << endl;

        }

    } else {
        cout << "INTEGRATION TEST" << endl;
        char name[50];
        int nGroups;
        cin >> nGroups;
        Group **groups = new Group *[nGroups];
        for (int i = 0; i < nGroups; i++) {
            int type;
            cin >> type;
            cin >> name;
            if (type == 1) { //normal group
                groups[i] = new Group(name);
            } else { //private group
                groups[i] = new PrivateGroup(name);
            }
            int nUsers;
            cin >> nUsers;
            for (int j = 0; j < nUsers; j++) {
                User u;
                cin >> u;

                try {
                    groups[i]->addMember(u);
                } catch (OperationNotSupported e) {
                    e.showMessage();
                }

            }
        }

        cout << "BEFORE CHANGE OF PRIVATE GROUP COEFFICIENT" << endl;
        for (int i = 0; i < nGroups; ++i) {
            cout << *groups[i];
        }
        PrivateGroup::setCapacity(15);
        cout << "AFTER CHANGE OF PRIVATE GROUP COEFFICIENT" << endl;
        for (int i = 0; i < nGroups; ++i) {
            cout << *groups[i];
        }
    }
}