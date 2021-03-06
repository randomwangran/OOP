#include "stdafx.h"
#include <iostream>
#include <string>
#include <array>
#include <cstdlib>
#include <ctime>

int getRandomNumber(int min, int max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);  // static used for efficiency, so we only calculate this value once
																				 // evenly distribute the random number across our range
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

class Creature
{
protected:
	std::string m_name;
	char m_symbol;
	int m_health;
	int m_attackDamage;
	int m_gold;
	
public:

	Creature(std::string name, char symbol, int health, int attackDamage, int gold)
		: m_name(name), m_symbol(symbol), m_health(health), m_attackDamage(attackDamage), m_gold(gold)
	{
	}

	const std::string& getName() { return m_name; }
	char getSymbol() { return m_symbol; }
	int getHealth() { return m_health; }
	int getAttackDamage() { return m_attackDamage; }
	int getGold() { return m_gold; }

	void reduceHealth(int reduce)
	{
		m_health -= reduce;
	}

	bool isDead()
	{
		if (m_health <= 0)
			return true;
		else
			return false;
	}

	void addGold(int gold)
	{
		m_gold += gold;
	}

};

class Player : public Creature
{
	int m_level = 1;
public:
	Player(std::string name)
		: Creature(name, '@', 10, 1, 0)
	{
	}

	void levelUp()
	{
		m_level += 1;
		m_attackDamage += 1; 
	}

	int getLevel()
	{
		return m_level;
	}

	bool hasWon()
	{
		if (m_level >= 20)
		   return true;
		else
		   return false;
	}


};

class Monster : public Creature
{
	
public:
	enum Type
	{
		TYPE_DRAGON,
		TYPE_ORC,
		TYPE_SLIME,
		TYPE_MAX
	};

	struct MonsterData
	{
		std::string name;
		char symbol;
		int health;
		int attackDamage;
		int gold;
	};

private:
	static MonsterData monsterData[Monster::TYPE_MAX];

public:
	Monster(Type type) : Creature(monsterData[type].name, monsterData[type].symbol, monsterData[type].health, monsterData[type].attackDamage, monsterData[type].gold)
	{
	}
	
	static Monster getRandomMonster()
	{
		return static_cast<Type> (getRandomNumber(0, TYPE_MAX - 1));
	}


};

Monster::MonsterData Monster::monsterData[Monster::TYPE_MAX]
{
	{ "dragon", 'D', 20, 4, 100 },
    { "orc", 'o', 4, 2, 25 },
    { "slime", 's', 1, 1, 10 }
};

void attackMonster(Player &p, Monster &m)
{
	if (!m.isDead())
	{
		m.reduceHealth(p.getAttackDamage());
		std::cout << "You hit the " << m.getName() << " for " << p.getAttackDamage() << " damage." << std::endl;
	}
}

void attackPlayer(Player &p, Monster &m)
{
	if (!m.isDead())
	{
		p.reduceHealth(m.getAttackDamage());
		std::cout << "The " << m.getName() << " hit you " << m.getAttackDamage() << " damage." << std::endl;
	}
}


bool fightMonster(Player &p, Monster &m)
{
	std::cout << "You have encountered a " << m.getName() << " " << m.getSymbol() << std::endl;
	std::cout << "(R)un or (F)ight: "<< std::endl;
	char choice;
	std::cin >> choice;

	switch (choice)
	{
	case 'f':
	{
		attackMonster(p,m);
		attackPlayer(p,m);

		return true;
	}

	case 'r':
	{
		int indice = getRandomNumber(0, 100);

		if (indice <= 1)
		{
			std::cout << "You failed to flee." << std::endl;
			attackPlayer(p, m);
			return true;
		}
		else
		{
			std::cout << "You successfully fled." << std::endl;
			return false;
		}
	}
	};
}


int main()
{
	std::cout << "Enter your name: ";
	std::string playerName;
	std::cin >> playerName;

	Player p(playerName);
	std::cout << "Welcome, " << p.getName() << ".\n";

	//std::cout << "You have " << p.getHealth() << " health and are carrying " << p.getGold() << " gold.\n";



	//Monster m = Monster::getRandomMonster();
	bool flagWin = p.hasWon();

		while (!(p.isDead()) && !(flagWin))
		{
			srand(static_cast<unsigned int>(time(0))); // set initial seed value to system clock
			rand(); // get rid of first result

			Monster m = Monster::getRandomMonster();
			flagWin = p.hasWon();
			bool flagFlee = fightMonster(p, m);

			do
			{
				flagFlee = fightMonster(p, m);
			} while (!m.isDead() && flagFlee);

			if (flagFlee)
			{
				std::cout << "You killed the " << m.getName() << "." << std::endl;
				p.levelUp();
				std::cout << "You found " << m.getGold() << " gold." << std::endl;
				p.addGold(m.getGold());
				std::cout << "You are now level " << p.getLevel() << "." << std::endl;
			}

		};

		if (!flagWin)
		{
			std::cout << "You died at level " << p.getLevel() << " and with " << p.getGold() << " gold." << std::endl;
			std::cout << "Too bad you can't take it with you!" << std::endl;
		}
		else
			std::cout << "Congatuation! You win with gold " << p.getGold() << std::endl;

	system("pause");

	return 0;
	
}