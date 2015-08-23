# include "stdafx.h"
# include <iostream>
# include "player.h"
using  namespace std;

int Player::GetApathy()
{
	return apathy;
}

std::string Player::GetInventoryEntry()
{
	int number;
	do
	{
		std::string choice;
		cout << "\nPick a number for your choice: ";
		cin >> choice;
		number = atoi(choice.c_str());
	} while (number <= 0 || number > inventory.size());
	cout << "\nUsed " << inventory[number - 1] << ".\n";
	return inventory[number - 1];
}

int Player::ShowInventory()
{
	if (inventory.size() == 0){
		cout << "\nBut your inventory is empty!\n";
		return 0;
	}
	int number = 1;
	cout << endl;
	for (vector<string>::iterator iter = inventory.begin(); iter != inventory.end(); ++iter) {
		cout << number << ". " << *iter << endl;
		number++;
	}
	return inventory.size();
}

void Player::RemoveFromInventory(std::string selection)
{
	if (inventory.size() == 0){
		cout << "But your inventory is empty!\n";
		return;
	}
	
	for (vector<string>::iterator iter = inventory.begin(); iter != inventory.end(); ++iter) {
		if (*iter == selection)
		{
			cout << *iter << " removed.\n";
			inventory.erase(iter);
			return;
		}
	}
	
}

void Player::AddToInventory(std::string item)
{
	cout << endl;
	cout << item << " added.\n";
	inventory.push_back(item);
}

int Player::GetEvil()
{
	return evil;
}

int Player::GetGoodness()
{
	return goodness;
}

int Player::GetHealth()
{
	return health;
}

char Player::GetSex()
{
	return sex;
}

std::string Player::GetName()
{
	return name;
}

void Player::SetApathy(int a)
{
	apathy = a;
}

void Player::SetEvil(int e)
{
	evil = e;
}

void Player::SetGoodness(int g)
{
	goodness = g;
}

void Player::SetHealth(int h)
{
	health = h;
}

void Player::SetName(std::string n)
{
	name = n;
}

void Player::SetSex(char s)
{
	sex = s;
}

void Player::Reset()
{
	SetApathy(0);
	SetEvil(0);
	SetGoodness(0);
	SetHealth(10);
	inventory.clear();
}

void Player::ShowAlignment()
{
	cout << endl;
	cout << "Your will to bring peace to the world: " << GetGoodness() << endl;
	cout << "Your will to bring destruction to the world: " << GetEvil() << endl;
	cout << "Your absence of will: " << GetApathy() << endl;
}

void Player::ShowHealth()
{
	int points = GetHealth();
	if (points < 0)
	{
		points = 0;
		SetHealth(points);
	}
	else if (points > 10)
	{
		points = 10;
		SetHealth(points);
	}
	cout << "\nYou have " << points << " points left.\n";
	switch (points)
	{
	case 0:
		cout << "\nYou are most certainly dead. Make your way to the afterlife.\n";
		break;
	case 1:
	case 2:
	case 3:
		cout << "\nYou are on your last legs. Consider prayer for death or immediate treatment.\n";
		break;
	case 4:
	case 5:
	case 6:
		cout << "\nYou are not feeling well; you may need to tread carefully now.\n";
		break;
	case 7:
	case 8:
	case 9:
		cout << "\nYou've got a couple of hits, but it is nothing that should keep you down.\n";
		break;
	default:
		cout << "\nYou're in tip-top shape! Congratulations on staying well!\n";
		break;
	}
}