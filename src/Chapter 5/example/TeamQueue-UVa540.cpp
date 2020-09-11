#include <cstdio>
#include <queue>
#include <map>

#ifdef LOCAL
#include <My_Util_Cpp.h>
#endif

using namespace std;

const int maxt = 1000 + 10;

int main()
{
#ifdef LOCAL
io_redirect(__FILE__);
#endif

    int t, kase = 0;

    while(scanf("%d", &t) == 1 && t)
    {
        printf("Scenario #%d\n", ++kase);

        map<int, int> team; // team[i] return the team id of x(people id)

        for (int i = 0; i < t; i ++)
        {
            int n, x;
            scanf("%d", &n);

            while (n--)
            {
                scanf("%d", &x);
                team[x] = i; // x belong to team i ( 0 <= i < t, size: t);
            }
        }

        queue<int> q, q2[maxt]; // q for team; and q2 for queue inside team;

        while (1)
        {
            int x;
            char cmd[10];

            scanf("%s", cmd);

            if (cmd[0] == 'S')
            {
                break;
            }
            else if (cmd[0] == 'E')
            {
                scanf("%d", &x);
                int t  = team[x];
                if (q2[t].empty())
                {
                    q.push(t);
                }
                q2[t].push(x);
            }
            else if (cmd[0] == 'D')
            {
                int t = q.front();
                printf("%d\n", q2[t].front());

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