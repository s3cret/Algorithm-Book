#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int N, Q, kase = 0;
    while (cin >> N >> Q && N)
    {
        cout << "CASE# " << ++kase << ":\n";
        int marbles[N];
        for (int i = 0; i < N; i++)
        {
            cin >> marbles[i];
        }

        sort(marbles, marbles + N);

        for (int i = 0; i < Q; i++)
        {
            int guess = 0;
            scanf("%d", &guess);
            int index = lower_bound(marbles, marbles + N, guess) - marbles;
            if (marbles[index] == guess)
            {
                printf("%d found at %d\n", guess, index + 1);
            }
            else
            {
                printf("%d not found\n", guess);
            }
        }
    }

    return 0;
}