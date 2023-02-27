#include <iostream>
#include "minion.h"
using namespace std;

// Set the minionCount to 0
int Minion::minionCount = 0;

// Default constructor
Minion::Minion(){}

// Parameterized constructor
Minion::Minion(string n, float h, int e, int b)
{
    // Set name, height & bananasOwned
    name = n;
    height = h;
    eyes = e;
    bananasOwned = b;
    
    // Increase minion count by 1
    minionCount++;
}

// Getter to get the name of the minion
string Minion::getName() const
{
    return name;
}

// Getter to get the number of bananas 
int Minion::getBananas()
{
    return bananasOwned;
}

// Static member function to print minion created
void Minion::printMinionCount()
{
    cout << minionCount << " minions created." << endl;
}

// Overload > operator to check first minion height is greater than second Minion
bool Minion::operator>(const Minion &m) const
{
	if(height > m.height)
		return true;
	else
	    return false;
}

// Overload > operator to check first minion height is smaller than second Minion
bool Minion::operator<(const Minion &m) const
{
	if(height < m.height)
		return true;
	else
	    return false;
}

// Overload pre-increment operator to increase eyes by 1
Minion &Minion::operator++() 
{
    ++bananasOwned;
    return *this;
}

// Overload post-increment operator to increase eyes by 1
Minion Minion::operator++(int) 
{
    Minion temp;
    temp.bananasOwned = bananasOwned++;
    return temp;
}

// Overload insertion operator for output
ostream &operator<< (ostream &out, const Minion &m)
{
	out << "The minion " << m.name << " is " << m.height << " inches tall, has "<< m.eyes << " eye(s) and owns " << m.bananasOwned << " banana(s).\n";
	return out;
}

