#include "Building.h"
#include <iostream>
#include <string>
#include <list>

using namespace std;




Building::Building(int maxAge, int initCost) : MaxAge(maxAge), InitialCost(initCost), CurrentAge(0) {
    static int idCounter = 1;  // ID counter
    ID = idCounter++;
}


void Building::ToAge(int years)
    {
        CurrentAge += years;
        if (CurrentAge >= MaxAge) {
            Destroy();  
        }
    }

void Building::ShowInfo() const
{
        cout << "Building ID: " << ID << ", Max Age: " << MaxAge << ", Initial Cost: " << InitialCost
            << ", Current Age: " << CurrentAge << ", Current Cost: " << GetCost() << endl;
}

int Building::GetCost() const 
{
    if (CurrentAge >= MaxAge)
    {
        return 0;  
    }
    return InitialCost * (MaxAge - CurrentAge) / MaxAge;
} // linear cost counter


void Building::Destroy() 
{
    cout << "The building with ID: " << GetId() << " has been destroyed." << endl;
}




