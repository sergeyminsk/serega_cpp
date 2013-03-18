#include "multimapclass.h"

#include <iostream>
#include <map>
#include <iterator>

MultiMapClass::MultiMapClass()
{
    std::multimap<int, std::string> codes; // or "MapCode codes;" if defined "typedef std::multimap<int, std::string> MapCode;"

    codes.insert(std::pair<const int, std::string>(415, "San Francisco"));
/*    
    codes.insert(std::pair<const int, std::string>(510, "Oakland"));
    codes.insert(std::pair<const int, std::string>(718, "Brooklyn"));
    codes.insert(std::pair<const int, std::string>(718, "Staten Island"));
    codes.insert(std::pair<const int, std::string>(415, "San Rafael"));
    codes.insert(std::pair<const int, std::string>(510, "Berkeley"));
*/
    std::cout << "415: " << codes.count(415) << "\n"; // codes.count(415) - return  number(int) of  contain's string with the code '415' in 'codes'
    std::cout << "718: " << codes.count(718) << "\n"; // ---- /
    std::cout << "510: " << codes.count(510) << "\n"; // ---- /
    
    std::cout << "\tCode\tCity\n";
    
    std::multimap<int, std::string>::iterator it;
    for (it = codes.begin(); it != codes.end(); ++it) // show the all container codes the code and the string
        std::cout << "\t" << (*it).first << "\t" << (*it).second    << "\n";

    std::cout << "Cities with code 718:\n";
    std::pair<std::multimap<int, std::string>::iterator, std::multimap<int, std::string>::iterator> range = codes.equal_range(415);
    for (it = range.first; it != range.second; ++it)
        std::cout <<  (*it).second    << "\n";  
    //std::pair<int, int>::first;// r;
}

