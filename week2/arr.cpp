// Carter Grace Coding 1
// Arrays, For loops, emus, and switch statements

#include <iostream>
#include <string>
#include <cstdlib>


using namespace std;

int main() {
    srand(time(0));
    cout << "lets make some arrays!\n";

//arrays can not change their size
//arrays dont know where the last index is
// arrays are a list of simular varible types
//arrays are ordered

int scores[5]; //this is creating an integer array with a size of 5

scores[0] = 4545;
scores[1] = 13;
scores[2] = 9001;
scores[3] = -4;
scores[4] = 2456;

cout <<"the first high score is " << scores[0] << ".\n";

cout << "here are all the scores:\n";

int index = 0;
while(index < 5) {
    cout << scores[index] << "\n";
    index++;
}

cout << "using a for loop:\n";
//for loop has the 'iterator' built in.
for(int i = 0; i < 5; i++){
    cout << scores[i] << "\n";
}

// lets build a string array for names
string names [10];
string input;
index = 0;
// we want the user to add names to the array
while(index , 10) {
    cout << "type name, or 'done':";
    cin >> input;

    // until they type done
    if (input == "done") {
        cout << "Done adding names.\n";
        break;
    }

    names[index++] = input;
}
// or until the list is full
// show the list of names

for(int i = 0; i < 10; i++) {
    if(names[i] == "") {
        continue;
    }

    cout << names[i] << "\n";
}

// create a new string array
string newNames[] = {"mario", "luigi", "peach", "bowser", "captain toad", "rosalina", "yoshi", "bowser jr."};

cout << "here are the new names:\n";
for(int i = 0; i < 8; i++) {
    cout << i + 1 << ". " << newNames[i] << "\n";
}

int randIndex = rand() % 8;
string character = newNames[randIndex];

cout << character << ", let's talk about them.\n";

// THEY ARE ONLY VALUES THAT WE SPECIFY
// THEY CORRESPOND TO NUMBERS, STARTING WITH 0
enum favor {LOVE, LIKE, DISLIKE, LOATHE};

switch(rand() % 4) {
    case LOVE:
    cout << "I love " << character << ".\n";
    break;
     case LIKE:
    cout << "I like " << character << ".\n";
    break;
     case DISLIKE:
    cout << "I dislike " << character << ".\n";
    break;
     case LOATHE:
    cout << "I loathe " << character << ".\n";
    break;
}

    return 0;
}