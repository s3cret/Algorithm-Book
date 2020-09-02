#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include <util.h>

#define size 1010

void alpha_times(int *cn, char *str);
int cmp(const void *a, const void *b);
int cmp_int_arr(int *a, int *b, int arr_size);

int main()
{
#ifdef LOCAL
    char filename[sizeof(__FILE__) + 1];
    get_input_filename(filename, __FILE__);
    freopen(filename, "r", stdin);
#endif
    char a[size], b[size];
    int cn1[26], cn2[26];
    while (scanf("%s%s", a, b) == 2)
    {

        memset(cn1, 0, sizeof(cn1));
        memset(cn2, 0, sizeof(cn2));

        alpha_times(cn1, a);
        alpha_times(cn2, b);
        
        qsort(cn1, 26, sizeof(int), cmp);
        qsort(cn2, 26, sizeof(int), cmp);

        if (cmp_int_arr(cn1, cn2, 26))
        {
            puts("YES");
        }
        else
        {
            puts("NO");
        }
    }

    return 0;
}

void alpha_times(int *cn, char *str)
{
    int n = strlen(str);

    for (int i = 0; i < n; i++)
    {
        int alpha_i = str[i] - 'A';
        cn[alpha_i]++;
    }
}

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int cmp_int_arr(int *a, int *b, int arr_size)
{
    for (int i = 0; i < arr_size; i++)
    {
        if (a[i] != b[i])
        {
            return 0;
        }
    }

    return 1;
}
