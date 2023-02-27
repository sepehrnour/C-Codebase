#include "FoodOrder.h"
#include "DeliveryOrder.h"
#include 

// Constructor
FoodOrder::FoodOrder(std::string name, std::string date, std::string phone, float miles, std::string restaurantName)
    : DeliveryOrder(name, date, phone, miles)
{
    this->restaurantName = restaurantName;
    this->foodCount = 0;
}

