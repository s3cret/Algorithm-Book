// #define DEBUG
#include <algorithm>
#include <iostream>
#include <string>
#include <map>
#ifdef LOCAL
#include <My_Util_Cpp.h>
#endif

using namespace std;

typedef pair<int, int> Pair;

map<string, int> IDcache;

Pair p;
// the second int should be a row number
// it would store c1 c2 to the map
// if there has already a value r, then the current r2 and r is what it is looking for
map<Pair, int> mp;

string read_data()
{
    string tmp;
    char c;
    while ((c = getchar()) && c != ',' && c != '\n' && c != EOF)
    {
        tmp += c;
    }
    return tmp;
}

int ID(string input)
{
    if (IDcache.find(input) != IDcache.end())
    {
        return IDcache[input];
    }
    return IDcache[input] = IDcache.size();
}

int main()
{
#ifdef LOCAL
    io_redirect(__FILE__);
#endif
    // ios::sync_with_stdio(false);
    int n, m;
    while (cin >> n >> m)
    {
        getchar(); // to eat the return sign

        int database[n][m], flag = 0;
        int c1, c2, r1, r2;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                database[i][j] = ID(read_data());

#ifdef DEBUG
                cout << database[i][j];
                if (j == m - 1)
                {
                    cout << endl;
                }
                else
                {
                    cout << " ";
                }
#endif
            }
        }

        for (int i = 0; i < m - 1; i++)
        {
            if (flag)
            {
                break;
            }
            for (int j = i + 1; j < m; j++)
            {
                if (flag)
                {
                    break;
                }
                mp.clear();
                for (int r = 0; r < n; r++)
                {
                    p.first = database[r][i];
                    p.second = database[r][j];
#ifdef DEBUG
                    printf("p=(%d, %d)\n", database[r][i], database[r][j]);
#endif

                    if (mp.find(p) != mp.end())
                    {
                        flag = 1;
                        r1 = min(mp[p], r);
                        r2 = max(mp[p], r);
                        c1 = min(i, j);
                        c2 = max(i, j);
                        break;
                    }
                    else
                    {
                        mp[p] = r;
                    }
                }
            }
        }

        if (flag)
        {
            cout << "NO" << endl;
            cout << r1 + 1 << ' ' << r2 + 1 << endl;
            cout << c1 + 1 << ' ' << c2 + 1 << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }
    return 0;
}