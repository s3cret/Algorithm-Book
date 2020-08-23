#include<stdio.h>
#include<string.h>

int main()
{
    char file[20] = __FILE__;
    char *filename = strtok(file, "-");

    FILE *fin = fopen(strcat(filename, ".out"), "rb");
    strtok(filename, ".");
    FILE *fout = fopen(strcat(filename, ".test"), "wb");

    int a, b, c;
    while(fscanf(fin, "%d%d%d", &a, &b, &c) == 3) {
        fprintf(fout, "%d : %d : %d = %d : %d : %d\n", a, b, c, 1, b / a, c / a);
    }

    fclose(fin);
    fclose(fout);

    return 0;
}