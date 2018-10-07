#include "FBullCowGame.h"
#include <map>
#define TMap std::map
//rebuild
using int32 = int;
// Constructor
FBullCowGame::FBullCowGame() {
	Reset();
}

void FBullCowGame::Reset()
{
	MyCurrentTry = 1; // Run time values override compile time vals
	bIsGameWon = false;
	constexpr int32 MAX_TRIES = 9;
	//MyMaxTries = MAX_TRIES;

	const FString HIDDEN_WORD = "abc";
	MyHiddenWord = HIDDEN_WORD;
	return;
}

int32 FBullCowGame::GetMaxTries() const
{
	TMap<int32, int32> WordLengthToMaxTries
	{
		{3, 4},
		{4, 7},
		{5, 10},
		{6, 13}
	};
	return WordLengthToMaxTries[MyHiddenWord.length()];
}

int32 FBullCowGame::GetCurrentTry() const
{
	return MyCurrentTry;
}

int32 FBullCowGame::GetHiddenWordLength() const
{
	return MyHiddenWord.length();
}

bool FBullCowGame::GetIsGameWon() const
{
	return bIsGameWon;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	// if the guess isn't an isogram
	if (!IsIsogram(Guess))
	{
		return EGuessStatus::Not_Isogram;
	}	

	// if guess isn't lowercase
	else if (!IsLowercase(Guess))
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
	MyCurrentTry++;
	
	FBullCowCount BullCowCount;
	// loop through all letters in the hidden word
	int32 WordLength = MyHiddenWord.length();// error handled input 
	// int32 GuessLength = Guess.length();
	// O(n^2)
	for (int32 HChar = 0; HChar < WordLength; HChar++)
	{ // compare letters against guess
		for (int32 GChar = 0; GChar < WordLength; GChar++)
		{
			if (Guess[GChar] == MyHiddenWord[HChar])
			{
				(HChar == GChar) == true ? BullCowCount.Bulls++ : BullCowCount.Cows++;
			}
		}
	}
	(BullCowCount.Bulls == WordLength) == true ? bIsGameWon = true : bIsGameWon = false;
	return BullCowCount;
}

bool FBullCowGame::IsIsogram(FString Word) const
{
	if (Word.length() <= 1) { return true; }
	TMap<char, bool> LetterSeen;
	// compiler decides type of iterator
	for (auto Letter : Word)
	{
		Letter = tolower(Letter);
		if (LetterSeen[Letter]) 
		{ 
			return false;
		}
		else
		{
			LetterSeen[Letter] = true;
		}
	}
	return true;
}

bool FBullCowGame::IsLowercase(FString Word) const
{
	for (auto Letter : Word)
	{
		if (!islower(Letter))
		{
			return false;
		}
	}
	return true;
}
