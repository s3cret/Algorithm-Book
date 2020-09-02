#include <stdio.h>
#include <string.h>

#ifdef LOCAL
#include <util.h>
#endif

#define maxn 100

int win, lose, left, chance;
char s[maxn], in[maxn];

void guess(char c);

int main()
{
#ifdef LOCAL

char filename[sizeof(__FILE__) + 1];
get_input_filename(filename, __FILE__);
freopen(filename, "r", stdin);

#endif


    int rnd;
    while (scanf("%d%s%s", &rnd, s, in) == 3 && rnd != -1)
    {
        printf("Round %d\n", rnd);
        win = lose = 0;
        left = strlen(s);
        chance = 7;

        for (int i = 0; i < strlen(in); i++)
        {
            guess(in[i]);
            if (win || lose)
                break;
        }

        if (win)
            puts("You win.");
        else if (lose)
            puts("You lose.");
        else
            puts("You chickened out.");

    }

    return 0;
}

void guess(char c)
{
    int bad = 1;

    for (int i = 0; i < strlen(s); i++)
        if (c == s[i]) { bad = 0; s[i] = ' '; left--; }

    if (bad) chance--;
    if (!left) win = 1;
    if (!chance) lose = 1;
}
