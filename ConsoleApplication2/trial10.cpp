#include "stdafx.h"
#include <string>
#include <iostream>
#include <conio.h>
#include "player.h"
#include "variousfunc.h"
using namespace std;

void theTenthTrial(Player &player, vector<string>& questionList)
{
	if (player.GetHealth() == 0) { return; }

	cout << "You enter your way into a forest clearing, the sun \n";
	cout << "shining its way down into a perfectly circular pool\n";
	cout << "of clear water.\n";
	forward();
	cout << "The plants themselves glisten in the light, a holy glow.\n";
	forward();
	cout << "When you look up and expect the sun, however, you see nothing.\n";
	forward();
	cout << "There is no sun, no sky, or anything except the bark of the tree\n";
	cout << "that has been residing over your trials for this entire journey.\n";
	forward();
	cout << "This is the end, no doubt about it.\n";
	forward();
	cout << "You peer into the pool of water and see... yourself.\n";
	forward();
	cout << "It is not exactly yourself, though.\n";
	forward();

	int apathy = player.GetApathy();
	int evil = player.GetEvil();
	int good = player.GetGoodness();
	
	cout << "A voice suddenly rings out from the skies above.\n";
	forward();
	cout << "'" << player.GetName() << ", this is what the trials have seen you become.'\n"; 
	forward();
	if (evil > good && evil > apathy)
	{
		cout << "You see a foul and terrifying beast in the pool.\n";
		forward();
		cout << "It is wreathed in flames and destroys and kills as it pleases.\n";
		forward();
		cout << "It is nothing but the face of pure evil.\n";
	}
	else if (good > evil && good > apathy)
	{
		cout << "You see an angel, a savior of all man and woman.\n";
		forward();
		cout << "The angel is beautiful and sings of glory to all humanity.\n";
		forward();
		cout << "It is nothing but the face of pure goodness.\n";
	}
	else if (apathy > evil && apathy > good)
	{
		cout << "You see absolutely nothing.\n";
		forward();
		cout << "There is no one in the pool, not even your own reflection.\n";
		forward();
		cout << "It is nothing but what apathy brings.\n";
	}
	else if (apathy == evil && evil > good)
	{
		cout << "You see a dark god on a throne of corpses.\n";
		forward();
		cout << "It sits on its throne and rules over all evil, yet does nothing.\n";
		forward();
		cout << "It is among the dead for which it rules.\n";
	}
	else if (evil == good && evil > apathy)
	{
		cout << "You see a creature of neither good nor evil.\n";
		forward();
		cout << "It is one with its ways of humanity and inhumanity.\n";
		forward();
		cout << "It is unapologetically one with nature and the ways of life and\n";
		cout << "living.\n";
		forward();
		cout << "A being that lives beyond good and evil.\n";
	}
	else if (apathy == good && good > evil)
	{
		cout << "You see a peaceful and young soul.\n";
		forward();
		cout << "It wishes for nothing but lives in the ways of kindness\n";
		cout << "and compassion\n";
		forward();
		cout << "A being that lives in peaceful abandon.\n";
	}
	else
	{
		cout << "You see an enlightened being.\n";
		forward();
		cout << "It transcends good, evil, and all in between.\n";
		forward();
		cout << "It has ascended to true balance and godliness.\n";
		forward();
		cout << "The ultimate in neutrality.\n";
	}
	forward();
	cout << "'This is who you are, " << player.GetName() << ". This is your fate\n";
	cout << "outside of the tree that you have been so bold to survive.'\n";
	forward();
	string title = "Do you accept your true self?";
	questionList.push_back("I do. That is who I am.");
	questionList.push_back("No! That can't be me! You're wrong!");
	int choice = askQuestion(title, questionList);

	if (choice == 2)
	{
		cout << "The voice rings out once more in disappointment.\n";
		forward();
		forward();
		cout << "'You have gone so far to only reject what you have made\n";
		cout << "yourself to become.'\n";
		forward();
		cout << "'The tree has no choice but to remake you until you can accept yourself.'\n";
		forward();
		cout << "'We shall turn back time and relive your life until you are ready...'\n";
		forward();
		return;
	}
	cout << "The voice rings out in response to your acceptance.\n";
	forward();
	forward();
	cout << "'Very well then. Now we shall erase all memory of the odd and strange\n";
	cout << "happenings and leave you with nothing but your true self...'\n";
	forward();
	cout << "You wake up with a start.\n";
	forward();
	cout << "You end up outside of the tree, but the way is closed.\n";
	forward();
	cout << "Rather, there was no way at all. You try to remember your trials\n";
	cout << "but darkness clouds your mind.\n";
	forward();
	cout << "You think of it now as only a dream and move onto your life.\n";
	forward();
	cout << "If anyone asks, you merely respond that there were no trials.\n";
	forward();
	cout << "However...\n";
	forward();
	if (evil > good && evil > apathy)
	{
		cout << "You live your life for destruction's sake.\n";
		forward();
		cout << "Murdering, devouring, taking what is not yours.\n";
		forward();
		cout << "You live your life happily satiated in the pleasures of evil.\n";
	}
	else if (good > evil && good > apathy)
	{
		cout << "You live your life living to the fullest in service of others.\n";
		forward();
		cout << "Nothing but thoughts of love run through your head for the \n";
		cout << "rest of your days.\n";
		forward();
		cout << "You die happily in the company of those who love you.\n";
	}
	else if (apathy > evil && apathy > good)
	{
		cout << "You live your life detached from others.\n";
		forward();
		cout << "Nothing carries any meaning and you soon do not care if it does not.\n";
		forward();
		cout << "You live your life without living in the slightest.\n";
	}
	else if (apathy == evil && evil > good)
	{
		cout << "You live your life desperately trying to live out your pleasures.\n";
		forward();
		cout << "However, you can find no meaning in the death and destruction\n";
		cout << "that you bring to others.\n";
		forward();
		cout << "Even as you end your own life...\n";
	}
	else if (evil == good && evil > apathy)
	{
		cout << "You live your life in balance of your own desires.\n";
		forward();
		cout << "Good, evil, it means not to you.\n";
		forward();
		cout << "You are who you are and you live such that noone can convince\n";
		cout << "you otherwise.\n";
	}
	else if (apathy == good && good > evil)
	{
		cout << "You live out your life in peace with all those before you.\n";
		forward();
		cout << "Like a river, you flow with grace without conflict or desire.\n";
		forward();
		cout << "Some say that you lived for nothing but for you, your life\n";
		cout << "was lived well.\n";
	}
	else
	{
		cout << "You inexplicably live your life in nearly inhuman balance.\n";
		forward();
		cout << "Your life transcends human logic and you join the enlightened\n";
		cout << "spirits above.\n";
		forward();
		cout << "You take the next step in the transcendence of thought...\n";
	}
	forward();
}