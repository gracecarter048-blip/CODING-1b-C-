// Carter grace Coding 1 Spring 2026
// My first C++ program

#include <iostream>     // in out stream, for sending text to the console.

#include <string> // fpr player name

using namespace std;    // so we don't have to type "std::" all the time.

// here is where we start the program
int main() {
    
    // variables at the top is best practice.
    string playerName; 

    // ask player for there name
    cout << "what is your name, player? ";

    // assiagn whatever the player types as the player name
    cin >> playerName;

cout << "hello " << playerName <<"." <<endl;

    // cout << "Hello WORLD!" << endl;         // cout = console out, end line.


    return 0;                   // end the program
}