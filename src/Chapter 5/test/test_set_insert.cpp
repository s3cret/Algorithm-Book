#include <set>
#include <vector>

using namespace std;

typedef vector<int> Vector;

int main()
{
    set<Vector> s;
    Vector a;
    a.push_back(1);
    a.push_back(3);
    a.push_back(2);

    s.insert(a);

    return 0;
}