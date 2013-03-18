#include "iteratorsclass.h"
#include "listclass.h"
#include "setcontainerclass.h"
#include "multimapclass.h"
#include "functorclass.h"
#include "toobig.h"
#include "patternclass.h"
#include "mainclass.h"

#include <iostream>
#include <string.h>

MainClass::MainClass() : inches(7)
{
  constructorDefault+=1; std::cout << "\nconstructor first Default № " << constructorDefault << "\n";
}
MainClass::~MainClass()
{
  destructorDefault++; std::cout << "\ndestructor first Default № " << destructorDefault << "\n";
}

char* MainClass::getValOfChar()
{
	char tempValue[80];
	std::cout << "char: \n";
	std::cin >> tempValue;
	char *returnValue = new char[strlen(tempValue) + 1] ;
	strcpy(returnValue, tempValue); //
	return returnValue;
}
void MainClass::use_ptr() const
{
  int MainClass::*pt = &MainClass::inches; 
  std::cout << "this->pt:\t-\t" << this->*pt << "\n";
  std::cout << "this->MainClass::inches:\t" << this->MainClass::inches << "\n";
}
/*
void MainClass::toBinary(int t)
{
  char end asm ("end");
  for(t = 1073741824; t > 0; t = t/2 )
  {
    if(end & t)
      std::cout << "1";
    else std::cout << "0"; 
  } 
  std::cout << "\n";
}*/