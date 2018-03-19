// ConsoleApplication4.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <string>

enum MonsterType
{
	MONSTERTYPE_DRAGON,
	MONSTERTYPE_GOBLIN,
	MONSTERTYPE_ORC,
	MONSTERTYPE_SKELETON,
	MONSTERTYPE_TROLL,
	MONSTERTYPE_VAMPIRE,
	MONSTERTYPE_ZOMBIE,
	MAX_MONSTER_TYPES
};


class Monster
{
	MonsterType m_type;
	std::string m_name;
	std::string m_roar;
	int m_hit;
};

int main()
{


	std::cout << "Press enter to exit" << std::endl;
	std::cin.get();

	return 0;
}