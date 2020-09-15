#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
// #include <My_Util_Cpp.h>

#define append(x) push_back(x)

using namespace std;

vector<string> files;

void print(string v, int width, char fill = ' ')
{
    int times = width - v.length();
    if (times >= 0)
    {
        string to_fill(times, fill);
        cout << v << to_fill;
    }
    if (fill == '-')
    {
        printf("\n");
    }
}

int main()
{
    // io_redirect(__FILE__);
    int n;
    while (cin >> n && n)
    {
        print("", 60, '-');

        int M = 0;
        files.clear();
        for (int i = 0; i < n; i++)
        {
            string F;
            cin >> F;
            files.append(F);
            M = max(M, (int)F.length());
        }

        sort(files.begin(), files.end());

        int col = (60 - M) / (M + 2) + 1;
        int row = (n - 1) / col + 1;

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                int indx = j * row + i;
                if (indx < n)
                {
                    print(files[indx], j == col - 1 ? M : M + 2);
                }
            }
            printf("\n");
        }

    }

    return 0;
}