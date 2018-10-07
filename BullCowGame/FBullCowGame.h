#pragma once
#pragma once
#include <string>
#include <map>
#define TMap std::map

using FString = std::string; // More compatible with unreal
using int32 = int;

struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EGuessStatus
{
	Pending,
	Ok,
	Not_Isogram,
	Wrong_Length,
	Not_Lowercase
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

	bool GetIsGameWon() const;
	EGuessStatus CheckGuessValidity(FString) const;

	void Reset(); 
	
	// counts bulls and cows and increases tries
	FBullCowCount SubmitGuess(FString);

private:
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
	bool bIsGameWon;
	bool IsIsogram(FString) const;
};

