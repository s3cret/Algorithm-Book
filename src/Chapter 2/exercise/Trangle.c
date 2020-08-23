#include<stdio.h>

void print_space(int n) {
    for (int i = 0; i < n; i++)
    {
        printf(" ");
    }
    
}

void print_sign(int n) {
    for (int i = 0; i < n; i++)
    {
        printf("#");
    }
    
}

int main()
{
    int n;
    scanf("%d", &n);
    int N = 2 * n - 1;
    for (int i = 0; i < n; i++)
    {
        print_space(i);
        print_sign(N - 2 * i);
        print_space(i);
        puts("");
    }
    

    return 0;
}