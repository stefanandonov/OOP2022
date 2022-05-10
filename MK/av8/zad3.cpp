#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

class Secret {
public:
    virtual double simpleEntropy() = 0;

    virtual int total() = 0;

    friend bool operator==(Secret &s1, Secret &s2);

    friend bool operator!=(Secret &s1, Secret &s2);
};

class DigitSecret : public Secret {
    int numbers[100];
    int num;
public:
    DigitSecret(int *niza, int num) {
        this->num = num;
        for (int i = 0; i < num; i++) {
            numbers[i] = niza[i];
        }
    }

    double simpleEntropy() {
        int h = 0;
        for (int i = 0; i < num; i++) {
            int tmp = 0;
            for (int j = 0; j < num; j++) {
                if (numbers[i] == numbers[j]) {
                    tmp++;
                }
            }
            if (tmp == 1) {
                h++;
            }
        }
        if (h == 0)
            return 0;
        else
            return (double) h / num;

    }

    int total() {
        return num;
    }

    friend ostream &operator<<(ostream &o, DigitSecret &ds) {
        for (int i = 0; i < ds.num; i++) {
            o << ds.numbers[i];
        }
        return o << " Simple entropy: " << ds.simpleEntropy() << " Total: " << ds.total() << endl;
    }

    friend bool operator==(Secret &s1, Secret &s2);

    friend bool operator!=(Secret &s1, Secret &s2);
};

class CharSecret : public Secret {
    char letters[100];
    int num;
public:
    CharSecret(char *letters = "") {
        this->num = strlen(letters);
        strcpy(this->letters, letters);
    }

    double simpleEntropy() {
        int h = 0;
        for (int i = 0; i < num; i++) {
            int tmp = 0;
            for (int j = 0; j < num; j++) {
                if (letters[i] == letters[j]) {
                    tmp++;
                }
            }
            if (tmp == 1) {
                h++;
            }
        }
        return (double) h / (double) num;
    }

    int total() {
        return num;
    }

    friend ostream &operator<<(ostream &o, CharSecret &ds) {
        o << ds.letters;
        return o << " Simple entropy: " << ds.simpleEntropy() << " Total: " << ds.total() << endl;
    }

    friend bool operator==(Secret &s1, Secret &s2);

    friend bool operator!=(Secret &s1, Secret &s2);
};


bool operator==(Secret &s1, Secret &s2) {
    DigitSecret *ds1 = dynamic_cast<DigitSecret *>(&s1);
    if (ds1 != 0) {
        DigitSecret *ds2 = dynamic_cast<DigitSecret *>(&s2);
        if (ds2 != 0) {
            if (ds1->total() == ds2->total()) {
                bool ednakvi = true;
                for (int i = 0; i < ds1->total(); i++) {
                    if (ds1->numbers[i] != ds2->numbers[i]) {
                        return false;
                    }
                }
                return true;
            } else
                return false;
        } else
            return false;
    } else {
        CharSecret *cs1 = dynamic_cast<CharSecret *>(&s1);
        CharSecret *cs2 = dynamic_cast<CharSecret *>(&s2);
        return !strcmp(cs1->letters, cs2->letters);
    }
}

bool operator!=(Secret &s1, Secret &s2) {
    return !(s1==s2);
}

void process(Secret **secrets, int n) {
    Secret *najgolem;
    double max = 0;
    for (int i = 0; i < n; i++) {
        if (secrets[i]->simpleEntropy() > max) {
            najgolem = secrets[i];
            max = secrets[i]->simpleEntropy();
        }
    }
    DigitSecret *ds = dynamic_cast<DigitSecret *>(najgolem);
    if (ds != 0) {
        cout << *ds;
        return;
    }
    CharSecret *cs = dynamic_cast<CharSecret *>(najgolem);
    cout << *cs;
}

void printAll(Secret **secrets, int n) {
    for (int i = 0; i < n; i++) {
        DigitSecret *ds = dynamic_cast<DigitSecret *>(secrets[i]);
        if (ds != 0) {
            cout << *ds;
            continue;
        }
        CharSecret *cs = dynamic_cast<CharSecret *>(secrets[i]);
        cout << *cs;
    }
}


int main() {
    int n;
    cin >> n;
    if (n == 0) {
        cout << "Constructors" << endl;
        int numbers[] = {1, 2, 3, 4, 5};
        DigitSecret ds(numbers, 5);
        CharSecret cs("abcabc");
        cout << "OK" << endl;
    } else if (n == 1) {
        cout << "operator <<" << endl;
        int numbers[] = {1, 2, 3, 4, 5};
        DigitSecret ds(numbers, 5);
        CharSecret cs("abcabc");
        cout << ds;
        cout << cs << endl;
    } else if (n == 2) {
        cout << "== and !=" << endl;
        int numbers[] = {1, 2, 3, 4, 5};
        DigitSecret ds(numbers, 5);
        CharSecret cs("abcabc");
        CharSecret css("abcabc");
        cout << (ds == cs) << endl;
        cout << (cs != ds) << endl;
        cout << (cs == css) << endl;
        cout << (cs != css) << endl;
    } else if (n == 3) {
        cout << "Secret processor" << endl;
        int numbers1[] = {1, 2, 3, 4, 5, 6, 4, 3, 2, 1, 1, 2, 3, 4, 5};
        DigitSecret ds1(numbers1, 15);
        int numbers2[] = {1, 2, 3, 4, 5, 0, 0, 0, 5, 5, 4, 4, 3, 3, 2};
        DigitSecret ds2(numbers2, 15);
        int numbers3[] = {1, 0, 9, 4, 3, 8, 4, 0, 9, 3, 1, 4, 3, 2, 1, 4, 4, 3, 7, 2};
        DigitSecret ds3(numbers3, 20);
        CharSecret cs1("fhdaieowujkfjdsafjdsakjhueiqoyroq");
        CharSecret cs2("nvzcfsadrqipqhfjdfncxoqw");
        CharSecret cs3("uyoihfdsanmqeqrzvdhfeqyrq");
        Secret **s = new Secret *[6];
        s[0] = &ds1;
        s[1] = &ds2;
        s[2] = &ds3;
        s[3] = &cs1;
        s[4] = &cs2;
        s[5] = &cs3;
        process(s, 6);
        delete[] s;
    } else if (n == 4) {
        cout << "Print all secrets" << endl;
        int numbers1[] = {1, 2, 3, 4, 5, 5, 4, 3, 2, 1, 1, 2, 3, 4, 5};
        DigitSecret ds1(numbers1, 15);
        int numbers2[] = {1, 2, 3, 4, 5, 0, 0, 0, 5, 5, 4, 4, 3, 3, 2};
        DigitSecret ds2(numbers2, 15);
        int numbers3[] = {1, 0, 9, 4, 3, 8, 4, 0, 9, 3, 1, 4, 3, 2, 1, 4, 4, 3, 7, 2};
        DigitSecret ds3(numbers3, 20);
        CharSecret cs1("fhdaieowujkfjdsafjdsakjhueiqoyroq");
        CharSecret cs2("nvzcfsadrqipqhfjdfncxoqw");
        CharSecret cs3("uyoihfdsanmqeqrzvdhfeqyrq");
        Secret **s = new Secret *[6];
        s[0] = &ds1;
        s[1] = &ds2;
        s[2] = &ds3;
        s[3] = &cs1;
        s[4] = &cs2;
        s[5] = &cs3;
        printAll(s, 6);
        delete[] s;
    }

    return 0;
}
