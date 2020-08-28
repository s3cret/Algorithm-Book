#include <stdio.h>
#include <string.h>

const int size = 1e6;
char s[size], t[size];

int main()
{

#ifdef LOCAL
    freopen("AllInAll-UVa10340.in", "r", stdin);
#endif

    while (scanf("%s%s", s, t) != EOF)
    {
        int ns = strlen(s);
        int nt = strlen(t);
        int i = 0;

        for (int j = 0; j < nt; j++)
        {
            if (t[j] == s[i])
            {
                i ++;
            }
        }

        printf("%s\n", i == ns ? "Yes" : "No");

    }

    return 0;
}