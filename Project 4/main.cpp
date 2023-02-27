using namespace std;
#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <iomanip>
#include "DeliveryOrder.h"
#include "BobaOrder.h"
#include "FoodOrder.h"
#include "Account.h"
#include "InvalidInput.h"


int main()
{

  Account stuart("Staurt", "Owner");
  Account kevin("Kevin", "VIP");
  Account bob("Bob", "");

  DeliveryOrder *d;

  cout << "Kevin placing order.\n";

BobaOrder b("Kevin","123 Flower

Way","New York, NY 10014","123-456-0000",2,11,2020,10.4,"Bar Pa Tea");

d=&b;

try{
    b.addDrink("Matcha Lemonade");
    b.addDrink("Lemon Green Tea", false);
    b.addDrink("Brown Sugar Oolong Tea", false, 2);
    b.addDrink("Iron Goddess");
}
catch(InvalidInput& e){
    e.reason();
    cout << "Not serving requested drinks. Drink order ignored.\n\n";
}

b.printReceipt();
cout<<"Balance: $"<<b.getTotalBalance()<<endl;
cout<<"Discounted Balance: $"<<applyDiscount(d,kevin)<<"\n\n\n";

cout<<"Stuart placing order\n";

FoodOrder f("Stuart","123 Flower Way","New York, NY 10014","123-456-1111",2,11,2020,25.5,"Trauts Steak House");

d=&f;

try{
    f.addFood("Bone-in Ribeye", true, 2);
    f.addFood("Grilled Salmon", false, 1);
    f.addFood("Beyond Meat Burger", true, 3);
}
catch(InvalidInput& e){
    e.reason();
    cout << "Not serving requested food. Food order ignored.\n\n";
}
f.printReceipt();
cout<<"Balance: $"<<f.getTotalBalance()<<endl;
cout<<"Discounted Balance: $"<<applyDiscount(d,stuart)<<"\n\n\n";

cout<<"Bob decided to log in to his account and see whether he can afford ordering the same order as Stuart.\n";
f.printReceipt();
cout<<"Balance: $"<<f.getTotalBalance()<<endl;
cout<<"Discounted Balance: $"<<applyDiscount(d,bob)<<endl;
cout<<"Bob upset, cancelling order :( \n\n\n";

cout<<"Total order placed: "<<d->getOrderCount()<<"\n\n\n";


return 0;
}