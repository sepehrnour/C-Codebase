#include <string>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
using namespace std;
#include "Account.h"

Account::Account(string musername){
    username = musername;
    status = "regular";
}

Account::Account(string musername, string mstatus){
    username = musername;
    status = mstatus;
}

Account::~Account(){
    cout << "Account removed." << endl;
}

string Account::getstatus() const{
    return status;
}