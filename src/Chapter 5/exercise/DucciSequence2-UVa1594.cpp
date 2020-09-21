#include <algorithm>
#include <set>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        set<vector<int> > s;
        vector<int> tmp;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            tmp.push_back(x);
        }

        while (1)
        {
            int a = tmp[0];
            for (int i = 0; i < (n - 1); i++)
                tmp[i] = (abs(tmp[i] - tmp[(i + 1)]));
            tmp[n - 1] = abs(a - tmp[n - 1]);

            bool b = s.insert(tmp).second;
            if (b == false)
            {
                cout << "LOOP" << endl;
                break;
            }
            else if (count(tmp.begin(), tmp.end(), 0) == tmp.size())
            {
                cout << "ZERO" << endl;
                break;
            }
        }
    }
    return 0;
}