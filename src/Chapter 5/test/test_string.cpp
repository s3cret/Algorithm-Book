#include <string>
#include <iostream>

using namespace std;

int main()
{
    string s = "helloworld";
    string s1 = "";
    string s2 = "";

    for (int i = 0; i < s.length() - 1; i++)
    {
        s1 += s[i];
        s2 = s.substr(i + 1);
        cout << s1 << " : " << s2 << endl;
    }

    return 0;
}