#include <stdio.h>
#include <stdbool.h>

void doublePrecise();
void logic();
void ifTest();

int main()
{
    // doublePrecise();
    logic();

    return 0;
}

void ifTest() {
    if(true) {
        if(true) {
            printf("x ++");
        }
        else{
            printf("y ++");
        }
    }
}

void doublePrecise()
{
    double a;
    scanf("%lf", &a);
    printf("%.201f\n", a / 3);
}

void logic()
{
    // if(true && true || false)
    // {
    //     printf("'true && true || false' is true.\n");
    // }

    // if(false && false || true)
    // {
    //     printf("'false && false || true' is true.\n");
    // }

    bool a, b, c;
    bool array[3] = {a, b, c};
    int temp;

    for (int i = 0; i < 3; i++)
    {
        scanf("%d", &temp);
        if (temp != 0)
        {
            array[i] = false;
            printf("%s\n", array[i]);
        }
        else
        {
            array[i] = true;
        }
    }

    if (a && b || c) {
        printf("%d && %d || %d is true\n", a, b, c);
    }
    else {
        printf("%d && %d || %d is false\n", a, b, c);
    }
}