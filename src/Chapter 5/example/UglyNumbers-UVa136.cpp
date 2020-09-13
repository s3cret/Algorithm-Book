#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;
#define ASCENDING greater<LL>

typedef long long LL;
const int coeff[3] = {2, 3, 5};

int main()
{
    priority_queue<LL, vector<LL>, ASCENDING > pq;
    set<LL> s;

    pq.push(1);
    s.insert(1);

    for (int i = 1; ; i++)
    {
        LL x = pq.top(); pq.pop();
        if (i == 1500)
        {
            cout << "The 1500'th ugly number is " << x << ".\n";
            break;
        }

        for (int j = 0; j < 3; j++)
        {
            LL x2 = x * coeff[j];
            // if  not find it
            if (s.find(x2) == s.end())
            {
                s.insert(x2);
                pq.push(x2);
            }
        }
    }

    return 0;
}
