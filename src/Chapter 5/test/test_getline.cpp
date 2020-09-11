#include <iostream>
#include <My_Util_Cpp.h>
#include <string>

using namespace std;

#define NOTFOUND string::npos

string readline()
{
    string tmp;
    getline(cin, tmp);
    return tmp;
}

int main()
{
    io_redirect(__FILE__);

    string a;

    a = readline();

    if (a.find("haelasdf") == NOTFOUND)
    {
        cout << "npos" << endl;
        cout << string::npos << endl;
        cout << a.find("helasdf") << endl;
    }

    // if ()
    // {

    // }

    return 0;
}