#include <string>
#include <iostream>

using namespace std;

int main()
{
    string a = "Aa+bB";
    int pos = a.find("+");

    string b = a.substr(pos + 1);
    cout << b << endl;


    return 0;
}