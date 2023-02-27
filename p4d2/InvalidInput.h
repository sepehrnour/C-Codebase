#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <fstream>
using namespace std;
#ifndef INVALIDINPUT_H
#define INVALIDINPUT_H

class InvalidInput
{
private:
    const string message;

public:
    InvalidInput(string input) : message("Invalid input \"" + input + "\".\n") {
        // Constructor body
    }

    void print_reason() {
        cout << message;
    }    
};
#endif