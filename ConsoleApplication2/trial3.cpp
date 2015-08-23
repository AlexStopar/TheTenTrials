#include "stdafx.h"
#include <vector>
#include <string>
#include <iostream>
#include <conio.h>
#include "player.h"
#include "variousfunc.h"
using namespace std;

void theThirdTrial(Player &player, vector<string>& questionList)
{
	if (player.GetHealth() == 0) { return; }
	cout << "The way is dark. You can barely see in front of your eyes as\n";
	cout << "you move forward to the next trial.\n";
	forward();
	cout << "Suddenly the moon shines upon you, its gaze illuminating what\n";
	cout << "appears to be a sacrificial ground covered in patches of dry grass.\n";
	forward();
	cout << "You find it paradoxical that you would find the moon shining\n";
	cout << "inside a tree, but it is possible that you may have reached \n";
	cout << "an exit somewhere in the cavern.\n";
	forward();

	string title = "Could you run now? Could you escape and never return to these trials?";
	questionList.push_back("This is magic. I am still within the tree, aren't I?");
	questionList.push_back("To hell with these trials! To freedom!");
	int choice = askQuestion(title, questionList);
	if (choice == 2){
		cout << "You think that you have the ability to escape. You are not \n";
		cout << "bound by the trials as long as you have the choice to run!\n";
		forward();
		forward();
		cout << "At least, that's what you thought fifteen hours ago.\n";
		forward();
		cout << "Running away has led you to an endless desert of night, the grass\n";
		cout << "becoming sand under the moonlit sky.\n";
		forward();
		cout << "Indeed, the trials have you trapped here for eternity.\n";
		forward();
		cout << "You receive 10 points of damage from eternity!\n";
		if (changeHealth(player, 10)) { return; }
	}
	cout << "No, you think. The trials have a strange power beyond my knowledge.\n";
	forward();
	forward();
	cout << "It would be unwise at this point to challenge such power without expecting\n";
	cout << "some grave consequences.\n"; 
	forward();
	cout << "Moving along the sacrificial ground, you find a line of torches that \n";
	cout << "form a faint path leading to a desolate and rocky hill.\n";
	forward();
	cout << "So those are where the hills are, you think, remembering the urge to run\n";
	cout << "when facing the centipede baby.\n";
	forward();
	cout << "After a while, you move the path up the hill, passing by the haze of each torch.\n";
	forward();
	title = "Perhaps it would be wise to pick one of these torches up?";
	questionList.push_back("Yeah, this torch could come in handy for a later situation.");
	questionList.push_back("I don't really feel like taking one of these along with me.");
	questionList.push_back("You don't tell me what to do, game! I go my own path!");
	choice = askQuestion(title, questionList);
	if (choice == 1){
		cout << "Feeling that one of these torches would come in handy, you reach out \n";
		cout << "and remove one, feeling the power in your hand.\n";
		forward();
		forward();
		cout << "Unfortunately, it is unwise to place things in your pockets that are \n";
		cout << "on fire.\n";
		forward();
		cout << "You receive a point of fire damage for attemping to put a flaming\n";
		cout << "torch in your inventory.\n";
		if (changeHealth(player, 1)) { return; }
	}
	else if (choice == 2){
		cout << "You resist the urge to kleptomaniacally take everything you see.\n";
		forward();
		forward();
	}
	else {
		cout << "You are choosing one of the paths the game made for you.\n";
		forward();
		forward();
		cout << "Best you stop pretending that you have the illusion of free will.\n";
		forward();
	}

	cout << "At the top of the hill, you see a large and unusual device mounted\n";
	cout << "on a table large enough for a person to barely lie down.\n";
	forward();
	cout << "A bald and emaciated man is lying on the table, the device running \n";
	cout << "large metal spikes all throughout his body.\n";
	forward();
	cout << "His eyes are bloodshot, wide awake with pain and terror.\n";
	forward();
	cout << "Before you can speak any words to him, a large electric shock surges\n";
	cout << "through the device and fills the man with pain.\n";
	forward();
	cout << "He makes an unintelligible sound of torture and primal fear.\n";
	forward();
	cout << "'Kill me!' he finally says, his voice rushed and desperate. 'Kill \n";
	cout << "me and free me from this torment!'\n";
	forward();
	cout << "He starts sobbing and begs for your mercy.\n";
	bool isKeyholeVisible = false;
	forward();

	
	char input;
	do{
		displayHelp();
		input = resolveDecision(player);
		if (input == 'l')
		{
			cout << "\nYou see the man covered in scars that still bleed from spikes\n";
			cout << "that are driven into his flesh.\n";
			forward();
			cout << "There are burns where the electricity has run through his body as well.\n";
			forward();
			cout << "Apart from the gruesome sight, you notice an odd thing next to\n";
			cout << "the table; a keyhole.\n";
			forward();
			cout << "It looks as if it could fit a knife of some sort.\n";
			isKeyholeVisible = true;
			forward();
			input = 'r';
		}
		else if (input == 'u'){
			string item = player.GetInventoryEntry();
			if (item == "Guardian Head"){
				cout << "\nThe head rustles to life out of your pocket and stares\n";
				cout << "upon the torture device.\n";
				forward();
				forward();
				cout << "It speaks: 'IT WOULD BE WISE TO FILL THIS DEVICE'S PURPOSE.'\n";
				forward();
				cout << "It then slips back into your pocket as quickly as it awoke.\n";
				forward();
				input = 'r';
			}
			else{
				cout << "You pull out the knife with an intent to end the misery of\n";
				cout << "this poor stranger.\n";
				forward();
				forward();
				title = "How will you use the knife?";
				questionList.push_back("Slit his throat as painlessly as you can.");
				questionList.push_back("Have some fun gutting his body and making him scream.");
				if (isKeyholeVisible){
					questionList.push_back("Activate the device.");
				}
				choice = askQuestion(title, questionList);
				if (choice == 3){
					player.SetEvil(player.GetEvil() + 2);
					cout << "You stick the knife in the keyhole of the device.\n";
					forward();
					forward();
					cout << "The device whirs to life and sticks the spikes deeper into the\n";
					cout << "man, his flesh tearing and oozing blood.\n";
					forward();
					cout << "He lets out one final scream before the device bursts into flame,\n";
					cout << "and a green light emanates from the device to you for 3 points of \n";
					cout << "rejuvenating health.\n";
					forward();
					changeHealth(player, -3);
					player.RemoveFromInventory("Obsidian Knife");
					forward();
				}
				else if (choice == 2)
				{
					player.SetEvil(player.GetEvil() + 2);
					cout << "You carve into his flesh with glee, giving no mercy as \n";
					cout << "you ensure he dies a painful death.\n";
					forward();
					forward();
				}
				else{
					player.SetGoodness(player.GetGoodness() + 2);
					cout << "'Hush, poor man,' you say as you close his eyes and hold his head.\n";
					forward();
					forward();
					cout << "With a clean slice, you run the knife along his throat and slit it.\n";
					forward();
					cout << "His expression is calm as he dies out.\n";
					forward();
				}
				cout << "Feeling finished with the task, you move on forward to a\n";
				cout << "door that appears to lead nowhere.\n";
				forward();
				cout << "Upon opening that door, you move your way onto the next trial...\n";
				forward();
				return;
			}
		}
	} while (input == 'r');

	if (input == 's')
	{
		cout << "\nYou decide to speak your will to the man and answer his question.\n";
		forward();
		title = "Kill me!";
		questionList.push_back("It would be much more fun to watch you rot in pain.");
		questionList.push_back("But I... I don't want to kill you...");
		questionList.push_back("Whatever you say, man.");
		choice = askQuestion(title, questionList);
		if (choice == 1)
		{
			player.SetEvil(player.GetEvil() + 1);
			cout << "He sobs further, all hope lost from his eyes.\n";
			forward();
			forward();
			cout << "'So you're just like them, aren't you?' he mumbles to himself.\n";
			forward();
		}
		else if (choice == 2)
		{
			player.SetGoodness(player.GetGoodness() + 1);
			cout << "'You don't understand!' he yells.\n";
			forward();
			forward();
			cout << "'Don't just stand there and watch me suffer! Kill me!'\n";
			forward();
		}
		else
		{
			player.SetApathy(player.GetApathy() + 1);
			cout << "He has a glint of hope in his eyes.\n";
			forward();
			forward();
			cout << "He is convinced you just might kill him out a whim.\n";
			forward();
		}
	}
	title = "You stand here with a simple choice: Kill him or leave him?";
	questionList.push_back("Leave him and find an exit.");
	questionList.push_back("Strangle him and end his misery.");
	choice = askQuestion(title, questionList);
	if (choice == 1)
	{
		cout << "You turn your back to him amidst his cries and pleading.\n";
		forward();
		forward();
		cout << "Regardless of his pain, you see no use in committing murder.\n";
		forward();
		cout << "While attempting to escape the hill you feel a sharp pain\n";
		cout << "in your body.\n";
		forward();
		cout << "Electric shocks pulse through your body for 3 points of damage!\n";
		forward();
		if (changeHealth(player, 3)) { return; }
		cout << "It seems as if the trials will not let you escape without \n";
		cout << "ending the tortured man's misery.\n";
		forward();
	}
	
	cout << "You put your hands to his throat and squeeze.\n";
	forward();
	forward();
	cout << "The act does not take long, as his neck is weak and brittle\n";
	cout << "from starvation and torture.\n";
	forward();
	cout << "After committing the heinous act, you make your way to what seems\n";
	cout << "like a door that leads nowhere.\n";
	forward();
	cout << "Upon opening it, you make your way to your next trial...\n";
	forward();
	
	
}