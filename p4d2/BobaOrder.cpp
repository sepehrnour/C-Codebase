#include <string>
#include <iostream>
#include "DeliveryOrder.h"
#include "BobaOrder.h"
#include "InvalidInput.h"

using namespace std;


//Constructor
BobaOrder::BobaOrder(string name, string date, string phone, float miles, string shopName) : DeliveryOrder(name, date, phone, miles)
{
    this -> shopName = shopName;
    drinksCount = 0;
}

//BobaOrder receipt function modifier
void BobaOrder::receipt() const 
{
    DeliveryOrder::receipt();
    cout << "\tDrnks Count: "<< drinksCount <<endl;
}

//addDrink by drinkName and save drinkPrice and drinkCount function includes InvalidInput throw
void BobaOrder::addDrink(string drinkName)
{
    float drinkPrice = 0.00;

        if(drinkName == "Green Tea Latte")
        {
            drinkPrice += 5.80;
        }
        else if(drinkName == "Brown Sugar Boba Milk")
        {
            drinkPrice += 7.80;
        }
        else if(drinkName == "Brown Sugar Pearl Milk")
        {
            drinkPrice += 9.80;
        }
        else
        {
            throw InvalidInput(drinkName);
            drinksCount--;
        }
    if(drinkPrice > 0)
    {
        orderBalance =+ (drinkPrice + 1.5);
    }

    drinksCount += 1;
}

//addDrink function including boba bool and count int with InvalidInput throw
void BobaOrder::addDrink(string drinkName, bool boba, int count)
{
    float drinkPrice = 0.00;

        if(drinkName == "Green Tea Latte")
        {
            drinkPrice += 5.80;
        }
        else if(drinkName == "Brown Sugar Boba Milk")
        {
            drinkPrice += 7.80;
        }
        else if(drinkName == "Brown Sugar Pearl Milk")
        {
            drinkPrice += 9.80;
        }
        else
        {
            throw InvalidInput(drinkName);
            drinksCount--;
        }
    if(boba==true)
    {
        orderBalance += (drinkPrice + 1.5) * count;
    }
    else
    {
        orderBalance += (drinkPrice) * count;
    }

    drinksCount += count;
}

//BobaOrder VIPdiscount function modifier
float BobaOrder::VIPdiscount()
{
    if (drinksCount > 10)
    {
        return 0.85;
    }
    else if (drinksCount > 5)
    {
        return 0.9;
    }
    else if (drinksCount > 2)
    {
        return 0.95;
    }
    else if (drinksCount <= 2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//Destructor
BobaOrder::~BobaOrder()
{
    cout << "BobaOrder destroyed." <<endl;
}

int BobaOrder::drinksCount = 0;