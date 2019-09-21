#include <stdio.h>
#include <stdlib.h>

//函数原型
// 分配动态数组
int * AllocArray(int);
// 数组遍历
void Traversal(int *, int, void (*pf)(int *));
// 功能函数
void Input(int *);
void Output(int *);

int main()
{
    int *p = NULL;
    int n = 0;

    // 把输入重定向到文件"data.txt"
    freopen("data.txt", "r", stdin);
    // 数组大小
    scanf("%d", &n);
    printf("array length = %d.\n", n);

    /*分配内存*/
    p = AllocArray(n);

    Traversal(p, n, Input);
    // 把输入重定向回键盘
    freopen("CON", "r", stdin);
    printf("array is:\n");
    Traversal(p, n, Output);
    printf("\n");

    // 释放内存
    free(p);
    p = NULL; //防止悬空指针

    return 0;
}
// 函数定义
// 为数组开辟空间
int * AllocArray(int n)
{
    int *p = NULL;

    /*分配n个sizeof(int)字节的
    连续存储空间*/
    p = (int *)malloc(n * sizeof(int));
    if(NULL == p) // 内存申请失败的处理
    {
        printf("Not enough memory!\n");
        exit(1);
    }

    // 返回分配的地址
    return p;
}

// 遍历数组
void Traversal(int *pa, int n, void (*pf)(int *))
{
    int *p;

    // 遍历数组，使用指针进行操作
    for(p = pa; p < pa + n; p++)
    {
        pf(p); // 调用传入的函数
    }
}

// 输入数据
void Input(int * pData)
{
    scanf("%d", pData);
}
// 输出数据
void Output(int * pData)
{
    // 输出
    printf("%d ", *pData);
}