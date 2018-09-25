#pragma once
#include <string>
// rebuild

class FBullCowGame
{
public:
	//void Reset(); // TODO return rich return value create definition file
	int GetMaxTries();
	int GetCurrentTry();
	bool IsGameWon();
	bool CheckGuessValidity(std::string);

private:
	int MyCurrentTry = 0;
	int MyMaxTries = 5;
};
// something
