#include <set>
#include <iostream>
using namespace std;

int main()
{
    set<int> s;
    pair<set<int>::iterator, bool> p;
    
    p = s.insert(3);
    p = s.insert(3);
    p = s.insert(4);
    p = s.insert(4);
    p = s.insert(3);

    cout << p.second << endl;
    cout << *(p.first) << endl;

    return 0;
}