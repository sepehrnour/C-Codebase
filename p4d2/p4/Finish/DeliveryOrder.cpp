#include <string>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
using namespace std;
#include "DeliveryOrder.h"

float DeliveryOrder::OrderCount = 0;

// Constructor
DeliveryOrder::DeliveryOrder(string mName, string mDate, string mPhone, float mMiles){
    name = mName;
    date = mDate;
    phone = mDate;
    miles = mMiles;

    orderBalance = 0;
    OrderCount++;
}
float DeliveryOrder::getOrderCount(){
    return OrderCount;
}
// Destructor
DeliveryOrder::~DeliveryOrder(){
    cout << "DeliveryOrder destroyed." << endl;
}
// GetTotalBalance function
float DeliveryOrder::getTotalBalance() const{
    return orderBalance * (1 + taxRate) + miles * DeliveryRate;
}
// Receipt function 
void DeliveryOrder::receipt() const{
    cout << "Order Detail:" << "\n";
    cout << "\tName: " << name << "\n";
    cout << "\tDate: " << date << "\n";
    cout << "\tPhone: " << phone << "\n";
    cout << "\tOrder Balance: $" << orderBalance << endl;
}