#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int a = 12;
    queue<int*> q;
    q.push(&a);

    // cout << q.front() << endl;
    printf("address of q.front()=%d\n", *(q.front()));

    a = 1;

    printf("address of q.front()=%d\n", *(q.front()));

    return 0;
}