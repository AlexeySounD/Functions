#include <string>
#include <iostream>
using namespace std;

//Version 1
enum CharacterState { Healed, Damaged, Dead };

int CharacterHealthUpdate(float& health, float impact, CharacterState state);
int DistanceCalculation(float impact, float distance);

int main()
{
    float CharacterHealth;
    float ItemImpact;
    float ItemDistance;

    cout << "Please write a number of Character Health: ";
    cin >> CharacterHealth;

    cout << "Please write a number of Character Impact: ";
    cin >> ItemImpact;

    cout << "Please write a number of Impact Item Distance: ";
    cin >> ItemDistance;

    int DistanceResultDamage = DistanceCalculation(ItemImpact, ItemDistance);

    CharacterState state = (DistanceResultDamage < 0) ? Healed :
        (CharacterHealth <= 0) ? Dead : Damaged;

    CharacterHealthUpdate(CharacterHealth, DistanceResultDamage, state);

    system("pause");
    return 0;
}

int CharacterHealthUpdate(float& health, float impact, CharacterState state)
{
    switch (state)
    {
    case Healed:
        health = health + (impact * -1);
        cout << "Your hero healed by: " << impact * -1 << " And now has: " << health << " hp" << endl;
        break;
    case Damaged:
        health -= impact;
        if (health > 0)
        {
            cout << "Your hero was damaged by: " << impact << " And now has: " << health << " hp" << endl;
        }
        else
        {
            cout << "Dude, your hero died. You can't take any more damage." << endl;
        }
        break;
    case Dead:
        cout << "Your hero is already dead and cannot take any damage." << endl;
        break;
    default:
        cout << "Unknown state!" << endl;
        break;
    }
    return health;
}

int DistanceCalculation(float impact, float distance)
{
    if (distance > 100)
    {
        impact = 0;
    }
    else if (distance >= 0 && distance <= 100)
    {
        impact = impact * (1 - distance / 100);
    }
    return impact;
}


//Version 2
//int CharacterHealthUpdate(int& health, int& impact, int& distance);
//
//int DistanceCalculation(int& impact, int& distance);


//int main()
//{
//	int CharacterHealth;
//	int ItemImpact;
//	int ItemDistance;
//
//	int DamageResult;
//
//	//CharacterStatus status;
//
//	cout << "Please write a number of Character Health: " << endl;
//	cin >> CharacterHealth;
//
//	cout << "Please write a number of Character Impact:  " << endl;
//	cin >> ItemImpact;
//
//	cout << "Please write a number of Impact Item Distance: " << endl;
//	cin >> ItemDistance;
//
//	
//	DamageResult = DistanceCalculation(ItemImpact, ItemDistance);
//
//	CharacterHealthUpdate(CharacterHealth,DamageResult, ItemDistance);
//
//	system("pause");
//}


//int CharacterHealthUpdate(int& health, int& item_impact, int& distance)
//{
//  int result_impact;
//if (item_impact < 0 && health > 0)
//{
//	result_impact = health - item_impact;
//	cout << "Your hero healed on : " << item_impact / -1 << " And now Character has: " << result_impact << " hp" << endl;
//
//}
//else if (item_impact > 0)
//{
//	result_impact = health - item_impact;
//	cout << "Your hero damaged on : " << item_impact << " And now Character has: " << result_impact << " hp" << endl;
//}
//else if (item_impact >= health)
//{
//	result_impact = health - item_impact;
//	health = 0;
//	cout << "Your hero died" << " And now Character has: " << health << " hp" << endl;
//}
//
//else if (item_impact = 0)
//{
//	result_impact = health + item_impact;
//	cout << "Your hero anyway Died and doesn't take any damage :" << endl;
//}
//
//else if (health !=0 || health > 0 )
//{
//	result_impact = health - item_impact;
//	cout << "Your hero damaged on : " << item_impact << " And now Character has: " << result_impact << " hp" << endl;
//}
//else if (health = 0) 
//{
//	result_impact = health - item_impact;
//	cout << "Dude, your hero died. You can't take any damage " << endl;
//}
//else if (health < 0 && item_impact < 0 && distance < 0)
//{
//	result_impact = health;
//	cout << "Dude, your hero died at start of the game, relax " << endl;
//}
//return health;
//}
//
//
//int DistanceCalculation(int& item_impact, int& distance)
//
//{
//	float result_impact; 
//	if(distance > 100)
//	{
//		item_impact = 0;
//		result_impact = item_impact;
//	}
//	else if (distance < 100 || distance >= 0)
//	{
//		result_impact = item_impact * (1 - distance / 100.0f);
//	}
//
//	return result_impact;
//}