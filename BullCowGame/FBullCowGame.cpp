#include "FBullCowGame.h"
//rebuild

// Constructor
FBullCowGame::FBullCowGame() {
	Reset();
}

void FBullCowGame::Reset()
{
	MyCurrentTry = 1; // Run time values override compile time vals
	
	constexpr int MAX_TRIES = 9;
	MyMaxTries = MAX_TRIES;
	return;
}

int FBullCowGame::GetMaxTries() const
{
	return MyMaxTries;
}

int FBullCowGame::GetCurrentTry() const
{
	return MyCurrentTry;
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}

bool FBullCowGame::CheckGuessValidity(std::string)
{
	return false;
}