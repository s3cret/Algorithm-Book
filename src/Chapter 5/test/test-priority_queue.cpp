#include <algorithm>
#include <queue>
#define ASCENDING greater<int>
using namespace std;

int main()
{
    priority_queue<int, vector<int>, ASCENDING > pq;

    pq.push(2);
    pq.push(7);
    pq.push(9);

    int size = pq.size();

    for (int i = 0; i < size; i++)
    {
        printf("%d\n", pq.top());
        pq.pop();
    }

    return 0;
}