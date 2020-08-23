#include<stdio.h>
#include<string.h>

#define INF 100000000

int main()
{

    // char *filename = __FILE__;
    char file[] = __FILE__;
    char *filename = strtok(file, "-");

    FILE *fin = fopen(strcat(filename, ".in"), "rb");
    filename = strtok(filename, ".");
    FILE *fout = fopen(strcat(filename, ".out"), "wb");

    int max = -INF, min = INF, s = 0, count = 0, t;

    while (fscanf(fin, "%d", &t) == 1)
    {
        count ++;
        s += t;
        if(t > max) max = t;
        if(t < min) min = t;
    }
    fprintf(fout, "min=%d\nmax=%d\naverage=%d\n", min, max, s / count);

    fclose(fin);
    fclose(fout);

    return 0;
}