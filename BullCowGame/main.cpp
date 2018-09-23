#include <iostream>
#include <string>

using namespace std;

int main()
{
	constexpr int WORD_LENGTH = 5;
	string Guess = "";
	cout 
		<< "Welcome to Bulls and Cows, a fun word game.\n"
		<< "Try to guess the "
		<< WORD_LENGTH
		<< " letter isogram!\n";

	// get player guess
	cin >> Guess;

	// repeat player guess
	cout 
		<<"You guessed: "
		<< Guess 
		<< endl;

	system("pause");
	return 0;
}