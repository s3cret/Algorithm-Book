#include <stdio.h>
#include <string.h>

#ifdef LOCAL
#include <util.h>
#endif

#define maxn 21

int n, k, m;
int arr[maxn];
int out;

int go(int p, int t, int d);

int main()
{
#ifdef LOCAL
    char filename[sizeof(__FILE__) + 2];
    get_input_filename(filename, __FILE__);
    freopen(filename, "r", stdin);
    get_output_filename(filename);
    freopen(filename, "w", stdout);
#endif

    while (scanf("%d%d%d", &n, &k, &m) == 3 && n < 20 && n != 0)
    {
        int left = n;
        for (int i = 1; i < n + 1; i++)
            arr[i] = i;

        int p1 = n, p2 = 1;

        while (left)
        {
            p1 = go(p1, k, 1);
            p2 = go(p2, m, -1);
            printf("%3d", p1);
            left --;
            if (p2 != p1)
            {
                printf("%3d", p2);
                left --;
            }
            // after print
            arr[p1] = arr[p2] = 0;
            if (left)
            {
                printf(",");
            }
        }
        printf("\n");
    }

    return 0;
}

int go(int p, int t, int d)
{
    while (t --)
    {
        do
        {
            p = (p + d - 1 + n) % n + 1;
        }while(arr[p] == 0);

    }
    return p;
}
