#include <iostream>
#include <string>

using namespace std;

void PrintIntro();
string GetGuessAndPrintBack();

// Application starting point
int main()
{
	PrintIntro();

	constexpr int NUMBER_OF_TURNS = 5;
	for (int count = 0; count < NUMBER_OF_TURNS; count++) {
		GetGuessAndPrintBack();
	}
	system("pause");
	return 0;
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

// Implementation of get player guess
string GetGuessAndPrintBack()
{
	cout << "Enter your guess: ";
	string Guess = "";
	getline(cin, Guess);
	// print player guess
	cout
		<< "You guessed: "
		<< Guess
		<< endl;
	return Guess;
}