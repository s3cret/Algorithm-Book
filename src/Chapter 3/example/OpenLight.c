#include<stdio.h>
#include<string.h>
#define maxn 105
int lights[maxn];

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    memset(lights, 0, n + 1); // light 0 is off, 1 is on
    
    for(int p = 1; p <= k; p ++) {
        for(int i = 1; i <= n; i ++) {
            if(i % p == 0 || p % i == 0) {
                lights[i] = !lights[i];
            }
        }
    }

    // print the anwser
    for(int i = 1; i <= n; i ++) {
        if(lights[i] == 1) {
            printf("%d ", i);
        }
    }
    printf("\n");

    return 0;
}
