#include "iteratorsclass.h"

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <string>
#include <cmath>

void IteratorsClass::output(const std::string& s)
{
  std::cout << s << " ";
}

void IteratorsClass::outputchar(const char& s)
{
  std::cout << s << " ";
}

void IteratorsClass::outputint(const int& s)
{
  std::cout << s << " ";
}

void IteratorsClass::ostream_iterator_func()
{
  std::vector<char> nou(26);
  std::vector<std::string> via(26);
  for(int i = 0; i < 26; i++) 
    nou[i] = i+97;  
  std::ostream_iterator<char, char> out_item(std::cout, " ");
  *out_item++ = 'd';
  std::cout << "\n";
  copy(nou.begin(), nou.end(), out_item);
  std::cout << "\n";
  copy(nou.rbegin(), nou.rend(), out_item); // vyvodit nou v obratnom poryadke cherez probel
  std::cout << "\n";
  copy(nou.begin(), nou.end(), via.begin());
  for_each(via.begin(), via.end(), IteratorsClass::output);
  std::cout << "\n";
}

void IteratorsClass::back_insert_iterator_func()
{
  std::vector<std::string> nou(4);
  std::string via[2];
  
  for(int j = 0; j < 2; j++)
    for(int i = 0; i < 4; i++) 
      via[j] += i+99;  
    
  for(int i = 0; i < 4; i++)
    nou[i] = i + 97;
  
  copy(via, via + 3, std::back_insert_iterator<std::vector<std::string> >(nou));
  for_each(nou.begin(), nou.end(), output);
  std::cout << '\n';
}

void IteratorsClass::insert_iterator_func()
{
  std::vector<std::string> nou(4);
  std::string via[2];
  for(int j = 0; j < 2; j++)
    via[j] += j+101;  
    
  for(int i = 0; i < 4; i++)
    nou[i] = i + 97;
  
  std::cout << "Before:\n\tstd::vector<std::string> nou(4) =\t";
  for(int i = 0; i < 4; i++)
    std::cout << nou[i] << " ";
  std::cout << "\n\tstd::string via[2] =\t" <<  via[0] << " " << via[1] << "\n";
  
  copy(via, via + 2, std::insert_iterator<std::vector<std::string> >(nou, nou.begin()));
  
  std::cout << "After:\n\tstd::vector<std::string> nou(4) =\t";
  for_each(nou.begin(), nou.end(), output);
  std::cout << "\n\n";
}

iterator IteratorsClass::find_ar(iterator ar, int n, const double &val)
{
  for(int i = 0; i < n; i++, ar++)
    if(*ar == val)
      return ar;
    return 0;
}

void IteratorsClass::fill_of_queue()
{
  std::ostream_iterator<int, char> out_item(std::cout, " ");
  std::vector<int> vecArr(4, 0);
  for_each(vecArr.begin(), vecArr.end(), outputint);
  std::cout << "\n";
  
  std::vector<int>(3, 3); // ?????
  
  vecArr.insert(vecArr.begin() + 2, 2);
//  for(std::vector<int>::iterator i = vecArr.begin(); i != vecArr.end(); i++)
//    std::cout << vecArr[i] << " ";
  std::cout << "\n";
  
  vecArr.erase(vecArr.begin() + 2);
  copy(vecArr.begin(), vecArr.end(), out_item);
  std::cout << "\n";
}

void IteratorsClass::input_by_cin()
{
  std::vector<int> vec;
  copy(std::istream_iterator<int, char>(std::cin), std::istream_iterator<int, char>(), vec.begin());
  for_each(vec.begin(), vec.end(), outputint);
}

