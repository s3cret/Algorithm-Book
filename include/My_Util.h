#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define docmax 1000000

// Notes: Remember to close the file: fclose(fin);
FILE *GetFileInput(char file[])
{
    char input[strlen(file)];
    strcpy(input, file);
    strtok(input, ".");
    strcat(input, ".in");

    FILE *fin = fopen(input, "r");

    return fin;
}

/* 
 * Description: this function edit the filename to filename.in
 * Inputs: fvar is char pointer; filename is the __FILE__ variable;
 * HERE: it will also check if the file is accessible and create it if inaccessible;
 */
void get_input_filename(char* fvar, char* filename)
{
    strcpy(fvar, filename);
    strtok(fvar, ".");
    strcat(fvar, ".in");

    // check if file is already existed
    if (access(fvar, F_OK) == -1)
        fclose(fopen(fvar, "w"));

}

void get_output_filename(char* fvar)
{
    strtok(fvar, ".");
    strcat(fvar, ".out");
    if (access(fvar, F_OK) == -1)
        fclose(fopen(fvar, "w"));
}

void PrintWholeDocument(FILE *fin)
{
    char buf[docmax];
    while (fgets(buf, docmax, fin) != NULL)
    {
        printf("%s", buf);
    }
}

void println_int_arr(int* arr, int arr_size)
{
    for (int i = 0; i < arr_size; i++)
    {
        printf(!(i == arr_size - 1) ? "%d " : "%d\n", arr[i]);
    }
}

void println_int_arr_0(int* arr)
{
    int last = 0;

    for (int i = 0; ; i++)
    {
        int after = arr[i + 1];
        if (after == 0) last = 1;
        printf(!last ? "%d " : "%d\n", arr[i]);
        if (last) break;
    }
}
