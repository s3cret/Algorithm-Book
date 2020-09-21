#include <queue>
#include <iostream>

#ifdef LOCAL
#include <My_Util_Cpp.h>
#endif

using namespace std;

int main()
{
#ifdef LOCAL
    io_redirect(__FILE__);
#endif
    int n;
    while (cin >> n && n)
    {
        queue<int> cards;

        for (int i = 1; i <= n; i++)
        {
            cards.push(i);
        }

        cout << "Discarded cards:";
        while (cards.size() >= 2)
        {
            int top = cards.front();
            cards.pop();
            int second = cards.front();
            cards.pop();
            cards.push(second);
            cout << " " << top;
            if (cards.size() != 1)
            {
                cout << ",";
            }
        }
        cout << endl;

        cout << "Remaining card: " << cards.front() << endl;
    }

    return 0;
}