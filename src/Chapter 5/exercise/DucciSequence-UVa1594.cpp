#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

#ifdef LOCAL
#include <My_Util_Cpp.h>
#endif

using namespace std;
typedef vector<int> Vector;

set<Vector> cache;

int main()
{

#ifdef LOCAL
    // io_redirect(__FILE__);
#endif
    int n;
    cin >> n;
    Vector tmp;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        tmp.push_back(x);
    }

    while (1)
    {
        int a = tmp[0];
        for (int i = 0; i < n - 1; i++)
        {
            tmp[i] = abs(tmp[i + 1] - tmp[i]);
        }
        tmp[n - 1] = abs(a - tmp[n - 1]);

        if (count(tmp.begin(), tmp.end(), 0) == tmp.size())
        {
            cout << "ZERO" << endl;
            break;
        }

        bool b = cache.insert(tmp).second;
        if (b == false)
        {
            cout << "LOOP" << endl;
            break;
        }
    }

    return 0;
}