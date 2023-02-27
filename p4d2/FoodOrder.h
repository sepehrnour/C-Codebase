#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <fstream>
using namespace std;
#include "DeliveryOrder.h"
#ifndef FOODORDER_H
#define FOODORDER_H

class FoodOrder : public DeliveryOrder
{
private:
    string restaurantName;
    int foodCount;

public:
    FoodOrder(string, string, string, float, string);
    ~FoodOrder();
    void receipt() const;
    float VIPdiscount();
    void addFood(string, int, bool);
    void addFood(string);
};
#endif
