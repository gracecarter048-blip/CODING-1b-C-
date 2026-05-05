// Carter Grace Coding 1 Final
// Making  the bones of a Poke'mon tamagotchi 

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <fstream> 

using namespace std;

void read(string path = "Final.txt") {
     // create a new var, and try to open file
    string line;
    ifstream readFile("Final.txt");      //input file on stream
    if(readFile.is_open()) {
        while(getline(readFile, line)) {
            cout << line << endl;
        }
    }
     //after we are done with file we close it
    readFile.close();

}

void read(vector<string>& vec, string path = "Final.txt") {
     string line;
    ifstream readFile("final.txt");      //input file on stream
    if(readFile.is_open()) {
        cout << "Pokedex open.\n";
        while(getline(readFile, line)) {
            vec.push_back(line);
        }
    }
    else {
        cout << "Couldn't open that file.\n";
    }
     //after we are done with file we close it
    readFile.close();
}

void write(vector<string>& vec, string path = "Final.txt") {

     ofstream writeFile(path);   
     if(writeFile.is_open()) {
        for(int i = 0; i < vec.size(); i++) {
            writeFile << vec[i] << endl;
        }
    }
     else {
        cout << "couldn't open new writeFile.\n";
    }
     
     writeFile.close();
}

int main() {
    cout << "Let's Begin Your Pokemon Training!\n";
    vector<string> favs;
    string userInput;

    string path = "Final.txt";
    cout << "Would you like to open your pokedex?\n";

    // get players anwser
     getline(cin, userInput);
     if(userInput != "yes") {
        path = userInput;
    }

    read();     //show current names
    read(favs); // add the names to the vector

    do{
         cout << "Would you like to add a pokemon to your list?"
         " if yes type 'yes', if not type 'no'.\n";
        getline(cin, userInput);
        if(userInput == "yes") {

            cout << "Lets add a New Pokemon.\n";
            //get players feedback
            getline(cin, userInput);
            cout << "here are your pokemon:\n";
            break;
        }
         if(userInput == "no") {
            cout << "What Pokemon would you like to train to be the best?\n";
            cin >> userInput;
            cout << "You chose: " << userInput << endl;
        }
        break;
    } while(true);


    return 0;
}