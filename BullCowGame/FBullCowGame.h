#pragma once
#pragma once
#include <string>
// rebuild
using FString = std::string; // More compatible with unreal
using int32 = int;
class FBullCowGame
{
public:
	// no arg constructor
	FBullCowGame(); //
	// Getters
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	bool IsGameWon() const;

	void Reset(); // TODO return rich return value create definition file
	bool CheckGuessValidity(FString);

private:
	int32 MyCurrentTry;
	int32 MyMaxTries;
};
// something
