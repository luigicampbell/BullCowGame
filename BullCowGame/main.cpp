#include <iostream>
#include <string>
#include "FBullCowGame.h"

// using namespace std; best practices?

void PrintIntro();
void PlayGame();
std::string GetGuess();
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
	int MaxTries = BCGame.GetMaxTries(); // Access class method and privately visible members
							
	for (int count = 1; count <= MaxTries; count++)
	{
		std::string Guess = GetGuess();
		std::cout << "________________________________\n";
		std::cout
			<< "You guessed: "
			<< Guess
			<< std::endl;
	}
	return;
}

// Implementation of get player guess
std::string GetGuess()
{
	int MyCurrentTry = BCGame.GetCurrentTry();
	std::cout 
		<< "Try "
		<< MyCurrentTry
		<< ", Enter your guess: ";
	std::string Guess = "";
	std::getline(std::cin, Guess);
	return Guess;
}

bool PlayAgain()
{
	std::cout << "Enter 'Y' for Yes or press any other key to quit... ";
	std::string Choice = "";
	std::getline(std::cin, Choice);
	return (Choice[0] == 'y' || Choice[0] == 'Y') == true ? true : false;
}