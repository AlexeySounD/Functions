#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

//Version 1
enum class CharacterState {
    Healed,
    Damaged,
    Dead,
};

float CharacterHealthUpdate(float Health, float Impact, CharacterState State);
float DistanceCalculation(float Impact, float Distance, float MaxDistance);

int main()
{
    float CharacterHealth = 100.f;
    float ItemImpact = 0;
    float ItemDistance = 0;
    const float MaxDistance = 100.f;

    cout << "Please write a number of Character Health: ";
    cin >> CharacterHealth;

    cout << "Please write a number of Character Impact: ";
    cin >> ItemImpact;

    cout << "Please write a number of Impact Item Distance: ";
    cin >> ItemDistance;

    const float DistanceResultDamage = DistanceCalculation(ItemImpact, ItemDistance, MaxDistance);

    const CharacterState state = (DistanceResultDamage > 0) ? CharacterState::Healed : CharacterState::Damaged;

    CharacterHealth = CharacterHealthUpdate(CharacterHealth, DistanceResultDamage, state);

    system("pause");
    return 0;
}

float CharacterHealthUpdate(float Health, float Impact, CharacterState state)
{
    switch (state)
    {
    case CharacterState::Healed:
        Health = Health + (Impact * -1);
        cout << "Your hero healed by: " << Impact * -1 << " And now has: " << Health << " hp" << endl;
        break;
    case CharacterState::Damaged:
        Health -= Impact;
        if (Health > 0.f)
        {
            cout << "Your hero was damaged by: " << Impact << " And now has: " << Health << " hp" << endl;
        }
        else
        {
            cout << "Dude, your hero died. You can't take any more damage." << endl;
        }
        break;
    case CharacterState::Dead:
        Health = 0.f;
        std::cout << "Character forcibly killed" << std::endl;
        break;
    default:
        cout << "Unknown state!" << endl;
        break;
    }
    return Health;
}

float DistanceCalculation(float Impact, float Distance, float MaxDistance)
{
    const float ClampedDistance = std::clamp(Distance, 0.f, MaxDistance);
    return Impact * (1 - ClampedDistance / MaxDistance);
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