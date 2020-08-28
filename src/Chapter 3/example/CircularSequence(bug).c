#include <stdio.h>
#include <string.h>

#define maxn 100

void swap(char *a, char *b);

int main()
{
    char input[maxn];
    scanf("%s", input);
    
    int p = strlen(input) - 1;
    for (int i = 0; i < strlen(input); i++) {

        while (p - 1 >= 0)
        {
            if (input[p] < input[p - 1])
            {
                swap(&input[p], &input[p - 1]);
            }

            p -= 1;
        }

        p = strlen(input) - 1;
    }

    puts(input);

    return 0;
}

void swap(char *a, char *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;

}
