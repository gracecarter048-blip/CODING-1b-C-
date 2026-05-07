// Carter Grace Coding 1 Final
// Making  the bones of a Poke'mon tamagotchi 

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <fstream> 

using namespace std; 

vector<string> FinalNames = {"Tombow", "Cheryl", "Escobar", "Inigo", "Franz"};

class starterPokemon {
public:
    string name;
    int health;
    int damage;

    // default constructor
    starterPokemon() {
        // get a random name between 0 and 
        name = FinalNames[rand() % FinalNames.size()] + " ";
        health = rand() % 5 + 5;
        damage = rand() % 6 + 3;
    }

    void hello() {
        cout << "My name is " << name << ".\nI have " << health;
        cout << " health and " << damage << " damage.\n";
    }

    bool attack(starterPokemon& opponent) {
        opponent.health -= damage;
        cout << name << " attacks " << opponent.name << "!\n";

        // did this attack defeat the opponent?
        if(opponent.health <= 0) {
            return true;
        }
        else {
            return false;
        }
    }
};

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
    ifstream readFile(path); // input file on stream
    if (readFile.is_open()) {
        cout << "Pokedex open.\n";
        while (getline(readFile, line)) {
            vec.push_back(line);
        }
        if (vec.empty()) {
            cout << "The Pokedex is empty. Please add Pokémon first.\n";
        }
    } else {
        cout << "Couldn't open that file.\n";
    }
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
    vector<string> Final;
    string userInput;
    
    string path = "Final.txt";
    cout << "Would you like to open your pokedex?\n";
    // get players anwser
    getline(cin, userInput);
    if(userInput != "yes") {
        path = userInput;

    }
    read();
    read(Final);

    cout << "Would you like to 'add' a pokemon, or 'select' a pokemon for battle?\n";
    
        getline(cin, userInput);

        if(userInput == "add") {
            //ask player what they want to add
            for(int i = 0; i < Final.size(); i++) {
                cout << "\t" << Final[i] << endl;
            }
            cout << "Lets add a new pokemon to collection.\n";
            //get players feedback
            getline(cin, userInput);
            //show player the new list
            Final.push_back(userInput);

            cout << "here is your collection:\n";
            for(int i = 0; i < Final.size(); i++) {
                cout << "\t" << Final[i] << endl;
            }   
        }

        if(userInput == "select") {
            read(Final); // add the names to the vector
            vector<string>::iterator iter;
            cout << "here are your Pokemon!\n";
            for(int i = 0; i < Final.size(); i++) {
                cout << "   " <<Final[i] <<"\n";
            }

            iter = Final.begin();
            iter += 1;
            cout << "What pokemon would you like to select?\n";
            getline(cin, userInput);
            // use the find algorithm
            iter = find(Final.begin(), Final.end(), userInput);
            if(iter != Final.end()) 
            cout << " " << *iter << " Has 2 Hunger bars, 2 Attack bars, 4 Health.\n";
        }
        do{
        cout << " Would you like to 'feed' him, 'train' him, or 'battle' with him?\n";
        getline(cin, userInput);
        if(userInput == "feed") {
            cout << "You have feed him, he is now full!\n";
            cout << "he is now ready to train or battle with you!\n";
        } 
        if(userInput == "train") {
            cout << "You both will now train, to be the very best!\n";
            cout << "Would you like to add to your attack or health?\n";
            getline(cin, userInput);
            if(userInput == "attack") {
                cout << "Attack has raised to 5 bars.\n";
            }
            if(userInput == "health") {
                cout << "Health has been raised to 6 bars, he now can take serious evolved pokemon blats.\n";
            }
            cout << "he is now ready to battle with you!\n";
        } 
   
        if(userInput == "battle") {
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
                Charizard.name = "Charizard";
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
                starterPokemon& fighterB = (fighterA.name == Charizard.name) ? yourPokemon : Charizard;

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
                    if(fighterA.attack(fighterB))  {
                        cout << fighterB.name << " has been defeated!\n";
                    }
                    else {
                        // fighterB punches
                        if(fighterB.attack(fighterA)) {
                            cout << fighterA.name << " has been defeated!\n";
                        }
                    }
                }
                return 0;
            }   
        }
    } while(true);
}