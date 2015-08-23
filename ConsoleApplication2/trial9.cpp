#include "stdafx.h"
#include <string>
#include <iostream>
#include <conio.h>
#include "player.h"
#include "variousfunc.h"
using namespace std;

void theNinthTrial(Player &player, vector<string>& questionList)
{
	if (player.GetHealth() == 0) { return; }
	cout << "You enter a dirty village that has seen better days.\n";
	forward();
	cout << "The buildings have wood rotting at the sides, and dust\n";
	cout << "fills the air.\n";
	forward();
	cout << "A burning is going on at the center of the village, with\n";
	cout << "a group of villagers surrounding a large cross.\n";
	forward();
	cout << "The cross burns with unkept flame, and a large wolf is pinned\n";
	cout << "to it.\n";
	forward();
	cout << "You hear their voices in unison in the crowd: 'Burn! Burn it to\n";
	cout << "the ground!'\n";
	forward();
	cout << "You slowly move your way through the crowd so that few of them\n";
	cout << "notice.\n";
	int choice;
	string title = "What will you say amongst the crowd?";
	questionList.push_back("(Keep silent)");
	questionList.push_back("Burn! Burn it to the ground!");
	questionList.push_back("Laugh and cheer on the burning.");
	questionList.push_back("Hey, stop this!");
	questionList.push_back("Did that wolf really deserve this?");
	choice = askQuestion(title, questionList);
	switch (choice)
	{
	case 1:
		player.SetApathy(player.GetApathy() + 2);
		cout << "The chant continues to ring in your ears.\n";
		forward();
		forward();
		cout << "You remain safe for the time being as an onlooker.\n";
		break;
	case 2:
		player.SetEvil(player.GetEvil() + 1);
		cout << "You join the chant of the villagers and it grows even\n";
		cout << "stronger than before.\n";
		forward();
		forward();
		cout << "The mood of the mob slightly intoxicates you with satisfaction.\n";
		break;
	case 3:
		player.SetEvil(player.GetEvil() + 2);
		cout << "The villagers notice you but continue their chanting.\n";
		forward();
		forward();
		cout << "Some of them like your mood and join in on the cheering.\n";
		break;
	case 4:
		player.SetGoodness(player.GetGoodness() + 2);
		cout << "Some of the villagers give you dirty looks but continue\n";
		cout << "with their chanting.\n";
		forward();
		forward();
		cout << "It seems your words have no effect on the matter.\n";
		break;
	default:
		player.SetGoodness(player.GetGoodness() + 1);
		cout << "A villager in tattered clothes responds, 'This foul beast\n";
		cout << "dares to terrify our village! We struck back and were victorious!'\n";
		forward();
		forward();
		cout << "You wonder if that was the whole truth of the situation.\n";
		break;
	}
	forward();
	cout << "Suddenly, the wolf starts howling and writhing in pain, jolting\n";
	cout << "the cross side to side.\n";
	forward();
	cout << "The villagers run to their homes as the cross snaps and the wolf\n";
	cout << "rolls desperately out of the fire.\n";
	forward();
	cout << "The beast resembles a large and menacingly dark dog, mangy and\n";
	cout << "somewhat damaged from the licks of the flame behind it.\n";
	forward();
	cout << "It looks in your eyes and growls. It is ready to attack.\n";
	forward();
	char input;
	string item;
	
	do
	{
		displayHelp();
		input = resolveDecision(player);
		if (input == 'l')
		{
			cout << "\nYou barely have time to glance at the creature as it\n";
			cout << "charges at you.\n";
			forward();
			cout << "It looks as if it has no weaknesses and will not go down easily.\n";
			input = 'r';
		}
		if (input == 's')
		{
			cout << "\nThis beast does not understand your language and the villagers\n";
			cout << "are too far away to help.\n";
			forward();
			cout << "Not that they would help you. They barely know you.\n";
			input = 'r';
		}
		if (input == 'u')
		{
			item = player.GetInventoryEntry();
			if (item == "Granny Smith")
			{
				if (changeHealth(player, eatApple(true))) { return; }
				forward();
				player.RemoveFromInventory("Granny Smith");
				input = 'r';
			}
			else if (item == "Obsidian Knife")
			{
				cout << "\nYou hold up the now shabby knife in an attempt to attack.\n";
				forward();
				forward();
				cout << "The wolf senses the knife and lunges at you, catching your\n";
				cout << "hand and mauling your arm for 5 points of damage.\n";
				forward();
				if (changeHealth(player, 5)) { return; }
				forward();
				cout << "The knife breaks in its teeth, crumbling to the ground.\n";
				forward();
				cout << "It is a very strong wolf indeed.\n";
				forward();
				player.RemoveFromInventory("Obsidian Knife");
				input = 'r';
			}
		}
	} while (input == 'r');
	if (input == 'u')
	{
		if (item == "Guardian Head")
		{
			cout << "\nYou toss the head into the beast's mouth.\n";
			forward();
			forward();
			cout << "The guardian takes one last roar before disappearing in the wolf's jaws.\n";
			forward();
			cout << "You take this precious chance to get away with your life, running\n";
			cout << "toward the end of the village with whatever stamina you can muster.\n";
		}
		else if (item == "Deathknell")
		{
			cout << "\nYou fiercely rush your blade towards the wolf.\n";
			forward();
			forward();
			cout << "It scratches you for a point of damage but your sword strike\n";
			cout << "does not miss its mark and fells the beast, piercing the brain\n";
			cout << "and impaling its head.\n";
			forward();
			if (changeHealth(player, 1)) { return; }
			forward();
			cout << "The blade drinks the blood of the beast with a voracious hunger.\n";
		}
		else
		{
			cout << "\nYou show the medallion to the beast.\n";
			forward();
			forward();
			cout << "It is entranced by the medallion and calms itself immediately.\n";
			forward();
			cout << "As you place the object on the ground, the wolf stares directly\n";
			cout << "at it and does not budge from the spot.\n";
			forward();
			cout << "You see no danger and find a chance to escape.\n";
		}
	}
	else
	{
		cout << "\nWith only your hands and no weapon, you attempt to quickly\n";
		cout << "scan the environment for available measures.\n";
		title = "What will you do against the wolf?";
		questionList.push_back("If I run fast enough, I can make the exit!");
		questionList.push_back("I can use the fire to scare off the wolf!");
		questionList.push_back("I can lure him toward the villagers and use them as bait!");
		choice = askQuestion(title, questionList);
		if (choice == 1)
		{
			cout << "You run as fast as your legs can carry you.\n";
			forward();
			forward();
			cout << "At this point, you are sure that running away never did you\n";
			cout << "any good in previous playthroughs.\n";
			forward();
			cout << "The beast catches up to you and rips your body apart for\n";
			cout << "10 points of damage.\n";
			if (changeHealth(player, 10)) { return; }
		}
		else if (choice == 2)
		{
			player.SetGoodness(player.GetGoodness() + 2);
			cout << "You make your way around the fire and grab an actual\n";
			cout << "torch without putting it in your inventory.\n";
			forward();
			forward();
			cout << "Taking advantage of the wolf's trauma, you successfully\n";
			cout << "scare it from the village without hurting it.\n";
			forward();
			cout << "The villagers carefully make their way out of the doors\n";
			cout << "and look at you, bewildered in your accomplishments.\n";
			forward();
			cout << "Satisfied with saving them, you move your way to the end\n";
			cout << "of the village.\n";
		}
		else
		{
			player.SetEvil(player.GetEvil() + 2);
			cout << "You run quickly toward the villagers' houses and make a\n";
			cout << "quick duck.\n";
			forward();
			forward();
			cout << "The wolf leaps above you and crashes through the house of\n";
			cout << "one of the villagers.\n";
			forward();
			cout << "You run for the end of the village and get away with your\n";
			cout << "life as you hear screaming in the distance and the sounds\n";
			cout << "of death.\n";
		}
	}
	forward();
	cout << "Nearly finished with your journey, you make your way into a \n";
	cout << "dark forest for your final trial...\n";
	forward();
}