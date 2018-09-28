#include "FBullCowGame.h"
//rebuild
using int32 = int;
using FString = std::string;
// Constructor
FBullCowGame::FBullCowGame() {
	Reset();
}

void FBullCowGame::Reset()
{
	MyCurrentTry = 1; // Run time values override compile time vals
	
	constexpr int32 MAX_TRIES = 9;
	MyMaxTries = MAX_TRIES;

	const FString HIDDEN_WORD = "abc";
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

int32 FBullCowGame::GetHiddenWordLength() const
{
	return MyHiddenWord.length();
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	// if the guess isn't an isogram
	if (false)
	{
		return EGuessStatus::Not_Isogram;
	}	

	// if guess isn't lowercase
	else if (false)
	{
		return EGuessStatus::Not_Lowercase;
	}	
	
	// if guess isn't right length 
	else if (GetHiddenWordLength() != Guess.length())
	{
		return EGuessStatus::Wrong_Length;
	}

	else 
	{
		return EGuessStatus::Ok;
	}
}
// receives a valid guess and increments turn and returns count
FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	// increment the turn number
	MyCurrentTry++;
	// set up a return variable
	FBullCowCount BullCowCount;
	// loop through all letters in the guess
	int32 HiddenWordLength = MyHiddenWord.length();
	// int32 GuessLength = Guess.length();
	// O(n^2)
	for (int32 HChar = 0; HChar < HiddenWordLength; HChar++)
	{ // compare letters against hidden word
		for (int32 GChar = 0; GChar < HiddenWordLength; GChar++)
		{
			if (Guess[GChar] == MyHiddenWord[HChar])
			{
				(HChar == GChar) == true ? BullCowCount.Bulls++ : BullCowCount.Cows++;
			}
		}
	}
	return BullCowCount;
}
