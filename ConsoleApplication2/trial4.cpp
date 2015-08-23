#include "stdafx.h"
#include <string>
#include <iostream>
#include <conio.h>
#include "player.h"
#include "variousfunc.h"
using namespace std;

void theFourthTrial(Player &player, vector<string>& questionList)
{
	if (player.GetHealth() == 0) { return; }
	cout << "You find yourself in a field much more lush than the previous trial.\n";
	forward();
	cout << "The rolling hills have a healthy green to them, and delicate \n";
	cout << "wildflowers season the landscape every now and then.\n";
	forward();
	cout << "The sun is shining but the temperature is in an ideal medium.\n";
	forward();
	cout << "This is truly a peaceful place. Your mind feels at rest for the \n";
	cout << "first time since you have traveled to take the trials.\n";
	forward();
	cout << "The main part that stands out is a large apple tree.\n";
	forward();
	cout << "While not the tree of the trials, the tree in the field is a lone\n";
	cout << "force, an expansive giant that covers a single bed with shade.\n";
	forward();
	cout << "Upon closer inspection, the bed looks tantalizingly good for \n";
	cout << "much deserved sleep.\n";
	forward();
	cout << "It is a simple and small bed, but the colors are calm whites\n";
	cout << "and greens, and the soft mattress looks too divine for you \n";
	cout << "not to take a nap.\n";
	forward();
	
	char input;
	do
	{
		displayHelp();
		input = resolveDecision(player);
		if (input == 'l')
		{
			cout << "\nYou see the tree in all its splendor. The apples are\n";
			cout << "juicy Granny Smiths, ripe enough for the picking.\n";
			forward();
			cout << "The bed itself has a note lying on the pillow.\n";
			forward();
			cout << "It reads, 'For my dearest " + player.GetName() + ": you deserve it.'\n";
			forward();
			cout << "You have no idea who would want to gift you a bed amidst\n";
			cout << "these trials; you remain cautious and suspicious.\n";
			forward();
			input = 'r';
		}
		if (input == 'u')
		{
			string item = player.GetInventoryEntry();
			if (item == "Guardian Head")
			{
				cout << "The head is asleep. Perhaps it could use a nap as well.\n";
				forward();
			}
			else
			{
				cout << "That bed looks villainous. It could use a stabbing.\n";
				forward();
				forward();
				cout << "You thrust the knife into the bed. Justice is done.\n";
				forward();
			}
			input = 'r';
		}
		
	}
	while (input == 'r');

	string title;
	int choice;
	if (input == 's')
	{
		cout << "\nYou decide to have a moment to yourself and meditate on your\n";
		cout << "adventures thus far.\n";
		forward();
		title = "What will you meditate on?";
		questionList.push_back("Bringing peace to your tired mind.");
		questionList.push_back("Your dear family and friends back home.");
		questionList.push_back("...nothing. Yeah, I don't see any reason to do this.");
		questionList.push_back("The untold riches of the trials.");
		questionList.push_back("That really hot creature you ran into a few trials back.");
		choice = askQuestion(title, questionList);
		switch (choice)
		{
		case 1:
			player.SetGoodness(player.GetGoodness() + 1);
			cout << "You bring to mind all sorts of peaceful things in life.\n";
			forward();
			forward();
			cout << "A bright summer day. A good night's sleep. Kittens.\n";
			forward();
			break;
		case 2:
			player.SetGoodness(player.GetGoodness() + 2);
			cout << "You think of all those who brought you joy in life.\n";
			forward();
			forward();
			cout << "You wouldn't be where you are now without them.\n";
			forward();
			break;
		case 3:
			cout << "'Yeah, this isn't doing anything,' you mutter to yourself.\n";
			forward();
			forward();
			cout << "You were never the type to find enlightenment in sitting \n";
			cout << "around.\n";
			forward();
			player.SetApathy(player.GetApathy() + 2);
			break;
		case 4:
			cout << "You think of all the wonder, glory, and power that lies \n";
			cout << "in wait at the end of the road.\n";
			forward();
			forward();
			cout << "From what the legends say, the rewards are enormous enough\n";
			cout << "to make you drool from thinking about them.\n";
			forward();
			player.SetEvil(player.GetEvil() + 1);
			break;
		default:
			cout << "A cavalcade of dirty thoughts races through your mind.\n";
			forward();
			forward();
			cout << "You enjoy your meditation for all the wrong reasons.\n";
			forward();
			player.SetEvil(player.GetEvil() + 2);
			break;
		}
	}

	cout << "\nThere are a series of tasks that lay before you.\n";
	forward();
	cout << "From your lesson in the previous trial, running away is \n";
	cout << "not an option.\n";
	forward();
	title = "But what to do with a bed and an apple tree?";
	questionList.push_back("Take an apple from the apple tree.");
	questionList.push_back("Sleep in the luxurious looking bed.");
	questionList.push_back("Walk, don't run away. Take a break.");
	choice = askQuestion(title, questionList);
	if (choice == 1){
		cout << "You pick an apple from the tree, hearing a soft snap\n";
		cout << "as the heavy fruit drops into your hand.\n";
		forward();
		forward();
		cout << "It looks foreboding, ominous, and...delicious.\n"; 
		forward();
		player.AddToInventory("Granny Smith");
		forward();
	}
	else if (choice == 3){
		cout << "You walk cautiously away from the field for a short stroll.\n";
		forward();
		forward();
		cout << "Perhaps a couple minutes of walking will help clear the mind.\n";
		forward();
		cout << "In no less than ten minutes of walking, though, you find yourself\n";
		cout << "right back where you were, and a bit tired to boot from the\n";
		cout << "warmth of the bright summer light.\n";
		forward();
	}
	cout << "You decide then to lay upon the soft bed, its comforting embrace\n";
	cout << "lulling you to a restful ease.\n";
	forward();
	forward();
	title = "Do you want to go to sleep?";
	questionList.push_back("Maybe just... a little bit...(yawn)");
	questionList.push_back("This is obviously a trap! I'm prone to suspicion!");
	choice = askQuestion(title, questionList);
	if (choice == 1)
	{
		cout << "You slowly drift yourself to sleep, feeling the warm embrace\n";
		cout << "of the bed around your body.\n";
		forward();
		forward();
		cout << "No perilous situation here.\n";
		forward();
	}
	else
	{
		cout << "You decide that this is all some sort of horrible trap; the\n";
		cout << "trial has been too peaceful thus far!\n";
		forward();
		forward();
		cout << "Before you can escape, a tree branch shoots out like a whip \n";
		cout << "and chains you to the bed, strangling you unconscious for \n";
		cout << "2 points of damage.\n";
		if (changeHealth(player, 2)) { return; }
	}
	cout << "Within your sleep, you feel as if you are gliding downward.\n";
	forward();
	cout << "Sinking slowly and surely by some odd force.\n";
	forward();
	title = "Do you continue sleeping?";
	questionList.push_back("Yeah, this dream is actually pretty nice.");
	questionList.push_back("Wait, this is lucid dreaming? I must be in danger!");
	choice = askQuestion(title, questionList);
	if (choice == 1)
	{
		cout << "You decide to keep on dreaming; it feels as if the dream\n";
		cout << "is trying to take you somewhere important.\n";
		forward();
		forward();
	}
	else
	{
		cout << "You try to force yourself awake, focused on escaping this \n";
		cout << "ominous slumber.\n";
		forward();
		forward();
		cout << "You open your eyes for a moment and find yourself wrapped in\n";
		cout << "a coccoon of branches!\n";
		forward();
		cout << "The branches soon suffocate you back to sleep for 2 points of\n";
		cout << "damage.\n";
		if (changeHealth(player, 2)) { return; }
	}
	cout << "Feeling the dream take hold, you sink further into your sleep.\n";
	forward();
	cout << "In the physical realm, your body also descends further into the bed,\n";
	cout << "a large sinkhole that drags you down into the earth.\n";
	forward();
	cout << "And therein lies the door to your next trial...\n";
	forward();
}