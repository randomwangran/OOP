// ConsoleApplication4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
//#include <string>

enum Ranks
{
	RANK_ACE,
	RANK_2,
	RANK_3,
	RANK_4,
	RANK_5,
	RANK_6,
	RANK_7,
	RANK_8,
	RANK_9,
	RANK_10,
	RANK_JACK,
	RANK_QUEEN,
	RANK_KING,
	MAX_RANK
};

enum Suits
{
	SUIT_CLUBS,
	SUIT_DIAMONDS,
	SUIT_HEARTS,
	SUIT_SPADES,
	MAX_SUIT
};

struct Card
{
	Ranks ranks;
	Suits suits;
};

void printCard(const Card &card)
{
	switch (card.ranks)
	{
	case RANK_ACE:
		std::cout << "A";
		break;
	case RANK_2:
		std::cout << "2";
		break;
	case RANK_3:
		std::cout << "3";
		break;
	case RANK_4:
		std::cout << "4";
		break;
	case RANK_5:
		std::cout << "5";
		break;
	case RANK_6:
		std::cout << "6";
		break;
	case RANK_7:
		std::cout << "7";
		break;
	case RANK_8:
		std::cout << "8";
		break;
	case RANK_9:
		std::cout << "9";
		break;
	case RANK_10:
		std::cout << "1";
		break;
	case RANK_JACK:
		std::cout << "J";
		break;
	case RANK_QUEEN:
		std::cout << "Q";
		break;
	case RANK_KING:
		std::cout << "K";
		break;
	}

	switch (card.suits)
	{
	case SUIT_CLUBS:
		std::cout << "C";
		break;
	case SUIT_DIAMONDS:
		std::cout << "D";
		break;
	case SUIT_HEARTS:
		std::cout << "H";
		break;
	case SUIT_SPADES:
		std::cout << "S";
		break;
	}

}

int main()
{

	Card a = { RANK_ACE, SUIT_CLUBS };

	printCard(a);


	system("pause");
	return 0;

}