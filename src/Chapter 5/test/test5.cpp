#include <iostream>
#include <algorithm>
#include <string>

// using namespace std;

int main()
{
    std::string str ("Please split this sentence into tokens");
    
    char* cstr = new char [str.length() + 1]; // +1 to store the '\0'
    strcpy(cstr, str.c_str());

    char* p = strtok(cstr, " ");

    while (p != 0)
    {
        std::cout << p << "\n";
        p = strtok(NULL, " ");
    }


    return 0;
}