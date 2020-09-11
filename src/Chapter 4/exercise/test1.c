#include <stdio.h>

typedef struct MyCell
{
    int type2;
    int type;
}MyCell;

void change(MyCell* m)
{
    m->type = 123;
}

int main()
{

    MyCell a = {.type = 1};
    MyCell* b = &a;
    printf("a.type=%d\n", a.type);

    change(&a);
    printf("a.type=%d\n", a.type);

    printf("address of a.type=%p\n", &a.type);
    printf("address of a=%p\n", &a);

    b->type = 321;
    printf("a.type=%d\n", a.type);

    return 0;
}