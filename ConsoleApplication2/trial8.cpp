#include "stdafx.h"
#include <string>
#include <iostream>
#include <conio.h>
#include "player.h"
#include "variousfunc.h"
using namespace std;

void theEighthTrial(Player &player, vector<string>& questionList)
{
	if (player.GetHealth() == 0) { return; }
	cout << "You hear the sound of breaking waves on a cliff.\n";
	forward();
	cout << "The wind bites hard on your face but you do not\n";
	cout << "feel the lack of oxygen that the sixth trial had \n";
	cout << "from its mountainous setting.\n";
	forward();
	cout << "The way from the previous trial leads out onto a rocky\n";
	cout << "outcrop facing an ocean.\n";
	forward();
	cout << "Small plants and mosses line the top of the outcrop, and\n";
	cout << "the rocks look old and weathered.\n";
	forward();
	cout << "The outcrop is quite large and leads on a path toward the \n";
	cout << "end of the cliff.\n";
	forward();
	cout << "Walking forward, you notice that the path leads right off\n";
	cout << "the edge of the cliff into the water below.\n";
	forward();
	cout << "The ocean seems as if it could stretch out for miles and miles,\n";
	cout << "and the cliff turns out to be a lonely island in the ocean.\n";
	forward();
	cout << "You see no way to continue and no way to escape.\n";
	forward();
	
	char input;
	do
	{
		displayHelp();
		input = resolveDecision(player);
		if (input == 'l')
		{
			cout << "\nThe ocean surrounds you with deep blue water.\n";
			forward();
			cout << "It is extraordinary that the area around you could be so\n";
			cout << "deep in comparison to this lone outcrop.\n";
			forward();
			cout << "If one sinks, one would most surely fall to the bottom\n";
			cout << "of the seas.\n";
			input = 'r';
		}
		if (input == 'u')
		{
			string item = player.GetInventoryEntry();
			if (item == "Obsidian Knife" || item == "Deathknell")
			{
				cout << "You feel that a weapon will do you no good in this\n";
				cout << "circumstance.\n";
				forward();
				forward();
				cout << "There is no enemy, no beast, no warrior to stand in your way.\n";
				forward();
				cout << "Only the water and a deep drop...\n";
				forward();
				input = 'r';
			}
			else if (item == "Granny Smith")
			{
				if (changeHealth(player, eatApple(true))) { return; }
				forward();
				player.RemoveFromInventory("Granny Smith");
				input = 'r';
			}
			else if (item == "Guardian Head")
			{
				cout << "\nYou hold out the head and let it gaze into the sea.\n";
				forward();
				forward();
				cout << "'THE SEA IS SHALLOW,' it bellows before going back into\n";
				cout << "your pocket.\n";
				input = 'r';
			}
		}
	} while (input == 'r');

	if (input == 'u')
	{
		cout << "\nYou decide to see what odd powers the tempter's medallion holds.\n";
		forward();
		forward();
		cout << "As you hold the blood-red medallion up to the cliff, the sky darkens\n";
		cout << "and the smell of ocean breeze fades.\n";
		forward();
		cout << "It seems you were in an illusion all along, as the outcrop is no more\n";
		cout << "and a dark corridor remains where such beauty once stood.\n";
		forward();
	}
	else
	{
		cout << "\nYou listen softly and hear the most delicate whispers amidst\n";
		cout << "the streams of air on the outcrop.\n";
		forward();
		forward();
		cout << "'It is difficult...' the whispers begin, 'to trust that which\n";
		cout << "you are not sure...'\n";
		forward();
		cout << "'Faith is a difficult thing to comprehend...'\n";
		forward();
		enum fall { good, evil, nothing };
		fall playerFall;
		string title = "Tell us...what do you have faith in?";
		questionList.push_back("In the goodwill of all the creatures of the earth.");
		questionList.push_back("In the dark parts that will always lay within us.");
		questionList.push_back("In the virtues that will never stray us from the wrong path.");
		questionList.push_back("In blood, lust, and greed. Can't go wrong with those.");
		questionList.push_back("Nothing. I'm an atheist.");
		int choice = askQuestion(title, questionList);
		switch (choice)
		{
		case 1:
			player.SetGoodness(player.GetGoodness() + 1);
			playerFall = good;
			cout << "'There is inherent good in all the creatures of the earth,' you\n";
			cout << "hear the whispers say.\n";
			forward();
			forward();
			break;
		case 2:
			player.SetEvil(player.GetEvil() + 1);
			playerFall = evil;
			cout << "'There is inherent evil in all the creatures of the earth,' you\n";
			cout << "hear the whispers say.\n";
			forward();
			forward();
			break;
		case 3:
			player.SetGoodness(player.GetGoodness() + 2);
			playerFall = good;
			cout << "'Be warned', you hear the whispers say.\n";
			forward();
			forward();
			cout << "'Virtues were never made to help you. They were made to shackle you\n";
			cout << "to your morals.'\n";
			forward();
			break;
		case 4:
			player.SetEvil(player.GetEvil() + 2);
			playerFall = evil;
			cout << "'Be warned', you hear the whispers say.\n";
			forward();
			forward();
			cout << "'What you trust will most certainly be your downfall.'\n";
			forward();
			break;
		default:
			playerFall = nothing;
			player.SetApathy(player.GetApathy() + 2);
			cout << "'You have no faith in anything...' the whispers say.\n";
			forward();
			forward();
			cout << "Their voice ring in your ears, 'And you will never find\n";
			cout << "anything worthwhile because of it.'\n";
			forward();
			break;
		}
		cout << "'Now...' the whispers say once more, 'believe in the impossible.'\n";
		forward();
		do
		{
			title = "Fall.";
			questionList.push_back("Listen to the voices and fall.");
			questionList.push_back("Listen to your own reason and turn back.");
			choice = askQuestion(title, questionList);
			if (choice == 2)
			{
				cout << "You turn behind yourself in fear of the impossible\n";
				cout << "but see nothing to go back to.\n";
				forward();
				forward();
				cout << "There is nothing that your reason can give you but\n";
				cout << "eternity on an outcrop.\n";
				forward();
			}
		} while (choice == 2);
		cout << "You take a jump off of the cliff.\n";
		forward();
		forward();
		if (playerFall == good)
		{
			cout << "You hear the songs of angels as you fall in what\n"; 
			cout << "seems to be the heavens themselves.\n";
			forward();
			cout << "Joy and happiness fills your soul and you feel that\n";
			cout << "you are flying, rather than falling.\n";
			forward();
			cout << "You feel your mother's embrace, your first kiss, and\n";
			cout << "the greatest accomplishment of your life all at once.\n";
			forward();
			cout << "If you died here, you would die the happiest human being\n";
			cout << "that ever existed.\n";
		}
		else if (playerFall == evil)
		{
			cout << "Power fills your heart as you fall through a tunnel of\n";
			cout << "darkened flames.\n";
			forward();
			cout << "Excitement and pride fills your soul and you feel that\n";
			cout << "you could rule the world and crush it underneath your feet.\n";
			forward();
			cout << "You feel the moments you steal and get away with it, the\n";
			cout << "sweet violence toward your fellow man, and the pleasures of\n";
			cout << "your darkest desires being satiated all upon you.\n";
			forward();
			cout << "You feel you have much to do and many sins to commit.\n";
		}
		else 
		{
			cout << "You float. You lack peace, and yet you lack resolve.\n";
			forward();
			cout << "Everything feels numb, and you no longer have a direction\n";
			cout << "from which to fall.\n";
			forward();
			cout << "You suddenly become afraid. Falling means nothing, but\n";
			cout << "nothing itself?\n";
			forward();
			cout << "It can be heaven or hell if interpreted as such. The ultimate\n";
			cout << "of all ends.\n";
		}
		forward();
		cout << "When the falling stops, you stand up with a start.\n";
		forward();
		cout << "The room is a dark corridor with no ocean breeze or whispers\n";
		cout << "in the wind.\n";
		forward();
	}
	cout << "Moving forward, you make your way to the penultimate trial...\n";
	forward();
}