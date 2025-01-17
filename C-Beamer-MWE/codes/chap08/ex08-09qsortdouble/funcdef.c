// 函数定义
// 比较函数
int cmp(const void *a, const void *b)
{
    // 需要先转换为(double*)指针,然后用*(double*)取内容
    // 应该判断a==b返回0，但是严格来说,两个double数是
    // 不可能相等的,只能用fabs(a-b)<1e-20之类的判断,
    // 因此，此处只返回了1和-1
    return (*(double *)a - * (double *)b) > 0.0 ? 1 : -1;
}
// 采用随机函数创建数组
void CreateArray(double *pa, int n)
{
    int i;
    // 用时间做随机种子，产生不同随机数
    srand((unsigned)time(NULL));
    for (i = 0; i < n; i++)
    {
        // 产生[0, n)之间的随机浮点数
        pa[i] = rand() / ((double)(RAND_MAX) / n);
    }
}
// 输出数据
void Output(double * pData, int n)
{
    int i;
    // n - 1不输出最后一个数
    for(i = 0; i < n - 1; i++)
    {
        printf("%f ", pData[i]);
    }
    // 最后不输出空格，并输出\n
    printf("%f\n", pData[i]);
}
