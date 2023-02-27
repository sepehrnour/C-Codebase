#include "Account.h"

Account::Account(std::string name, float balance)
{
    this->name = name;
    this->balance = balance;
}

std::string Account::getName()
{
    return this->name;
}

float Account::getBalance()
{
    return this->balance;
}

void Account::deposit(float amount)
{
    this->balance += amount;
}

void Account::withdraw(float amount)
{
    this->balance -= amount;
}