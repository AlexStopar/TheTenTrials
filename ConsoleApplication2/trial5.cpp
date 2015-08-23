#include "stdafx.h"
#include <string>
#include <iostream>
#include <conio.h>
#include "player.h"
#include "variousfunc.h"
using namespace std;

void theFifthTrial(Player &player, vector<string>& questionList)
{
	if (player.GetHealth() == 0) { return; }
	cout << "You end up in a pile of what seems like precious gold.\n";
	forward();
	cout << "Picking up a piece of gold and biting down on it, you indeed \n";
	cout << "confirm the luxury of the new room.\n";
	forward();
	cout << "Extraordinary objects such as solid gold suits of armor, tapestries \n";
	cout << "woven with gold thread, and floors paved with gold adorn the room as\n";
	cout << "if it were the palace of an emperor.\n";
	forward();
	cout << "You consider taking some of the gold with you.\n";
	forward();
	string title = "Should you take some of the excess gold around you?";
	questionList.push_back("Is that even a question? (starts filling pockets)");
	questionList.push_back("The church back home could use a couple of extra repairs...");
	questionList.push_back("Eh, this would weigh me down anyway.");
	int choice = askQuestion(title, questionList);
	switch (choice)
	{
	case 1:
		player.SetEvil(player.GetEvil() + 1);
		break;
	case 2:
		player.SetGoodness(player.GetGoodness() + 1);
		break;
	default:
		player.SetApathy(player.GetApathy() + 1);
		break;
	}
	cout << "Before you can even think about touching the gold, you \n";
	cout << "hear a loud snort.\n";
	forward();
	forward();
	cout << "A blast of heated air fills the room from further down.\n";
	forward();
	cout << "Cautiously moving forward, you see a frightening sight.\n";
	forward();
	cout << "What seems to be a draconic creature is resting amidst a nest of \n";
	cout << "golden chalices and rings.\n";
	forward();
	cout << "Its skin is purple and has two legs outstretched forward; its \n";
	cout << "claws look sharp enough to slice steel.\n";
	forward();
	cout << "Its eyes are the color of sickly gangrene and are staring right \n";
	cout << "at your face.\n";
	forward();
	cout << "It soon lifts itself with its wings onto its two legs and begins\n";
	cout << "to walk toward you with a relaxed yet terrifying pace.\n";
	forward();
	
	char input;
	do {
		displayHelp();
		input = resolveDecision(player);
		if (input == 'l')
		{
			cout << "\nUpon closer inspection its wings are tattered yet seem very strong;\n";
			cout << "they support the creature as it moves on two legs.\n";
			forward();
			cout << "Its tail is covered in sharp spikes and ends in a large anchor\n";
			cout << "of a barb.\n";
			forward();
			cout << "Drifting your eyes around you notice a golden sword at your feet.\n";
			forward();
			cout << "It glitters as if awaiting your hands.\n";
			forward();
			input = 'r';
		}
		else if (input == 'u')
		{
			string item = player.GetInventoryEntry();
			if (item == "Granny Smith")
			{
				changeHealth(player, eatApple(false));
				forward();
				player.RemoveFromInventory(item);
				forward();
			}
			else 
			{
				cout << "Not knowing what to really do with your item, you \n";
				cout << "throw your " << item << " at the creature.\n";
				forward();
				forward();
				cout << "It releases a burst of blue fire and incinerates the " << item << ".\n";
				forward();
				player.RemoveFromInventory(item);
				forward();
			}
			input = 'r';
		}
	} while (input == 'r');

	if (input == 't')
	{
		title = "What will you do against the terrible beast?";
		questionList.push_back("Find a suitable weapon.");
		questionList.push_back("Hide amongst the gold so it won't find me.");
		questionList.push_back("Give up.");
		choice = askQuestion(title, questionList);
		if (choice == 1){
			cout << "You notice the golden sword at your feet and pick it up.\n";
			forward();
			forward();
			cout << "It fits firmly into your hand and shines with a holy light.\n";
			forward();
			cout << "Aiming in your best swordfighter's stance, you take on the \n";
			cout << "reptilian horror with all your might!\n";
			forward();
			cout << "And realize far too late that the sword is actually made of gold.\n";
			forward();
			cout << "The creature melts the sword and incinerates you for 10 damage.\n";
			forward();
			if (changeHealth(player, 10)) { return; }
		}
		else if (choice == 2){
			cout << "You make your way behind a large pile of gold coins and stay \n";
			cout << "as silent as you can, hoping the creature will not hear you.\n";
			forward();
			cout << "Unfortunately, this does no good as it releases large bursts of fire\n";
			cout << "in all directions and manages to melt the pile you were hiding in.\n";
			forward();
			cout << "You manage to step back but you suffer 5 points of damage from \n";
			cout << "the heat of the melted gold.\n";
			forward();
			if (changeHealth(player, 5)) { return; }
		}
		else{
			forward();
		}
	}
	cout << "You decide to not take on the beast with your hands and try talking to it.\n";
	title = "What will you say?";
	questionList.push_back("Wyvern! I mean you no harm!");
	questionList.push_back("I beg of you, have mercy on me!");
	questionList.push_back("Touch me and I'll slice the skin from your bones!");
	questionList.push_back("Um... hey.");
	questionList.push_back("You are one hell of an ugly wyvern, y'know that?");
	choice = askQuestion(title, questionList);

	cout << "It answers your words:\n";
	forward();
	forward();

	switch (choice)
	{
	case 1:
		player.SetGoodness(player.GetGoodness() + 2);
		cout << "'Good. Most humans would either fight or flee. It's always\n";
		cout << "a bother when my prey runs.'\n"; 
		forward();
		cout << "It lets out a menacing laugh.\n";
		forward();
		cout << "'Just kidding.'\n";
		break;
	case 2:
		player.SetGoodness(player.GetGoodness() + 1);
		cout << "'If you insist. Pathetic little worm.'";
		forward();
		break;
	case 3:
		player.SetEvil(player.GetEvil() + 1);
		cout << "'Oooh, it looks as if we have a case of cowardice hiding\n";
		cout << "behind a lion's exterior.'";
		forward();
		cout << "It breathes cerulean flame in the air and you step back.\n";
		forward();
		cout << "'Don't be foolish,' it says with a grin.";
		break;
	case 4:
		player.SetApathy(player.GetApathy() + 2);
		cout << "'Hey. Was that all you had to say? I see you're not the \n";
		cout << "talkative type.'\n";
		forward();
		break;
	default:
		player.SetEvil(player.GetEvil() + 2);
		cout << "'In some circles, that would be a compliment.'\n";
		forward();
		cout << "'A wyvern would do well to strike fear and disgust into his\n";
		cout << "enemies' hearts. The only beauty I need is my flame.'\n";
		forward();
		break;
	}
	cout << "'In any case,' it continues, 'I should give you a fighting chance.'\n";
	forward();
	cout << "It whips its tail towards the ceiling and a sword that was hanging\n";
	cout << "from the ceiling falls at your feet.\n";
	forward();
	cout << "It is a sword of the blackest night, with hate and anger rising\n"; 
	cout << "from its pitch-black core.\n";
	forward();
	cout << "It is a sword of pure evil.\n";
	forward();
	title = "Take the sword named Deathknell and fight me!";
	questionList.push_back("With pleasure.");
	questionList.push_back("I don't want to fight, but this sword looks cool. Can I have it?");
	questionList.push_back("I dare not take such a cursed blade!");
	choice = askQuestion(title, questionList);
	if (choice == 1){
		player.SetEvil(player.GetEvil() + 2);
		cout << "You begin your fight with the wyvern, Deathknell in hand.\n";
		forward();
		forward();
		cout << "Vicious power courses through your veins and you feel like a dark god.\n";
		forward();
		cout << "Slash after slash produces black sparks against the wyvern's claws.\n";
		forward();
		cout << "It is no use for the wyvern, though.\n";
		forward();
		cout << "Within minutes, you slice into the neck of the beast and thrust\n";
		cout << "the cursed blade into the beast's maw. It is now dead.\n";
		forward();
		player.AddToInventory("Deathknell");
		forward();
		cout << "You then leave the beast's foetid corpse to your next trial...\n";
		forward();
	}
	else if (choice == 2){
		player.SetApathy(player.GetApathy() + 2);
		cout << "The wyvern looks at you with a puzzled face.\n";
		forward();
		forward();
		cout << "'I mean, you can, but it's slightly anticlimactic,' it replies.\n";
		forward();
		cout << "You take the sword, strap it around your back, and continue\n";
		cout << "onward toward the next trial...\n";
		forward();
		player.AddToInventory("Deathknell");
		forward();
		cout << "The wyvern, looking rather disappointed, goes back to sleep.\n";
		forward();
	}
	else{
		player.SetGoodness(player.GetGoodness() + 2);
		cout << "'Are you sure?' the wyvern replies.\n";
		forward();
		forward();
		cout << "You find yourself unable to touch the Deathknell.\n";
		forward();
		cout << "It laughs once more, a devious cackle.\n";
		forward();
		cout << "'Your morals betray your ascent to power. Go on, holy one.'\n";
		forward();
		cout << "The wyvern motions you to your exit into the next trial...\n";
		forward();
	}
}