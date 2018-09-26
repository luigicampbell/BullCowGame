/*
 * This is the console executable that uses BullCow Class
 * Acts as the view in a MVC pattern and is responsible for all user interaction.
 * Game logic in FullBullCow GameClass
 */

#include <iostream>
#include <string>
#include "FBullCowGame.h"

// using namespace std; best practices?
using FText = std::string; //mainly for user interaction
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetGuess();
bool PlayAgain();

// Application starting point
FBullCowGame BCGame; // instantiating game in global scope
int main()//something
{
	bool bPlayAgain = false;
	do
	{
		PrintIntro();
		PlayGame();
		bPlayAgain = PlayAgain();
	} while (bPlayAgain);

	return 0; // exit application
}

// Implementation of introduce game
void PrintIntro()
{
	constexpr int WORD_LENGTH = 9;
	std::cout
		<< "Welcome to Bulls and Cows, a fun word game.\n"
		<< "Try to guess the "
		<< WORD_LENGTH
		<< " letter isogram!\n";
	return;
}

void PlayGame()
{
	// Implementation of the game
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries(); // Access class method and privately visible members
	// TODO Refactor to use while loop						
	for (int32 count = 1; count <= MaxTries; count++)
	{
		FText Guess = GetGuess();
		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
		// print number of bulls and cows
		std::cout
			<< "Bulls: "
			<< BullCowCount.Bulls
			<< "| Cows: "
			<< BullCowCount.Cows
			<< std::endl;

		std::cout
			<< "________________________________\n"
			<< "You guessed: "
			<< Guess
			<< std::endl;
	}
	return;
}

// Implementation of get player guess
FText GetGuess()
{
	int32 MyCurrentTry = BCGame.GetCurrentTry();
	std::cout 
		<< "Try "
		<< MyCurrentTry
		<< ", Enter your guess: ";
	FText Guess = "";
	std::getline(std::cin, Guess);
	return Guess;
}

bool PlayAgain()
{
	std::cout << "Enter 'Y' for Yes or press any other key to quit... ";
	FText Choice = "";
	std::getline(std::cin, Choice);
	return (Choice[0] == 'y' || Choice[0] == 'Y') == true ? true : false;
}