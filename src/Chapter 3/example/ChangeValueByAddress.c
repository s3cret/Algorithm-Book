#include<stdio.h>

void changeByAddress(int *i);
void changeByValue(int i);

int main()
{
    int a = 123;
    printf("Before change: %d\n", a);
    changeByAddress(&a);
    // changeByValue(a);
    printf("After  change: %d\n", a);

    return 0;
}

void changeByAddress(int *i) {
    *i = 321;
}

void changeByValue(int i) {
    i = 321;
}