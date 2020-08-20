#include<stdio.h>

char *scanf_with_hint();
int * test();

int main()
{
    int input;
    // scanf("%d", &input);
    // printf("%d%d%d\n", input % 10, input / 10 % 10, input / 100);

    char *p = scanf_with_hint("First hint");
    char *password = "secret";

    printf("%s\n", p);
    printf("%s\n", p);

    printf("%p\n", test());
    return 0;
}

char * scanf_with_hint(char *hint)
{
    char *string = "helloworld";
    printf("%s\n", hint);
    return string;
}

int * test()
{
    int a = 123;
    printf("The address of var is %p\n", &a);
    int *p = &a;
    return p;
}