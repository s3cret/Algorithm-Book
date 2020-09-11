#include <queue>
#include <utility>

using namespace std;
typedef pair<int, int> Pair;

struct cmp
{
    bool operator()(const Pair& lhs, const Pair& rhs)
    {
        return lhs.second < rhs.second;
    }
};

int main()
{
    priority_queue<Pair, vector<Pair>, cmp> pq;
    pq.push(make_pair(3, 199));
    pq.push(make_pair(7, 1));
    pq.push(make_pair(2, 258));

    for (int i = 0, len = pq.size(); i < len; i++)
    {
        Pair p = pq.top();
        pq.pop();

        printf("(%d, %d)\n", p.first, p.second);
    }

    return 0;
}
