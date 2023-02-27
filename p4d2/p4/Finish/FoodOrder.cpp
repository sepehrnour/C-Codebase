#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <fstream>
using namespace std;
#include "DeliveryOrder.h"
#include "FoodOrder.h"
#include "InvalidInput.h"

// FoodOrder class inheriting from DeliveryOrder class
FoodOrder::FoodOrder(string mName, string mDate, string mPhone, float mMiles, string mrestrauntName) : DeliveryOrder(mName, mDate, mPhone, mMiles)
{
    restaurantName = mrestrauntName;

    foodCount = 0;
}
FoodOrder::~FoodOrder()
{
    cout << "FoodOrder destroyed." << endl;
}
void FoodOrder::receipt() const
{
    DeliveryOrder::receipt();

    cout << "\tFood Count : " << foodCount << endl;
}
// FoodOrder addfood function enter foodname, soup and sideamounts, saves foodPrice and foodCount; throws InvalidInput
void FoodOrder::addFood(string foodName, int sideAmount, bool addSoup)
{
    int foodPrice = 0;
    foodCount++;
    try
    {
        if (foodName == "Thick Cauliflower Steak")
        {
            foodPrice += 15;
        }
        else if (foodName == "Rack of Lamb")
        {
            foodPrice += 28;
        }
        else if (foodName == "Organic Scottish Salmon")
        {
            foodPrice += 23;
        }
        else if (foodName == "Grilled Lobster Risotto")
        {
            foodPrice += 46;
        }

        else
        {
            throw InvalidInput(foodName);
        }
    }
    catch (InvalidInput)
    {
        cout << "Not serving requested food.Food order ignored.\n\n"
             << endl;
        foodCount--;
    }
    if (foodPrice > 0)
    {
        if (addSoup = true)
        {
            orderBalance += foodPrice + 5 + (sideAmount * 6);
        }
        else if (addSoup = false)
        {
            orderBalance += foodPrice + (sideAmount * 6);
        }
    }
}
// FoodOrder addfood function enter by foodname, catch InvalidInput, save foodCount and foodPrice
void FoodOrder::addFood(string foodName)
{
    int foodPrice = 0;

    foodCount++;

    try
    {
        if (foodName == "Thick Cauliflower Steak")
        {
            foodPrice += 15;
        }
        else if (foodName == "Rack of Lamb")
        {
            foodPrice += 28;
        }
        else if (foodName == "Organic Scottish Salmon")
        {
            foodPrice += 23;
        }
        else if (foodName == "Grilled Lobster Risotto")
        {
            foodPrice += 46;
        }
        else
        {
            throw InvalidInput(foodName);
        }
    }
    catch (InvalidInput)
    {
        cout << "Not serving requested food. Food order ignored.\n\n"
             << endl;
        foodCount--;
    }

    if (foodPrice > 0)
    {
        orderBalance += foodPrice;
    }
}
// FoodOrder VIPdiscount function logic
float FoodOrder::VIPdiscount()
{
    if (orderBalance > 50)
    {
        return 0.85;
    }
    else if (orderBalance > 30)
        return 0.9;

    else if (orderBalance > 20)
    {
        return 0.95;
    }
    else
    {
        return 1;
    }
}
