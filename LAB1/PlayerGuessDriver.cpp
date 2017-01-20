#if !defined (GUESS_ENUM)
#define GUESS_ENUM
	enum GuessEnum {EXACT, TOO_LOW, TOO_HIGH};
#endif

#include "Text.h"
#include "ReadFile.h"
#include "Random.h"
#include "Keyboard.h"

#include <iostream>
using namespace std;

//insert your methods here
int getSecret(int *);
int* getRange();
int getGuess(int *);
GuessEnum processGuess(int, int);
int play (int *, int);

int main()
{
	String* n = createString("n");
	String* ready_str = readString("Are you ready to play? (y/n) ");

	while (compare(n, ready_str) != 0)
	{
		destroyString(ready_str);
	   
		//DO THIS
		  
		int* range = new int[2];
		int secret;
		int guessTotal;
		  
		range = getRange();
		secret = getSecret(range);
		guessTotal = play(range, secret);
		  
		delete []range;

		cout << "You got it in " << guessTotal << " guesses!" << endl;
		cin.ignore();
		ready_str = readString("Are you ready to play? (y/n) ");
	}

	destroyString(ready_str);
	destroyString(n);
	return 0;
}

// Make random number and return it
int getSecret(int *range)
{
	int secret;
	
	secret = getRandomInt(range[0], range[1]);
	
	return secret;
}

int* getRange()
{
	string prompt;
	string storage;
	
	cout << "Enter the file name containing the range for the secret number: ";
	storage = &readString(prompt);
	
	ReadFile* rf = createReadFile(storage);
	
	int *range = new int[2];
	
	for(int i = 0; i < 2; i++) {
		string *temp;
		
		temp = rf->readLine(rf);
		range[i] = a_to_i(temp);
	}
	return range;
}

int getGuess (int* range)
{
	int guess;
	
	cout << "Enter your guess: ";
	cin >> guess;
	
	while (guess < range[0] || guess > range[1]) {
		cout << "Wrong guess.\n" << "Enter your guess: ";
		cin >> guess;
	}
	
	return guess;
}

GuessEnum processGuess(int guess, int secret)
{
	GuessEnum tester;
	
	if (guess == secret)
		return tester = EXACT;
	else if (guess < secret)
		return tester = TOO_LOW;
	else if (guess > secret)
		return tester = TOO_HIGH;
}

int play (int* range, int secret)
{
	int counter = 0, guess = 0;
	GuessEnum result;
	
	while (result != EXACT)
	{
		counter++;
		guess = getGuess(range);
		result = processGuess(guess, secret);
		
		if (result == TOO_LOW)
			cout << "Too low\n";
		else if (result == TOO_HIGH)
			cout << "Too high\n";
	}
	
	return counter;
}