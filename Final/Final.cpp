// Carter Grace Coding 1 Final
// Making  the bones of a Poke'mon tamagotchi 

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <fstream> 

using namespace std; 

vector<string> FinalNames = {"Ash", "Team Rocket", "Brock", "Misty", "Giovoni"};

class starterPokemon {
public:
    string name;
    int health;
    int damage;

    // default constructor
    starterPokemon() {
        name = FinalNames[rand() % FinalNames.size()] + " ";
        health = rand() % 5 + 5;
        damage = rand() % 6 + 3;
    }
    // tell the player the stats of the pokemon
    void hello() {
        cout << "My name is " << name << ".\nI have " << health;
        cout << " health and " << damage << " damage.\n";
    }
    // Create attack code 
    bool attack(starterPokemon& opponent) {
        opponent.health -= damage;
        cout << name << " attacks " << opponent.name << "!\n";

        // did this attack defeat the opponent?
        if(opponent.health <= 0) {return true;}
        else {return false;}
    }
};
// reads Final.txt file, telling user all their pokemon
void read(vector<string>& vec, string path = "Final.txt") {
    string line;
    ifstream readFile(path); // input file on stream
    if (readFile.is_open()) {
        cout << "Pokedex open.\n";
        while (getline(readFile, line)) {vec.push_back(line);}
    } // if the wrong file gets typed, tell player file can't be found
    else { cout << "Couldn't open that file.\n";}
    readFile.close();
}

int main() {
    cout << "Let's Begin Your Pokemon Training!\n";
    vector<string> Final;
    string userInput;
    
    string path = "Final.txt"; // telling the computer what file we want
    cout << "Would you like to open your pokedex?\n";
    // get players anwser
    getline(cin, userInput);
    if(userInput == "yes") {path = userInput;
    read(Final);
    cout << "Would you like to 'add' a pokemon, or 'select' a pokemon for battle?\n";}
    
    getline(cin, userInput);
    // name a pokemon into the list
    if(userInput == "add") {
        //ask player what they want to add
        for(int i = 0; i < Final.size(); i++) {cout << "\t" << Final[i] << endl;}
        cout << "Lets add a new pokemon to collection.\n";
        //get players feedback
        getline(cin, userInput);
        //show player the new list
        Final.push_back(userInput);
        cout << "here is your collection:\n";
        for(int i = 0; i < Final.size(); i++) {cout << "\t" << Final[i] << endl;}   
    }

    if(userInput == "select") {
        read(Final); // add the names to the vector
        vector<string>::iterator iter;
        cout << "here are your Pokemon!\n";         //show user their collection
        for(int i = 0; i < Final.size(); i++) {
            cout << "   " <<Final[i] <<"\n";}
        iter = Final.begin();
        iter += 1;
        cout << "What pokemon would you like to select?\n";
        getline(cin, userInput);
        // use the find algorithm
        iter = find(Final.begin(), Final.end(), userInput);
        // this is if players anwser is found
        if(iter != Final.end()){cout << "We have found that name!\n";}
        // this is if players anwser can not be found
        else{ cout << "We couldn't find that name.\n";}
        cout << " " << *iter << " Has 2 Hunger bars, 2 Attack bars, 4 Health.\n";
    }
    do{ //give player the option to feed, train or battle with their pokemon
        cout << " Would you like to 'feed' him, 'train' him, or 'battle' with him?\n";
        getline(cin, userInput);
        if(userInput == "feed") {   //give player verbal feedback for feeding their pokemon
            cout << "You have feed him, he is now full!\n";
            cout << "He is now ready to train or battle with you!\n";
        } 
        else if(userInput == "train") {
            cout << "You both will now train, to be the very best!\n";
            cout << "Would you like to add to your attack or health?\n";
            getline(cin, userInput);
            if(userInput == "attack") {cout << "Attack has raised to 5 bars.\n";}
            if(userInput == "health") {
                cout << "Health has been raised to 6 bars, he now can take serious evolved pokemon blats.\n";}
            cout << "he is now ready to battle with you!\n";
        } 
        else if(userInput == "quit") {
            cout << "thanks for playing.\n";
            break;
        }
   
        else if(userInput == "battle") {
            cout << "Let's battle some pokemon!\n";
            cout << "You will battle Charizard, his attack is 4, and health is at 10.\n";
            cout << "Would you like to attack or run away?\n";
            getline(cin, userInput);
            if(userInput == "run") {
                cout << "Better luck next time, Thanks for Playing!\n";
                break;
            }
            if(userInput == "attack") {
                srand(time(0)); 
                starterPokemon Charizard;
                Charizard.name = "your Pokemon";
                Charizard.health = 10;
                Charizard.damage = 4;

                starterPokemon yourPokemon;
                yourPokemon.name = "yourPokemon";
                yourPokemon.health = 7;
                yourPokemon.damage = 6;

                Charizard.hello();
                yourPokemon.hello();

                cout << "Let's start the pokemon battle.\n";

                starterPokemon& fighterA = (rand() % 2 == 0) ? Charizard : yourPokemon;
                starterPokemon& fighterB = (fighterA.name == yourPokemon.name) ? yourPokemon : Charizard;

                if(rand() % 2 == 0) {
                    cout << "Charizard blasts first!\n";
                    fighterA = Charizard;
                    fighterB = yourPokemon;
                }
                else {
                    cout << "You blast first!\n";
                    fighterA = yourPokemon;
                    fighterB = Charizard;
                }
                while(fighterA.health > 0 && fighterB.health > 0) {
                    // fighterA punches
                    if(fighterA.attack(fighterB))  {cout << fighterB.name << " has been defeated!\n";}
                    else {
                        // fighterB punches
                        if(fighterB.attack(fighterA)) {cout << fighterA.name << " has been defeated!\n";}
                    }
                }
                return 0;
            }   
        }
    } while(true);
}