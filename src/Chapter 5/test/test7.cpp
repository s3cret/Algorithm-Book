#include <cstdio>
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

// #include <My_Util_Cpp.h>

const int maxi = 100000;

int main()
{
    // io_redirct(__FILE__);
    int n, m;
    scanf("%d%d", &n, &m);
    if (n < 1 || n > maxi || m < 1 || m > maxi)
        return 0;
    vector<long> girls;

    for (int i = 0; i < n; i++)
    {
        long tmp;
        scanf("%ld", &tmp);
        girls.push_back(tmp);
    }

    while (m--)
    {
        int day;
        scanf("%d", &day);
        if (day <= n && day >= 1)
        {
            set<long> s(girls.begin() + day - 1, girls.end());
            printf("%ld\n", s.size());
        }
    }

    return 0;
}