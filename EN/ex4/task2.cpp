//
// Created by Stefan Andonov on 3/18/22.
//

#include<cstring>
#include<iostream>

using namespace std;

class Team {
private:
    char name[50];
    int foundingYear;
    char city[50];
public:
    //default constructor and constructor with arguments 2in1 NesCafe constructor
    Team(char *_name = "", int _foundingYear = 1900, char *_city = "") {
        strcpy(name, _name);
        foundingYear = _foundingYear;
        strcpy(city, _city);
    }

    //copy-constructor
    Team(const Team &t) {
        cout << "Team copy-constructor called" << endl;
        strcpy(name, t.name);
        foundingYear = t.foundingYear;
        strcpy(city, t.city);
    }

    //destructor
    ~Team() {

    }

    void print() {
        cout << name << " " << city << " (" << foundingYear << ")" << endl;
    }

    bool equal(Team & team) {
        return strcmp(name, team.name) == 0;
    }


};

class Game {
private:
    Team home;
    Team away;
    int homeGoals;
    int awayGoals;
public:
    //default constructor
    Game() {
        homeGoals = 0;
        awayGoals = 0;
    }

    //constructor
    Game(Team _home, Team _away, int _homeGoals, int _awayGoals) {
        home = _home;
        away = _away;
        homeGoals = _homeGoals;
        awayGoals = _awayGoals;
    }

    //copy-constructor
    Game(const Game &other) {
        cout << "Game copy-constructor called" << endl;
        home = other.home;
        away = other.away;
        homeGoals = other.homeGoals;
        awayGoals = other.awayGoals;
    }

    ~Game() {
        //do nothing
    }

    void print() {
        cout << "Game between: " << endl;
        cout << "Home team: ";
        home.print();
        cout << "Away team: ";
        away.print();
        cout << "Result: " << homeGoals << ":" << awayGoals << endl;
    }

    friend Team rematch(Game game1, Game game2);
};

Team rematch(Game game1, Game game2) {
    if (game1.home.equal(game2.away) && game1.away.equal(game2.home)) {
        //this is a rematch
        int totalGoalsTeam1 = game1.homeGoals + game2.awayGoals;
        int totalGoalsTeam2 = game1.awayGoals + game2.homeGoals;
        if (totalGoalsTeam1>totalGoalsTeam2)   {
            return game1.home;
        } else if (totalGoalsTeam2>totalGoalsTeam1) {
            return game1.away;
        } else {
            return nullptr;
        }
    } else {
        return nullptr;
    }
}

int main() {
    Team t1("Barca", 1899, "Barcelona");
    Team t2("Real Madrid", 1901, "Madrid");

    Game game(t1, t2, 5, 1);
    Game game2(t2, t1, 1, 5); //4 calls to the copy-const of Team

    //explicit call of a copy constructor
    Team winner = rematch(game, game2); //2 calls to the copy-const of Game
    winner.print();

//    t1.print();
//    t2.print();
//    game.print();
    return 0;
}

