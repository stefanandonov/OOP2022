//
// Created by Stefan Andonov on 4/1/22.
//

#include<iostream>

using namespace std;

class WebPage {
private:
    char url[100];
    char *content;

    void copy (const WebPage & wp) {
        strcpy(this->url, wp.url);
        this->content = new char [strlen(wp.content)+1];
        strcpy(this->content, wp.content);
    }

public:
    //MUST default, w/ arguments, copy-constructor, operator =, destructor
    WebPage(char *url = "https://finki.ukim.mk", char *content = "This is the web page of FCSE - Skopje") {
        strcpy(this->url, url);
        this->content = new char [strlen(content)+1];
        strcpy(this->content, content);
    }

    WebPage (const WebPage & other) {
        copy(other);
    }

    WebPage & operator = (const WebPage & other) {
        if (this!=&other){
            delete [] content;
            copy(other);
        }
        return *this;
    }

    ~WebPage() {
        delete [] content;
    }

    bool equal (WebPage & other) {
        return !strcmp(this->url, other.url);
    }

    void print () {
        cout << "URL: " << url << endl << "Content: " << content << endl;
    }
};

class WebServer {
private:
    char name [30];
    WebPage * webPages;
    int count;

    void copy (const WebServer & ws) {
        strcpy(this->name, ws.name);
        this->count = ws.count;
        webPages = new WebPage[this->count];
        for (int i=0;i<this->count;i++) {
            this->webPages[i] = ws.webPages[i]; //operator = in WebPage
        }

    }
public:
    WebServer(char * name = "FINKI"){
        strcpy(this->name, name);
        this->count = 0;
        webPages = new WebPage[0];
    }

    WebServer (const WebServer & ws) {
        copy (ws);
    }

    WebServer & operator = (const WebServer & ws) {
        if (this!=&ws){
            delete [] webPages;
            copy(ws);
        }
        return *this;
    }

    ~WebServer() {
        delete [] webPages;
    }

    bool contains (WebPage & wp) {
        for (int i=0;i<this->count;i++) {
            if (webPages[i].equal(wp)){
                return true;
            }
        }
        return false;
    }

    void addPage (WebPage & wp) {
        if (contains(wp))
            return;

        WebPage * tmp = new WebPage[count+1];
        for (int i=0;i<count;i++){
            tmp[i]=webPages[i];
        }
        tmp[count]=wp;
        count++;
        delete [] webPages;
        webPages = tmp;
    }

    void deletePage (WebPage & wp) {
        if (contains(wp)) {
            WebPage * temp = new WebPage[count-1];
            int j=0;
            for (int i=0;i<count;i++){
                if (!webPages[i].equal(wp)) {
                    temp[j++]=webPages[i];
                }
            }
            delete [] webPages;
            webPages = temp;
            count--;
        }
    }

    void print () {
        cout << "Count of web pages: " << count <<endl;
        for (int i=0;i<count;i++) {
            webPages[i].print();
        }
    }



};

int main() {
    WebPage wp; //call to the default constructor
//    wp.print();

    WebPage wp1("https://courses.finki.ukim.mk");
//    wp1.print();

    //test copy constructor;
    WebPage wpCopy (wp);
//    wpCopy.print();

    //test = operator
    WebPage webPage;
    webPage = wp1;
//    webPage.print();

    WebServer ws;
    ws.addPage(wp);
    ws.addPage(wp1);
    ws.addPage(wpCopy);
    ws.addPage(webPage);
    ws.print();

    ws.deletePage(wp1);
    ws.print();
    return 0;
}