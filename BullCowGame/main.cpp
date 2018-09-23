#include <iostream>
#include <string>

using namespace std;

void PrintIntro();
string GetGuessAndPrintBack();

// Application starting point
int main()
{
	PrintIntro();
	GetGuessAndPrintBack();
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
		<< " letter isogram!\n"
		<< "Enter your guess: ";
	return;
}

// Implementation of get player guess
string GetGuessAndPrintBack()
{
	string Guess = "";
	getline(cin, Guess);
	// print player guess
	cout
		<< "You guessed: "
		<< Guess
		<< endl;
	return Guess;
}