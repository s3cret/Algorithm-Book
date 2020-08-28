#include <stdio.h>
#ifdef LOCAL
#include <util.h>
#endif

const char *msg = "This puzzle has no final configuration.";
char puzzle[5][5];

int main()
{
    FILE *fin = stdin;
#ifdef LOCAL
    fin = GetFileInput(__FILE__);
#endif

    int kase = 0;
    while (1)
    {
        int bi, bj;

        // init puzzle
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                char tmp;
                fscanf(fin, "%c", &tmp);

                // Z
                if (tmp == 'Z')
                {
                    return 0;
                }

                // prevent return sign
                if (tmp == 10)
                {
                    if (j == 4)
                    {
                        bi = i;
                        bj = j;
                    }
                    else
                    {
                        fscanf(fin, "%c", &tmp);
                    }
                }

                if (tmp == 32)
                {
                    bi = i;
                    bj = j;
                }

                puzzle[i][j] = tmp;
            }
        }

        printf("Puzzle #%d:\n", ++kase);

        // type the moving instructions
        char m = ' ';
        int print = 1;
        while (fscanf(fin, "%c", &m) == 1)
        {
            if (m == '0')
            {
                break;
            }

            int success = 1;
            //
            int oi = bi;
            int oj = bj;

            switch (m)
            {
                case 'A': bi--; break;
                case 'B': bi++; break;
                case 'L': bj--; break;
                case 'R': bj++; break;
            }

            if (!(bi >= 0 && bi <= 4 && bj >= 0 && bj <= 4))
            {
                printf("%s\n", msg);
                print = 0;
                break;
            }

            // begin swap
            // blank : puzzle[oi][oj]
            // to swap: puzzle[*i][*j]
            puzzle[oi][oj] = puzzle[bi][bj];
            puzzle[bi][bj] = ' ';

        }

        // print puzzle
        if (print)
        {
            for (int i = 0; i < 5; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    printf("%c ", puzzle[i][j]);
                }

                printf("%c\n", puzzle[i][4]);
            }
            printf("\n");
        }
    }

    fclose(fin);
    return 0;
}

