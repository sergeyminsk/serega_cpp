#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>

#include "stringclass.h"


void StringClass::stringOpenFileFunc()
{
    char info1[100];
    std::cin >> info1;
    std::cin.getline(info1, 6, 'q'); // read only six first simbls fom input stream and finishes if type 'q'
    std::cout << info1 << "\n";

    std::ifstream fin;
#ifdef WIN32
    fin.open("..\\serega*\\README.md");
#else
    fin.open("..//README.md");
#endif
    if(fin.is_open() == false)
    {
      std::cerr << "can not open file \n";
      exit(1);
    }
      std::string item;
      int count = 1;

    do
    {
      std::getline(fin, item, '\n');
      std::cout << count << "\t:\t" << item << std::endl;
      ++count;
    } while(fin);

    std::cout << "\tstringOpenFileFunc()  done\n";
    fin.close();
}

void StringClass::stringHowTo()
{
      std::string firstValString("qwertyuiopasdfghjklzxcvbnm");
      std::string secValString  ("qwertyuiopasdfghjklzxcvbnm");
      std::string thirdValString;
      char char_val = 'A';

      if(firstValString.length()== secValString.size()) // length and size return the same value
      {
        std::cout << "Pass!\n";
      }else
      {
        std::cout << "Fail!\n";
      }
      std::cout << "firstValString.length():\t" << firstValString.length() << "\n";
      std::cout << "firstValString.size():\t\t" << firstValString.size() << "\n";

      std::cout << "std::string::npos:\t" << std::string::npos << "\n\n"; // max value what can contain std::string

      std::cout << "find(\"i\", 0):\t"
                << firstValString.find("i", 7) << "\n\n"; // returnes int value that indicate to value before "i"

      std::cout << "rfind(\"io\"):\t"
                << firstValString.rfind("io") << "\n\n";

      std::cout << "find_first_of(\"io\"):\t"
                << firstValString.find_first_of("io") << "\n\n";

      std::cout << "find_last_of(\"io\"):\t"
                << firstValString.find_last_of("io") << "\n\n"; // count includes finding symbol

      std::cout << "find_first_not_of(\"qwe\"):\t"
                << firstValString.find_first_not_of("qwe") << "\n\n";

      std::cout << "firstValString.find_last_not_of(\"qwe\"):\t"
                << firstValString.find_last_not_of("qwe") << "\n\n";

      std::cout << "before:\t" << char_val << "\tafter:\t" << (char)std::tolower(char_val) << "\n\n"; // or toupper()

      std::string hok(20, 'o');
      std::cout << hok << "\n";

      { std::cout << "\n";
        std::srand(std::time(0));
        std::cout << std::rand() % 5 << std::rand() % 10 << "\n"; // every second different value
        std::cout << "\n";
      }


      thirdValString.reserve(0);
      std::cout << "firstValString.find(\"i\", 0):\t" << firstValString.find("i", 7) << "\n\n"
                << firstValString.c_str() << "\t"
                << firstValString.capacity() << "\n\n"; // count of all symbols
      std::cout << "thirdValString.capacity()\t" << thirdValString.capacity() << "\n\n";// count of all symbols
      thirdValString = "qwsade";
      std::cout << thirdValString << "\t" << thirdValString.c_str()
                << "\t\n\nthirdValString.capacity():\t" << thirdValString.capacity() << "\n\n";

      std::wstring hh; // mean std::string with wchar_t
      wchar_t rr;
      std::cout << "hh.capacity():\t" << hh.capacity() << "\nsizeof(rr):\t" << sizeof(rr) << "\n";
}
