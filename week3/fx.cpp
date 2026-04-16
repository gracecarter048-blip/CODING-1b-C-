// Carter Grace Coding 1
// functions

#include <iostream>
#include <string>
#include <cstdlib>      // for rand
#include <ctime>            //for time
#include <vector>

using namespace std;

// declaring and defining a new function
// the return we are calling is void
// the name of this function is sayHello
//the input parameters go in the prenthiseis
void sayHello() {
    cout << "hello!\n";
}

// int and void are the returns

void doAddition(int firstNum, int secondNum) {
    cout << "Our first number is " << firstNum << ".\n";
    cout << "Our second number is " << secondNum << ".\n";
    cout << "togethor they make " << firstNum + secondNum << ".\n";
}

int dieRoll(int sides = 6) {
    return rand() % sides + 1;
}

// create a function
// return type of bool
// name is askYesNo
// no input parameters
bool askYesNo(string question = "Do you want to keep playing?") {
    while(true) {
        cout << question << "?\n";
        string input;
        getline(cin, input);

        if(input == "yes") {
        return true;            //this will break out of the entire function
        }
        else if(input == "no") {
        return false;           // this will break out of the entire function
        }
        else {
        cout << "I did not understand. Please type 'yes' or 'no'.\n";
        }
    }
}

// varible of arrays
void showVec(vector<string>& vec) {
    for(int i = 0; i < vec.size(); i++) {
        cout << vec[i] << endl;
    }
}

// create a reference with the & symbol next to the varible type
// int& number; or string& name;

// reference let us edit the original.
void addStringToVec(vector<string>& vec) {
    cout << "What name would you like to add?\n";
    string input;
    getline(cin, input);

    vec.push_back(input);

    showVec(vec);       //the added name exsits here.
}

int main() {
    srand(time(0));
    vector<string> names = {"batman", "robin", "joker", "alfred"};
    cout << "Finally, Functions!\n";

    sayHello();

    cout << " Lets roll our dice! Our first number is " << dieRoll(6) << ".\n";

    doAddition(dieRoll(20), dieRoll(20));
    doAddition(dieRoll(), dieRoll(22));

    showVec(names);         //notice that it doesn't add the string to our names vector

    addStringToVec(names);

    if(askYesNo()) {
        cout << "Lets start the next Level!\n";
    }
    else {
        cout << "Thanks for playing my game!\n";
    }
    return 0;

    if(askYesNo("Do you like the Game?")) {
        cout << "I'm glad to hear!\n";
    }
    else {
        cout << "thanks for trying my game.\n";
    }

}