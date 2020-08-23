#include<stdio.h>

int main()
{
// this is the so-called compile sign
#ifdef LOCAL
    printf("helloworld, local\n");
#endif

    printf("You can see me\n");

    return 0;
}