#include <stdio.h>
#include <string.h>

#ifdef LOCAL
#include <util.h>
#endif

void printcodes();
int readint(int len);

int code[7][1 << 7];
int read_header();

// Only func defined before main can be used in main
int main()
{
#ifdef LOCAL
    char filename[sizeof(__FILE__) + 2];
    get_input_filename(filename, __FILE__);
    freopen(filename, "r", stdin);
    get_output_filename(filename);
    freopen(filename, "w", stdout);
#endif
    // read the header
    while (read_header())
    {
// printcodes();
        while (1)
        {
            int len = readint(3);
            if (len == 0)
                break;

            while (1)
            {
                int v = readint(len);
                if (v == (1 << len) - 1)
                    break;
                putchar(code[len][v]);
            }
        }

        putchar('\n');
    }

    return 0;
}

int readchar()
{
    while (1)
    {
        int c = getchar();
        if (c != '\n' && c != '\r')
            return (int)c;
    }
}

/*
 * Description: this function convert the binary input to decimal numbers
 * Inputs: length of number read from stdin
 * Returns: a decimal number from 3 digital binary number
 */
int readint(int len)
{
    int res = 0;
    while (len--)
        res = 2 * res + readchar() - '0';

    return res;
}

/*
 * Description: this function read the header and store them accordingly to codes arr
 * Returns: 0 when EOF or 1 when get input from stdin
 * Inputs: nothing
 */
int read_header()
{
    memset(code, 0, sizeof(code));

    code[1][0] = readchar();

    for (int len = 2; len <= 7; len++)
    {
        for (int i = 0; i < (1 << len) - 1; i++)
        {
            int ch = getchar();

            if (ch == EOF)
                return 0;

            if (ch == '\n' || ch == '\r')
                return 1;

            code[len][i] = ch;
        }
    }

    return 1;
}

void printcodes()
{
    for (int len = 1; len <= 7; len++)
    {
        for (int i = 0; i < (1 << len) - 1; i++)
        {
            printf("code[%d][%d] = %d\n", len, i, code[len][i]);
        }
    }
}
