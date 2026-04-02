// Carter Grace Coding 1
// Random Numbers

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    //seed the random number
    srand(time(0));
    cout << "random Number.\n";

    cout << "here is our first random number: " << rand() << ".\n";

    int counter = 0;
    while(counter++ < 10) {
        int number = rand();
        int min = 50;
        int max = 100;
        int range = max - min;
        int clampedNumber = (number % range) + min;


        cout << clampedNumber << endl;
    }

// set varibles
    // the random number
    int randomRange = (rand() % 11) + 10;
    int number = (rand() % randomRange) + 1;
    int totalguesses = 0;
    // the guess/input
    int guess = -1;
    //start loop
    while(true) {
// ask for the players guest between 1 and 10(inclusive)
cout << "im thinking of a number between 1 and 10, can you guess it?\n";
//get the players guess
cin >> guess;
totalguesses++;
// evaluate the players guest for to
//  high,
if(guess > number) {
    cout << "too High!\n";
}
//  to low, and
else if(guess < number) {
    cout << "Too Low!\n";
}
//  to corect
else {
    cout << "thats right you guessed correctly!\n";
    break;
}
}
//break out of loop
// if wrong guest keeping looping

    return 0;

}