// NOT SOLVED
#include <iostream>
#include <vector>

#ifdef LOCAL
#include <My_Util_Cpp.h>
#endif

using namespace std;

int main()
{
#ifdef LOCAL
    io_redirect(__FILE__);
#endif
    // input
    int K;
    cin >> K;
    while (K--)
    {
        int n, pos, max_indx = -1, output = 0;
        cin >> n >> pos;

        vector<int> printq;
        for (int i = 0; i < n; i++)
        {
            int task;
            cin >> task;
            printq.push_back(task);
        }

        // solution
        while (1)
        {
            output++;
            max_indx = distance(printq.begin(), max_element(printq.begin(), printq.end()));
            if (max_indx == pos)
            {
                break;
            }
            else if (max_indx == 0)
            {
                printq.erase(printq.begin());
                pos--;
                continue;
            }
            else // max_indx != 0 && max_indx != pos
            {
                if (pos == 0)
                {
                    pos = printq.size() - 1;
                }
                else if (max_indx > pos)
                {
                    // do nothing
                }

                if (max_indx < pos)
                {
                    pos--;
                }

                printq.erase(printq.begin() + max_indx);
            }
        }

        cout << output << endl;
    }

    return 0;
}
