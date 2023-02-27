#include <string>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
using namespace std;
#ifndef DELIVERYORDER_H
#define DELIVERYORDER_H

class DeliveryOrder
{
    private:
    string name;
    string date;
    string phone;
    float miles;
    static float OrderCount;
    const float taxRate = 0.09;
    const float DeliveryRate = 1.50;

    protected:
    float orderBalance;

    public:
    float gettaxRate() const;
    float getDeliveryRate() const;

    static float getOrderCount();

    void receipt() const;

    float getTotalBalance() const;

    virtual float VIPdiscount() = 0;

    DeliveryOrder(string, string, string, float);
    ~DeliveryOrder();
};
#endif