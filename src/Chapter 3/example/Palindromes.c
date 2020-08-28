#include<stdio.h>
#include<string.h>
#include<ctype.h>
const char *msg[] = {"not a palindrome", "a regular palindrome", "a mirrored string", "a mirrored palindrome"};
const char *convert_map = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";


int main()
{
    // char file[20] = __FILE__;
    // char *filename = strtok(file, ".c");
    // strcat(filename, ".in");
    
    // FILE *fin = fopen(filename, "rb");
    FILE *fin = stdin;

    char input[30];
    while(fscanf(fin, "%s", input) == 1)
    {
        int mirrored = 1, palindrome = 1;
        int n = strlen(input);

        for(int i = 0; i < (n + 1 ) / 2; i ++)
        {
            char current = input[i];
            int index;
            if (isalpha(current)) {
                index = current - 'A';
            }
            else
            {
                index = current - '0' + 25;
            }

            if (current != input[n - 1 - i])
            {
                palindrome = 0;
            }

            if ( input[n - 1 - i] != convert_map[index])
            {
                mirrored = 0;
            }

        }

        printf("%s -- is %s.\n\n", input, msg[mirrored * 2 + palindrome]);

    }

    fclose(fin);
    return 0;
}