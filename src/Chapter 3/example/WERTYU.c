#include<stdio.h>
#include<string.h>

char s[] = "1234567890-=\\`QWERTYUIOP[]ASDFGHJKL;'ZXCVBNM,./";

int main()
{
    char c;
    int i;
    while((c = getchar()) != EOF) {
        // printf("%d", c); // return int is 10
        for(i = 0; s[i] && s[i] != c; i ++);
        if(s[i]) putchar(s[i - 1]);
        else putchar(c);
    }

    return 0;
}