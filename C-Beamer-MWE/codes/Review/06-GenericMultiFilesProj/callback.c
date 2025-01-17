/*--------------------------------------------------------------------------------
* Copyright (c) 2017,西北农林科技大学信息学院计算机科学系
* All rights reserved.
*
* 文件名称：traversal.c
* 文件标识：见配置管理计划书
* 摘要：遍历数组函数原型的定义。
*
* 当前版本：1.0
* 作者：耿楠
* 完成日期：2017年11月28日
*
* 取代版本：无
* 原作者：耿楠
* 完成日期：2017年11月28日
------------------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "define.h"
#include "callback.h" // 函数原型头文件

//-----------------------------------------------------------------------------------------------
// 名称：void RandIntArray(void *ptr, size_t count, size_t size)
// 功能：用rand函数产生一个随机整数数组
// 参数：
//       [void *ptr] --- 数组起始地址的指针
//       [size_t count] --- 数组长度
//       [size_t size] --- 数组一个元素的大小(字节)，建议使用sizeof(a[0])
// 返回：无
// 作者：耿楠
// 日期：2017年11月19日
//-----------------------------------------------------------------------------------------------
void RandIntArray(void *ptr, size_t count, size_t size)
{
    // 要取[a,b)之间的随机整数（包括a，但不包括b)，使用：
    // (rand() % (b - a)) + a
    for(int i  = 0; i < count; i++)
    {
        *(int*)(ptr + i * size) = rand() % N; // 生成[0, N)之间的随机数
    }
}

//-----------------------------------------------------------------------------------------------
// 名称：void RandDfArray(void *ptr, size_t count, size_t size)
// 功能：用rand函数产生一个随机浮点数数组
// 参数：
//       [void *ptr] --- 数组起始地址的指针
//       [size_t count] --- 数组长度
//       [size_t size] --- 数组一个元素的大小(字节)，建议使用sizeof(a[0])
// 返回：无
// 作者：耿楠
// 日期：2017年11月19日
//-----------------------------------------------------------------------------------------------
void RandDfArray(void *ptr, size_t count, size_t size)
{
    // 要取[a,b)之间的随机整数（包括a，但不包括b)，使用：
    // (rand() % (b - a)) + a
    for(int i  = 0; i < count; i++)
    {
        *(double*)(ptr + i * size) =  rand() / (double)(RAND_MAX / N); // 产生[1,N)内的随机浮点数
    }
}

//-----------------------------------------------------------------------------------------------
// 名称：static char *RandString(char *str, size_t size)
// 功能：用rand函数随机产生一个字符串
// 参数：
//       [char *str] --- 字符串起始地址指针
//       [size_t size] --- 字符串长度
// 返回：[static char *] --- 字符串首地址， static的目的是仅在此文件中使用该函数
// 作者：耿楠
// 日期：2017年11月23日
//-----------------------------------------------------------------------------------------------
static char *RandString(char *str, size_t size)
{
    // 用于产生随机字符串的字符集(字符只能取该字符集中的字符)
    const char charset[] = "abcdefghijklmnopqrstuvwxyz"
                           "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    //"0123456789,.-#'?!";
    if(size != 0)
    {
        --size;
        for (size_t n = 0; n < size; n++)
        {
            int key = rand() % (int) (sizeof(charset) - 1); // 随机产生字符集范围内的下标值
            str[n] = charset[key]; // 在字符集中选取字符
        }
        str[size] = '\0'; // 空字符
    }

    return str; // 返回字符串指针
}

//-----------------------------------------------------------------------------------------------
// 名称：void Rand2DCharArray(void *ptr, size_t count, size_t size)
// 功能：随机产生一个字符串数组(字符型二维数组)
// 参数：
//       [void *ptr] --- 数组起始地址的指针
//       [size_t count] --- 数组长度
//       [size_t size] --- 数组一个元素的大小(字节)
// 返回：无
// 作者：耿楠
// 日期：2017年11月23日
//-----------------------------------------------------------------------------------------------
void Rand2DCharArray(void *ptr, size_t count, size_t size)
{
    // 要取[a,b)之间的随机整数（包括a，但不包括b)，使用：
    // (rand() % (b - a)) + a
    for(int i = 0; i < count; i++)
    {
        int strlen = rand() % ((int)size - 2) + 2; // 长度范围：[2, size)

        RandString(ptr, strlen); // 随机产生一个字符串
        ptr += size; // 调整指针
    }
}

//-----------------------------------------------------------------------------------------------
// 名称：void RandStrPtArray(void *ptr, size_t count, size_t size)
// 功能：随机产生一个字符串数组(字符型指针数组)
// 参数：
//       [void *ptr] --- 数组起始地址的指针
//       [size_t count] --- 数组长度
//       [size_t size] --- 数组一个元素的大小(字节)
//       [size_t strmaxlen] --- 字符串的最大长度(个)
// 返回：无
// 注意：本函数使用了malloc函数，调用后注意使用free函数释放空间
// 作者：耿楠
// 日期：2017年11月23日
//-----------------------------------------------------------------------------------------------
void RandStrPtArray(void *ptr, size_t count, size_t size, size_t strmaxlen)
{
    // 要取[a,b)之间的随机整数（包括a，但不包括b)，使用：
    // (rand() % (b - a)) + a

    char *p ;

    for(int i = 0; i < count; i++)
    {
        int strlen = rand() % (strmaxlen - 2) + 2; // 长度范围：[2, strmaxlen)

        p = (char*)malloc(strlen * sizeof(char)); // 分配空间
        RandString(p, strlen); // 随机产生一个字符串
        memcpy(ptr, &p, size);
        ptr += size; // 调整指针
    }
}

//-----------------------------------------------------------------------------------------------
// 名称：void InputInt(void * pData)
// 功能：用scanf输入一个整数
// 参数：
//       [void * pData] --- 数据起始地址的指针
// 返回：无
// 注意：需要在函数内部进行强制地址类型转换，以实现整数输入
// 作者：耿楠
// 日期：2017年11月19日
//-----------------------------------------------------------------------------------------------
void InputInt(void * pData)
{
    scanf("%d", (int*)pData);
}

//-----------------------------------------------------------------------------------------------
// 名称：void RandInt(void * pData)
// 功能：用rand函数产生一个随机整数
// 参数：
//       [void * pData] --- 数据起始地址的指针
// 返回：无
// 注意：需要在函数内部进行强制地址类型转换，以实现整数输入
// 作者：耿楠
// 日期：2017年11月23日
//-----------------------------------------------------------------------------------------------
void RandInt(void * pData)
{
    // 要取[a,b)之间的随机整数（包括a，但不包括b)，使用：
    // (rand() % (b - a)) + a
    *(int*)(pData) = rand() % N; // 生成[0, N)之间的随机数
}

//-----------------------------------------------------------------------------------------------
// 名称：void OutputInt(void * pData)
// 功能：用printf输出一个整数
// 参数：
//       [void * pData] --- 数据起始地址的指针
// 返回：无
// 注意：需要在函数内部进行强制地址类型转换，以实现整数输出
// 作者：耿楠
// 日期：2017年11月19日
//-----------------------------------------------------------------------------------------------
void OutputInt(void * pData)
{
    // 输出
    printf("%d ", *(int *)pData);
}

//-----------------------------------------------------------------------------------------------
// 名称：void InputDf(void * pData)
// 功能：用scanf输入一个浮点数
// 参数：
//       [void * pData] --- 数据起始地址的指针
// 返回：无
// 注意：需要在函数内部进行强制地址类型转换，以实现浮点数输入
// 作者：耿楠
// 日期：2017年11月19日
//-----------------------------------------------------------------------------------------------
void InputDf(void * pData)
{
    scanf("%lf", (double*)pData);
}

//-----------------------------------------------------------------------------------------------
// 名称：void RandDf(void * pData)
// 功能：用rand函数产生一个随机浮点数
// 参数：
//       [void * pData] --- 数据起始地址的指针
// 返回：无
// 注意：需要在函数内部进行强制地址类型转换，以实现浮点数输入
// 作者：耿楠
// 日期：2017年11月23日
//-----------------------------------------------------------------------------------------------
void RandDf(void * pData)
{
    // 要取[a,b)之间的随机整数（包括a，但不包括b)，使用：
    // (rand() % (b - a)) + a
    *(double*)(pData) =  rand() / (double)(RAND_MAX / N); // 产生[1,N)内的随机浮点数
}

//-----------------------------------------------------------------------------------------------
// 名称：void OutputDf(void * pData)
// 功能：用printf输出一个浮点数
// 参数：
//       [void * pData] --- 数据起始地址的指针
// 返回：无
// 注意：需要在函数内部进行强制地址类型转换，以实现浮点数输出
// 作者：耿楠
// 日期：2017年11月19日
//-----------------------------------------------------------------------------------------------
void OutputDf(void * pData)
{
    // 输出
    printf("%.2f ", *(double *)pData);
}

//-----------------------------------------------------------------------------------------------
// 名称：void InputStr(void * pData)
// 功能：用scanf输入一个字符串
// 参数：
//       [void * pData] --- 数据起始地址的指针
// 返回：无
// 注意：需要在函数内部进行强制地址类型转换，以实现字符串输入
// 作者：耿楠
// 日期：2017年11月23日
//-----------------------------------------------------------------------------------------------
void InputStr(void * pData)
{
    scanf(" %[^\n]", (char *)pData); // 前导空格用于丢弃前一次scanf留下的'\n'，"%[^\n]"用于匹配除\n外的所有字符
}

//-----------------------------------------------------------------------------------------------
// 名称：void OutputStr(void * pData)
// 功能：用puts输出一个字符串
// 参数：
//       [void * pData] --- 数据起始地址的指针
// 返回：无
// 注意：需要在函数内部进行强制地址类型转换，以字符串输出
// 作者：耿楠
// 日期：2017年11月23日
//-----------------------------------------------------------------------------------------------
void OutputStr(void * pData)
{
    // 输出
    puts((char *)pData);
}

//-----------------------------------------------------------------------------------------------
// 名称：void OutputStrPt(void * pData)
// 功能：用puts输出一个字符串
// 参数：
//       [void * pData] --- 数据起始地址的指针
// 返回：无
// 注意：需要在函数内部进行强制地址类型转换，以字符串输出
// 作者：耿楠
// 日期：2017年11月23日
//-----------------------------------------------------------------------------------------------
void OutputStrPt(void * pData)
{
    // 输出
    puts(*(char **)pData);
}

//-----------------------------------------------------------------------------------------------
// 名称：void OutputStu(void * pData)
// 功能：输出一个结构体的内容
// 参数：
//       [void * pData] --- 数据起始地址的指针
// 返回：无
// 注意：需要在函数内部进行强制地址类型转换，以结构体形式输出
// 作者：耿楠
// 日期：2017年11月29日
//-----------------------------------------------------------------------------------------------
void OutputStu(void * pData)
{
    // 强制转换指针类型
    StuNode *p = (StuNode *)pData;
    // 输出
    printf("%d\t%s\t%s\t%d/%d/%d\n", p->ID, p->name,
           p->gender, p->birthday.year,
           p->birthday.month, p->birthday.day);
}

//-----------------------------------------------------------------------------------------------
// 名称：void OutputStuPt(void * pData)
// 功能：输出一个结构体的内容
// 参数：
//       [void * pData] --- 数据起始地址的指针
// 返回：无
// 注意：需要在函数内部进行强制地址类型转换，以结构体形式输出
// 作者：耿楠
// 日期：2017年11月30日
//-----------------------------------------------------------------------------------------------
void OutputStuPt(void * pData)
{
    // 强制转换指针类型
    StuNode *p = *((StuNode **)pData);
    // 输出
    printf("%d\t%s\t%s\t%d/%d/%d\n", p->ID, p->name,
           p->gender, p->birthday.year,
           p->birthday.month, p->birthday.day);
}

//-----------------------------------------------------------------------------------------------
// 名称：int GreaterInt(const void *a, const void *b)
// 功能：用于整数的比较小于函数
// 参数：
//       [const void *a] --- 第一个元素的起始地址
//       [const void *b] --- 第二个元素的起始地址
// 返回：[int] --- *a > *b返回正值，否则返回0或负值
// 注意：需要在函数内部进行强制地址类型转换，以实现整数比较
// 作者：耿楠
// 日期：2017年11月19日
//-----------------------------------------------------------------------------------------------
int GreaterInt(const void *a, const void *b)
{
    // a > b = 1, a < b = -1, (a == b) = 0
    // (*a > *b) - (*a < *b);
    return (*(const int*)a > *(const int*)b) - (*(const int*)a < * (const int*)b);
}

//-----------------------------------------------------------------------------------------------
// 名称：int LesserInt(const void *a, const void *b)
// 功能：用于整数的比较小于函数
// 参数：
//       [const void *a] --- 第一个元素的起始地址
//       [const void *b] --- 第二个元素的起始地址
// 返回：[int] --- *a < *b返回正值，否则返回0或负值
// 注意：需要在函数内部进行强制地址类型转换，以实现整数比较
// 作者：耿楠
// 日期：2017年11月19日
//-----------------------------------------------------------------------------------------------
int LesserInt(const void *a, const void *b)
{
    //return *(const int*)b - * (const int*)a;
    return (*(const int*)b > *(const int*)a) - (*(const int*)b < * (const int*)a);
}

//-----------------------------------------------------------------------------------------------
// 名称：int GreaterDf(const void *a, const void *b)
// 功能：用于浮点数的比较大于函数
// 参数：
//       [const void *a] --- 第一个元素的起始地址
//       [const void *b] --- 第二个元素的起始地址
// 返回：[int] --- *a > *b返回正值，否则返回0或负值
// 注意：需要在函数内部进行强制地址类型转换，以实现浮点数比较
// 作者：耿楠
// 日期：2017年11月19日
//-----------------------------------------------------------------------------------------------
int GreaterDf(const void *a, const void *b)
{
    return (*(const double*)a > *(const double*)b) ? 1 :
           (*(const double*)a < * (const double*)b) ? -1 : 0;//*(double*)a - * (double*)b;
}

//-----------------------------------------------------------------------------------------------
// 名称：int LesserDf(const void *a, const void *b)
// 功能：用于浮点数的比较小于函数
// 参数：
//       [const void *a] --- 第一个元素的起始地址
//       [const void *b] --- 第二个元素的起始地址
// 返回：[int] --- *a < *b返回正值，否则返回0或负值
// 注意：需要在函数内部进行强制地址类型转换，以实现浮点数比较
// 作者：耿楠
// 日期：2017年11月19日
//-----------------------------------------------------------------------------------------------
int LesserDf(const void *a, const void *b)
{
    return (*(const double*)b > *(const double*)a) ? 1 :
           (*(const double*)b < * (const double*)a) ? -1 : 0; //*(double*)b - * (double*)a;
}

//-----------------------------------------------------------------------------------------------
// 名称：int GreaterStr(const void *s1, const void *s2)
// 功能：用于浮点数的比较大于函数(二维数组方式)
// 参数：
//       [const void *s1] --- 第一个元素的起始地址
//       [const void *s2] --- 第二个元素的起始地址
// 返回：[int] --- *s1 > *s2返回正值，否则返回0或负值
// 注意：需要在函数内部进行强制地址类型转换，以实现字符串比较
// 作者：耿楠
// 日期：2017年11月23日
//-----------------------------------------------------------------------------------------------
int GreaterStr(const void *s1, const void *s2)
{
    return (strcmp((const char *)s1, (const char *)s2));
}

//-----------------------------------------------------------------------------------------------
// 名称：int LesserStr(const void *s1, const void *s2)
// 功能：用于字符串比较小于的函数(二维数组方式)
// 参数：
//       [const void *s1] --- 第一个元素的起始地址
//       [const void *s2] --- 第二个元素的起始地址
// 返回：[int] --- *s1< *s2返回正值，否则返回0或负值
// 注意：需要在函数内部进行强制地址类型转换，以实现字符串比较
// 作者：耿楠
// 日期：2017年11月23日
//-----------------------------------------------------------------------------------------------
int LesserStr(const void *s1, const void *s2)
{
    return (strcmp((const char *)s2, (const char *)s1));
}

//-----------------------------------------------------------------------------------------------
// 名称：int GreaterStrPt(const void *s1, const void *s2)
// 功能：用于字符串比较大于的函数(指针数组方式)
// 参数：
//       [const void *s1] --- 第一个元素的起始地址
//       [const void *s2] --- 第二个元素的起始地址
// 返回：[int] --- **s1 > **s2返回正值，否则返回0或负值
// 注意：需要在函数内部进行强制地址类型转换，以实现字符串比较
// 作者：耿楠
// 日期：2017年11月23日
//-----------------------------------------------------------------------------------------------
int GreaterStrPt(const void *s1, const void *s2)
{
    return (strcmp(*(const char **)s1, *(const char **)s2));
}

//-----------------------------------------------------------------------------------------------
// 名称：int LesserStrPt(const void *s1, const void *s2)
// 功能：用于字符串比较小于的函数(指针数组方式)
// 参数：
//       [const void *s1] --- 第一个元素的起始地址
//       [const void *s2] --- 第二个元素的起始地址
// 返回：[int] --- **s1 < **s2返回正值，否则返回0或负值
// 注意：需要在函数内部进行强制地址类型转换，以实现字符串比较
// 作者：耿楠
// 日期：2017年11月23日
//-----------------------------------------------------------------------------------------------
int LesserStrPt(const void *s1, const void *s2)
{
    return (strcmp(*(const char **)s2, *(const char **)s1));
}

//-----------------------------------------------------------------------------------------------
// 名称：int GreaterStu(const void *s1, const void *s2)
// 功能：用于字符串比较大于的函数(指针数组方式)
// 参数：
//       [const void *s1] --- 第一个元素的起始地址
//       [const void *s2] --- 第二个元素的起始地址
// 返回：[int] --- **s1 > **s2返回正值，否则返回0或负值
// 注意：需要在函数内部进行强制地址类型转换，以实现字符串比较
// 作者：耿楠
// 日期：2017年11月29日
//-----------------------------------------------------------------------------------------------
int GreaterStu(const void *s1, const void *s2)
{
    StuNodePt p1 = (StuNodePt)s1;
    StuNodePt p2 = (StuNodePt)s2;
    return (strcmp(p1->name, p2->name));//p1->ID - p2->ID;
}

//-----------------------------------------------------------------------------------------------
// 名称：int LesserStu(const void *s1, const void *s2)
// 功能：用于字符串比较小于的函数(指针数组方式)
// 参数：
//       [const void *s1] --- 第一个元素的起始地址
//       [const void *s2] --- 第二个元素的起始地址
// 返回：[int] --- **s1 < **s2返回正值，否则返回0或负值
// 注意：需要在函数内部进行强制地址类型转换，以实现字符串比较
// 作者：耿楠
// 日期：2017年11月29日
//-----------------------------------------------------------------------------------------------
int LesserStu(const void *s1, const void *s2)
{
    StuNodePt p1 = (StuNodePt)s1;
    StuNodePt p2 = (StuNodePt)s2;
    return (strcmp(p2->name, p1->name));//p2->ID - p1->ID;
}

//-----------------------------------------------------------------------------------------------
// 名称：int GreaterStuPt(const void *s1, const void *s2)
// 功能：用于字符串比较大于的函数(指针数组方式)
// 参数：
//       [const void *s1] --- 第一个元素的起始地址
//       [const void *s2] --- 第二个元素的起始地址
// 返回：[int] --- **s1 > **s2返回正值，否则返回0或负值
// 注意：需要在函数内部进行强制地址类型转换，以实现字符串比较
// 作者：耿楠
// 日期：2017年11月30日
//-----------------------------------------------------------------------------------------------
int GreaterStuPt(const void *s1, const void *s2)
{
    StuNodePt p1 = *((StuNodePt *)s1);
    StuNodePt p2 = *((StuNodePt *)s2);
    return (strcmp(p1->name, p2->name));//p1->ID - p2->ID;
}

//-----------------------------------------------------------------------------------------------
// 名称：int LesserStuPt(const void *s1, const void *s2)
// 功能：用于字符串比较小于的函数(指针数组方式)
// 参数：
//       [const void *s1] --- 第一个元素的起始地址
//       [const void *s2] --- 第二个元素的起始地址
// 返回：[int] --- **s1 < **s2返回正值，否则返回0或负值
// 注意：需要在函数内部进行强制地址类型转换，以实现字符串比较
// 作者：耿楠
// 日期：2017年11月30日
//-----------------------------------------------------------------------------------------------
int LesserStuPt(const void *s1, const void *s2)
{
    StuNodePt p1 = *((StuNodePt *)s1);
    StuNodePt p2 = *((StuNodePt *)s2);
    return (strcmp(p2->name, p1->name));//p2->ID - p1->ID;
}
