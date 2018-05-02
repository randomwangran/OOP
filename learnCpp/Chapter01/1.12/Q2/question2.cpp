#include <iostream>
#include "io.cpp"

int readNumber();
void writeAnswer(int a);

int main(){
  writeAnswer(readNumber()+readNumber());
  system("pause");
}