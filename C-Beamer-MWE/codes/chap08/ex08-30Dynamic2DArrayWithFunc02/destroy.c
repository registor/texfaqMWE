...
/*释放每一行的空间*/
for (i = 0; i < m; i++)
{
    free(p[i]);
    // 将不用的指针赋值为NULL，防止野指针
    p[i] = NULL; 
}

/*释放存储每一行首地址的内存空间*/
free(p);
// 将不用的指针赋值为NULL，防止野指针
p = NULL; 
...
