#ifndef VARIOUSFUNC_H
#define VARIOUSFUNC_H
#include <vector>
#include <string>
#include "player.h"
using namespace std;

int askQuestion(string title, vector<string>& list);
void forward();
char resolveDecision(Player& player);
void displayHelp();
bool changeHealth(Player& player, int points);
void makeTestInventory(Player& player);
int eatApple(bool isSeventhTrial);
#endif