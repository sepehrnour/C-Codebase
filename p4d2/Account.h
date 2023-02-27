#include <string>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
using namespace std;
#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account
{
private:
    string username, status;

public:
    string getstatus() const;
    Account(string, string);

    Account(string);
    ~Account();
};
#endif