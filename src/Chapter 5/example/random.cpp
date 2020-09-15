#include <algorithm>
#include <vector>
using namespace std;

void test_sort(vector<int> &v)
{
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size() - 1; i++)
    {
        assert(v[i] <= v[i+1]);
    }
}

void fill_random_int(vector<int> &v, int cnt)
{
    v.clear();
    for (int i = 0; i < cnt; i++)
    {
        v.push_back(rand() % 100);
    }
}

int main(int n, char *args[])
{
    srand(time(NULL));
    vector<int> foo;

    fill_random_int(foo, 1000000);

    test_sort(foo);

    return 0;
}