#include<stdio.h>
#include<string.h>

int main()
{
    char file[20] = __FILE__;
    char *filename = strtok(file, ".");
    // printf("%lu\n", strlen(filename));

    FILE *fout = fopen(strcat(filename, ".out"), "wb");

    for(int i = 100; i <= 333; i ++) {
        int abc = i;
        int def = abc * 2;
        int ghi = abc * 3;
        if(ghi < 1000) {
            fprintf(fout, "%d %d %d\n", abc, def, ghi);
        }
    }

    fclose(fout);

    return 0;
}