#include <string>
#include <iostream>
#include "InvalidInput.h"
#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account
{
private:
  string username, status;

public:
  // constructor
  Account(string username, string status = "")
  {
    username = username;
    status = status;
  }

  // getter function for Status
  const string getStatus()
  {
    return status;
  }

  // destructor
  ~Account()
  {
    cout << "Account removed.\n";
  }
};

// applyDiscount function
float applyDiscount(DeliveryOrder *d, Account &a)
{
  if (a.getStatus() == "Owner")
  {
    return round(d->getTotalBalance() * 0.1);
  }
  else if (a.getStatus() == "VIP")
  {
    return round(d->getTotalBalance() * d->discount());
  }
  else
  {
    return round(d->getTotalBalance());
  }
}

#endif