#include <stdio.h>
#include <string.h>

#ifdef LOCAL
#include <util.h>
#endif

int code[8][(1 << 7) - 1];

int read_human_char();
int readheader();
int readint(int len);
void printcodes();

int main()
{
#ifdef LOCAL
    char filename[sizeof(__FILE__) + 2];
    get_input_filename(filename, __FILE__);
    freopen(filename, "r", stdin);
    get_output_filename(filename);
    freopen(filename, "w", stdout);
#endif

    while (readheader())
    {
        while (1)
        {
            int len = readint(3);
            if (len == 0)
                break;

            while (1)
            {
                int v = readint(len);
                // if len = 111...
                if (v == (1 << len) - 1)
                    break;
                putchar(code[len][v]);
            }
        }
        putchar('\n');
    }

    return 0;
}

int readint(int len)
{
    int res = 0;
    while (len)
    {
        char c = getchar();

        if (c != '\n' && c != '\r')
        {
            res = res * 2 + c - '0';
            len--;
        }
    }

    return res;
}

int read_human_char()
{
    char c;
    while (1)
    {
        c = getchar();
        if (c != '\n' && c != '\r')
        {
            break;
        }
    }

    return c;
}

int readheader()
{
    memset(code, 0, sizeof(code));

    while (1)
    {
        code[1][0] = read_human_char();

        for (int len = 2; len <= 7; len++)
        {
            for (int i = 0; i < (1 << len) - 1; i++)
            {
                char c = getchar();

                if (c == EOF)
                {
                    return 0;
                }
                if (c == '\n' || c == '\r')
                {
                    return 1;
                }

                code[len][i] = c;
            }
        }

        return 1;
    }
}

void printcodes()
{
    for (int len = 1; len <= 7; len++)
    {
        for (int i = 0; i < (1 << len) - 1; i++)
        {
            if (code[len][i] != 0)
                printf("code[%d][%d] = %c\n", len, i, code[len][i]);
        }
    }
}