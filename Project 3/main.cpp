// Used for input & output functions
#include <iostream>
#include <fstream>
// Include Minion.h
#include "minion.h"
#include "minion.cpp"

using namespace std;

// Main function
int main()
{
    // Used to store name, height & bananaOwned
    string name;
    float height = 0;
    int eyes = 0;
    int bananasOwned = 0;
    ifstream minionsFile("minions.txt");
    if(!minionsFile.is_open()) {
        cout << "File failed to open" << endl;
        return 0;
    }
    // Take the name, height, eyes, and bananasOwned for the first minion
    minionsFile >> name >> height >> eyes >> bananasOwned;
    // Create first minion
    const Minion minion1(name, height, eyes, bananasOwned);
    // Take the name, height, eyes, and bananasOwned for the second minion
    minionsFile >> name >> height >> eyes >> bananasOwned;
    // Create second minion
    Minion minion2(name, height, eyes, bananasOwned);
    // Take the name, height, eyes, and bananasOwned for the third minion
    minionsFile >> name >> height >> eyes >> bananasOwned;
    // Create third minion
    Minion minion3(name, height, eyes, bananasOwned);

    //Finding the taller minion
    if (minion1 > minion2) {
    cout << minion1.getName() << " is taller than " << minion2.getName();
    } 
    if (minion2 < minion3) {
    cout << minion3.getName() << " is taller than " << minion2.getName();
    }
    cout << endl << endl;
    
    //Minion2 getname and gets 2 bananas
    cout << minion2;
    cout << minion2.getName() << " getting bananas.\n";
    cout << "The minion now has " << (++(++minion2)).getBananas() << " banana(s).\n" << endl;

    //Minion3 getname and bananas
    cout << minion3;
    cout << minion3.getName() << " getting bananas.\n";
    cout << "Before getting bananas, the minion had " << minion3++.getBananas() << " banana(s).\n";
    cout << "After getting bananas, the minion has " << minion3.getBananas() << " banana(s).\n" << endl;
    
    //Minion count print
    minion3.printMinionCount();
    return 0;
}
