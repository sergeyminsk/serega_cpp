#include "listclass.h"
#include "iteratorsclass.h"

#include <vector>
#include <iostream>
#include <list>
#include <algorithm>

ListClass::ListClass()
{
  for(int i = 0; i < 5; i++)
    one.push_back(i + 97); ;
  
  for(int i = 0; i < 5; i++)
    two.push_back(i + 102);
  
  for(int i = 0; i < 5; i++)
    three.push_back(i + 107);
  
  for(int i = 0; i < 5; i++)
    arrAy[i] = i + 107;
}

void ListClass::standart()
{
    std::list<int> one(2, 1);
    std::list<int> two(2, 2);
    std::list<int> three(2, 3);
    
    one.splice(one.end(), two);
    for_each(one.begin(), one.end(), IteratorsClass::outputint);
    std::cout << "\n";

    
    one.merge(three);
    for_each(one.begin(), one.end(), IteratorsClass::outputint);
    std::cout << "\n";
    
    one.unique(); // удаляет повторяющиеся элементы
    for_each(one.begin(), one.end(), IteratorsClass::outputint);
    std::cout << "\n";

    one.remove(2);
    for_each(one.begin(), one.end(), IteratorsClass::outputint);
    std::cout << "\n";
    
    one.sort();
    for_each(one.begin(), one.end(), IteratorsClass::outputint);
    std::cout << "\n";
}

void ListClass::insert_splice()
{
  ListClass w, e;
  std::cout << "Before:\n";
  w.show_list_one_two_three(w.one, w.two, w.three);
//  for_each(w.one.begin(), w.one.end(), IteratorsClass::outputint);
  w.one.splice(w.one.end(), w.two);
  std::cout << "After .splice:\n";
  w.show_list_one_two_three(w.one, w.two, w.three);
  
  std::cout << "Before:\n";
  e.show_list_one_two_three(e.one, e.two, e.three);
  std::cout << "\tarrAy[] =\t"; 
  for(int i = 0; i < 5; i++)
    std::cout << e.arrAy[i] << " "; 
  std::cout << ";\n";
  e.one.insert(e.one.end(), e.arrAy, e.arrAy + 5);
  
  std::cout << "After .insert:\n";
  e.show_list_one_two_three(e.one, e.two, e.three);
  std::cout << "\tarrAy[] =\t"; 
  for(int i = 0; i < 5; i++)
    std::cout << e.arrAy[i] << " "; 
  std::cout << ";\n";
}

void ListClass::show_list_one_two_three(std::list<char> &one, std::list<char> &two, std::list<char> &three)
{
  std::cout << "\tone =\t";
  for_each(one.begin(), one.end(), IteratorsClass::outputchar);
  std::cout << ";\ttwo =\t";
  for_each(two.begin(), two.end(), IteratorsClass::outputchar);
  std::cout << ";\tthree =\t";
  for_each(three.begin(), three.end(), IteratorsClass::outputchar);
  std::cout << ";\n";
}
/* remove() with STL list contaner */
void ListClass::removeFunc()
{
  for_each(one.begin(), one.end(), IteratorsClass::outputchar);
  std::cout << "\n";
  one.remove('b'); // remove and change size of contaner
  for_each(one.begin(), one.end(), IteratorsClass::outputchar);
  std::cout << "\n";
  for_each(two.begin(), two.end(), IteratorsClass::outputchar);
  std::cout << "\n";
  
  /* indicating where need remove, but do not change size of contaner *
   * can help the iterator 'erase' */
  remove(two.begin(), two.end(), 'g'); 
  
  for_each(two.begin(), two.end(), IteratorsClass::outputchar);
  std::cout << "\n";
  
}

