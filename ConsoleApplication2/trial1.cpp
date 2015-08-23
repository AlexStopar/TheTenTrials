#include "stdafx.h"
#include <vector>
#include <string>
#include <iostream>
#include <conio.h>
#include "player.h"
#include "variousfunc.h"
using namespace std;

void theFirstTrial(Player &player, vector<string>& questionList)
{
	if (player.GetHealth() == 0) { return; }
	cout << "As you walk through the foreboding jade doors, an odd cornucopia\n";
	cout << "of scents assaults your nostrils.\n";
	forward();
	cout << "You hear a 'Slam!' and the doors behind you are shut.\n";
	forward();
	cout << "The doors themselves melt and twist until they are nothing but\n";
	cout << "a jade covering on a wall.\n";
	forward();
	cout << "You are aware that there is no escape from this place, at least\n";
	cout << "until the trials are finished.\n";
	forward();
	cout << "You move your way forward and view a luxurious sight; a warm\n";
	cout << "pool of heavenly water lies at your feet, and food of the\n";
	cout << "highest quality adorns the edges.\n";
	forward();
	cout << "The juiciest fruit and the most tender meats form the scents that\n";
	cout << "invoke a vicious hunger within you.\n";
	forward();
	
	char input;
	do{
		displayHelp();
		input = resolveDecision(player);
		if (input == 's')
		{
			cout << "\nYour voice will reach no ears in this silent place.\n";
			forward();
			cout << "Honestly, who wants to talk to food before they eat it?\n";
			forward();
			input = 'r';
		}
		if (input == 'u')
		{
			string item = player.GetInventoryEntry();
			if (item == "Guardian Head")
			{
				forward();
				cout << "\nYou pull the head out of your pocket; its eyes open\n";
				cout << "with a soft and unyielding gaze.\n";
				forward();
				cout << "It starts to mash its teeth and chomp violently, as if\n";
				cout << "anticipating the food.\n";
				forward();
				cout << "'THAT FOOD...IS HEAVENLY.' It slips back into your pocket.\n";
				forward();
			}
			else{
				cout << "\nYou're not that far in the game yet, you cheater.\n";
				forward();
			}
			input = 'r';
		}
	} while (input == 'r');

	string title;
	int choice;
	if (input == 't'){
		title = "What do you want to do?";
		questionList.push_back("Eat some of the culinary delights.");
		questionList.push_back("Get in the luxurious water.");
		choice = askQuestion(title, questionList);
		if (choice == 1)
		{
			forward();
			cout << "\nYou take a bite out of the nearest salmon fillet that you\n";
			cout << "can get your hands on.\n";
			forward();
			cout << "The taste is smooth and is wonderful to the palate.\n";
			forward();
			cout << "You gain a point of health for your abilty to not look a gift\n";
			cout << "horse in the mouth.\n";
			forward();
			changeHealth(player, -1);
		}
		else
		{
			forward();
			cout << "\nYou remove your garments and slowly dip your body into the water.\n";
			forward();
			cout << "The water is warm and beckons you to stay until your muscles become\n";
			cout << "relaxed enough to continue your journey.\n";
			forward();
		}
	}
	
	cout << "\nYou then see a woman who is also bathing in the beautiful waters.\n";
	forward();
	cout << "She herself is a goddess among women; her loveliness looks as if it were\n";
	cout << "made to be pleasure to both the eyes and the body\n";
	forward();
	cout << "'Come to me,' she says, beckoning you forward with her delicate finger.\n";
	forward();
	cout << "Regardless of your sexual preferences, you move forward anyways, bound\n";
	cout << "by a force greater than mere looks.\n";
	forward();
	cout << "You behold her in her lovely form, with skin as soft as silk and hair \n";
	cout << "that flows down to her shoulders in a sensual brunette hue.\n";
	forward();
	cout << "Her nudity in the pool is vibrant, making her look much like the delicacies\n";
	cout << "that lie outside the waters.\n";
	forward();
	string gender;
	switch (player.GetSex())
	{
	case 'm':
		gender = "man";
		break;
	case 'f':
		gender = "woman";
		break;
	case 'n':
		gender = "person";
		break;
	}
	title = "Tell me, sweet " + gender + ", do you wish something of my body?";
	questionList.push_back("I'm not really attracted to girls. Sorry about that.");
	questionList.push_back("I'm not interested in sex. You don't really do anything for me.");
	questionList.push_back("You are a beautiful lady, but I must decline.");
	questionList.push_back("Perhaps a kiss, but that will be all for me.");
	questionList.push_back("Shall we feast and pleasure ourselves to our heart's content?");
	questionList.push_back("(Grab her)");
	choice = askQuestion(title, questionList);
	bool wantMan = false;
	forward();
	switch (choice)
	{
	case 1:
		wantMan = true;
		break;
	case 2:
		player.SetApathy(player.GetApathy() + 2);
		cout << "She scowls. 'Pfft. People like you are so boring. Go and pass, mortal.\n";
		forward();
		break;
	case 3:
		cout << "'Such a shame.' She reveals her true face to you in the blink of an eye.\n";
		forward();
		cout << "Your mind suddenly has visions of a creature black as tar and with wings\n";
		cout << "of batlike origin.\n";
		forward();
		cout << "You stumble back as you see the horrors of her true face.\n";
		forward();
		cout << "'Now I am not so beautiful now, am I?'\n";
		forward();
		player.SetGoodness(player.GetGoodness() + 2);
		break;
	case 4:
		cout << "'Really?' She raises an eyebrow. 'Just a small kiss?'\n";
		forward();
		cout << "You lean toward her body and plant the softest of kisses on her lips.\n";
		forward();
		cout << "She responds by extending fangs from her mouth and taking a bite\n";
		cout << "from your cheek for 3 points of damage.\n";
		if (changeHealth(player, 3)) { return; }
		cout << "'Watch your affections, trialist.' She sneers as you stumble back.\n";
		forward();
		player.SetGoodness(player.GetGoodness() + 1);
		break;
	case 5:
		cout << "You entrance yourself with pleasures beyond all compare.\n"; 
		forward();
		cout << "At the end, however, you feel weak, as if you have had vital essence\n";
		cout << "drained from your body.\n";
		forward();
		cout << "6 points to be exact.\n";
		if (changeHealth(player, 6)) { return; }
		cout << "You look in horror as the woman before you is now a batlike creature,\n";
		cout << "a succubus that has taken advantage of your lust.\n";
		forward();
		cout << "'My, my, that was divine. For me, that is.' She laughs with venom on her lips.\n"; 
		forward();
		player.SetEvil(player.GetEvil() + 1);
		break;
	case 6:
		cout << "You entrance yourself with pleasures beyond all compare.\n";
		forward();
		cout << "At the end, however, you feel weak, as if you have had vital essence\n";
		cout << "drained from your body.\n";
		forward();
		cout << "6 points to be exact.\n";
		if (changeHealth(player, 6)) { return; }
		cout << "You look in horror as the woman before you is now a batlike creature,\n";
		cout << "a succubus that has taken advantage of your lust.\n";
		forward();
		cout << "'My, that was rough. Even for me.' She seems somewhat irritated.\n";
		forward();
		player.SetEvil(player.GetEvil() + 2);
		break;
	default:
		break;
	}
	if (wantMan){
		cout << "You blink your eyes and you suddenly see a male version of the woman.\n";
		forward();
		cout << "His body looks strong and virile, and his handsomeness is beyond compare.\n";
		forward();
		cout << "He gazes into your soul with entrancingly green eyes and beckons you.\n";
		forward();
		title = "What of me now, " + gender + "? What do you think of me now?";
		questionList.push_back("(Give into your desires and jump onto him)");
		questionList.push_back("I honestly have no interest in you.");
		questionList.push_back("Fair brother, I wish only to pass to the next trial.");
		questionList.push_back("My, you are... beautiful.");
		questionList.push_back("Now that's more like it. Let's get down to what's on our minds, eh?");
		choice = askQuestion(title, questionList);
		forward();
		switch (choice)
		{
		case 1:
			player.SetEvil(player.GetEvil() + 2);
			cout << "Forbidden pleasures are yours, and he is surprised at your forcefulness.\n";
			forward();
			cout << "In midst of ectasy, you cringe in horror as he morphs into a batlike brute\n";
			cout << "and sucks 6 points of life out of your soul!\n";
			if (changeHealth(player, 6)) { return; }
			cout << "'Oh human,' he murmurs while laughing to himself. 'You are far too easy to\n"; 
			cout << "seduce.'\n";
			forward();
			break;
		case 2:
			cout << "'Pathetic', he pouts. 'Men and women would kill for the taste of this.'\n"; 
			player.SetApathy(player.GetApathy() + 2);
			forward();
			break;
		case 3:
			cout << "'I am anything but fair, you naive " + gender + ".'\n";
			forward();
			cout << "He growls and his eyes turn from dazzling green to deathly black.\n";
			forward();
			player.SetGoodness(player.GetGoodness() + 2);
			break;
		case 4:
			cout << "He moves toward you as you are almost hypnotized by his beauty, extending\n";
			cout << "his mouth to yours for a kiss.\n";
			forward();
			cout << "He bites your shoulder and puts you in 2 points of ecstatic damage.\n";
			if (changeHealth(player, 2)) { return; }
			cout << "'Such tender flesh and appetizing soul you have, fair " + gender + ".'\n";
			forward();
			player.SetGoodness(player.GetGoodness() + 1);
			break;
		default:
			cout << "You return his gaze with one of mischief, and proceed to show him the \n";
			cout << "limits of your passion.\n";
			forward();
			cout << "In midst of ectasy, you cringe in horror as he morphs into a batlike brute\n";
			cout << "and sucks 6 points of life out of your soul!\n";
			if (changeHealth(player, 6)) { return; }
			cout << "'Oh human,' he murmurs while laughing to himself. 'You are far too easy to\n";
			cout << "seduce.'\n";
			player.SetEvil(player.GetEvil() + 1);
			forward();
			break;
		}
		cout << "He waves his hand and the luxuries of the room dissipate into thin air.\n";
		forward();
		cout << "'Well then,' he says, motioning you to the next room. 'Away with you.'\n";
		forward();
	}
	else{
		cout << "She snaps her fingers and the smorgasbord vanishes along with the water.\n";
		forward();
		cout << "'Go on then', she says, motioning you to the next room. 'Get out of my sight.'\n";
		forward();
	}
	cout << "You make your way toward the next room, the scents fading as you face your next trial...\n";
	forward();
}
