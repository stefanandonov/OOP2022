//
// Created by Stefan Andonov on 4/20/22.
//

#include<iostream>

using namespace std;

class TennisPlayer {
protected:
    char name[50];
    bool playsInLeague;
public:
    TennisPlayer(char *name = "", bool playsInLeague = false) {
        cout <<"TennisPlayer constructor"<<endl;
        strcpy(this->name, name);
        this->playsInLeague = playsInLeague;
    }

    TennisPlayer(const TennisPlayer &tp) {
        cout <<"TennisPlayer copy-constructor"<<endl;
        strcpy(this->name, tp.name);
        this->playsInLeague = tp.playsInLeague;
    }

    void print() {
        cout << "TennisPlayer " << name << " " << (playsInLeague ? "plays in league" : "doesn't play in league")
             << endl;
    }

    friend ostream &operator<<(ostream &out, const TennisPlayer &tp) {
        return out << "TennisPlayer " << tp.name << " "
                   << (tp.playsInLeague ? "plays in league" : "doesn't play in league");
    }

    ~TennisPlayer() {
        cout <<"TennisPlayer destructor"<<endl;
    }
};

class RankedTennisPlayer : public TennisPlayer {
private:
    int rank;
public:
    RankedTennisPlayer(char *name = "", bool playsInLeague = false, int rank = 100) : TennisPlayer(name,
                                                                                                   playsInLeague) {
        cout <<"RankedTennisPlayer constructor"<<endl;
        this->rank = rank;
    }

    RankedTennisPlayer(const TennisPlayer &tp, int rank) : TennisPlayer(tp) {
        cout <<"RankedTennisPlayer constructor"<<endl;
        this->rank = rank;
    }

    RankedTennisPlayer(const RankedTennisPlayer & other) : TennisPlayer(other) {
        this->rank = other.rank;
    }

    friend ostream & operator << (ostream & out, const RankedTennisPlayer & rtp) {
        out <<"Ranked";
        TennisPlayer tmp (rtp);
        out << tmp << ", is ranked " <<rtp.rank;
        return out;
    }

    ~RankedTennisPlayer() {
        cout <<"RankedTennisPlayer destructor"<<endl;
    }

};

int main() {
//    TennisPlayer tp("Novak Djokovic", true);
//    cout << tp << endl;
//    RankedTennisPlayer rtp (tp, 1);
//    cout << rtp << endl;

    RankedTennisPlayer rtp ("Novak Djokovic", true, 1);
    //cout << rtp << endl;

    TennisPlayer tp = rtp;
    cout << tp;
    return 0;
}