#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char remainder[4 + 1]; // +1 for the null terminator
    memset(remainder, 0, sizeof(remainder));

    printf("strlen(remainder)=%lu\n", strlen(remainder));
    remainder[strlen(remainder)] = '1';
    printf("strlen(remainder)=%lu\n", strlen(remainder));
    remainder[strlen(remainder)] = '2';
    printf("strlen(remainder)=%lu\n", strlen(remainder));
    remainder[strlen(remainder)] = '3';
    printf("strlen(remainder)=%lu\n", strlen(remainder));
    remainder[strlen(remainder)] = '4';
    printf("strlen(remainder)=%lu\n", strlen(remainder));

    printf("str=%d\n", atoi(remainder));

    return 0;
}