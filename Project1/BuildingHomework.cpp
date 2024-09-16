#include <iostream>
#include <string>
#include <list>
#include "Building.h"
using namespace std;



// Functions Headers
void CreateNewBuilding(list<Building*>& buildings);
void ShowAllBuildings(const list<Building*>& buildings);
Building* GetBuildingById(const list<Building*>& buildings, int id);
void ShowMessage(const string& message);

int main() {
    bool GameStart = true;
    list<Building*> buildings;

    int command;
    cout << "Welcome to the building cost sim! \n\n";

    while (GameStart) 
    {
        cout << "To create new building press 0\n";
        cout << "To add age to a specific building press 1\n";
        cout << "To check the cost of a specific building press 2\n";
        cout << "To show all buildings press 3\n";
        cout << "To exit press 4\n";

        cin >> command;
        system("cls");

        if (command == 0) {
            CreateNewBuilding(buildings);
        }
        else if (command == 1) {
            ShowAllBuildings(buildings);
            cout << "Enter the building ID to add age: ";
            int id, years;
            cin >> id;
            Building* building = GetBuildingById(buildings, id);
            if (building) {
                cout << "Enter the number of years to add: ";
                cin >> years;
                building->ToAge(years);
            }
            else {
                cout << "Building with ID " << id << " not found!" << endl;
            }
            system("pause");
        }
        else if (command == 2) {
            ShowAllBuildings(buildings);
            cout << "Enter the building ID to check its cost: ";
            int id;
            cin >> id;
            Building* building = GetBuildingById(buildings, id);
            if (building) {
                cout << "Building ID: " << building->GetId() << ", Current Cost: " << building->GetCost() << endl;
            }
            else {
                cout << "Building with ID " << id << " not found!" << endl;
            }
            system("pause");
        }
        else if (command == 3) {
            ShowAllBuildings(buildings);
            system("pause");
        }
        else if (command == 4) {
            GameStart = false;
        }
        system("cls");
    }

    cout << "Thanks for playing! \n";
    system("pause");

  
    return 0;
}

// Create new building function
void CreateNewBuilding(list<Building*>& buildings) {
    int maxAge, initCost;
    cout << "Enter the building's max age: ";
    cin >> maxAge;
    cout << "Enter the building's initial cost: ";
    cin >> initCost;

    Building* newBuilding = new Building(maxAge, initCost);
    buildings.push_back(newBuilding);
    ShowMessage("Congratulations! You created a new building:");
    newBuilding->ShowInfo();
    system("pause");
}

// Show list of buildings
void ShowAllBuildings(const list<Building*>& buildings) {
    if (buildings.empty()) {
        cout << "No buildings available.\n";
    }
    else {
        for (const Building* building : buildings) {
            building->ShowInfo();
        }
    }
}

// Get buildings from ID
Building* GetBuildingById(const list<Building*>& buildings, int id) {
    for (Building* building : buildings) {
        if (building->GetId() == id) {
            return building;
        }
    }
    return nullptr;
}

// ShowMessage function
void ShowMessage(const string& message) {
    system("cls");
    cout << message << endl;
}