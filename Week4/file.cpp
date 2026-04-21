// Carter Grace Coding 1b
// writing to and reading from files

#include <iostream>
#include <string>
#include <vector>
#include <fstream>      // file stream

using namespace std;

void read(string path = "save.txt") {
     // create a new var, and try to open file
    string line;
    ifstream readFile("save.txt");      //input file on stream
    if(readFile.is_open()) {
        cout << "the file is open.\n";
        while(getline(readFile, line)) {
            cout << line << endl;
        }
    }
    else {
        cout << "Couldn't open that file.\n";
    }
     //after we are done with file we close it
    readFile.close();

}

void read(vector<string>& vec, string path = "save.txt") {
     string line;
    ifstream readFile("save.txt");      //input file on stream
    if(readFile.is_open()) {
        cout << "the file is open.\n";
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

void write(vector<string>& vec, string path = "save.txt") {

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
    cout << "lets write to a file!\n";
    vector<string> favs;
     string input = "asdf";


    string path = "save.txt";
    
    cout << "what file would you like to open?\ntype 'no' to use default.\n";
    getline(cin, input);
    if(input != "no") {
        path = input;
    }
   

    read();     //show current names
    read(favs); // add the names to the vector
  

    cout << "what name would you like to add?\n";
    cout << "enter a empty line to stop.\n";
    // create a file to write to open it
     

    while(input != "") {
        cout << "> ";
        getline(cin, input);
        if(input == "") {
            break;      //stop before we add a blank name vector
        }
        //send to file
        favs.push_back(input);
    }

    write(favs, path);

    return 0;
}