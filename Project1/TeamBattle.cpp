#include <iostream>
#include <string>
#include <list>
#include <format>
#include <cstdlib>
#include <ctime>

using namespace std;

enum GameState
{
	AddingNewCharacter,
	RemovingCharacter,
	StartingBattle,
	undefined
};

enum CharacterState
{
	InLobby,
	OutOfLobby,
	Dead
};

string StateOfCharacterToString(CharacterState CharState);

class Chracter;
class Team;


class Character
{
public:
	Character(string name, float health, float damage);
	// GetName () CONST - ne bydet menyatsa ykazatel na NAME 
	string GetName() const { return Name; }
	float GetHealth() const { return CurrentHealth; }
	float GetDamage() const { return Damage; }
	CharacterState GetState() const { return State; }
	void SetState(CharacterState NewState)
	{
		State = NewState;
	}

	//string ShowInfo() const { return  Name + "\t" + std::to_string(CurrentHealth) + "\t" + std::to_string(Damage); }
	string ShowInfo() const { return  Name + "\t" + std::to_string(static_cast<int>(CurrentHealth)) + "\t" + std::to_string(static_cast<int>(Damage)); }
	string ShowFullInfo() const {
		return  Name + "\t" + std::to_string(static_cast<int>(MaxHealth)) 
					 + "\t" + std::to_string(static_cast<int>(Damage))
					 + "\t" + std::to_string(static_cast<int>(CurrentHealth))
					 + "\t\t" + std::to_string(static_cast<int>(TeamNum)) 
					 + "\t" + StateOfCharacterToString(State);
	}

	void SetTeamNumber(int number)
	{
		TeamNum = number;
	}

	void TakeDamage(float takedDamage)
	{
		CurrentHealth -= takedDamage;
		if (CurrentHealth <= 0)
		{
			State = Dead;
		}
	}

private:
	string Name;
	int TeamNum;
	float MaxHealth;
	float CurrentHealth;
	float Damage;
	CharacterState State;
	Team* Teams/* = new Team{"team"}*/;
};

class Team
{
public:
	Team(string name)
	{
		Name = name;
	}
	void AddCharacter(Character* newMember)
	{
		Characters.push_back(newMember);
	}
	void DeleteCharacter(Character* MemberToRemove)
	{
		Characters.remove(MemberToRemove);
	}

	std::list<Character*> GetCharacters() const { return Characters; }
	string GetName() const { return Name; }

private:
	string Name;
	std::list<Character*> Characters;
};





void StartGame();

void ShowMessage(string message);

std::list<Character*> GetCharacterList(std::list<Character*> charlist, CharacterState state);




Character::Character(string name, float health, float damage)
{
	Name = name;
	MaxHealth = health;
	CurrentHealth = health;
	Damage = damage;
	State = CharacterState::OutOfLobby;
}


void ShowCharactersList(std::list<Character*>& Characters);

void CreateNewCharacter(std::list<Character*>& Characters);

void ShowCharactersListFullInfo(std::list<Character*>& Characters);


void TeamBattle(Team* team0, Team* team1);

