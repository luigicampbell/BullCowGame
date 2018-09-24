#pragma once
class FBullCowGame
{
public:
	void Reset(); // TODO return rich return value
	int GetMaxTries();
	int GetCurrentTry();
	bool IsGameWon();
	bool CheckGuessValidity(string guess);

private:
	int MyCurrentTry;
	int MyMaxTries;
};

