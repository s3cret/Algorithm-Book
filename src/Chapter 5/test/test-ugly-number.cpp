#include <iostream>
#include <queue>
#include <vector>
#include <set>

using namespace std;
typedef long long LL;

set<LL> u_nums;
priority_queue<LL, vector<LL>, greater<LL> > q;
const int coefficient[3] = {2, 3, 5};

bool check(LL l);

int main()
{

    q.push(1);
    u_nums.insert(1);
    int count = 1;
    while (1)
    {
        LL n = q.top();
        q.pop();
        for (int i = 0; i < 3; i++)
        {
            LL x = coefficient[i] * n;
            if (check(x))
            {
                q.push(x);
            }
        }

        if (count == 1500)
        {
            cout << n << endl;
            break;
        }
        count++;
    }

    return 0;
}

bool check(LL l)
{
    return u_nums.insert(l).second;
}
