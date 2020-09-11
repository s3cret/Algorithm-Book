#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
#include <map>

using namespace std;

typedef set<int> Set;

map<Set, int> IDcache;
vector<Set> Setcache;

int ID(Set x)
{

    cout << "Your set address = " << &x << endl;

    cout << "IDcache.count(x) returns:" << IDcache.count(x) << endl;

    cout << "Size of set: " << x.size() << endl;

    if (IDcache.count(x)) return IDcache[x];

    Setcache.push_back(x);

    return IDcache[x] = Setcache.size() - 1;
}

int main()
{

    ID(Set());
    ID(Set());

    cout << "Setcache.size() = " << Setcache.size() << endl;

    return 0;
}