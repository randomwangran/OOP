// classChildChecker.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h" // what's this headfile?
#include <iostream>
#include <string>

class ParentA {

public: ParentA() {}

		std::string m_name;

		std::string getName() const { return m_name; }

		void printName() const {
		
			std::cout << "I am a child of A." << std::endl;

		}
};

class ParentB {
public: ParentB() {}

		std::string m_name;
		
		void functionParentB() {
			std::cout << "I am a child of B" << std::endl;
		}
};

class childA : public ParentA {
public:

	int ChildA() {}

	void printNameInChild() {

		std::cout << "This is a print from child" << std::endl;
	}

};

class childB : public ParentB {
public:

	int ChildB() {}

};

int main() {

	childA lucifer;
	childB angela;

	lucifer.m_name = "Lucifer";
	angela.m_name = "Angela";

	std::cout << lucifer.getName() << '\n';
	std::cout << angela.getName() << '\n';

	//lucifer.printName();
	lucifer.printNameInChild();

	std::cout << "Hello world!" << std::endl;
	
}

/* notes

Why Shift + F11 cannot jump back out the entry point?

For example, if the cursor is on 


    getName(), then press 'F11', I go to its definition,

    but, I want goback by pressing 'Shift+F11', but not work.

	I guess, its the issue with my emacs kbd set for VS.

	In exploring, I found that "Alt + F11", which is peak definition.

	It is more handy.
  */