int main()
{
	// test DATA	
	Character* character1 = new Character{ "Bob" , 100, 10 };
	Character* character2 = new Character{ "Ala" , 10, 12 };
	Character* character3 = new Character{ "Vobla" , 100, 50 };
	Character* character4 = new Character{ "Anton" , 1, 1 };
	std::list<Character*> Characters = { character1, character2, character3, character4 };
	Team* team0 = new Team("Team0");
	Team* team1 = new Team("Team1");

	//Variables
	bool GameStart = true;
	int Command;
	int Round = 0;

	//Start of the Game Loop
	cout << "Welcome to the combat game! \n";
	while (GameStart)
	{
		cout << "Round : " << Round << endl;
		cout << "Please write a command from 0 to 5 : \n\n";
		cout << "To add new Character to the Team press: 0 \n";
		cout << "To remove Character from the battle press: 1 \n";
		cout << "To start the battle press: 2 \n";
		cout << "To create Character: 3 \n";
		cout << "Show Teams 4: \n";
		cout << "Show list of all characters press 5: \n\n";
		//cout << "Show All Characters 5 : " << Characters << endl;
		cout << "To exit press 6 : \n";

		cin >> Command;
		system("cls");
		if (Command == 0)
		{
			if (Characters.size() > 0)
			{
				int id;
				int counter = 0;
				int teamid;
				bool CharFound = false;
				std::list<Character*> OutOfLobbyCharacters = GetCharacterList(Characters, CharacterState::OutOfLobby);
				ShowCharactersList(OutOfLobbyCharacters);
				cout << "Choose Character ID to add the Team: ";
				cin >> id;
				cout << "Choose Team to add (0 or 1) : ";
				cin >> teamid;
				for (Character* TempChar : OutOfLobbyCharacters)
				{
					if (counter == id)
					{
						CharFound = true;
						if (teamid == 0)
						{
							team0->AddCharacter(TempChar);
							TempChar->SetTeamNumber(teamid);
							TempChar->SetState(CharacterState::InLobby);
							ShowMessage("You added char to team 0");
							break;
						}
						else if (teamid == 1)
						{
							team1->AddCharacter(TempChar);
							TempChar->SetTeamNumber(teamid);
							TempChar->SetState(CharacterState::InLobby);
							ShowMessage("You added char to team 1");
							break;
						}
						else
						{
							cout << "Incorrect team number";
						}
					}

					counter++;
				}
				if (CharFound == false)
				{
					ShowMessage("Characters didn't found: ");
				}
			}
			else
			{
				char choose;
				ShowMessage("Pull of characters is zero. Please ADD char");
				cout << "Do you wana create character :  y or n " << endl;
				cin >> choose;
				if (choose == 'y')
				{
					CreateNewCharacter(Characters);
				}
				else
				{
					ShowMessage("Return to main menu");
					system("pause");
				}
			}
		}
		else if (Command == 1)
		{
			int teamid;
			cout << "Select team which player will be removed: ";
			cin >> teamid;

			if (teamid == 0)
			{
				int CharacterID;
				int counter = 0;
				system("cls");
				std::list<Character*> Team0Characters = team0->GetCharacters();
				cout << "Team0 is : \n";
				ShowCharactersList(Team0Characters);
				cout << "Choose Character's ID: \n ";
				cin >> CharacterID;
				for (Character* TempChar : Team0Characters)
				{
					if (CharacterID == counter)
					{
						team0->DeleteCharacter(TempChar);
						TempChar->SetState(CharacterState::OutOfLobby);
						break;
					}
					counter++;
				}

			}
			else if (teamid == 1)
			{
				int CharacterID;
				int counter = 0;
				system("cls");
				cout << "Team1 is : \n";
				std::list<Character*> Team1Characters = team1->GetCharacters();
				ShowCharactersList(Team1Characters);
				cout << "Choose Character's ID: \n ";
				cin >> CharacterID;
				for (Character* TempChar : Team1Characters)
				{
					if (CharacterID == counter)
					{
						team0->DeleteCharacter(TempChar);
						TempChar->SetState(CharacterState::OutOfLobby);
						break;
					}
					counter++;
				}
			}
			system("pause");
		}
		else if (Command == 2)
		{
			int FirstAttack;
			cout << "Please choose who attacks first? : (0 - Team0 , 1 - Team1, 2 - Random) ";
			cin >> FirstAttack;
			if (FirstAttack == 2)
			{
				int a = 0, b = 1;
				std::srand(std::time(0));
				FirstAttack = a + std::rand() % (b - a + 1);
			}
			if (FirstAttack == 0)
			{
				TeamBattle(team0, team1);
				TeamBattle(team1, team0);				
			}
			else if (FirstAttack == 1)
			{
				TeamBattle(team1, team0);
				TeamBattle(team0, team1);
			}	
			

			Round++;
		}
		else if (Command == 3)
		{

			CreateNewCharacter(Characters);

		}
		else if (Command == 4)
		{
			system("cls");
			std::list<Character*> Team0Characters = team0->GetCharacters();
			cout << "Team0 is : \n";
			ShowCharactersList(Team0Characters);
			cout << "Team1 is : \n";
			std::list<Character*> Team1Characters = team1->GetCharacters();
			ShowCharactersList(Team1Characters);
			system("pause");
		}
		else if (Command == 5)
		{
			system("cls");
			ShowCharactersListFullInfo(Characters);
			system("pause");
		}
		else if (Command == 6)
		{
			GameStart = false;
		}
		system("cls");
	}
	cout << "Thanks for playing! \n";
	system("pause");
}

