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

using namespace std;

int main() {
    cout << "Lets Edit your Favorite Games List!\n";

    vector<string> favgames = {"mario", "pacman", "Eldin Ring"};
    string input;

    do{
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

        if(input == "edit") {
            vector<string>::iterator iter;
            cout << "here are your favs!\n";
            for(int i = 0; i < favgames.size(); i++) {
                cout << "   " <<favgames[i] <<"\n";
            }

            cout << "What Game would you like to Select?\n";
            getline(cin, input);

            iter = favgames.begin();

            cout << "iter is pointing at " << *iter << ".\n";

            iter += 1;

            cout << "now iter is pointing at " << *iter << ".\n";

            // use the find algorithm
            iter = find(favgames.begin(), favgames.end(), input);
            if(iter != favgames.end()) {
                cout << "We have found " << *iter << "!\n";
                cout << "would you like to change out this Game?\n";
                getline(cin, input);

                if (input == "yes") {
                    cout << "what would you like to chage it too?\n";
                    getline(cin, input);

                    *iter = input;
                }

                cout << "here are your Favorite Games!\n";
            for(int i = 0; i < favgames.size(); i++) {
                cout << "   " <<favgames[i] <<"\n";
            }
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

        else if(input == "quit") {
            cout << "thanks for playing the game.\n";
            break;
        }
   

//end of push
    } while(true);

    return 0;
}