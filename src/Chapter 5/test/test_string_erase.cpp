#include <string>
#include <iostream>
#include <sstream>

using namespace std;

string remove_punct(string& str)
{
    stringstream ss(str);
    string buf;
    while (ss >> buf)
    {
        for (int i = 0, len = buf.size(); i < len; i++)
        {
            if (ispunct(buf[i]))
            {
                buf.erase(i--, 1);
                len--;
            }
        }
        cout << buf << endl;
    }
    return buf;
}

int main()
{
    string a = "hello, world. this. is. my. alg.rithm";

    save(a);
    // int position, int length
    // a.erase(7, 3);

    // cout << a << endl;

    return 0;
}