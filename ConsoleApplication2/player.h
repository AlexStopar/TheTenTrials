#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include <string>

class Player
{
public:
	
	void Reset();
	void ShowHealth();
	void ShowAlignment();
	void AddToInventory(std::string item);
	void RemoveFromInventory(std::string selection);
	void SetHealth(int h);
	void SetName(std::string n);
	void SetApathy(int a);
	void SetEvil(int e);
	void SetGoodness(int g);
	void SetSex(char s);
	int ShowInventory();
	std::string GetInventoryEntry();
	int GetHealth();
	int GetApathy();
	int GetEvil();
	int GetGoodness();
	std::string GetName();
	char GetSex();
private:
	std::vector<std::string> inventory;
	std::string name = "Zamut";
	char sex = 'n';
	int health = 10;
	int apathy;
	int evil;
	int goodness;
};

#endif