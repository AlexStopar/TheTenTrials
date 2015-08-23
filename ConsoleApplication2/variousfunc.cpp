#include "stdafx.h"
#include <vector>
#include <string>
#include <iostream>
#include "player.h"
#include <conio.h>
using namespace std;

void makeTestInventory(Player& player)
{
	player.AddToInventory("Guardian Head");
	player.AddToInventory("Obsidian Knife");
	player.AddToInventory("Granny Smith");
	player.AddToInventory("Deathknell");
	player.AddToInventory("Tempter Medallion");
}

void forward()
{
	cin.ignore(256, '\n');
}

int eatApple(bool isSeventhTrial)
{
	if (!isSeventhTrial)
	{
		cout << "\nYou eat the delicious apple for 2 points of health.\n";
		forward();
		forward();
		return -2;
	}
	else
	{
		cout << "\nYou waited too long to eat an apple.\n";
		forward();
		forward();
		cout << "It is rotten to the core and sickens your stomach \n";
		cout << "for 2 points of damage.";
		forward();
		return 2;
	}
}
int askQuestion(string title, vector<string>& list)
{
	int number = 1;
	string choice;
	cout << title << "\n\n";
	for (vector<string>::const_iterator iter = list.begin(); iter != list.end(); ++iter) {
		cout << number << ". " << *iter << endl;
		number++;
	}
	do
	{
		cout << "\nPick a number for your choice: ";
		cin >> choice;
		number = atoi(choice.c_str());
	} while (number <= 0 || number > list.size());
	list.clear();
	return number;
}

bool changeHealth(Player& player, int points)
{
	player.SetHealth(player.GetHealth() - points);
	player.ShowHealth();
	forward();
	if (player.GetHealth() == 0)
	{
		return true;
	}
	return false;
}

void displayHelp()
{
	cout << "\nPress 'l' to look, 's' to speak, 'u' to use, 'h' to display help, 't' to touch,"; 
	cout << " 'i' to display inventory, 'a' to show alignment, and 'e' to show health.\n";
}

char resolveDecision(Player& player)
{
	char choice = _getch();
	switch (choice){
	case 'e':
		player.ShowHealth();
		return 'r';
	case 'i':
		player.ShowInventory();
		return 'r';
	case 'h':
		displayHelp();
		return 'r';
	case 'a':
		player.ShowAlignment();
		return 'r';
	case 'u':	
		if (player.ShowInventory() == 0)
		{
			return 'r';
		}
		return 'u';
	case 't':
		return 't';
	case 's':
		return 's';
	case 'l':
		return 'l';
	default:
		return 'r';
	}
	
}