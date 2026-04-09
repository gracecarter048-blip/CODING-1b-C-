//Carter Grace
//Vectors, iterators, and algorithims

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cout << "Lets learn Vectors!\n";

    string input;

    do{
        cout << "what would you like to do?\n";
        cout << "you can type 'quit', 'find', 'push'.\n";

        getline(cin, input);

        if(input == "push") {
            cout << "Lets make our first vector of strings.\n";


            vector<string> names;

            names.push_back("finn");
            names.push_back("lady rainicorn");
            names.push_back("jake");
            names.push_back("the lich");

            cout << "here are your names!\n";
            for(int i = 0; i < names.size(); i++) {
                cout << "\t" << names[i] << "\n";
            }

            cout << "there are " << names.size() << " names.\n\n";

            cout << *(names.end() - 1) << " is a dick. lets get rid of him.\n";

            names.pop_back();

            cout << "here are your names!\n";
            for(int i = 0; i < names.size(); i++) {
                cout << "\t" << names[i] << "\n";
            }  
        }//end of push
        else if(input == "find") {
            cout <<"lets try to use the find algorithm.\n";

            //building a iterator
            vector<string> favs = 
            
            {"Star wars", "Back to the future", "Kill Bill"};

            vector<string>::iterator iter;
            cout << "here are your favs!\n";
            for(int i = 0; i < favs.size(); i++) {
                cout << "   " <<favs[i] <<"\n";
            }

            // make iter point at the first element in the vector
            iter = favs.begin();
            
            // use ther asterisk is a "dereference operator"
            cout << "iter is pointing at " << *iter << ".\n";

            iter += 1;

            cout << "now iter is pointing at " << *iter << ".\n";

            cout << "What name would you like to select?\n";
            getline(cin, input);

            // use the find algorithm
            iter = find(favs.begin(), favs.end(), input);
            if(iter != favs.end()) {
                cout << "We're found " << *iter << "!\n";
                cout << "would you like to change this fav?\n";
                getline(cin, input);

                if (input == "yes") {
                    cout << "what would you like to chage it too?\n";
                    getline(cin, input);

                    *iter = input;
                }

                cout << "here are your favs!\n";
            for(int i = 0; i < favs.size(); i++) {
                cout << "   " <<favs[i] <<"\n";
            }
            }
            else{
                cout << "we couldn't find that name.\n";
            }
        }
        else if(input == "quit") {
            cout << "thanks for playing the game.\n";
            break;
        }
        else{
            cout << "i didn't reconise that command.\n";
        }
    } while(true);

    // create a new vector of strings

    return 0;
}