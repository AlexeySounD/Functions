#pragma once








class Building
{
public:
    // Constructor
    Building(int maxAge, int initCost);

    int GetMaxAge() const { return MaxAge; }
    int GetId() const { return ID; }
    int GetInitCost() const { return InitialCost; }
    int GetCurrentAge() const { return CurrentAge; }

    //Functions
    // Current building cost
    int GetCost() const;

    void ToAge(int years);

    // Building info
    void ShowInfo() const;

private:
    // Destroy Building
    void Destroy();

    int ID;
    int MaxAge;
    int InitialCost;
    int CurrentAge;
};