#include <stdio.h>
#include <string.h>

int main()
{
    int T;
    scanf("%d", &T);

    while (T--)
    {
        char input[81];
        scanf("%s", input);
        int score = 0, combo = 0;
        for (int i = 0; i < strlen(input); i++) {

            if (input[i] == 'O')
            {
                combo ++;
                score += combo;
            }
            else
            {
                combo = 0;
            }
        }

        printf("%d\n", score);

    }
    return 0;
}