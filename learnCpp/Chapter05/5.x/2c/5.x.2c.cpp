// ConsoleApplication4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <random>
#include <ctime>

int checkInput();

void information()
{
	std::cout << "Let's play a game.  I'm thinking of a number.  You have 7 tries to guess what it is.";
}

int getUserInput(int count)
{
	std::cout << "Guess # " << count << ": ";
	return checkInput();

}

int getUserInitalInput()
{
	int userInput;
	std::cout << "Guess #1: ";
	return checkInput();

}

int getRandomNumber(int min, int max)
{
	static std::mt19937 mersenne(static_cast<unsigned int>(time(0))); 
	static const double fraction = 1.0 / (mersenne.max() + 1.0);
	return min + static_cast<int>((max - min + 1) * (mersenne() * fraction));
}

bool isGaussCorrect(int target, int userInput)
{
	if (target == userInput)
		return true;
	else
		return false;
}

void guessHighOrLow(int userInput, int target)
{
	if (userInput < target)
		std::cout << "Your guess is too low." << std::endl;
	else
		std::cout << "Your guess is too high." << std::endl;
}

char playAgain()
{
	while (true)
	{
		std::cout << "Would you like to play again (y/n)? ";
		char a;
		std::cin >> a;
	   
		if (a == 'y' || a == 'n')
			return a;
	}
}

int checkInput()
{
	while (true)
	{
		int userInput;
		std::cin >> userInput;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "Oops, that input is invalid.  Please try again.\n";
		}
		else
		{
			std::cin.ignore(32767, '\n');
			return userInput;
		}

	}

}

int main()
{
	tryAgain:
	information();

	int target = getRandomNumber(1, 100);
	int userInput = getUserInitalInput();
	int counter = 1;
	bool trueFlag = false;

	if (!(isGaussCorrect(target, userInput)))
	{
		do
		{
			if (isGaussCorrect(target, userInput))
			{
				trueFlag = true;
				break;
			}
			else
			{
				guessHighOrLow(userInput, target);
				counter++;
				userInput = getUserInput(counter);
			}
		} while (counter < 7);
		
			if (trueFlag)
				std::cout << "Correct! You win! " << std::endl;
			else
				std::cout << "Sorry, you lose. The correct number is " << target << std::endl;
	}
	else
	{
		std::cout << "Correct! You win! " << std::endl;
	}

	
	if (playAgain() == 'y')
		goto tryAgain;
	else
		std::cout << "Thank you for playing.";

	system("pause");

    return 0;

} 