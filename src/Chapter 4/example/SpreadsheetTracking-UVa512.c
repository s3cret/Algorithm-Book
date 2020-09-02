#include <stdio.h>
#include <string.h>

#ifdef LOCAL
#include <util.h>
#endif

#define maxn 100
#define BIG 10000

int r, c, n, d[maxn][maxn], d2[maxn][maxn], ans[maxn][maxn], op[maxn];

void copy(char type, int p, int q);
void del(char type);
void ins(char type);

// maybe change type local variable to a global one
int main()
{

#ifdef LOCAL
    char filename[sizeof(__FILE__) + 2];
    get_input_filename(filename, __FILE__);
    freopen(filename, "r", stdin);
    get_output_filename(filename);
    freopen(filename, "w", stdout);
#endif

    int r1, c1, r2, c2, q, kase = 0;
    char cmd[10];
    memset(d, 0, sizeof(d));
    while (scanf("%d%d", &r, &c) && r)
    {
        scanf("%d", &n);
        // init the r * c size matrix
        for (int i = 1; i <= r; i++)
        {
            for (int j = 1; j <= c; j++)
            {
                d[i][j] = BIG * i + j;
            }
        }

        // run command
        while (n--)
        {
            scanf("%s", cmd);

            if (cmd[0] == 'E')
            {
                scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
                int tmp = d[r1][c1];
                d[r1][c1] = d[r2][c2];
                d[r2][c2] = tmp;
            }
            else // cmd[0] = 'D' or 'I'
            {
                int a, x;
                scanf("%d", &a);
                memset(op, 0, sizeof(op));

                for (int i = 0; i < a; i++)
                {
                    scanf("%d", &x);
                    op[x] = 1;
                }

                if (cmd[0] == 'D')
                {
                    del(cmd[1]);
                }
                else
                {
                    ins(cmd[1]);
                }
            }
        }

        // init ans
        memset(ans, 0, sizeof(ans));
        for (int i = 1; i <= r; i++)
        {
            for (int j = 1; j <= c; j++)
            {
                ans[d[i][j] / BIG][d[i][j] % BIG] = i * BIG + j;
            }
        }

        if (kase > 0)
            printf("\n");

        printf("Spreadsheet #%d\n", ++kase);
        scanf("%d", &q);
        while (q--)
        {
            scanf("%d%d", &r1, &c1);
            printf("Cell data in (%d,%d) ", r1, c1);
            if (ans[r1][c1] == 0)
            {
                printf("GONE\n");
            }
            else
            {
                printf("moved to (%d,%d)\n", ans[r1][c1] / BIG, ans[r1][c1] % BIG);
            }
        }
    }

    return 0;
}

void copy(char type, int p, int q)
{
    if (type == 'R')
    {
        for (int i = 1; i <= c; i++)
        {
            d[p][i] = d2[q][i];
        }
    }
    else // type == 'C'
    {
        for (int i = 1; i <= r; i++)
        {
            d[i][p] = d2[i][q];
        }
    }
}

void del(char type)
{
    memcpy(d2, d, sizeof(d));
    int roc = type == 'R' ? r : c, roc2 = 0;
    for (int i = 1; i <= roc; i++)
    {
        if (!op[i])
        {
            copy(type, ++roc2, i);
        }
    }

    if (type == 'R')
        r = roc2;
    else
        c = roc2;
}

void ins(char type)
{
    memcpy(d2, d, sizeof(d));
    int roc = type == 'R' ? r : c, roc2 = 0;
    for (int i = 1; i <= roc; i++)
    {
        if (op[i])
        {
            copy(type, ++roc2, 0); // 0000.. to roc2
        }
        copy(type, ++roc2, i);
    }

    if (type == 'R')
        r = roc2;
    else
        c = roc2;
}
