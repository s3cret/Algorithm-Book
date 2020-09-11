#include <cstdio>
#include <algorithm>
#include <vector>

int main()
{
    std::vector<int> a;
    a.push_back(1);
    printf("a.size()=%lu\n", a.size());
    a.pop_back();
    printf("a.size()=%lu\n", a.size());
    a.resize(2);
    printf("a.size()=%lu\n", a.size());
    return 0;
}