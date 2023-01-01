#define NOT_VALID_OPTION -1
#define CPP_OK 0
#define CPP_NOK -1;

#define ROCK 1
#define PAPER 2
#define SCISSOR 3

#include <iostream>
#include <ctime>
#include <cstdlib>
#include<bits/stdc++.h>


using std::cout;
using std::endl;
using std::string;
using std::cin;




void start();
int getUserMove(int*);
int getComputerMove(int*);


int main() {
    srand(time(nullptr));
    start();
    return 0;
}

void start(){
    int playerMove;
    int computerMove;

    getComputerMove(&computerMove);

    while(true) {

        while(true) {
            int funSuccess = getUserMove(&playerMove);
            if (funSuccess == 0) {
                cout << playerMove << endl;
                break;
            } else {
                cout << "Incorrect Value Provided! Please Pick A Valid Option" << endl;
            }
        }


        if(playerMove == computerMove){
            cout << "Tie!" << endl;
        }else if(playerMove == PAPER && computerMove == ROCK){
            cout << "Player Wins!" << endl;
        }
        else if(playerMove == ROCK && computerMove == SCISSOR){
            cout << "Player Wins!" << endl;
        }
        else if(playerMove == SCISSOR && computerMove == PAPER){
            cout << "Player Wins!" << endl;
        }else{
            cout << "Computer Wins!" << endl;
        }

        string playAgain;
        cout << "Would You Like To Player Again? (Y/N)" << endl;
        cin >> playAgain;

        transform(playAgain.begin(), playAgain.end(), playAgain.begin(), ::tolower);
        if(playAgain == "n") {
            cout << "GoodBye!" << endl;
            break;
        }
    }



}

int getUserMove(int* userChoice){
    string temp;
    cout << "Choose An Option Below:" << endl;
    cout << "1) Rock\n2) Paper\n3) Scissor" << endl;
    cin >> temp;
    transform(temp.begin(), temp.end(), temp.begin(), ::tolower);

    if(temp == "rock"){
        *userChoice = ROCK;
    }else if(temp == "paper"){
        *userChoice = PAPER;
    }else if(temp == "scissor"){
        *userChoice = SCISSOR;
    }else{
        *userChoice = NOT_VALID_OPTION;
        return CPP_NOK;
    }

    return CPP_OK;

}

int getComputerMove(int* computerChoice){
    *computerChoice = 1 + (rand() % 3);
    return CPP_OK;
}
