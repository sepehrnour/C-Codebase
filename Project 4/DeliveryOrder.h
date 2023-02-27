//Header File for DeliveryOrder
#include <iostream>
#include <string>
#include "InvalidInput.h"
#ifndef DELIVERYORDER_H
#define DELIVERYORDER_H


class DeliveryOrder {
    private:
        std::string name;
        std::string date;
        std::string phone;
        float miles;
        float orderBalance;
        static int orderCount;
        void receipt();
        float getTotalBalance();
        static int getOrderCount();
        virtual float VIPdiscount() = 0;
    protected:
        float getOrderBalance();
    public:
        static const float taxRate = 0.09;
        static const float deliveryRate = 1.5;
    
    DeliveryOrder(string name, string date, string phone, float miles, float orderBalance)
  {

    name = name;
    phone = phone;
    date = date;
    miles = miles;
    orderBalance = 0;
    orderCount++;
  }

// printReceipt function
  const printReceipt()
  {
    cout << "Order Detail:" << "\n";
    cout << "\tName: " << name << "\n";
    cout << "\tDate: " << date << "\n";
    cout << "\tPhone: " << phone << "\n";
    cout << "\tOrder Balance: $" << orderBalance << endl;
  }

  // getTotalBalance function
  const float getTotalBalance()
  {
    return orderBalance * (1 + taxRate) + miles * deliveryRate;
  }

  // static getOrderCount function
  static getOrderCount()
  {

    return orderCount;
  }

  // pure virtual discount function
  virtual float discount()
  {
  }

  // destructor
  ~DeliveryOrder()
  {
    cout << "DeliveryOrder destroyed.\n";
  }
}

int DeliveryOrder::orderCount = 0;
#endif