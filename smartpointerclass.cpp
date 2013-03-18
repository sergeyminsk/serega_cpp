#include "smartpointerclass.h"

#include <string>
#include <iostream>
#include <memory>

void SmartPointerClass::simplyPointer(std::string &str)
{
  std::string *pd = new std::string(str);
//  *pd = str;
  std::cout << "" << *pd << "\t";
  delete  pd;
  return;
}

void SmartPointerClass::smartPointer(std::string &str)
{
  std::auto_ptr<std::string> ps(new std::string(str));
//  *ps = str;
  std::cout << "" << *ps << "\n";
  return;
} 
