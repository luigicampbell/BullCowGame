#pragma once
#pragma once
#include <string>
// rebuild
using FString = std::string; // More compatible with unreal
using int32 = int;

struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

class FBullCowGame
{
public:
	// no arg constructor
	FBullCowGame(); //
	// Getters
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;

	bool IsGameWon() const;
	bool CheckGuessValidity(FString) const;

	void Reset(); // TODO return rich return value create definition file
	
	// counts bulls and cows and increases tries
	FBullCowCount SubmitGuess(FString);

private:
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
};
// something
