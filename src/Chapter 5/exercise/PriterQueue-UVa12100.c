#include <stdio.h>
#include <string.h>

#ifdef LOCAL
#include <My_Util.h>
#endif

int Q[1001];

int main()
{
#ifdef LOCAL
    char filename[sizeof(__FILE__) + 3];
    get_input_filename(filename, __FILE__);
    freopen(filename, "r", stdin);
    get_output_filename(filename);
    freopen(filename, "w", stdout);
#endif
    int K;
    scanf("%d", &K);
    for (int k = 0; k < K; k++)
    {
        memset(Q, 0, sizeof(Q));
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &Q[i]);
        }

        // solution
        int head = 0, tail = n - 1, ans = 0;
        while (head < tail)
        {
            int J = Q[head];

            ans++;
            // find max_i
            int max_i = head;
            for (int i = head; i <= tail; i++)
            {
                if (Q[i] > Q[max_i])
                {
                    max_i = i;
                }
            }

            if (max_i == m)
            {
                break;
            }

            if (head != max_i)
            {
                ans--;
                Q[tail + 1] = J;
                // Q[head] = Q[max_i];
                // Q[max_i] = 0;
                tail++;
                if (head == m)
                {
                    m = tail;
                }
            }
            head++;
        }

        if (head == tail)
        {
            ans++;
        }

        printf("%d\n", ans);
    }

    return 0;
}