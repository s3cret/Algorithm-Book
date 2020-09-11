#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    vector<vector<int> > a;
    vector<int> b;
    b.push_back(12);
    a.push_back(b);

    int n = a[0][0];
    printf("n=%d\n", n);

    return 0;
}