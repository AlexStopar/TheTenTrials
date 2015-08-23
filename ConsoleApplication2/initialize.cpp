#include "stdafx.h"
#include <vector>
#include <string>
#include <iostream>
#include <conio.h>
#include "player.h"
#include <iomanip>
#include "variousfunc.h"
using namespace std;

void initializeTrialist(Player &player, vector<string>& questionList)
{
	cout << "Tell me your name, trialist: ";
	char name[10];
	cin >> setw(10) >> name;
	name[0] = toupper(name[0]);
	player.SetName(name);
	cout << "\nAh, " << player.GetName() << ". What an odd name.\n\n";

	do{
		char sex;
		cout << "Are you a male or a female? (m for male, f for female, n for neither): ";
		sex = _getch();
		cout << endl;
		player.SetSex(sex);
	} while (player.GetSex() != 'm' && player.GetSex() != 'f' && player.GetSex() != 'n');

	switch (player.GetSex())
	{
	case 'm':
		cout << "Ah, quite the man I see here.\n\n";
		break;
	case 'f':
		cout << "Ah, quite the woman I see here.\n\n";
		break;
	default:
		cout << "Ah, so you identify as neither? Interesting.\n\n";
		break;
	}
	
	forward();
	forward();
	cout << "Now answer me a couple of questions to determine your nature.\n\n";
	forward();
	string title = "What would you wish for more than your own life?";
	questionList.push_back("Peace on Earth.");
	questionList.push_back("Why the hell would I put something over my own life?");
	questionList.push_back("I don't really know; my wishes aren't that great.");
	int choice = askQuestion(title, questionList);

	switch (choice)
	{
	case 1:
		player.SetGoodness(player.GetGoodness() + 1);
		break;
	case 2:
		player.SetEvil(player.GetEvil() + 1);
		break;
	default:
		player.SetApathy(player.GetApathy() + 1);
		break;
	}

	title = "\nHow do you feel about marriage?";
	questionList.push_back("I don't think I'm ready for that type of thing.");
	questionList.push_back("It's something that I'll probably do when I'm in love.");
	questionList.push_back("Depends on how much money I'll get.");
	choice = askQuestion(title, questionList);

	switch (choice)
	{
	case 1:
		player.SetApathy(player.GetApathy() + 1);
		break;
	case 2:
		player.SetGoodness(player.GetGoodness() + 1);
		break;
	default:
		player.SetEvil(player.GetEvil() + 1);
		break;
	}

	title = "\nLastly, why did you seek out the tree?";
	questionList.push_back("I hear there's a lot of power hidden within.");
	questionList.push_back("I seek the wisdom of the trials.");
	questionList.push_back("I just kinda felt like it, y'know?");
	questionList.push_back("The game just put me here. I didn't really choose.");
	choice = askQuestion(title, questionList);

	switch (choice)
	{
	case 1:
		player.SetEvil(player.GetEvil() + 1);
		break;
	case 2:
		player.SetGoodness(player.GetGoodness() + 1);
		break;
	case 3:
		player.SetApathy(player.GetApathy() + 1);
		break;
	default:
		cout << "\nYou're a game character now; you might as well act out your role.\n";
		forward();
		break;
	}
	forward();
	cout << "Now remember your senses and who you are..." << endl;
	forward();
	cout << "\nAnd begin your ten trials...\n";
	forward();
}

