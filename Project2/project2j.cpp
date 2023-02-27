#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
using namespace std;

//Create matrix power function to calculate total power 
float matrix_power(int botPower[], int botsCount, float bossPower)
{
    float total = 0;
    for (int i = 0; i < botsCount; i++)
    {
        total += botPower[i];
    }
    total += bossPower;
    return total;
}

//Define template function
template <typename T>
T single_missile_power(T enemyPower)
{
    if (enemyPower <= 10)
    {
        return (2 * enemyPower);
    }
    else if (enemyPower > 10)
    {
        return (5 * enemyPower);
    }
    return 0;
}

//First void function that loads maxtrix power using pass by reference
void load_dva(float &defenseMatrix , float matrixPowerRequired)
{
    if (matrixPowerRequired > defenseMatrix )
        defenseMatrix  = matrixPowerRequired;
}

//Second void function that loads the missile power using pass by reference
void load_dva(int &microMissiles, float missilePowerRequired)
{
    int missilesNeeded = ceil(missilePowerRequired / 80);
    if (missilesNeeded > microMissiles)
    {
        microMissiles = missilesNeeded;
    }
}

//Main function 
int main()
{
    //Open combat file
    ifstream combatFile("combat.txt");
    //Check file open successfully
    if(!combatFile.is_open()) {
        cout << "File failed to open" << endl;
        return 0;
    }
    //Define core global variables
    int botsCount;
    combatFile >> botsCount;
    float bossPower;
    int microMissiles;
    float defenseMatrix ;

    //Initializing botsPower array based on botsCounts variable
    int* botsPower = new int[botsCount];
    //Stepping through array reading from file to define botsPower array  
    for (int i = 0; i < botsCount; i++)
    {
        combatFile >> botsPower[i];
    }

    //Reading the bosspower, microMissile count, and defenseMatrix power from combatFile
    combatFile >> bossPower >> microMissiles >> defenseMatrix ;

    //Matrix power function call 
    float matrixPowerRequired = matrix_power(botsPower, botsCount, bossPower);

    //Missile power required variable defined
    float missilePowerRequired = 0;

    //Add the output of single_missile_power function for every botsPower input
    for (int i = 0; i < botsCount; i++)
    {
        missilePowerRequired += single_missile_power(botsPower[i]);
    }
    missilePowerRequired += single_missile_power(bossPower);

    //Load maxtrix power required by defense matrix 
    load_dva(defenseMatrix , matrixPowerRequired);

    //Load missile power required by defense matrix 
    load_dva(microMissiles, missilePowerRequired);

    //Create report file named "report.txt" which includes D.Va's full combat report 
    ofstream reportFile("report.txt", ios::out);
    reportFile << "D.Va's Combat Report\n";
    reportFile << "Combat with " << botsCount << " enemy bots and one enemy boss with power " << bossPower << ".\n";
    reportFile << "Loaded mech with " << microMissiles << " micro missiles and the defense matrix with power " << defenseMatrix << endl;
    reportFile << "Ready for combat!";
    
    //Close open files
    combatFile.close();
    reportFile.close();

    return 0;
}