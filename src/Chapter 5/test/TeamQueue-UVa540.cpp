#include <cstdio>
#include <algorithm>
#include <queue>
#include <map>

#include <My_Util_Cpp.h>


using namespace std;

map<int, int> team;

int main()
{

    io_redirect(__FILE__);

    int n, kase = 0;
    while (scanf("%d", &n) == 1 && n)
    {
        printf("Scenario #%d\n", ++kase);

        for (int i = 0; i < n; i++)
        {
            int q;
            scanf("%d", &q);
            while (q--)
            {
                int x;
                scanf("%d", &x);
                team[x] = i;
            }
        }

        char cmd[10];
        queue<int> q, q2[n + 1];
        while (1)
        {
            scanf("%s", cmd);

            if (cmd[0] == 'S')
            {
                break;
            }

            if (cmd[0] == 'E')
            {
                int x;
                scanf("%d", &x);
                int t = team[x];

                if (q2[t].empty())
                {
                    q.push(t);
                }

                q2[t].push(x);

            }
            else if (cmd[0] == 'D')
            {
                int t = q.front();
                int x = q2[t].front();
                printf("%d\n", x);
                q2[t].pop();

                if (q2[t].empty())
                {
                    q.pop();
                }
            }
        }
        printf("\n");
    }

    return 0;
}