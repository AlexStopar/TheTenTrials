#include "stdafx.h"
#include <vector>
#include <string>
#include <iostream>
#include <conio.h>
#include "player.h"
#include "variousfunc.h"
using namespace std;

void theSecondTrial(Player &player, vector<string>& questionList)
{
	if (player.GetHealth() == 0) { return; }
	cout << "You find your way into a dark and ominous cavern of obsidian.\n";
	forward();
	cout << "The walls shimmer with a gleam from the light of the previous trial,\n";
	cout << "and you can hear gurgling noises deeper inside.\n";
	forward();
	cout << "You manuever your way forward until you reach a nest carrying what\n";
	cout << "looks like a grotesque combination of man and centipede.\n";
	forward();
	cout << "A gigantic caricature of a baby's head rests upon multitudes of gigantic\n";
	cout << "claws for insectoid legs.\n";
	forward();
	cout << "The centipede baby is sleeping softly, with its thousand legs seizing and\n";
	cout << "jittering every now and then.\n";
	forward();
	displayHelp();
	forward();
	cout << "\nBefore you can make any choice in the matter, the centipede baby stirs\n";
	cout << "awake and moves in a startingly quick motion as it surrounds you in a \n";
	cout << "spiral.\n";
	forward();
	cout << "It opens its eyes and releases a deafening wail, a howl that shakes the \n";
	cout << "innards of the cavern and resounds in your eardrums.\n";
	forward();

	string title = "'WAAAAAAAAAAAAAAAAAAAAAAAAAAH!' it screams. What will you do?";
	questionList.push_back("Run for the hills! Wherever the hills may be!");
	questionList.push_back("Attempt to calm down the crying centipede baby.");
	questionList.push_back("Look around for some sort of weapon.");
	int choice = askQuestion(title, questionList);
	forward();

	switch (choice)
	{
	case 1:
		cout << "Before you even think of looking for hills to run to, the centipede baby \n";
		cout << "grabs you in its adorable maw and chews on you.\n";
		forward();
		cout << "You suffer 8 points of damage inside a cute baby's mouth.\n";
		if (changeHealth(player, 8)) { return; }
		break;
	case 2:
		cout << "You remember a lullaby your mother used to sing to you when you were young.\n";
		forward();
		cout << "As if on cue...\n";
		forward();
		cout << "You sing with a frightened and hushed tone; the centipede baby seems \n";
		cout << "to be listening to your words.\n";
		forward();
		cout << "It looks relatively pleased, at least for the moment.\n";
		player.SetGoodness(player.GetGoodness() + 1);
		forward();
		break;
	default:
		cout << "You scramble to the ground, narrowly avoiding a hungry baby's maw.\n";
		forward();
		cout << "While searching, you find a lengthy shard of obsidian that you can use \n";
		cout << "as a knife for protection.\n";
		forward();
		player.AddToInventory("Obsidian Knife");
		break;
	}

	cout << "The centipede baby calms its assault and looks down at you with inquistive eyes.\n";
	forward();
	cout << "It waits for your response.\n";
	forward();
	
	char input;
	do{
		displayHelp();
		input = resolveDecision(player);
		if (input == 'l')
		{
			cout << "Getting a closer look at the beast, you see an adorable crop of dark hair on \n";
			cout << "the centipede baby's cranium.\n";
			forward();
			cout << "Such a thing would be so cute if it wasn't attached to a centipede body with \n";
			cout << "flesh like a rotting corpse and razor talons for legs.\n";
			forward();
			cout << "Its teeth, oddly well developed for a baby, do not seem friendly either.\n";
			forward();
			input = 'r';
		}
		else if (input == 't')
		{
			cout << "Before you make a brutish action, you consider the problems of acting with \n";
			cout << "only your bare hands.\n";
			forward();
			cout << "Perhaps it would be better to use a knife or some other means of dealing\n";
			cout << "with the creature instead of running for one's dear life.\n";
			forward();
			cout << "You make an entertaining dog rendition with your hands; unfortunately, \n";
			cout << "the centipede baby will require more persuasion than that.\n";
			forward();
			input = 'r';
		}
	}
	while (input == 'r');

	if (input == 'u')
	{
		string item = player.GetInventoryEntry();
		if (item == "Guardian Head")
		{
			cout << "\nYou pull out the head from your pocket and it grows to full size.\n";
			forward();
			forward();
			cout << "It lazily opens its eyes as if rising from a deep slumber.\n";
			forward();
			cout << "With a toss you throw the head at the centipede baby, the head letting \n";
			cout << "out a final roar before disappearing inside the baby's mouth.\n";
			forward();
			player.RemoveFromInventory(item);
			forward();
			cout << "As the creature enjoys its meal, you find a way to escape further down the \n";
			cout << "crevices of the cavern.\n";
			forward();
		}
		else 
		{
			cout << "You thrust your knife straight into the nearest piece of flesh you can find.\n";
			forward();
			forward();
			cout << "The centipede baby screams with a pained cry and whips you to the side, \n";
			cout << "causing you 3 damage in the process.";
			forward();
			if (changeHealth(player, 3)) { return; }
			cout << "Luckily, you find your way near the exit and make your way through as the \n";
			cout << "creature is occupied.";
			forward();
		}
	}
	else{
		cout << "You decide to confront the centipede baby with the words of a human dealing\n";
		cout << "with a child rather than the weapons of an attacker.\n";
		forward();
		title = "What sort of tone will you use with the baby?";
		questionList.push_back("A soothing and pleasant voice that a parent would use for their little baby.");
		questionList.push_back("A harsh, scathing tone to let the baby know it has been very bad.");
		questionList.push_back("Maybe it's smarter than you thought. Just talk to it like a regular human.");
		choice = askQuestion(title, questionList);
		switch (choice)
		{
		case 1:
			cout << "'Hush, little one,' you say in a soft voice.\n";
			forward();
			forward();
			cout << "The centipede baby calms down. It is a just a baby after all.\n";
			forward();
			cout << "'It's going to be alright. Go to sleep, my precious angel.'\n";
			forward();
			cout << "You start singing the child to sleep in your finest parental voice.\n";
			forward();
			cout << "After awhile, the baby is asleep and you cautiously tip-toe your way to the\n";
		    cout << "exit.\n";
			player.SetGoodness(player.GetGoodness() + 2);
			forward();
			break;
		case 2:
			cout << "'Bad! Bad freak baby thing!' you yell at the creature.\n";
			forward();
			forward();
			cout << "You assume that the baby doesn't know what you are saying and you lash\n";
			cout << "out at the thing with all sorts of terrible words.\n";
			forward();
			cout << "'Disgusting! Freakish pile of rotten flesh! Get out of my sight and \n";
			cout << "never come back!'\n";
			forward();
			cout << "The baby responds to your tone of voice and gets scared, running away\n";
			cout << "and leaving you to go to the exit in peace.\n";
			player.SetEvil(player.GetEvil() + 2);
			forward();
			break;
		default:
			cout << "'Honestly, this is all a farce, isn't it? You know what I'm saying,\n";
			cout << "don't you?'\n";
			forward();
			forward();
			cout << "The centipede baby looks awfully confused.\n";
			forward();
			cout << "Maybe it is a baby after all, you think.\n";
			forward();
			cout << "You go with your actions anyway, disinterested in the mewlings of a \n";
			cout << "stupid baby.\n";
			forward();
			cout << "'Well then, what do you have to say for yourself? No secret plan, no \n";
			cout << "ultimate role of testing the trialist?'\n";
			forward();
			cout << "'Uggy?' it says, looking rather confused.\n";
			forward();
			cout << "You sigh. 'Whatever,' you say, 'I'm out of here.'\n";
			forward();
			cout << "You leave the confused looking child onto the exit. It seems as if having \n";
			cout << "no care for fear or games leaves the purpose of the creature quite void.\n"; 
			player.SetApathy(player.GetApathy() + 2);
			forward();
			break;
		}
		cout << "You make your way onto the third trial...\n";
		forward();
	}
	
}