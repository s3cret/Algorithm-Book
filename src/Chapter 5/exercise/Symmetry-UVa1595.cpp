// #define DEBUG
#include <algorithm>
#include <iostream>
#include <climits>
#include <map>
#include <vector>

#ifdef LOCAL
#include <My_Util_Cpp.h>
#endif

using namespace std;
typedef pair<double, double> Pair;
typedef map<Pair, int> Map;

Map mp;
vector<Pair> vec;

int main()
{
#ifdef LOCAL
    io_redirect(__FILE__);
#endif
    int K;
    cin >> K;
    // case begin
    for (int k = 0; k < K; k++)
    {
        // init a new case
        double left = INT_MAX, right = INT_MIN, symmetry_axis = 0;
        int n, found = 0;
        cin >> n;
        Pair p;
        mp.clear();
        vec.clear();
        for (int i = 0; i < n; i++)
        {
            cin >> p.first;
            cin >> p.second;

            left = min(p.first, left);
            right = max(p.first, right);

            mp[p] = 1;
            vec.push_back(p);
        }
#ifdef DEBUG
        cout << "There are " << right - left << " colomns to be scanned;" << endl;
#endif
        // x is the symmetry axis
        double x = (left + right) / 2;
        for (int i = 0; i < vec.size(); i++)
        {
            Pair cur = vec[i];
            // calculate the other point
            cur.first = 2 * x - cur.first;
#ifdef DEBUG
            cout << "(" << vec[i].first << ", " << vec[i].second << ")"
                 << ": ";
            cout << "(" << cur.first << ", " << cur.second << ")" << endl;
#endif
            if (mp[cur] == 0)
            {
                found = 0;
                // break and move the symmetry axis to next
                break;
            }
            else
            {
                found = 1;
                symmetry_axis = x;
            }
        }

        if (found)
        {
            // cout << symmetry_axis << endl;
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}