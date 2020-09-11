#include <string>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

#ifdef LOCAL
#include <My_Util_Cpp.h>
#endif

using namespace std;

int n;
const int maxn = 25;

vector<int> pile[maxn];

void find_elemnt(int &p, int &h, int a)
{
    for (p = 0; p < n; p++)
    {
        for (h = 0; h < pile[p].size(); h++)
        {
            if (pile[p][h] == a)
                return;
        }
    }
}

void reset_pile(int p, int h)
{
    for (int i = h + 1; i < pile[p].size(); i++)
    {
        int b = pile[p][i];
        pile[b].push_back(b);
    }
    pile[p].resize(h + 1);
}

void pile_onto(int pa, int ha, int pb)
{
    for (int i = ha; i < pile[pa].size(); i++)
    {
        pile[pb].push_back(pile[pa][i]);
    }
    pile[pa].resize(ha);
}

void print()
{
    for (int i = 0; i < n; i++)
    {
        cout << i << ":";
        for (int j = 0; j < pile[i].size(); j++)
        {
            cout << " " << pile[i][j];
        }
        cout << "\n";
    }
}

int main()
{
#ifdef LOCAL
io_redirct(__FILE__);
#endif

    cin >> n;
    // init pile
    for (int i = 0; i < n; i++)
    {
        pile[i].push_back(i);
    }

    string s1, s2;
    int a, b;
    while (cin >> s1 >> a >> s2 >> b)
    {
        if (s1.compare("quit") == 0)
            break;

        int pa, ha, pb, hb;
        find_elemnt(pa, ha, a);
        find_elemnt(pb, hb, b);

        if (pa == pb)
            continue;

        if (s1.compare("move") == 0)
            reset_pile(pa, ha);
        if (s2.compare("onto") == 0)
            reset_pile(pb, hb);

        pile_onto(pa, ha, pb);
    }

    print();

    return 0;
}