void TeamBattle(Team* team0, Team* team1)
{
	for (Character* TempChar0 : team0->GetCharacters())
	{
		if (TempChar0->GetState() == CharacterState::Dead)
		{
			break;
		}
		for (Character* TempChar1 : team1->GetCharacters())
		{
			if (TempChar1->GetState() != CharacterState::Dead)
			{
				cout << "Character " << TempChar0->GetName() << " attacks " << TempChar1->GetName() << " and taked  " << TempChar0->GetDamage() << " damage" << endl;
				TempChar1->TakeDamage(TempChar0->GetDamage());
				if (TempChar1->GetHealth() <= 0)
				{
					cout << "Character: " << TempChar1->GetName() << " Is Dead" << endl;
					cout << "Character: " << TempChar0->GetName() << " from: " << team0->GetName() << " Win" << endl;
				}
				else
				{
					cout << "Character: " << TempChar1->GetName() << " now has: " << TempChar1->GetHealth() << " HP" << endl;
				}				
				system("pause");
				break;
			}

		}
	}
}

void CreateNewCharacter(std::list<Character*>& Characters)
{
	string name;
	float health = 0.f;
	float damage = 0.f;
	cout << "Write character name: ";
	cin >> name;
	cout << "Write character health: ";
	cin >> health;
	cout << "Write character damage: ";
	cin >> damage;

	Character* NewChar = new Character(name, health, damage);
	Characters.push_back(NewChar);
	ShowMessage("Congratulations !! You created new character : ");
	cout << NewChar->ShowInfo() << endl;
	system("pause");
}

void ShowCharactersList(std::list<Character*>& Characters)
{
	int counter = 0;
	cout << "ID\t" << "Name\t" << "HP\t" << "DMG" << endl;
	for (Character* TempChar : Characters)
	{
		cout << counter << "\t" << TempChar->ShowInfo() << endl;
		counter++;
	}
}
void ShowCharactersListFullInfo(std::list<Character*>& Characters)
{
	int counter = 0;
	cout << "ID\t" << "Name\t" << "HP\t" << "DMG\t" << "Current HP\t" << "TEAM\t" << "STATUS \t" << endl;
	for (Character* TempChar : Characters)
	{
		cout << counter << "\t" << TempChar->ShowFullInfo() << endl;
		counter++;
	}
}

void ShowMessage(string message)
{
	system("cls");
	cout << message << endl;
}

void StartGame()
{

}

std::list<Character*> GetCharacterList(std::list<Character*> charlist, CharacterState state)
{
	list<Character*> newlist;
	for (Character* TempChar : charlist)
	{
		if (TempChar->GetState() == state)
		{
			newlist.push_back(TempChar);
		}
	}
	return newlist;
}

string StateOfCharacterToString(CharacterState CharState)
{
	switch (CharState)
	{
	case InLobby: return "Inlobby";
	case OutOfLobby: return "OutOfLobby";
	case Dead: return "Dead";
	default: return "UNKNOWN";
	}
}

//Visov vseh igrokov iz poola