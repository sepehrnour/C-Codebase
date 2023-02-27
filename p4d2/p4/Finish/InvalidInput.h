#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <fstream>
using namespace std;
#ifndef INVALIDINPUT_H
#define INVALIDINPUT_H

// Class definition
class InvalidInput
{
    // Members
private:
    const string message;

public:
    InvalidInput(string input) : message("Invalid input \"" + input + "\".\n")
    {
    }

    void print_reason()
    {
        cout << message;
    }
};
#endif