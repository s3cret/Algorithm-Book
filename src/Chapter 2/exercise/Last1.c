#include<stdio.h>

int main()
{
    int i;
    for(i = 0; i != 10; i += 1) {
        printf("%d\n", i);
        if(i == 30) {
            break;
        }
    }

    return 0;
}