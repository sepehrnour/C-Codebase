#include <string>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
using namespace std;
#include "DeliveryOrder.h"
#ifndef BOBAORDER_H
#define BOBAORDER_H

class BobaOrder : public DeliveryOrder
{
private:
    string shopName;
    static int drinksCount;

public:
    // Constructor
    BobaOrder(string, string, string, float, string);
    // Destructor
    ~BobaOrder();

    void receipt() const;

    void addDrink(string, bool, int);
    void addDrink(string);

    float VIPdiscount();
};

#endif
