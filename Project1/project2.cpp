#include <iostream>
#include <string>
using namespace std;

//Structure for user account defined

struct userAccount {
    string username;
    string nationality;
    int age;
    float account_bal;
};

int main() {

    //Define an array of user accounts size of 10

    userAccount accts[10];

    //Ask for user input provided at while loop

    cout << "Enter username and age, serperating with space: " << endl;

    //Struct variable redefiniton in main 

    string username;
    string nationality;
    int age;
    float account_bal;
    int  userCount = 0;

    //Variables key to output questions defined

    float highestBalance = 0.0;
    float balanceSum = 0.0;
    int usersFromJapan = 0;
    int underage = 0;

    //While loop starts entry of a user account

    while (cin >> username >> nationality >> age >> account_bal){
        userAccount user;
        user.username = username;
        user.nationality = nationality;
        user.age = age;
        user.account_bal = account_bal;
        accts[userCount] = user;
        userCount++;

    }

    //Highest balance for loop

    for (int i = 0; i < userCount; i++){
        if (highestBalance < accts[i].account_bal){
            highestBalance = accts[i].account_bal;
        }
    }

    //Balance sum for loop

    for (int i = 0; i < userCount; i++){
        balanceSum += accts[i].account_bal;
    }

    //Japanese user for loop

    for (int i = 0; i < userCount; i++){
        if (accts[i].nationality == "Japanese")
        {
            usersFromJapan++;
        }
    }

    //Underage users for loop
    for (int i = 0; i < userCount; i++){
        if (accts[i].age < 18)
        {
            underage++;
        }
    }

    //Questions and variable answers outputted from calculations

    cout << "Q: What is the highest account balance among all users?" << endl;
    cout << "A:$" << highestBalance << endl << endl;
    cout << "Q: What's the sum of account balance of all users?" << endl;
    cout << "A:$" << balanceSum << endl << endl;
    cout << "Q: How many users come from Japan?" << endl;
    cout << "A:" << usersFromJapan << endl << endl;
    cout << "Q: Do we have any user younger than 18?" << endl;
    if (underage > 0)
    {
        cout << "A: Yes" << endl << endl;
    }
    else
    {
        cout << "A: No" << endl << endl;
    }
    return 0;
}