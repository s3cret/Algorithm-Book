#include <stdio.h>
#include <string.h>

int main()
{
    int n = 4;
    while (n--)
    {
        int arr[1024 * 4];
        memset(arr, 0, sizeof(arr));
        if (n == 1)
        {
            printf("%lu\n", sizeof(arr));
            printf("%p\n", arr);

            // if it is too big, bigger than the stack size
            int size = 1e7;
            int segementfault[size];
            printf("It won't display: %lu\n", sizeof(segementfault));
            printf("It won't display: %p\n", segementfault);
        }

        if (n == 3)
        {
            printf("%lu\n", sizeof(arr));
            printf("%p\n", arr);
        }
    }

    return 0;
}