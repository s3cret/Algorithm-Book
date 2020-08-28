#include<stdio.h>

int main()
{
    int count = 0;
    // printf("%d %d %d\n", count ++, count ++, count ++);
    count = count ++;
    printf("%d\n", count);

    return 0;
}