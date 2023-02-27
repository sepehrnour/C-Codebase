#include <iostream>
#include <string>
using namespace std;

//Defining struct for user
struct userAccount {
    string username;
    string nationality;
    int age;
    float accountBalance;
};

int main() {
    //Creating an array of total 10 user accounts under array name accts
    userAccount accts[10];

    //Ask for user input by outputting user requirements
    cout << "Enter username and age, serperating with space: " << endl;

    //Defining variables from struct for use in main function 
    string username;
    string nationality;
    int age;
    float accountBalance;
    int userCount = 0;
    //Defining variables for output questions
    float highestBalance = 0.0;
    float balanceSum = 0.0;
    int usersFromJapan = 0;
    int under18 = 0;
    //Start while loop for user entry into array
    while (cin >> username >> nationality >> age >> accountBalance){
        userAccount user;
        user.username = username;
        user.nationality = nationality;
        user.age = age;
        user.accountBalance = accountBalance;
        accts[userCount] = user;
        userCount++;

    }
    //for loop to check for highest balance
    for (int i = 0; i < userCount; i++){
        if (highestBalance < accts[i].accountBalance){
            highestBalance = accts[i].accountBalance;
        }
    }
     //for loop to check for total balance summed
    for (int i = 0; i < userCount; i++){
        balanceSum += accts[i].accountBalance;
    }
     //for loop to check for number of Japanese users
    for (int i = 0; i < userCount; i++){
        if (accts[i].nationality == "Japanese")
        {
            usersFromJapan++;
        }
    }
     //for loop to check for underage users
    for (int i = 0; i < userCount; i++){
        if (accts[i].age < 18)
        {
            under18++;
        }
    }
    //Output of questions from user account
    cout << "Q: What is the highest account balance among all users?" << endl;
    cout << "A:$ " << highestBalance << endl << endl;
    cout << "Q: What's the sum of account balance of all users?" << endl;
    cout << "A:$ " << balanceSum << endl << endl;
    cout << "Q: How many users come from Japan?" << endl;
    cout << "A: " << usersFromJapan << endl << endl;
    cout << "Q: Do we have any user younger than 18?" << endl;
    if (under18 > 0)
    {
        cout << "A: Yes" << endl << endl;
    }
    else
    {
        cout << "A: No" << endl << endl;
    }
    return 0;
}