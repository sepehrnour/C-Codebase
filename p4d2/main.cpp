#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <fstream>
using namespace std;
#include "DeliveryOrder.h"
#include "InvalidInput.h"
#include "FoodOrder.h"
#include "BobaOrder.h"
#include "Account.h"
#include "DeliveryOrder.cpp"
#include "FoodOrder.cpp"
#include "BobaOrder.cpp"
#include "Account.cpp"

float applyDiscount(DeliveryOrder *, const Account &);

int main()
{
    // Pointer for DeliveryOrder object
    DeliveryOrder *ptr;
    const Account Stuart("Stuart", "Owner"); // Account object for Stuart
    Account Kevin("Kevin", "VIP");           // Account object for Kevin
    Account Bob("Bob");                      // Account object for Bob
    cout << fixed << setprecision(2);

    cout << "Kevin placing order. \n";
    BobaOrder d1("Kevin", "11/20/2022", "123-456-0000", 10.40, "M Tea");
    // BobaOrder object for Kevin's order
    ptr = &d1;

    // Adding drinks to order with InvalidInput Catch
    try
    {
        d1.addDrink("Green Tea Latte", true, 1);
        d1.addDrink("Brown Sugar Pearl Milk", false, 1);
        d1.addDrink("Brown Sugar Boba Milk", false, 2);
        d1.addDrink("Iron Goddess", false, 0);
    }
    catch (InvalidInput &somp)
    {
        somp.print_reason();
        cout << "Not serving requested drinks. Drink order ignored. \n"
             << endl;
    }
    // Print Kevin Receipt
    d1.receipt();
    cout << "Balance: $" << ptr->getTotalBalance() << endl;
    cout << "Discounted Balance: $" << applyDiscount(ptr, Kevin) << "\n"
         << endl;
    cout << "Start placing order. \n";
    FoodOrder d2("Stuart", "11/20/2022", "123-456-1111", 25.5, "Tavern Green");
    // BobaOrder object for Stuart's order
    ptr = &d2;
    // Adding drinks to order with InvalidInput Catch
    try
    {
        d2.addFood("Thick Cauliflower Steaks", 1, true);
        d2.addFood("Organic Scottish Salmon");
        d2.addFood("Rack of Lamb", 0, true);
    }
    catch (InvalidInput &tomp)
    {
        tomp.print_reason();
        cout << "Not serving requested food. Food order ignored. \n"
             << endl;
    }
    // Print Stuart Receipt
    d2.receipt();

    cout << "Balance: $" << ptr->getTotalBalance() << endl;
    cout << "Discounted Balance: $" << applyDiscount(ptr, Stuart) << "\n"
         << endl; // He gets a discount because he is a VIP and

    cout << "Bob decided to log in to his account and see whether he can afford ordering the same order as Stuart. \n";
    d2.receipt();
    cout << "Balance: $" << ptr->getTotalBalance() << endl;
    cout << "Discounted Balance: $" << applyDiscount(ptr, Bob) << endl;
    cout << "Bob upset, canceling order :(\n\n";
    cout << "Total order placed: " << ptr->getOrderCount() << "\n"
         << endl; // This line prints how many orders were placed
    return 0;
}

// Function to apply discounts to the order based on the Account status of the customer
float applyDiscount(DeliveryOrder *Pptr, const Account &Temp)
{
    if (Temp.getstatus() == "Owner")
    {
        return (0.1 * Pptr->getTotalBalance());
    }
    else if (Temp.getstatus() == "VIP")
    {
        return (Pptr->VIPdiscount() * Pptr->getTotalBalance());
    }
    else
    {
        return (Pptr->getTotalBalance());
    }
}