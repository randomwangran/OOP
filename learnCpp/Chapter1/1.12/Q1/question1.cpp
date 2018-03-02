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

int main(){

  writeAnswer(readNumber()+readNumber());
  system("pause");
}