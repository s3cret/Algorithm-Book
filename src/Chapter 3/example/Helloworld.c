#include<stdio.h>
#include<string.h>
#define length 1000
int inputs[length];
char file[] = __FILE__;

int main()
{
    char *filename = strtok(file, ".");
    strcat(filename, ".in");

    FILE *fin = fopen(filename, "rb");

    int x, n = 0; // n equals inputs.size - 1
    while(fscanf(fin, "%d", &x) == 1 && x != 0) {
        inputs[n ++] = x;
    }

    for(int i = n - 1; i > 0; i --) {
        printf("%d ", inputs[i]);
    }

    printf("%d\n", inputs[0]);
    
    fclose(fin);

    return 0;
}