#include <map>
#include <cstdio>

#ifdef LOCAL
#include <My_Util_Cpp.h>
#endif

using namespace std;

int main()
{
#ifdef LOCAL
    io_redirect(__FILE__);
#endif
    int n;
    while (scanf("%d", &n) && n)
    {
        bool exchange = 1;
        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            int a, b;
            scanf("%d%d", &a, &b);
            mp[a]--;
            mp[b]++;
        }

        for (map<int, int>::iterator it = mp.begin(); it != mp.end(); it++)
        {
            if (it->second != 0)
            {
                exchange = 0;
                break;
            }
        }

        if (exchange)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }

    return 0;
}