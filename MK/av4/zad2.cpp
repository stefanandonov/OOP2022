//
// Created by Stefan Andonov on 3/16/22.
//


#include<iostream>
#include<cstring>

using namespace std;

class Team {
    char name[50];
    int foundingYear;
    char city[50];

public:
    //2in1 constructor, default i so argument
    Team(char *_name = "", int _foundingYear = 1990, char *_city = "") {
        strcpy(name, _name);
        strcpy(city, _city);
        foundingYear = _foundingYear;
    }

    Team(const Team &t) {
        cout <<"Team copy-constructor" <<endl;
        strcpy(name, t.name);
        strcpy(city, t.city);
        foundingYear = t.foundingYear;
    }

    ~Team() {

    }

    bool isEqual(Team & other) {
        return strcmp(name, other.name) == 0;
    }

    void print () {
        cout << name <<endl;
    }

    void setName(const char *string) {
        strcpy(name, string);
    }
};


class Game {
    Team homeTeam;
    Team awayTeam;
    int homeGoals;
    int awayGoals;

public:

    Game() {
        homeGoals = 0;
        awayGoals = 0;
    }

    Game(Team _homeTeam,
         Team _awayTeam,
         int _homeGoals,
         int _awayGoals) {
        homeTeam = _homeTeam;
        awayTeam = _awayTeam;
        homeGoals = _homeGoals;
        awayGoals = _awayGoals;
    }

    Game(const Game &g) {
        cout<<"Game copy-constructor"<<endl;
        homeTeam = g.homeTeam;
        awayTeam = g.awayTeam;
        homeGoals = g.homeGoals;
        awayGoals = g.awayGoals;
    }

    ~Game() {

    }

    bool isRematch(Game & other) {
        return homeTeam.isEqual(other.awayTeam) && awayTeam.isEqual(other.homeTeam);
    }

    friend Team duel (Game & first, Game & second);
};

Team duel (Game & first, Game & second) {
    if (first.isRematch(second)) {
        int goalsOfFirstTeam = first.homeGoals + second.awayGoals;
        int goalsOfSecondTeam = first.awayGoals + second.homeGoals;
        if (goalsOfFirstTeam>goalsOfSecondTeam) {
            return first.homeTeam;
        } else if (goalsOfFirstTeam<goalsOfSecondTeam) {
            return first.awayTeam;
        } else {
            return nullptr;
        }
    } else {
        return nullptr;
    }
}


int main() {

    Team team1 ("Barca", 1899, "Barcelona");
    Team team2 ("Real Madrid", 1902, "Madrid");

//    Team team3 (team2);
//    team3.setName("Chelsea");


    Game firstGame (team1, team2, 10, 5);
    Game secondGame (team2, team1, 4, 6);

    cout<<firstGame.isRematch(secondGame)<<endl;
//
    duel(firstGame, secondGame).print();


    return 0;
}