#include "stdafx.h"
#include <string>
#include <iostream>
#include <conio.h>
#include "player.h"
#include "variousfunc.h"
using namespace std;

void theSixthTrial(Player &player, vector<string>& questionList)
{
	if (player.GetHealth() == 0) { return; }
	cout << "The new environment you step into is even further removed\n";
	cout << "than the other odd places supposedly within the innards of\n";
	cout << "the tree.\n";
	forward();
	cout << "You find yourself higher up in the mountains, the air becoming \n";
	cout << "thin from the altitude.\n";
	forward();
	cout << "Blistering wind pelts your face and snow as white as doves soon \n";
	cout << "follows.\n";
	forward();
	cout << "Ahead of you is a lonely ice bridge connecting an impassably deep\n";
	cout << "chasm.\n";
	forward();
	cout << "A single wrong step would mean an early grave.\n";
	forward();
	cout << "You gingerly walk forward, attempting to block the wind as you \n";
	cout << "traverse the chasm.\n";
	forward();
	cout << "Halfway through, you notice a figure clad in icy blue armor\n";
	cout << "make their way to meet you across the bridge.\n";
	forward();
	cout << "The figure is carrying a knife of cold steel and seems as if they\n";
	cout << "have an intent to kill.\n";
	forward();
	cout << "'Halt!' a voice rings out from within the shell of the armor.\n";
	forward();
	cout << "The voice is that of a female.\n";
	forward();
	string title = "How dare you cross this sacred ground?";
	questionList.push_back("Sacred? What's so sacred about this place?");
	questionList.push_back("And what role do you play in the trials?");
	questionList.push_back("What do you look like under that armor, anyway?");
	int choice = askQuestion(title, questionList);
	if (choice == 1)
	{
		cout << "'This place is the halfway point between those who seek the\n";
		cout << "trials and those who must finish, even if their very lives \n";
		cout << "fall to ruin because of it.'\n";
		forward();
		forward();
		cout << "'I sense unworthiness in you; thus you shall not continue\n";
		cout << "until I have judged you as able to do so.'\n";
	}
	else if (choice == 2)
	{
		cout << "'I stand here to judge those who seek resolve in the trials.'\n";
		forward();
		forward();
		cout << "'Nothing like a fight to the death to keep their sense sharp.'\n";
	}
	else 
	{
		cout << "'If you must know, I look like a woman.'\n";
		forward();
		forward();
		cout << "'Regardless, you will still meet the same fate if you act foolishly,\n";
		cout << "even if I am of the fairer sex.'\n";
		forward();
		cout << "She brandishes her blade and has not wavered in her resolve.\n";
	}
	forward();
	cout << "'Nevertheless,' she says, readying her fighting pose, 'you will now\n";
	cout << "answer what is necessary to pass.'\n";
	forward();
	cout << "'You may be able to risk your own life for the sake of the trials but...'\n";
	forward();
	title = "Can you risk and sacrifice the lives of others to reach your goal?";
	questionList.push_back("I mean, if I don't know you and it's self-defense...");
	questionList.push_back("It hurts me to do so, but sacrifices must be made.");
	questionList.push_back("Nothing pleases me more. (Make lascivious movement with your tongue)");
	questionList.push_back("I don't want to hurt you. Please, let's talk this over!");
	questionList.push_back("You want to fight then? Sure; I'm going to have some fun with this.");
	choice = askQuestion(title, questionList);
	switch (choice)
	{
	case 1:
		player.SetApathy(player.GetApathy() + 2);
		cout << "'Don't bother trying to make excuses.' She sounds disgusted.\n";
		forward();
		forward();
		cout << "'You wreak of indecisiveness, relying on simple reason to carry \n";
		cout << "you through your life.'\n";
		break;
	case 2:
		player.SetGoodness(player.GetGoodness() + 1);
		cout << "'Good. You are clean of heart but know when death must be done.'\n";
		forward();
		forward();
		cout << "She looks impressed by your resolve.\n";
		break;
	case 3:
		player.SetEvil(player.GetEvil() + 2);
		cout << "She spits into the chasm in disgust.\n";
		forward();
		forward();
		cout << "'You disgust me, vile creature,' she remarks.\n";
		break;
	case 4:
		player.SetGoodness(player.GetGoodness() + 2);
		cout << "'Your naive ways will not turn the tide of my blade.'\n";
		forward();
		forward();
		cout << "She points the knife to your face. 'If you do not fight \n";
		cout << "me, you shall surely perish.'\n";
		break;
	default:
		cout << "'Hm, interesting.' She seems impressed by your bloodlust.\n";
		forward();
		forward();
		cout << "'I haven't had a good fight in a very long while. Let's hope\n";
		cout << "that you can deliver.'\n";
		player.SetEvil(player.GetEvil() + 1);
		break;
	}
	forward();
	cout << "'Alright,' she says, moving her body into a hostile fighting pose\n";
	cout << "with her feet firmly planted on the bridge.\n";
	forward();
	string gender;
	switch (player.GetSex())
	{
	case 'm':
		gender = "boy";
		break;
	case 'f':
		gender = "girl";
		break;
	case 'n':
		gender = "human";
		break;
	}
	cout << "'Enough prattle; come at me, " << gender << "!'";
	forward();
	
	char input;
	string item = "";
	do{
		displayHelp();
		input = resolveDecision(player);
		if (input == 's')
		{
			cout << "\nIt seems that she has no wish to continue prattling.\n";
			forward();
			cout << "Prattling further will most certainly result in your death.\n";
			input = 'r';
		}
		if (input == 'l')
		{
			cout << "\nYou get a quick look at the warrior.\n";
			forward();
			cout << "The body is hidden behind a genderless suit of armor, fitted\n";
			cout << "to a thin body.\n";
			forward();
			cout << "Her knife is deadly sharp, and will meet anything with\n";
			cout << "equal or lesser value with overwhelming force.\n";
			forward();
			cout << "You also notice that there is ice beneath your feet.\n";
			input = 'r';
		}
		if (input == 'u'){
			item = player.GetInventoryEntry();
			if (item == "Guardian Head")
			{
				cout << "\nThe head does not bother coming out of your pocket,\n";
				cout << "surely due to the brevity of the situation.\n";
				forward();
				forward();
				cout << "'YOU FOOL!' It yells, 'GRAB A WEAPON!'\n";
				input = 'r';
			}
			else if (item == "Granny Smith")
			{
				changeHealth(player, eatApple(false));
				forward();
				player.RemoveFromInventory(item);
				input = 'r';
			}
		}
	} while (input == 'r');

	if (input == 't')
	{
		cout << "\nYou decide to take the warrior on with your bare hands.\n";
		forward();
		title = "What will be your course of action?";
		questionList.push_back("Punch her in the jaw!");
		questionList.push_back("Grapple her off the bridge!");
		questionList.push_back("Trip her!");
		questionList.push_back("Consult a strategy guide!");
		choice = askQuestion(title, questionList);
		switch (choice)
		{
		case 1:
			cout << "You aim your fist for her face with all your might.\n";
			forward();
			forward();
			cout << "Unfortunately, she quickly moves her head out of the way\n";
			cout << "and stabs you in the heart.\n";
			forward();
			cout << "You fall into the chasm for 10 points of damage.\n";
			forward();
			if (changeHealth(player, 10)) { return; }
			break;
		case 2:
			cout << "You attempt to wrestle the warrior off the bridge.\n";
			forward();
			forward();
			cout << "She forsees your stance and stabs you in the heart as\n";
			cout << "you try to grab her.\n";
			forward();
			cout << "You fall into the chasm for 10 points of damage.\n";
			forward();
			if (changeHealth(player, 10)) { return; }
			break;
		case 3:
			cout << "You remembered that you are on a bridge of ice.\n";
			forward();
			forward();
			cout << "Attempting the swiftest movement possible, you slide your leg\n";
			cout << "under hers as she runs toward you to attack.\n";
			forward();
			cout << "She lets out a scream as she slips off the bridge into oblivion\n";
			cout << "and takes 10 points of damage from the fall.\n";
			forward();
			break;
		default:
			cout << "Before you can attempt to cheat, the warrior stabs your strategy\n";
			cout << "guide and pushes you off the bridge.\n";
			forward();
			forward();
			cout << "'Hmph,' she announces as you fall. 'Pathetic.'\n";
			forward();
			cout << "You fall into the chasm for 10 points of damage.\n";
			forward();
			if (changeHealth(player, 10)) { return; }
			break;
		}
	}
	else{
		if (item == "Obsidian Knife")
		{
			cout << "You grasp the knife in your hand and firmly plant yourself\n";
			cout << "onto the ground, ready for her attack.\n";
			forward();
			forward();
			cout << "You barely deflect her knife with yours; she takes another\n";
			cout << "shot and stabs your shoulder for 2 points of damage.\n";
			forward();
			if (changeHealth(player, 2)) { return; }
			forward();
			cout << "Taking the advantage while her guard is down, you stab through\n";
			cout << "her armor in a weak spot to the neck.\n";
			forward();
			cout << "She drops her blade into the chasm and clutches her neck\n";
			cout << "as she gurgles and falls into oblivion for 10 points of damage.\n";
			forward();
		}
		else
		{
			cout << "You pull out the cursed blade, Deathknell.\n";
			forward();
			forward();
			cout << "'No...' she whispers, a hint of worry in her voice. 'Where \n";
			cout << "did you get that blade?!'\n";
			forward();
			cout << "With a rush of force as black as midnight, you slice straight\n";
			cout << "through her body at the chest.\n";
			forward();
			cout << "The bottom of her body falls to its knees as her upper half\n";
			cout << "falls into the chasm for 10 points of damage.\n";
			forward();
			cout << "Lust for more blood surges through your head as you slowly\n";
			cout << "sheathe Deathknell.\n";
			player.SetEvil(player.GetEvil() + 1);
			forward();
		}
	}
	cout << "Confident that the battle is won, you continue down the bridge and\n";
	cout << "into a door of green ice into your next trial...\n";
	forward();
}
