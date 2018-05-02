#include "io.h"
#include <iostream>

int readNumber()
{
  int userInput;
  std::cout << "Please input a number.";
  std::cin  >> userInput;
  return userInput;
}

void writeAnswer(int a)
{
  std::cout << a << std::endl;
}