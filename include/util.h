#include <stdio.h>
#include <string.h>

#define maxn 1000000

// TODO: is it a pointer
FILE *GetFileInput(char file[])
// Notes: Remember to close the file: fclose(fin);

{
    char input[strlen(file)];
    strcpy(input, file);
    strtok(input, ".");
    strcat(input, ".in");

    FILE *fin = fopen(input, "r");

    return fin;
}

void PrintWholeDocument(FILE *fin)
{
    char buf[maxn];
    while (fgets(buf, maxn, fin) != NULL)
    {
        printf("%s", buf);
    }
}

