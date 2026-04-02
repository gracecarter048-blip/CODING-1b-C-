// Carter Grace
// varibles and logic

// compile with the developer command prompt
// 'cl /EHsc main.cpp' is what you type to compile
// 'main' or 'main.exe' to run the program.

#include <iostream>
using namespace std;

int main() {
    cout << "lets learn about varibles and logic!\n";


int playerAge = -1;
string playerName = "Darth Vader";
float happinessPrecent = 0.61f;
bool keepPlaying = true;

// just like a branch in ue
if(playerAge == -1){
    cout << "how old are you?\n";
    cin >> playerAge;

    if(playerAge <= 12) {
        cout << "im sorry, this game is for grown ups!\n";
        return 0;       //quit the game early
    }
    else {
        cout << "WOW, " << playerAge << " years, that is a long time!\n";
    } // end of if(playerAge)
}

    if(playerName == "Darth Vader") {
        cout << "is your name " <<playerName << "?\n";
        string input;
        cin >> input;
        if(input == "yes") {
            cout << "well, thats convenient!\n";
        }
        else {
            cout << "what is your name?\n";
            cin >> playerName;
        }
    }
bool debug = false; 
    if(playerAge == 19 && playerName == "Carter") {

        cout << "hello, Creator. Debug mode is on.\n";
    }

    cout << "hello " << playerName << ".\n";

if(debug) {
    cout << "playerAge = " << playerAge << ".\n";
    cout << "playername = " << playerName << ".\n";
    cout << "happinessPrecent = " << happinessPrecent << ".\n";
    cout << "keepPlaying = " << keepPlaying << ".\n";
}


    return 0;
}