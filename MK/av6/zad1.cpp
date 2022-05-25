#include<iostream>
#include<cstring>

using namespace std;

class Word {
private:
    char *content;
    int frequency;

    void copy(const Word &other) {
        this->content = new char[strlen(other.content) + 1];
        strcpy(this->content, other.content);
        this->frequency = other.frequency;
    }

public:
    Word(char *content = "", int frequency = 1) {
        this->content = new char[strlen(content) + 1];
        strcpy(this->content, content);
        this->frequency = frequency;
    }

    Word(const Word &w) {
        copy(w);
    }

    Word &operator=(const Word &w) {
        if (this != &w) {
            delete[] content;
            copy(w);
        }
        return *this;
    }

    ~Word() {
        delete[] content;
    }

    void print() {
        cout << content << " " << frequency << endl;
    }

    Word & increaseFrequency() {
        ++frequency;
        return *this;
    }

    int getFrequency() {
        return this->frequency;
    }

    bool equal(const Word &w) {
        if (strlen(content) != strlen(w.content))
            return false;

        for (int i = 0; i < strlen(content); i++) {
            if (tolower(content[i]) != tolower(w.content[i]))
                return false;
        }

        return true;
    }
};

class Text {
private:
    Word *words;
    int n;

    void copy(const Text &other) {
        this->n = other.n;
        words = new Word[this->n];
        //strcpy (this->words,words); //NIKAKO
        for (int i = 0; i < n; i++) {
            words[i] = other.words[i]; //tuka se povikuva operator = od class Word
        }
    }

public:
    Text() {
        this->n = 0;
        words = new Word[0]; //initially empty
    }

    Text(const Text &t) {
        copy(t);
    }

    Text & operator = (const Text &t) {
        if (this!=&t) {
            delete [] words;
            copy(t);
        }
        return *this;
    }

    ~Text() {
        delete [] words;
    }

    void addWord (const Word & newWord) {
        for (int i=0;i<n;i++) {
            if (words[i].equal(newWord)) {
                words[i].increaseFrequency();
                return ;
            }
        }

        //dokolku dojdeme do tuka --> zborot ne e pronajden
        Word * tmp = new Word [n+1];
        for (int i=0;i<n;i++) {
            tmp[i] = words[i]; //tuka se povikuva operator = od Word
        }
        tmp[n++]=newWord;
        delete [] words;
        words = tmp;
    }

    void print () {
        for (int i=0;i<n;i++) {
            words[i].print();
        }
    }

    int getFrequencyFor(char * word) {
        Word wordObj (word);
        for (int i=0;i<n;i++) {
            if (words[i].equal(wordObj)) { //Word.equal(char *)
                return words[i].getFrequency();
            }
        }
        return -1;
    }
};

int main() {

    int testCase;
    cin >> testCase;

    if (testCase == 1) {
        cout << "TESTING WORD CONSTRUCTORS" << endl;
        Word w("OOP");
        cout << "check 1 passed" << endl;
        Word w1("OOP", 2);
        cout << "check 2 passed" << endl;
    } else if (testCase == 2) {
        cout << "TESTING WORD METHOD PRINT" << endl;
        Word w("OOP");
        w.print();
    } else if (testCase == 3) {
        cout << "TESTING WORD METHOD PRINT" << endl;
        char word[100];
        cin >> word;
        Word w(word);
        w.print();
    } else if (testCase == 4) {
        cout << "TESTING WORD COPY CONSTRUCTOR AND OPERATOR = (FOR ASSIGNMENT)" << endl;
        Word w("FINKI");
        Word w1;
        w1 = w;
        Word w2 = w1;
        w1.print();
        w2.print();
    } else if (testCase == 5) {
        cout << "TESTING WORD METHOD increaseFrequency" << endl;
        Word w("FINKI");
        int freq = w.getFrequency();
        if (freq + 1 == (w.increaseFrequency().increaseFrequency().increaseFrequency().increaseFrequency()).getFrequency()) {
            cout << "increaseFrequency is implemented correctly" << endl;
        } else {
            cout << "increaseFrequency is not implemented correctly" << endl;
        }
    } else if (testCase == 6) {
        cout << "TESTING WORD METHOD equal" << endl;
        Word w("FINKI");
        Word w1("FiNkI");
        Word w2("OOP");
        cout << "FINKI" << (w.equal(w1) ? "==" : "=/=") << "FiNkI" << endl;
        cout << "FINKI" << (w.equal(w2) ? "==" : "=/=") << "OOP" << endl;
        cout << "FiNkI" << (w1.equal(w2) ? "==" : "=/=") << "OOP" << endl;
        cout << "FINKI" << (w.equal(w) ? "==" : "=/=") << "FINKI" << endl;
        cout << "FiNkI" << (w1.equal(w1) ? "==" : "=/=") << "FiNkI" << endl;
    } else if (testCase == 7) {
        cout << "TESTING TEXT, method addWord" << endl;
        Text t;
        int n;
        cin >> n;
        while (n) {
            char word[100];
            cin >> word;
            Word w(word);
            t.addWord(w);
            --n;
        }
        t.print();
    } else if (testCase == 8) {
        cout << "TESTING TEXT METHOD getFrequencyFor" << endl;
        Text t;
        t.addWord("OOP");
        t.addWord("FINKI");
        t.addWord("oop");
        t.addWord("prv");
        t.addWord("Kolokvium");
        cout << t.getFrequencyFor("OOP") << endl;
        cout << t.getFrequencyFor("prv") << endl;
        cout << t.getFrequencyFor("vtor") << endl;
    } else if (testCase == 9) {
        cout << "TESTING COPY CONSTRUCTOR AND OPERATOR = FOR CLASS TEXT" << endl;
        Text t;
        t.addWord("OOP");
        t.addWord("FINKI");
        t.addWord("prv");
        t.addWord("Kolokvium");
        Text t1 = t;
        Text t2;
        t2 = t1;
        t1.print();
        t2.print();
        cout << "TEST PASSED" << endl;

    }

    return 0;
}