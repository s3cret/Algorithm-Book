#include <stdio.h>
#include <string.h>

int main()
{
    char a[4] = "ab.";
    printf("Original length: %lu\n", strlen(a));
    printf("__FILE__ size: %lu\n", sizeof(__FILE__));
    printf("__FILE__ length: %lu\n", strlen(__FILE__));

    strtok(a, "."); // won't change the size
    // strcat(a, "CAT");

    printf("After    change: %lu\n", strlen(a));

    return 0;
}