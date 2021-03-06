/*
 * This is the console executable that uses BullCow Class
 * Acts as the view in a MVC pattern and is responsible for all user interaction.
 * Game logic in FullBullCow GameClass
 */
#pragma once

#include <iostream>
#include <string>
#include "FBullCowGame.h"

// using namespace std; best practices?
using FText = std::string; //mainly for user interaction
using int32 = int;

// prototyping for in class
void PrintIntro();
void PrintGameSummary();
void PlayGame();
FText GetValidGuess();
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

void PrintIntro()
{
	int32 WORD_LENGTH = BCGame.GetHiddenWordLength();
	std::cout
		<< "Welcome to Bulls and Cows, a fun word game.\n"
		<< "{        ]\n"
		<< "O\\     /0'\n"
		<< "  B   8    \n"
		<< "Try to guess the "
		<< WORD_LENGTH
		<< " letter isogram!\n";
	return;
}

void PrintGameSummary()
{
	BCGame.GetIsGameWon() ? std::cout << "\nYou Win!\n" : std::cout << "\nYou lose...\n";
}

void PlayGame()
{
	// Implementation of the game
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries(); // Access class method and privately visible members
	// TODO Refactor to use while loop						
	while(!BCGame.GetIsGameWon() && BCGame.GetCurrentTry() <= MaxTries)
	{
		FText Guess = GetValidGuess();

		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);

		// print number of bulls and cows
		std::cout
			<< "Bulls: "
			<< BullCowCount.Bulls
			<< " | Cows: "
			<< BullCowCount.Cows;

		std::cout
			<< std::endl
			<< "________________________________\n"
			<< "You guessed: "
			<< Guess
			<< std::endl;
	}
	PrintGameSummary();

	return;
}

// Implementation of get player guess
//Loop continuously until guess is valid
FText GetValidGuess()
{
	EGuessStatus Status = EGuessStatus::Pending;
	FText Guess = "";
	do
	{
		int32 MyCurrentTry = BCGame.GetCurrentTry();

		std::cout
			<< std::endl
			<< "Try "
			<< MyCurrentTry
			<< " out of "
			<< BCGame.GetMaxTries()
			<< ", Enter your guess: ";

		std::getline(std::cin, Guess);
		Status = BCGame.CheckGuessValidity(Guess);

		switch (Status)
		{
		case EGuessStatus::Wrong_Length:
			std::cout
				<< "Please enter a "
				<< BCGame.GetHiddenWordLength()
				<< " letter word.\n\n";
			break;
		case EGuessStatus::Not_Isogram:
			std::cout
				<< "Please enter a word with no repeating letters.\n\n";
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout
				<< "Letters must be lowercase.\n\n";
			break;
		default:
			break;
		}

	} while (Status != EGuessStatus::Ok);
	return Guess;
}

bool PlayAgain()
{
	std::cout << "Enter 'Y' for Yes or press any other key to quit... ";
	FText Choice = "";
	std::getline(std::cin, Choice);
	return (Choice[0] == 'y' || Choice[0] == 'Y') == true ? true : false;
}
