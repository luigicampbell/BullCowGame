#include <iostream>
#include <string>

using namespace std;

void PrintIntro();
void PlayGame();
string GetGuess();


// Application starting point
int main()
{
	PrintIntro();
	PlayGame();
	return 0; // exit application
}

// Implementation of introduce game
void PrintIntro()
{
	constexpr int WORD_LENGTH = 9;
	cout
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
	for (int count = 0; count < NUMBER_OF_TURNS; count++) {
		string Guess = GetGuess();
		cout << "________________________________\n";
		cout
			<< "You guessed: "
			<< Guess
			<< endl;
	}
	return;
}

// Implementation of get player guess
string GetGuess()
{
	cout << "Enter your guess: ";
	string Guess = "";
	getline(cin, Guess);
	return Guess;
}

