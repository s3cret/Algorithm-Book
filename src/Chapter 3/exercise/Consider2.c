#include <stdio.h>
#include <string.h>
#define maxn 1000000 + 10

int main()
{
    char s[maxn];
    scanf("%s", s);
    int tot = 0;
    for (int i = 0; i < strlen(s); i++) {
        printf("%c ", s[i]);
        if(s[i] == '1')
        {
            tot++;
        }
    }
    printf("%d\n", tot);

    return 0;
}