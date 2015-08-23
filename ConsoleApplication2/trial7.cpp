#include "stdafx.h"
#include <string>
#include <iostream>
#include <conio.h>
#include "player.h"
#include "variousfunc.h"
using namespace std;

void theSeventhTrial(Player &player, vector<string>& questionList)
{
	if (player.GetHealth() == 0) { return; }
	cout << "The green ice doors close behind you as you step further\n";
	cout << "into what seems to be a mountain temple.\n";
	forward();
	cout << "The interior intially resembles something simple yet ornate,\n";
	cout << "but you notice odd engravings on the walls of the temple\n";
	cout << "as you make your way forward.\n";
	forward();
	cout << "At first the scenes depicted resembled holy events like a\n";
	cout << "church, but you now see all sorts of evil acts on the wall.\n";
	forward();
	cout << "Theft, greed, murder, and all sorts of vile things show the\n";
	cout << "temple to be a grotesque parody of a holy place.\n";
	forward();
	cout << "At the center of the temple, you see an orange Buddha-like figure\n";
	cout << "resting atop a bladed chariot. The blades are attached to ropes\n";
	cout << "and act as if they have a will of their own.\n";
	forward();
	cout << "His back is initially to you but he lazily rolls his body over\n";
	cout << "to your side.\n";
	forward();
	cout << "'Ah,' he says, sounding mildly amused.\n";
	forward();
	cout << "'A visitor, it seems. Here to ask this mighty one for what it seeks.'\n";
	forward();
	cout << "'I can give you whatever you want.'\n";
	forward();
	bool tempted = false;
	string title = "Tell me, child, do you seek unimaginable power?";
	questionList.push_back("I do seek it.");
	questionList.push_back("I do not seek it.");
	int choice = askQuestion(title, questionList);
	if (choice == 1)
	{
		tempted = true;
		cout << "A surging power flows through your veins like electricity.\n";
		forward();
		forward();
		cout << "You feel you have the strength and speed to take on one\n";
		cout << "hundred of the deadliest wyverns.\n";
		player.SetEvil(player.GetEvil() + 2);
	}
	else {
		player.SetGoodness(player.GetGoodness() + 1);
		player.SetApathy(player.GetApathy() + 1);
		cout << "'Such a pity,' it replies.\n";
		forward();
		forward();
		cout << "'There is no reason why you should pass up the chance to\n";
		cout << "grow stronger, foolish one.'\n";
	}
	forward();
	title = "Do you also seek wealth to furnish your life for years to come?";
	questionList.push_back("Yes, I'm tired of being poor.");
	questionList.push_back("No, I honestly refuse.");
	choice = askQuestion(title, questionList);
	if (choice == 1)
	{
		tempted = true;
		cout << "Your pockets fill with gems and gold.\n";
		forward();
		forward();
		cout << "'There we are,' it says. 'Now you can support your\n";
		cout << "family like you always wanted to.'\n"; 
		player.SetEvil(player.GetEvil() + 2);
	}
	else {
		player.SetGoodness(player.GetGoodness() + 1);
		player.SetApathy(player.GetApathy() + 1);
		cout << "'Such a pity,' it replies.\n";
		forward();
		forward();
		cout << "'There is no reason why you should pass up the chance to\n";
		cout << "improve your lifestyle, stupid one.'\n";
	}
	forward();
	title = "Lastly, do you wish to gain the love of who you always wanted?";
	questionList.push_back("I would, more than anything.");
	questionList.push_back("I already have my true love, thank you.");
	questionList.push_back("I think I'll stick with being single.");
	choice = askQuestion(title, questionList);
	if (choice == 1)
	{
		player.SetEvil(player.GetEvil() + 1);
		tempted = true;
		cout << "The figure snaps his fingers as if casting a quick spell.\n";
		forward();
		forward();
		cout << "'There,' he says. 'One true love waiting on your return.'\n";
	}
	else if (choice == 2)
	{
		player.SetGoodness(player.GetGoodness() + 1);
		cout << "He smirks upon hearing you say the words 'true love'.\n";
		forward();
		forward();
		cout << "'Ah, but who is to say how long your so called true love will last?'\n"; 
	}
	else
	{
		player.SetApathy(player.GetApathy() + 1);
		cout << "'Such a pity. Have fun dying alone,' he replies.\n";
		forward();
		forward();
		cout << "You retort, 'We all die alone eventually. No use pretending\n";
		cout << "I've got a happy ending.'\n";
	}
	forward();
	cout << "'Now then,' he says after his offerings, 'What is it that you\n";
	cout << "might want?'\n";
	forward();
	cout << "'I can offer you the world and much more than the trials will\n";
	cout << "ever provide.'\n";
	forward();
	cout << "The blades attached to his chariot start whipping around fiercely,\n";
	cout << "as to scare you from moving onward past the tempter.\n";
	forward();
	
	char input;
	bool armed;
	do
	{
		displayHelp();
		input = resolveDecision(player);
		if (input == 'u')
		{
			string item = player.GetInventoryEntry();
			if (item == "Guardian Head")
			{
				cout << "\nYou hold up the head to the tempter.\n";
				forward();
				forward();
				cout << "'LIAR... USE A WEAPON.' it whispers before jumping back in your pocket.\n";
				forward();
				cout << "'You know,' the tempter offers, 'I could give you a much\n";
				cout << "better pet. A lying cat, perhaps?'\n";
			}
			else if (item == "Granny Smith")
			{
				cout << "\n'Here,' the tempter remarks, holding out his hand.\n";
				forward();
				forward();
				cout << "Why have that dinky little apple when you can have my gifts?\n";
				forward();
				cout << "You are then surrounded by gigantic, delicious fruits of all\n";
				cout << "shapes and sizes.\n";
				forward();
				cout << "They are delicious enough to make your stomach gurgle.\n";
			}
			else if (item == "Obsidian Knife")
			{
				tempted = true;
				armed = true;
				cout << "'Fancy little weapon you have there,' the tempter replies.\n";
				forward();
				forward();
				cout << "He waves his hand and your knife is now a brilliant diamond blade.\n";
				forward();
				cout << "'It can cut through anything. Except for me, that is.' He chuckles.\n";
			}
			else 
			{
				tempted = true;
				armed = true;
				cout << "'Ah,' he says with an impressed tone. 'The Deathknell.'\n";
				forward();
				forward();
				cout << "He glances at the blade and it surges with an even greater\n";
				cout << "power than you ever felt possible.\n";
			}
			forward();
			input = 'r';
		}
		else if (input == 'l')
		{
			cout << "\nYou look upon the tempter. His chariot is lavish and\n";
			cout << "terrifying to behold, and his body is rather portly.\n";
			forward();
			cout << "A blood-red medallion adorns his chest.\n";
			forward();
			cout << "However, you feel a strange force that almost attracts you\n";
			cout << "to the tempter.\n";
			forward();
			cout << "In any other case but this you would never find him\n";
			cout << "attractive, but here...\n";
			forward();
			input = 'r';
		}
	} while (input == 'r');
	if (input == 's')
	{
		cout << "\n'Come now,' the tempter says, clapping his hands and\n";
		cout << "ceasing the terrifying motion of the chariot's blades.\n";
		forward();
		cout << "'Forget these trials. All that awaits you is not reward,\n";
		cout << "but pain and regret.'\n";
		forward();
		cout << "'Those who spoke of riches from the trials came to me and\n";
		cout << "left with anything of their desires.'\n";
		forward();
		title = "Do you want to leave and live a life of luxury? I promise it.";
		questionList.push_back("You know what? I will take your offer.");
		questionList.push_back("The trials wait for me. I shall continue.");
		choice = askQuestion(title, questionList);
		if (choice == 1)
		{
			cout << "You are then transported outside of the tree in a flash.\n";
			forward();
			forward();
			cout << "As quickly as you left, you also forget all of your journey.\n";
			forward();
			cout << "You have no regrets, but you remember your reward; riches\n";
			cout << "and fortune beyond your wildest dreams.\n";
			forward();
			cout << "You come home a great ruler and are surrounded by wealth, pleasure, \n";
			cout << "and success for the rest of your days.\n";
			forward();
			cout << "Living life to the fullest, you die of old age surrounded\n";
			cout << "by family who care about you, and you lay down to rest.\n";
			forward();
			cout << "...That is, until the tempter grabs your soul and descends into\n";
			cout << "a hell from which there is no escape.\n";
			forward();
			cout << "'I forgot to mention', the tempter says, laughing as he takes\n";
			cout << "a bite out of your soul.\n";
			forward();
			cout << "'My services always come at a price.'\n";
			forward();
			cout << "You have ended your trials prematurely and paid the price.\n";
			forward();
			player.SetHealth(0);
			return;
		}
		else
		{
			cout << "'You leave me no choice then,' he says, anger welling in his voice.\n";
			forward();
			forward();
			cout << "His blades become wild with rage and whip fiercely in your direction.\n";
			forward();
		}
	}
	cout << "You decide to act against the tempter, for there are trials to be done.\n";
	title = "What will you do against the tempter?";
	questionList.push_back("Run past him! There's no way I can take on this guy!");
	questionList.push_back("I shall attack! For glory!");
	choice = askQuestion(title, questionList);
	if (choice == 1)
	{
		cout << "You make a mad dash for the space behind the tempter where\n";
		cout << "you believe the trials will continue.\n";
		forward();
		forward();
		if (armed)
		{
			cout << "The blades lunge for your neck but you deftly strike\n";
			cout << "them back.\n";
			forward();
			cout << "Your weapon serves you well.\n";
		}
		else
		{
			cout << "The blades whip themselves at you and strike a fierce\n";
			cout << "cut on your side for 2 points of damage!\n";
			forward();
			if (changeHealth(player, 2)) { return; }
		}
		forward();
		cout << "'Come back, coward!' the tempter yells as you make your\n";
		cout << "way to the back of the temple.\n";
	}
	else{
		if (armed)
		{
			cout << "You arm yourself with your weapon and jump your way\n";
			cout << "towards the tempter.\n";
			forward();
			forward();
			cout << "Brushing the blades out of the way, you stab your\n";
			cout << "own blade straight into the heart of the tempter.\n";
			forward();
			cout << "The life in his eyes fades and the medallion drops\n";
			cout << "to the floor.\n";
			forward();
			cout << "You pick it up after your sensational victory.\n";
			forward();
			player.AddToInventory("Tempter Medallion");
		}
		else 
		{
			cout << "You attempt to take on the attacker but the\n";
			cout << "blades hold you back, stabbing you in the shoulder\n";
			cout << "and throw you against the wall for 7 points of damage.\n";
			forward();
			forward();
			if (changeHealth(player, 7)) { return; }
			forward();
			cout << "'I like your tenacity, child.' He grins.\n";
			forward();
			cout << "He lets you leave, but you drag away your bloody body in shame.\n";
		}
	}
	forward();

	if (tempted)
	{
		cout << "As you leave the temple, your blessings turn to dust\n";
		cout << "and you end up with the same equipment that you brought\n";
		cout << "with you into the temple.\n";
		forward();
		cout << "The tempter's promises were hollow and useless.\n";
		forward();
	}
	cout << "With your life intact, you move your way to your next trial...\n";
	forward();
}