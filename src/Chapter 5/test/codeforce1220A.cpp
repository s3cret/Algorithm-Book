#include <stdio.h>

int main()
{

    int n;
    scanf("%d", &n);
    char s[100005];
    scanf("%s", s);
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'n')
        {
            printf("1 ");
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'z')
        {
            printf("0 ");
        }
    }

}