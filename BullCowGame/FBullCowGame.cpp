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

	const FString HIDDEN_WORD = "futtle buckery";
	MyHiddenWord = HIDDEN_WORD;
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
FBullCowCount FBullCowGame::SubmitGuess(FString)
{
	// increment the turn number
	MyCurrentTry++;
	// set up a return variable
	FBullCowCount BullCowCount;
	// loop through all letters in the guess
	//int32 HiddenWordLength = MyHiddenWord.length();
	for (char& i : MyHiddenWord)
	{// compare letters against hidden word
			// if they match
				// increment bulls if in same place
				// increment cows if they are not
	}
	return BullCowCount;
}
