#include <iostream>
#include <string>
#include "InvalidInput.h"
#include "DeliveryOrder.h"
#ifndef BOBA_ORDER_H
#define BOBA_ORDER_H

class BobaOrder : public DeliveryOrder
{
private:
    strd::string shopName;
    static int drinksCount;

public:
    // constructor
    BobaOrder(string name, string date, string phone, float miles, string shopName, int drinksCount)
        : DeliveryOrder(name, date, phone, miles)

          // printReceipt function
          const printReceipt()
    {
        DeliveryOrder::printReceipt();
        cout << "\tOrdered Drinks: " << drinksCount << endl;
    }

    // overridding discount function
    float discount()
    {
        if (drinksCount > 10)
        {
            return 0.8;
        }
        else if (drinksCount > 5)
        {
            return 0.9;
        }
        else if (drinksCount > 2)
        {
            return 0.95;
        }
        else
        {
            return 1;
        }
    }

    // addDrink function
    void addDrink(string nameOfDrink, bool boba = true, int count = 1)
    {
        if (nameOfDrink == "Green Tea Latte")
        {
            if (boba == true)
            {
                balance += (5.8 + 1.5) * count;
            }
            else
            {
                balance += 5.8 * count;
            }
            drinksCount += count;
        }
        else if (nameOfDrink == "Brown Sugar Boba Milk")
        {
            if (boba == true)
            {
                balance += (7.8 + 1.5) * count;
            }
            else
            {
                balance += 7.8 * count;
            }
            drinksCount += count;
        }
        else if (nameOfDrink == "Brown Sugar Pearl Milk")
        {
            if (boba == true)
            {

                balance += (9.8 + 1.5) * count;
            }
            else
            {
                balance += 9.8 * count;
            }
            drinksCount += count;
        }
        else
        {
            throw InvalidInput(nameOfDrink);
        }
    }

    // destructor
    ~BobaOrder()
    {
        cout << "BobaOrder destroyed.\n";
    }
};

int BobaOrder::drinksCount = 0;
#endif
