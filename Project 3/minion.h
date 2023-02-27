#ifndef MINION_H
#define MINION_H

#include <iostream>
using namespace std;

// Create a class Minion
class Minion
{
    // Used to store name
    string name;
    
    // Used to store height
    float height;

    // Used to store eyes
    int eyes;
    
    // Used to store bananasOwned
    int bananasOwned;
    
    // Used to store minion count
    static int minionCount;
    
    public:
        
        // Default constructor
        Minion();
        
        // Parameterized constructor
        Minion(string n, float h, int e, int b);
        
        // Getter to get the height of minion
        string getName() const;

        int getBananas();
        
        // Static member function to print minion created
        static void printMinionCount();
        
        // Overload > operator to check first minion height is greater than second Minion
        bool operator>(const Minion &m) const;
        
        // Overload > operator to check first minion height is smaller than second Minion
        bool operator<(const Minion &m) const;
        
        // Overload pre-increment operator to increase height by 1
        Minion& operator++();
        
        // Overload post-increment operator to increase height by 1
        Minion operator++(int); 
        
        // Overload insertion operator for output
        friend ostream& operator<<(ostream& out, const Minion& m);
};

#endif