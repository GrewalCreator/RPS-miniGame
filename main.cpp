#define NOT_VALID_OPTION -1
#define CPP_OK 0
#define CPP_NOK -1;

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

    while(true) {
        int funSuccess = getUserMove(&playerMove);
        if (funSuccess == 0) {
            cout << playerMove << endl;
            break;
        } else {
            cout << "Incorrect Value Provided! Please Pick A Valid Option" << endl;
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
        *userChoice = 1;
    }else if(temp == "paper"){
        *userChoice = 2;
    }else if(temp == "scissor"){
        *userChoice = 3;
    }else{
        *userChoice = NOT_VALID_OPTION;
        return CPP_NOK;
    }

    return CPP_OK;

}

int getComputerMove(int* computerChoice){
    
}
