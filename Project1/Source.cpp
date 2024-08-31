#include <string>
#include <iostream>
using namespace std;



// TO DO: Change if\else on enum for homework
//enum CharacterStatus 
//{
//   Damaged,
//   unDamaged,
//   Healed
//};
//void UpdateCharacterHealth(CharacterStatus Ch_Status, int& distance, int& damage, int& health);

int CharacterHealthUpdate(int& health, int& impact, int& distance);

int DistanceCalculation(int& impact, int& distance);


int main()
{
	int CharacterHealth;
	int ItemImpact;
	int ItemDistance;

	int DamageResult;

	//CharacterStatus status;

	cout << "Please write a number of Character Health: " << endl;
	cin >> CharacterHealth;

	cout << "Please write a number of Character Impact:  " << endl;
	cin >> ItemImpact;

	cout << "Please write a number of Impact Item Distance: " << endl;
	cin >> ItemDistance;

	
	DamageResult = DistanceCalculation(ItemImpact, ItemDistance);

	CharacterHealthUpdate(CharacterHealth,DamageResult, ItemDistance);

	system("pause");
}


//void UpdateCharacterHealth(CharacterStatus Ch_Status, int& distance, int& damage, int& health)
//{
//	switch (Ch_Status)
//	{
//	case Damaged:
//		if (distance )
//		break;
//	case unDamaged:
//		break;
//	case Healed:
//		break;
//	default:
//		break;
//	}
//}
int CharacterHealthUpdate(int& health, int& item_impact, int& distance)
{
  int result_impact;
if (item_impact < 0 && health > 0)
{
	result_impact = health - item_impact;
	cout << "Your hero healed on : " << item_impact / -1 << " And now Character has: " << result_impact << " hp" << endl;

}
else if (item_impact > 0)
{
	result_impact = health - item_impact;
	cout << "Your hero damaged on : " << item_impact << " And now Character has: " << result_impact << " hp" << endl;
}
else if (item_impact >= health)
{
	result_impact = health - item_impact;
	health = 0;
	cout << "Your hero died" << " And now Character has: " << health << " hp" << endl;
}

else if (item_impact = 0)
{
	result_impact = health + item_impact;
	cout << "Your hero anyway Died and doesn't take any damage :" << endl;
}

else if (health !=0 || health > 0 )
{
	result_impact = health - item_impact;
	cout << "Your hero damaged on : " << item_impact << " And now Character has: " << result_impact << " hp" << endl;
}
else if (health = 0) 
{
	result_impact = health - item_impact;
	cout << "Dude, your hero died. You can't take any damage " << endl;
}
else if (health < 0 && item_impact < 0 && distance < 0)
{
	result_impact = health;
	cout << "Dude, your hero died at start of the game, relax " << endl;
}
return health;
}


int DistanceCalculation(int& item_impact, int& distance)

{
	float result_impact; 
	if(distance > 100)
	{
		item_impact = 0;
		result_impact = item_impact;
	}
	else if (distance < 100 || distance >= 0)
	{
		result_impact = item_impact * (1 - distance / 100.0f);
	}

	return result_impact;
}