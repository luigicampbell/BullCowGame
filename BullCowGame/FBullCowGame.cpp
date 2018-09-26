#include "FBullCowGame.h"
//rebuild
using int32 = int;
// Constructor
FBullCowGame::FBullCowGame() {
	Reset();
}

void FBullCowGame::Reset()
{
	MyCurrentTry = 1; // Run time values override compile time vals
	
	constexpr int32 MAX_TRIES = 9;
	MyMaxTries = MAX_TRIES;
	return;
}

int32 FBullCowGame::GetMaxTries() const
{
	return MyMaxTries;
}

int32 FBullCowGame::GetCurrentTry() const
{
	return MyCurrentTry;
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}

bool FBullCowGame::CheckGuessValidity(FString)
{
	return false;
}
// receives a valid guess and increments turn and returns count
BullCowCount FBullCowGame::SubmitGuess(FString)
{
	// increment the turn number
	// set up a return variable
	// loop through all letters in the guess
		// compare letters against hidden word
	return BullCowCount();
}
