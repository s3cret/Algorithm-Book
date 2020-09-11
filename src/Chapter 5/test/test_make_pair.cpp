#include <utility>
#include <string>

using namespace std;

int main()
{
    // ios::sync_with_stdio(false);
    pair<int, string> p;

    // p = make_pair
    p = make_pair(1, "helloworld");

    printf("p.first=%d\n", p.first);
    printf("p.second=%s\n", p.second.c_str());

    return 0;
}