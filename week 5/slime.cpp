// Carter Grace Coding 1
// Inheritance, Vectors of classes, and slime battleing!

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

// this is a global vector, visable
vector<string> names = {"Alfred", "Barbara", "Quentin", "Sandra", "Glenn", "Betty"};

class baseSlime {
    public:
    string name = "";
    int health = 0;
    int damage = 0;

    int startingHealth = 0;

    // defualt constructor
    baseSlime() {
        cout << "A new slime has been found.\n";
        name = names[rand() % names.size()] + " slime";
        health = rand() % 4 + 4;
        startingHealth = health;
        damage = rand() % 3 + 3;
    }

    void hello() {
        cout << "I'm " << name << ", with " << health << " health ";
        cout << "and " << damage << " damage.\n";
    }

    // attack another slime
    void attack(baseSlime& opponent) {
        opponent.health -= damage;
        cout << name << " has done " << damage << " damage to ";
        cout << opponent.name << "!\n";
    }

};

class bossSlime : public baseSlime {
    public:
    int damageMultiplier = 3;

    // constructor for boss
    // this runs after the baseSlime constructor muts
    bossSlime() {
        // should inherit health
        // should inherit the cout statement
        name = "boss";
        damage = damage * damageMultiplier;
    }

    // attack another slime
    bool attack(baseSlime& opponent) {
        cout << "this is a boss attack!\n";
        opponent.health -= damage;
        cout << name << " has done " << damage << " damage to ";
        cout << opponent.name << "!\n";

        if(opponent.health <= 0)  return true;
        else                return false;      
        }

    void taunt() {
        cout << "I will crush your bones with my slime!\n";
    
    }
};

int main() {
    srand(time(0));     // seed the random number
    cout << "Slime Bettles\n";

    //create a slime
    baseSlime gerald;
    gerald.name = "Gerald";
    gerald.hello();

    bossSlime destroyer;
    destroyer.name = "destroyer";
    destroyer.hello();
    destroyer.taunt();

    cout << "Gerald is feeling cheeky...\n";
    gerald.attack(destroyer);

    cout << "Destroyer is enraged!\n";
    if(destroyer.attack(gerald)) {
        cout << "Gerald is no more. DED.\n";
    }

    // create a vector of slimes
    // than pick two to fight
    // global varibles

    // create a new vector of slime with a size of 6
    vector<baseSlime> sludge(6);

    if(true) {
        bossSlime superSlime;
        sludge.push_back(superSlime);
    }

    for(auto& slime : sludge) {
        cout << slime.name << "\n";
    }


    random_shuffle(sludge.begin, sludge.end());

    auto& a = sludge[0];    // a is equal to the second slime
    auto& b = sludge[1];    // b is equal to the second slime

    cout << a.name << " is fighting " << b.name << "!!!\n\n";

    while(a.health > 0 && b.health > 0) {
        if(a.attack(b)) {
            cout << b.name << " has been defeated by ";
            cout << a.name << ".\n";
        }
        else {
            if(b.attack(a)) {
                cout << a.name << " has been defeated by ";
                cout << b.name << ".\n";
            }
        }
    }


    return 0;
}