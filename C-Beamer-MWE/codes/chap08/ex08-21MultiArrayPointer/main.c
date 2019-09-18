#include <stdio.h>

#define M 3
#define N 2

int main(void)
{
    int i, j;
     // 数组声明并初始化
    int a[M][N] ={{1,2 }, {3, 4}, {5, 6}};
    int (*p)[N] = a; // 指向数组的指针

    for(i = 0; i < M; i++)
    {
        for(j = 0; j < N; j++)
        {
            // 通过指针操作数组元素
            p[i][j] = (i + 1) * (j + 1);
        }
    }

    for(i = 0; i < M; i++)
    {
        // N-1 不输出最后一个元素
        for(j = 0; j < N - 1; j++)
        {
            // 通过指针操作数组元素
            printf("%d ", p[i][j]);
        }
        // 最后一个元素后不输出空格
        printf("%d\n", p[i][j]);
    }

    return 0;
}
