//
// Created by Stefan Andonov on 3/23/22.
//

#include<iostream>
#include<cstring>

using namespace std;

class WebPage {
    char url[100];
    char *content;

    void copy(const WebPage &wp) {
        strcpy(this->url, wp.url);
        this->content = new char[strlen(wp.content) + 1];
        strcpy(this->content, wp.content);
    }

public:
    WebPage(char *url = "https://finki.ukim.mk", char *content = "Web sajt na FINKI") {
        strcpy(this->url, url);
        this->content = new char[strlen(content) + 1];
        strcpy(this->content, content);
    }

    WebPage(const WebPage &wp) {
        copy(wp);
    }

    WebPage &operator=(const WebPage &wp) {
        if (this != &wp) {
            delete[] content;
            copy(wp);
        }
        return *this;
    }

    ~WebPage() {
        delete[] content;
    }

    void print() {
        cout << url << endl << content << endl;
    }

    bool equal(const WebPage &wp) {
        return strcmp(this->url, wp.url) == 0;
    }
};

class WebServer {
private:
    char name[30];
    WebPage *webPages;
    int size;

    void copy(const WebServer &ws) {
        strcpy(this->name, ws.name);
        this->size = ws.size;
        this->webPages = new WebPage[this->size];
        for (int i = 0; i < this->size; i++) {
            this->webPages[i] = ws.webPages[i]; //tuka ke padne bez operator = vo WebPage
        }
    }

public:
    WebServer(char *name = "FINKI server") {
        this->size = 0;
        strcpy(this->name, name);
        this->webPages = new WebPage[size];
    }

    WebServer(const WebServer &ws) {
        copy(ws);
    }

    WebServer &operator=(const WebServer &ws) {
        if (this != &ws) {
            delete[] webPages;
            copy(ws);
        }
        return *this;
    }

    ~WebServer() {
        delete[] webPages;
    }

    void addPage(const WebPage &wp) {
        if (hasPage(wp))
            return;

        WebPage *tmp = new WebPage[size + 1];
        for (int i = 0; i < size; i++) {
            tmp[i] = webPages[i]; //tuka ke padne ako nemate operator = vo WebPage
        }
        tmp[size++] = wp;
        delete [] webPages;
        webPages = tmp;
    }

    void print () {
        cout << name << endl;
        for (int i=0;i<size;i++) {
            webPages[i].print();
        }
    }

    bool hasPage (const WebPage & wp) {
        bool found = false;
        for (int i=0;i<size;i++) {
            if (webPages[i].equal(wp)) {
                found = true;
                break;
            }
        }
        return found;
    }

    void deletePage (const WebPage & wp) {
        if (hasPage(wp)) {
            WebPage * tmp = new WebPage[size-1];
            int j=0;
            for (int i=0;i<size;i++) {
                if (!webPages[i].equal(wp)) {
                    tmp[j++]=webPages[i];
                }
            }
            size--;
            delete [] webPages;
            webPages = tmp;
        }
    }

};

int main() {
    WebPage wp;

    WebPage copy(wp);
    WebPage testAssignment;
    testAssignment = wp;

//    wp.print(); //default constructor
//    copy.print(); //copy constructor
//    testAssignment.print(); //operator =

//    cout << wp.equal(copy);

    WebServer ws ("FINKI");
    ws.addPage(wp);

    WebPage courses ("courses.finki.ukim.mk", "Moodle za potrebite na FINKI");
    ws.addPage(copy);
    ws.addPage(testAssignment);
    ws.addPage(courses);
    ws.print();
    cout << "------";
    ws.deletePage(copy);
    ws.print();

}