// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include "player.h"
#include <string>
#include <conio.h>
#include "variousfunc.h"
#include "showtitle.h"
#include "initialize.h"
#include "prologue.h"
#include "trial1.h"
#include "trial2.h"
#include "trial3.h"
#include "trial4.h"
#include "trial5.h"
#include "trial6.h"
#include "trial7.h"
#include "trial8.h"
#include "trial9.h"
#include "trial10.h"

using namespace std;

Player player;
vector<string> questionList;

int main()
{
	showTitle();
	//makeTestInventory(player);
	char choice = 'n';
	do{
		initializeTrialist(player, questionList);
		prologue(player, questionList);
		theFirstTrial(player, questionList);
		theSecondTrial(player, questionList);
		theThirdTrial(player, questionList);
		theFourthTrial(player, questionList);
		theFifthTrial(player, questionList);
		theSixthTrial(player, questionList);
		theSeventhTrial(player, questionList);
		theEighthTrial(player, questionList);
		theNinthTrial(player, questionList);
		theTenthTrial(player, questionList);
		
		player.ShowAlignment();
		player.Reset();
		cout << "\nDo you wish to try again? (y for yes)\n";
		choice = tolower(_getch());
		cout << endl;
	} while (choice == 'y');
	
	return 0;
}



