#include <stdio.h>
#include <string.h>

#define INF 1000000000

int main()
{
    char file[] = __FILE__;
    // const char *d = "-";
    // const char *d1 = ".";
    char *filename = strtok(file, "-");
    // char *second = strtok(NULL, d);
    // char *third = strtok(NULL, d); // NULL
    // char *fourth;

    FILE *fin = fopen(strcat(filename, ".in"), "rb");
    filename = strtok(filename, ".");
    FILE *fout = fopen(strcat(filename, ".out"), "wb");

    /* it can also be changed to the regular stdin and stdout */
    // fin = stdin;
    // fout = stdout;

    int n = 0, x, min = INF, max = -INF, s = 0;
    while (fscanf(fin, "%d", &x) == 1)
    {
        s += x;
        if (x < min)
            min = x;
        if (x > max)
            max = x;
        n++;
    }

    fprintf(fout, "min=%d\nmax=%d\naverange=%.3f\n", min, max, (float)s / n);
    fclose(fin);
    fclose(fout);

    return 0;
}