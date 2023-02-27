#include <string>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
using namespace std;
#include "Account.h"

// Constructor
Account::Account(string musername)
{
    username = musername;
    status = "regular";
}

Account::Account(string musername, string mstatus)
{
    username = musername;
    status = mstatus;
}

// Destructor
Account::~Account()
{
    cout << "Account removed." << endl;
}

// Account class getstatus function
string Account::getstatus() const
{
    return status;
}