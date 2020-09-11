#include <iostream>
#include <algorithm>
#include <set>
#include <stack>
#include <vector>
#include <map>

#ifdef LOCAL
#include <My_Util_Cpp.h>
#endif

using namespace std;
typedef set<int> Set;

#define ALL(x) x.begin(), x.end()
#define INSERTER(x) inserter(x, x.begin())


int ID(Set x);

Set s;
// always push ID to stk
stack<int> stk;
vector<Set> Setcache;
map<Set, int> IDcache;

/* 
    Set: set<int>: represent a set
        value  '1' for '{}',
               '2' for '{{}}',
               '3' for '{{{}}}',
                ...
    
    Setcache: vector<set>: to store all the sets;
    IDcache: map<Set, int>: map the a Set to its UNIQUE ID;
 */

int main()
{

#ifdef LOCAL
    io_redirect(__FILE__);
#endif

    ios::sync_with_stdio(false);

    int kase, n;
    cin >> kase;

    while (kase--)
    {
        cin >> n;
        while (n--)
        {
            string op;
            cin >> op;
            
            // Push
            if (op[0] == 'P')
            {
                stk.push(ID(Set())); // push 0 to stack; with Setcache[0] = Set{nothing here};
            }

            // Duplicate
            else if (op[0] == 'D')
            {
                stk.push(stk.top());
            }

            else
            {
                Set x1 = Setcache[stk.top()];
                stk.pop();
                Set x2 = Setcache[stk.top()];
                stk.pop();
                Set x;

                // Union
                if (op[0] == 'U')
                    set_union(ALL(x1), ALL(x2), INSERTER(x));

                // Intersect
                if (op[0] == 'I')
                    set_intersection(ALL(x1), ALL(x2), INSERTER(x));
                
                if (op[0] == 'A')
                {
                    x = x2;
                    x.insert(ID(x1));
                }

                stk.push(ID(x));
            }

            cout << Setcache[stk.top()].size() << endl;
        }

        cout << "***" << endl;

    }

    return 0;
}

int ID(Set x)
{
    if (IDcache.count(x)) return IDcache[x];

    Setcache.push_back(x);
    // THen x's index is Setcache() - 1

    // index is returned
    return IDcache[x] = Setcache.size() - 1;
}
