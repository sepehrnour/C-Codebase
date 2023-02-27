#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
using namespace std;

//Define matrix power function to calculate total power 
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

//Template function for single missile power based on single enemy-power input variable
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

//First void function that determines and loads maxtrix power required by defense matrix using pass by reference
void load_dva(float &defenseMatrix , float matrixPowerRequired)
{
    if (matrixPowerRequired > defenseMatrix )
        defenseMatrix  = matrixPowerRequired;
}

//Second void function that determines and loads the missile power required using pass by reference
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
    //Define number of bots, bosspower, microMissile count and defenseMatrix power
    int botsCount;
    combatFile >> botsCount;
    float bossPower;
    int microMissiles;
    float defenseMatrix ;

    //Initializing the array of botsPower
    int* botsPower = new int[botsCount];
    //Iterating through the array reading from combat file and defining bot power atribute at designated index 
    for (int i = 0; i < botsCount; i++)
    {
        combatFile >> botsPower[i];
    }

    //Combatfile reading the bosspower, microMissile count, and defenseMatrix power
    combatFile >> bossPower >> microMissiles >> defenseMatrix ;

    //Call matrix power function to determine power required
    float matrixPowerRequired = matrix_power(botsPower, botsCount, bossPower);

    //Define missile power required variable to determine power required
    float missilePowerRequired = 0;
    //Iterate through botsCount while adding the output of single_missile_power function for every botsPower input
    for (int i = 0; i < botsCount; i++)
    {
        missilePowerRequired += single_missile_power(botsPower[i]);
    }
    missilePowerRequired += single_missile_power(bossPower);

    //Loading maxtrix power required by defense matrix 
    load_dva(defenseMatrix , matrixPowerRequired);

    //Loading missile power required by defense matrix 
    load_dva(microMissiles, missilePowerRequired);

    //Generate report file named "report.txt" which includes D.Va's full combat report 
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