// fav games assigment
// add a game
//edit a game
//remove a game
// show all games(sorted)
//quit

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
//need this for the use of having names throughout the game
using namespace std;

int main() { //this is the beginning of the whole code
    cout << "Lets Edit your Favorite Games List!\n";
    // Give the names on list to player
    vector<string> favgames = {"mario", "pacman", "Eldin Ring"};
    string input;

    do{ //Ask players what they want to do
        cout << "what would you like to do?\n";
        //create players options
        cout << "you can type 'add', 'remove', 'edit', 'show all', 'quit'.\n";
         getline(cin, input);

         if(input == "add") {
            //ask player what they want to add
              for(int i = 0; i < favgames.size(); i++) {
                 cout << "\t" << favgames[i] << endl;
            }
            cout << "Lets add another Video Game to the List.\n";
            //get players feedback
            getline(cin, input);
            //show player the new list
            favgames.push_back(input);

            cout << "here are your favorite games:\n";
            for(int i = 0; i < favgames.size(); i++) {
                 cout << "\t" << favgames[i] << endl;
            }
            
        }

        if(input == "remove") {
            //ask player what game they want to get rid of
            cout << "what game would you like to remove from list?\n";
            sort(favgames.begin(), favgames.end());
            for(int i = 0; i < favgames.size(); i++) {
                 cout << "\t" << favgames[i] << endl;
            }
            // gain players answer
            getline(cin, input);

            //find game to remove
             auto iter = find(favgames.begin(), favgames.end(), input);

            //remove game
            if(iter != favgames.end()) {
                cout << "We've found that name. removing now.\n";
                favgames.erase(iter);
            }
            cout << "here are your favorite games:\n";
            for(int i = 0; i < favgames.size(); i++) {
                 cout << "\t" << favgames[i] << endl;
            }
        }

        else if(input == "edit") {
            vector<string> favgames = 
            {"mario", "eldin ring", "pacman"};
            vector<string>::iterator iter;
            cout << "here are your favorite games!\n";
            for(int i = 0; i < favgames.size(); i++) {
                cout << "   " <<favgames[i] <<"\n";
            }

            iter = favgames.begin();
            iter += 1;
            cout << "What game would you like to Edit?\n";
            getline(cin, input);
            // use the find algorithm
            iter = find(favgames.begin(), favgames.end(), input);
            if(iter != favgames.end()) {
                cout << "We have found " << *iter << "!\n";
                cout << "would you like to change out this Game?\n";
                getline(cin, input);
// if player says yes let them change a game
                if (input == "yes") {
                    cout << "what would you like to chage it too?\n";
                    getline(cin, input);

                    *iter = input;
                }
                favgames.push_back(input);
                cout << "here are your Games!\n";
            for(int i = 0; i < favgames.size(); i++) {
                cout << "   " <<favgames[i] <<"\n";
            }
            }
            else{   //if wrong game gets put in take player back to menu
                cout << "we couldn't find that name.\n";
            }
        }

        if(input == "show all") {
            //summon names of video games from list
            vector<string> favgames;

            favgames.push_back("mario");
            favgames.push_back("pacman");
            favgames.push_back("eldin ring");
            // tell the player her are your games

            cout << "here are your Games!\n";
            for(int i = 0; i < favgames.size(); i++) {
                cout << "\t" << favgames[i] << "\n";
            }
        }

        else if(input == "quit") {  //if player types quit they end the game
            cout << "thanks for playing the game.\n";
            break;
        }

//end of push
    } while(true);

    return 0;
}