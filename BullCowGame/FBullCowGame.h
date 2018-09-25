#pragma once
#pragma once
#include <string>
// rebuild

class FBullCowGame
{
public:
	// no arg constructor
	FBullCowGame(); //
	// Getters
	int GetMaxTries() const;
	int GetCurrentTry() const;
	bool IsGameWon() const;

	void Reset(); // TODO return rich return value create definition file
	bool CheckGuessValidity(std::string);

private:
	int MyCurrentTry;
	int MyMaxTries;
};
// something
