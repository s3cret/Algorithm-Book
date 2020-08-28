#include<stdio.h>
#include<time.h>
#include<string.h>
#define maxn 20
int matrix[maxn][maxn];

int main()
{
    int n, x, y;
    scanf("%d", &n);

    int count = 0;
    memset(matrix, 0, sizeof(matrix));
    count = matrix[x = n - 1][y = 0] = 1;

    while(count < n * n - 1) {

        // down
        while(y + 1 < n && !matrix[x][y + 1]) matrix[x][++y] = ++count;
        // left
        while(x - 1 >= 0 && !matrix[x - 1][y]) matrix[--x][y] = ++count;
        // up
        while(y - 1 >= 0 && !matrix[x][y - 1]) matrix[x][--y] = ++count;
        // right
        while(x + 1 < n && !matrix[x + 1][y]) matrix[++x][y] = ++count;

    }

    // print

    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < n; j ++) {
            printf("%3d", matrix[j][i]);
        }
        printf("\n");
    }

    printf("Time used = %.8f\n", (double)clock() / CLOCKS_PER_SEC);

    return 0;
}