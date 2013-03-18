#include "setcontainerclass.h"
#include "iteratorsclass.h"

#include <iostream>
#include <set>
#include <string>
#include <iterator>
#include <algorithm>

void SetContainerClass::lowerUpperBound()
{
  std::ostream_iterator<std::string, char> out(std::cout, " ");
  std::set<std::string> c;
  std::string str3[3] = {"grungly", "heavy", "metal"};

  c.insert(str3, str3 + 3);
  copy(c.begin(), c.end(), out);
  std::cout << "\n";
  copy(c.lower_bound("ghost"), c.upper_bound("spook"), out);
  std::cout << "\n";
}
/*
 * output 'one' and 'two' by 'out' (ostream_iterator)
 */
void SetContainerClass::set_union_func()
{
  std::ostream_iterator<std::string, char> out(std::cout, " ");
  
  std::string str1[n] = {"str1.1","str1.2","str1.3","str1.4","str1.5","strO_o"};
  std::string str2[n] = {"str2.1","str2.2","str2.3","str2.4","str2.5","strO_o"};  
  
  std::set<std::string> one(str1, str1 + n);
  std::set<std::string> two(str2, str2 + n);
  
  std::set_union(one.begin(), one.end(), two.begin(), two.end(), out);
}

void SetContainerClass::set_intersection_difference_func()
{
  std::ostream_iterator<std::string, char> out(std::cout, " ");
  
  std::string str1[n] = {"str1.1","str1.2","str1.3","str1.4","str1.5","strO_o"};
  std::string str2[n] = {"str2.1","str2.2","str2.3","str2.4","str2.5","strO_o"};  
  
  std::set<std::string> one(str1, str1 + n);
  std::set<std::string> two(str2, str2 + n);
  
  std::cout << "the same elements:\n\t";
  std::set_intersection(one.begin(), one.end(), two.begin(), two.end(), out); // showing the same elements
  std::cout << "\nthe different elements\n\t";
  std::set_difference(one.begin(), one.end(), two.begin(), two.end(), out); // showing the different elements
}

void SetContainerClass::setFunc()
{
  std::cout << "before:\n\tstd::string string1[n] = { c b c d e f };\n";
  std::string string1[n] = {"c","b","c","d","e","f"};
/*  for(int i = 0; i < 6; i++)
  {
    if(i == 0) { 
      string1[i] = i + 98; 
      continue;
    }
    string1[i] = i + 97;
  }
  */
  std::set<std::string, std::less<std::string> > d1; // old implementing
  std::set<std::string> d2(string1, string1 + n); // new implementing
  std::ostream_iterator<std::string, char> out(std::cout, " ");
  std::cout << "after:\n\tstd::string string1[n] = { ";
  copy(d2.begin(), d2.end(), out);
  std::cout << "};\n";
}


