#include <stdio.h>

void printArray(int i, char arr[2][2]);

int main()
{
    // int i = 0;
    // char a[2][2] = {{'a', 'b'}, {'x', 'z'}};
    // printArray(i, a);

    // printf("%d\n", i);

    char a;
    scanf("%c", &a);
    printf("%d\n", a);

    return 0;
}

void printArray(int i, char arr[2][2])
{
    arr[i][i] = '8';
    printf("%c\n", arr[0][0]);
    i = 123;
}