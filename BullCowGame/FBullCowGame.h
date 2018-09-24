#pragma once
#include <string>
class FBullCowGame
{
public:
	void Reset(); // TODO return rich return value
	int GetMaxTries();
	int GetCurrentTry();
	bool IsGameWon();
	bool CheckGuessValidity(std::string);

private:
	int MyCurrentTry;
	int MyMaxTries;
};

