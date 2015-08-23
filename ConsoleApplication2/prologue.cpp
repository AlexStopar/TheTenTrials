#include "stdafx.h"
#include <vector>
#include <string>
#include <iostream>
#include <conio.h>
#include "player.h"
#include "variousfunc.h"
using namespace std;

void prologue(Player &player, vector<string>& questionList)
{
	cout << "You begin your trials by going up to the gigantic tree." << endl;
	forward();
	cout << "The entrance is dark, foreboding, and looks as if no light" << endl;
	cout << "can escape it. You hear an echo from the innards of the tree.\n" << endl;
	forward();

	string title = "Do you feel fear upon beholding the entrance to the tree?";
	questionList.push_back("I do! Free me from this torment and let me leave!");
	questionList.push_back("Indeed, but it may be worth my while if I look inside...");
	int choice = askQuestion(title, questionList);
	if (choice == 1)
	{
		cout << "You turn tail and leave, letting your cowardice take hold of you." << endl;
		forward();
		forward();
		cout << "As you turn your back, a branch whips out and deals 10 points of damage." << endl;
		forward();
		if (changeHealth(player, 10)) { return; }
	}
	forward();
	cout << "\nMustering up the bravery to move onward, you make your way into\n";
	cout << "the dark entrance.\n";
	forward();
	cout << "Within the tree is an unusual sight; the room inside is much larger than \n";
	cout << "anything the tree can support from the outside. An odd sorcery indeed.\n";
	forward();
	cout << "A large figure stands in front of a set of double doors crafted of dazzling\n"; 
	cout << "jade.\n";
	forward();
	cout << "It is holding a menacing halberd and does not have its head on its body, \n";
	cout << "keeping the appendage close by on an adjacent pedestal.\n";
	forward();
	cout << "It seems to be sleeping. The head's eyes are closed and the body is slumped.\n";
	forward();

	char input;
	do{
		displayHelp();
		input = resolveDecision(player);
		if (input == 'l')
		{
			cout << "\nYou look upon the strange creature. It has dark blue skin \n";
			cout << "and muscles that look strong enough to strangle a bull with one arm.\n";
			forward();
			cout << "Best you tread lightly and not engage the creature with violence.\n";
			forward();
			input = 'r';
		}
	} while (input == 'r');

	if (input == 't'){
		string title = "\nWhat should you do about the creature?";
		questionList.push_back("Attack the creature head on!");
		questionList.push_back("Sneak past and see if I can open the doors.");
		questionList.push_back("Take the head so he can't see me.");
		choice = askQuestion(title, questionList);
		forward();
		if (choice == 1)
		{
			cout << "You ready your fists with violence in your eyes, with absolute\n";
			cout << "certainty that you can take on the beast.\n";
			forward();
			cout << "As you near your way toward the creature, it awakens and lets out\n";
			cout << "a guttural roar from its severed head, paralyzing you with fear.\n";
			forward();
			cout << "It lunges toward you with its halberd, swinging it through the air\n";
			cout << "with a deafening whistle before impaling you to the ground for 10\n";
			cout << "points of damage.\n";
			forward();
			if (changeHealth(player, 10)) { return; }
		}
		else if (choice == 2)
			{
				cout << "You decide to sneak past the creature, gingerly stepping past the \n";
				cout << "beast and moving slowly towards the massive doors of jade.\n";
				forward();
				cout << "With enough luck, you make your way to the doors, your hands \n";
				cout << "running along the cold jade, finding some form of knob or lock.\n";
				forward();
				cout << "A dark blue hand suddenly pins you against the wall as the creature\n";
				cout << "slowly rises the rest of its body from its slumber.\n";
				forward();
				cout << "You take 2 points of damage!\n";
				if (changeHealth(player, 2)) { return; }
				cout << "The creature pulls its head up with the other hand and opens its \n";
				cout << "lightly glowing purple eyes.\n";
				forward();
				cout << "It then places you down and proceeds to speak.\n";
				forward();
			}
			else{
				cout << "You run your way up to the head and proceed to pick it up. \n";
				forward();
				cout << "It is a very large head, and you can barely lift it.\n";
				forward();
				cout << "Suddenly, the creature awakens from its slumber, its head\n";
				cout << "roaring and vibrating your body.\n";
				forward();
				cout << "It roars: 'YOU SINFUL BEAST! HOW DARE YOU COMMIT SUCH A CRIME?'\n";
				forward();
				cout << "A strange thing happens; a force emanantes from your\n";
				cout << "inventory and shrinks the head to pocket size.\n";
				forward();
				cout << "You pocket the odd trinket as the giant swings around madly,\n";
				cout << "ramming itself into the jade doors in the process.\n";
				forward();
				cout << "The doors open and you slip on by, narrowly avoiding death.\n";
				player.AddToInventory("Guardian Head");
				player.SetEvil(player.GetEvil() + 3);
				return;
			}
		}
		else{
			cout << "\nYou yell out, 'Hello there! Are you the guardian of the tree?\n";
			forward();
			cout << "The beast slowly rises and lifts its head to meet your gaze.\n";
			forward();
		}

		cout << "Speak, descendent of humanity: What do you think of my disgusting\n";
		cout << "body? Does my strength terrify you?\n";
		forward();
		title = "What do you think of me? Speak, or perish.";
		questionList.push_back("Honestly, I just really don't care.");
		questionList.push_back("You frighten me, but you may be more than what you seem.");
		questionList.push_back("Have you looked in a mirror? You're a headless freak!");
		questionList.push_back("Yeah, you're awfully disgusting.");
		questionList.push_back("What you look outside does not decide your glory inside.");
		choice = askQuestion(title, questionList);
		forward();
		switch (choice)
		{
		case 1:
			player.SetApathy(player.GetApathy() + 2);
			cout << "'Hehe, you humans are the most pathetic when you don't have opinions.'\n";
			forward();
			cout << "He lets out a short laugh and pats you on the head.\n";
			break;
		case 2:
			player.SetGoodness(player.GetGoodness() + 1);
			cout << "'Ah, you may be wiser than I thought on first glance. Then again,\n";
			cout << "humans always seem like that.'";
			break;
		case 3:
			player.SetEvil(player.GetEvil() + 2);
			cout << "He glares at you.\n";
			forward();
			cout << "If I were ill-minded to respond to words over actions, your head\n";
			cout << "would be as severed as mine.\n";
			break;
		case 4:
			player.SetEvil(player.GetEvil() + 1);
			cout << "'You should have tea with me sometime. I'm not really that\n";
			cout << "disgusting when you get to know me.'\n";
			forward();
			cout << "He frowns.\n";
			break;
		case 5:
			player.SetGoodness(player.GetGoodness() + 2);
			cout << "'You place a lowly guardian like me on a pedestal?'\n";
			forward();
			cout << "He lets out a large bellow that resounds inside the room.\n";
			forward();
			cout << "'Such refreshing flattery.'\n";
		}
		forward();
		forward();
		cout << "'Regardless of your words, human, I merely stand here to test those \n";
		cout << "who wish to squabble instead of take the trials properly.'\n";
		forward();
		cout << "The creature slams the halberd onto the doors with a 'Twang!'\n";
		cout << "and the door opens. 'Step inside for your trials, human.'\n";
		forward();
		cout << "You step inside and continue your journey.\n";
		forward();
}