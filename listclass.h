#ifndef LISTCLASS_H
#define LISTCLASS_H

#include <list>

class ListClass
{  
private:
  
public:
  std::list<char> one;
  std::list<char> two;
  std::list<char> three;
  char arrAy[5];
  
  ListClass();

  void standart();
  static void insert_splice();
  static void show_list_one_two_three(std::list<char>&, std::list<char>&, std::list<char>&);
  void removeFunc();
};

#endif // LISTCLASS_H
