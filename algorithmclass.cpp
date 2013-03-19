#include "algorithmclass.h"

#include <iostream>
#include <string>
#include <algorithm>


/* change and mix letters in stream */
void AlgorithmClass::algorithm()
{
  std::string letters;
  std::cout << "Enter letters(quit to quit): ";
  while(std::cin >> letters && letters != "quit")
  {
    std::cout << "Permutation of " << letters << "\n";
    sort(letters.begin(), letters.end());
    std::cout << letters << "\n";
    while(next_permutation(letters.begin(), letters.end()))
      std::cout << letters << "\n";
    std::cout << "Enter next sequence(quit to quit): ";
  }
    
  
}

