#include <stdio.h>
#include <string.h>
// #include <util.h>

#define maxn 100005 // 1e6
int map[maxn];

int main()
{
    memset(map, 0, sizeof(map));
    for(int i = 1; i <= maxn; i ++) {

        int operate = i;
        int result = i;

        while (operate)
        {
            int digit = operate % 10;
            result += digit;
            
            if (result > maxn)
            {
                break;
            }

            operate /= 10;
            
        }

        if (result > maxn)
        {
            break;
        }

        if (!map[result])
        {
            map[result] = i;
        }

    }

    // FILE *fin = GetFileInput(__FILE__);

    int n, T;
    scanf("%d", &T);
    while (T --)
    {
        scanf("%d", &n);
        printf("%d\n", map[n]);
    }

    return 0;
}