#ifndef FOODORDER_H
#define FOODORDER_H
#include <iostream>
#include <string>
#include "InvalidInput.h"
#include "DeliveryOrder.h"

class FoodOrder : public DeliveryOrder
{
private:
    std::string restaurantName;
    int foodCount;

public:

    FoodOrder(std::string name, std::string date, std::string phone, float miles, std::string restaurantName) :  
    DeliveryOrder{name, date, phone, miles, orderCount, month, year, miles}
  {
    restaurantName = restaurantName;
  }


    void addFood(std::string foodName, int sideDishCount = 0, int count = 1);
    float VIPdiscount() override;
    void receipt() override;

  const printReceipt()
  {
    DeliveryOrder::printReceipt();
    cout << "\tOrdered Foods: " << foodCount << endl;
  }

  // overridding discount function
  float discount()
  {
    if (balance > 50)
    {
      return 0.8;
    }
    else if (balance > 30)
    {
      return 0.9;
    }
    else if (balance > 20)
    {
      return 0.95;
    }
    else
    {
      return 1;
    }
  }

  // addFood function
  void addFood(string nameOfMeat, bool soup = false, int count = 0)
  {
    if (nameOfMeat == "Bone-in Ribeye")
    {
      if (soup == true)
      {
        balance += 32 + (count * 1) + 0.5;
      }
      else
      {
        balance += 32 + (count * 1);
      }
      foodCount++;
    }
    else if (nameOfMeat == "Rack of Lamb")
    {
      if (soup == true)
      {
        balance += 28 + (count * 1) + 0.5;
      }
      else
      {
        balance += 28 + (count * 1);
      }

      foodCount++;
    }
    else if (nameOfMeat == "Grilled Salmon")
    {
      if (soup == true)
      {
        balance += 24 + (count * 1) + 0.5;
      }
      else
      {
        balance += 24 + (count * 1);
      }
      foodCount++;
    }
    else if (nameOfMeat == "Beyond Meat Burger")
    {
      if (soup == true)
      {
        balance += 22 + (count * 1) + 0.5;
      }
      else
      {
        balance += 22 + (count * 1);
      }
      foodCount++;
    }
    else
    {
      throw InvalidInput(nameOfMeat);
    }
  }

  // destructor
  ~FoodOrder()
  {
    cout << "FoodOrder destroyed.\n";
  }

int FoodOrder::foodCount = 0;


};
#endif