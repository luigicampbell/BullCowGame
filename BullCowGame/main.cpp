#include <iostream>
#include <string>
#include <FBullCowGame.h>

// using namespace std; best practices?

void PrintIntro();
void PlayGame();
std::string GetGuess();
bool PlayAgain();

// Application starting point
int main()
{
	bool bPlayAgain = false;
	do
	{
		PrintIntro();
		PlayGame();
		bPlayAgain = PlayAgain();
	}
	while (bPlayAgain);

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
	constexpr int NUMBER_OF_TURNS = 5;
	for (int count = 1; count <= NUMBER_OF_TURNS; count++) 
	{
		std::string Guess = GetGuess();
		std::cout << "________________________________\n";
		std::cout
			<< "You guessed: "
			<< Guess
			<< endl;
	}
	return;
}

// Implementation of get player guess
std::string GetGuess()
{
	std::cout << "Enter your guess: ";
	std::string Guess = "";
	getline(cin, Guess);
	return Guess;
}

bool PlayAgain()
{
	std::cout << "Enter 'Y' for Yes or press any other key to quit... ";
	char choice getline(cin,)
	return (choice == 'y' || choice == 'Y') == true ? true : false;
}