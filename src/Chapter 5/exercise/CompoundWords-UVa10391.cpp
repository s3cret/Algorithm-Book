// #define DEBUG
#include <string>
#include <map>
#include <iostream>
#include <vector>

#ifdef LOCAL
#include <My_Util_Cpp.h>
#endif

using namespace std;
typedef map<string, int> Map;

Map IDcache;
vector<string> Wcache;

int ID(string str)
{
    if (IDcache.find(str) != IDcache.end())
    {
        return IDcache[str];
    }

    Wcache.push_back(str);

    return IDcache[str] = Wcache.size() - 1;
}

int main()
{
#ifdef LOCAL
    io_redirect(__FILE__);
#endif
    string str;
    while (cin >> str)
    {
        ID(str);
    }

    for (int c = 0; c < Wcache.size(); c++)
    {
        string s = Wcache[c];
#ifdef DEBUG
        cout << s << endl;
#endif
        string s1 = "";
        string s2 = "";
        for (int i = 0; i < s.length() - 1; i++)
        {
            s1 += s[i];
            s2 = s.substr(i + 1);
#ifdef DEBUG
            cout << s1 << " : " << s2 << endl;
#endif
            if (IDcache.find(s1) != IDcache.end() && IDcache.find(s2) != IDcache.end())
            {
                cout << s << endl;
                break;
            }
        }
    }

    return 0;
}