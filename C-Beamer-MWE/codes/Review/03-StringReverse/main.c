/*--------------------------------------------------------------------------------
* Copyright (c) 2017,西北农林科技大学信息学院计算机科学系
* All rights reserved.
*
* 文件名称：main.c
* 文件标识：见配置管理计划书
* 摘要：演示字符串逆序程序的常见写法。
*
* 当前版本：1.0
* 作者：耿楠
* 完成日期：2017年11月21日
*
* 取代版本：无
* 原作者：耿楠
* 完成日期：2017年11月21日
------------------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10

//函数原型
char* CopyReverse(char *); // 拷贝方式实现逆序
char* InPlaceReverse(char *); // 原地逆序，指针方式实现
void InPlaceRecursiveReverse(char*, int, int); // 原地逆序，递归方式实现
char* InPlaceIdxReverse(char*, int, int); // 原地逆序，下标方式实现
char* XorReverse(char*); // 原地逆序，指针方式索引，异或方式实现
char* SentenceReverse(char*); // 原地逆序，按单词逆序
void ReversePrintWithStrlen(const char*); // 仅逆序按字符打印输出
void ReversePrintWithoutStrlen(const char*); // 仅逆序按字符打印输出，不使用系统函数
void ReversePrintRecursive(const char*); // 仅逆序按字符打印输出，使用递归方式

int main()
{
    char s[] = "This is a sentence";
    char *p;

    puts(s);

    p = CopyReverse(s); // 拷贝方式实现逆序
    puts(p);
    free(p); // 释放空间

    InPlaceReverse(s); // 原地逆序，指针方式实现
    puts(s);

    InPlaceRecursiveReverse(s, 0, strlen(s) - 1); // 原地逆序，递归方式实现
    puts(s);

    InPlaceIdxReverse(s, 0, strlen(s) - 1); // 原地逆序，下标方式实现
    puts(s);

    XorReverse(s); // 原地逆序，指针方式索引，异或方式实现
    puts(s);

    SentenceReverse(s); // 原地逆序，按单词逆序
    puts(s);

    ReversePrintWithStrlen(s); // 仅逆序按字符打印输出
    printf("\n");

    ReversePrintWithoutStrlen(s); // 仅逆序按字符打印输出，不使用系统函数
    printf("\n");

    ReversePrintRecursive(s); // 仅逆序按字符打印输出，使用递归方式
    printf("\n");

    return 0;
}

//-----------------------------------------------------------------------------------------------
// 名称：char* CopyReverse(char* s)
// 功能：字符串直接逆序。
//            算法：直接分配一个与原字符串等长的字符数组，然后反向拷贝
// 参数：
//       [char* s] --- 待逆序的字符串的指针
// 返回：[char*] --- 逆序后字符串的指针
// 注意：该函数返回的是用malloc分配空间，使用后需要用free进行空间释放。
// 作者：耿楠
// 日期：2017年11月21日
//-----------------------------------------------------------------------------------------------
char* CopyReverse(char* s)
{
    //将q指向字符串最后一个字符
    char* q = s;

    while(*q++) // 利用空循环找到最后一个字符的指针
    {
        ;
    }

    q -= 2; // 循环后指向'\0'后的一个字符，-2退回到最后一个字符

    //分配空间，存储逆序后的字符串，注意分配保存'\0'的空间。
    char* p = (char *)malloc((q - s + 2) * sizeof(char));
    char* r = p; // 记录首地址，以便返回该地址

    while(q >= s)
    {
        *p++ = *q--; // 逆序存储
    }

    *p = '\0';

    return r;
}

//-----------------------------------------------------------------------------------------------
// 名称：char* InPlaceReverse(char* s)
// 功能：原地逆序方式，不允许分配额外空间，将两边的字符逐个交换。
//            算法：设置两个指针，分别指向字符串的头部和尾部，
//                       然后交换两个指针所指的字符，并向中间移动指针直到相遇。
// 参数：
//       [char* s] --- 待逆序的字符串的指针
// 返回：[char*] --- 逆序后字符串的指针
// 作者：耿楠
// 日期：2017年11月21日
//-----------------------------------------------------------------------------------------------
char* InPlaceReverse(char* s)
{
    // p指向字符串头部
    char* p = s;

    char* q = s;

    while(*q) // 最终指向'\0'空字符
    {
        ++q;
    }
    q--; // q指向最后一个字符

    // 交换并移动指针，直到p和q相遇
    while(q > p)
    {
        char t = *p;
        *p = *q;
        *q = t;
        p++;
        q--;
    }

    return s;
}

//-----------------------------------------------------------------------------------------------
// 名称：void InPlaceRecursiveReverse(char* s, int left, int right)
// 功能：原地逆序，将两边的字符逐个交换。
//            算法：对字符串s在区间left和right之间进行逆序，递归法。
// 参数：
//       [char* s] --- 待逆序的字符串的指针
// 返回：[void] --- 无
// 作者：耿楠
// 日期：2017年11月21日
//-----------------------------------------------------------------------------------------------
void InPlaceRecursiveReverse(char* s, int left, int right)
{
    // 结束递归
    if(left >= right)
        return;

    // 交换
    char t = s[left];
    s[left] = s[right];
    s[right] = t;

    InPlaceRecursiveReverse(s, left + 1, right - 1); // 递归
}

//-----------------------------------------------------------------------------------------------
// 名称：char*InPlaceIdxReverse(char* s, int left, int right)
// 功能：原地逆序，将两边的字符逐个交换。
//            算法：对字符串s在区间left和right之间进行逆序，非递归法。
// 参数：
//       [char* s] --- 待逆序的字符串的指针
// 返回：[char*] --- 逆序后字符串的指针
// 作者：耿楠
// 日期：2017年11月21日
//-----------------------------------------------------------------------------------------------
char* InPlaceIdxReverse(char* s, int left, int right)
{
    // 利用循环实现交换
    while(left < right)
    {
        char t = s[left];
        s[left++] = s[right];
        s[right--] = t;
    }

    return s;
}

//-----------------------------------------------------------------------------------------------
// 名称：char* XorReverse(char* s)
// 功能：原地逆序，将两边的字符逐个交换。
//            算法：不允许临时变量的原地逆序，使用异或操作实现交换。
// 参数：
//       [char* s] --- 待逆序的字符串的指针
// 返回：[char*] --- 逆序后字符串的指针
// 注意：用异或方式实现数据交换。
// 作者：耿楠
// 日期：2017年11月21日
//-----------------------------------------------------------------------------------------------
char* XorReverse(char* s)
{
    // 保存原起始地址指针
    char* r = s;

    //令p指向字符串最后一个字符
    char* p = s;

    // 通过循环找到最后一个字符('\0'前的字符)
    while (*(p + 1) != '\0')
    {
        ++p;
    }

    // 使用异或操作进行交换
    while (p > s)
    {
        *p = *p ^ *s;
        *s = *p ^ *s;
        *p = *p ^ *s;
        p--;
        s++;
    }

    return r;
}

//-----------------------------------------------------------------------------------------------
// 名称：static void WordReverse(char* p, char* q)
// 功能：原地逆序，对指针p和q之间的所有字符逆序。
// 参数：
//       [char* p] --- 待逆序字符串起始指针
//       [char* q] --- 待逆序字符串结束指针
// 返回：[void] --- 无
// 注意：本函数仅为SentenceReverse函数调用， 设置为static避免在使用其它文件中能够调用。
// 作者：耿楠
// 日期：2017年11月21日
//-----------------------------------------------------------------------------------------------
static void WordReverse(char* p, char* q)
{
    while(p < q)
    {
        char t = *p;
        *p++ = *q;
        *q-- = t;
    }
}

//-----------------------------------------------------------------------------------------------
// 名称：char* SentenceReverse(char* s)
// 功能：将句子按单词逆序。
//            算法：先按单词逆序，再按字符逆序，如：
//                      This is a sentence
//                      sihT si a ecnetnes
//                      sentence a is This
// 参数：
//       [char* s] --- 待逆序的字符串的指针
// 返回：[char*] --- 逆序后字符串的指针
// 注意：本例以空格为单词分界字符
// 作者：耿楠
// 日期：2017年11月21日
//-----------------------------------------------------------------------------------------------
char* SentenceReverse(char* s)
{
    char* p = s; // 指向单词的首字符
    char* q = s; // 指向空格或者 '\0'

    while(*q != '\0')
    {
        if (*q == ' ')
        {
            WordReverse(p, q - 1);
            q++; // 指向下一个单词首字符
            p = q; // 调整到下一个单词的起始地址
        }
        else
            q++;
    }

    WordReverse(p, q - 1); // 对最后一个单词逆序
    WordReverse(s, q - 1); // 对整个句子逆序

    return s;
}

//-----------------------------------------------------------------------------------------------
// 名称：void ReversePrintWithStrlen(const char* s)
// 功能：字符串按逆序打印输出。
// 参数：
//       [const char* s] --- 待逆序的字符串的指针
// 返回：[void] --- 无
// 作者：耿楠
// 日期：2017年11月21日
//-----------------------------------------------------------------------------------------------
void ReversePrintWithStrlen(const char* s)
{
    int len = strlen(s); // 求出字符串长度

    for (int i = len - 1; i >= 0; --i)
    {
        printf("%c", s[i]); // 输出一个字符
    }
}

//-----------------------------------------------------------------------------------------------
// 名称：void ReversePrintWithoutStrlen(const char* s)
// 功能：字符串按逆序打印输出，不使用字符串长度函数。
// 参数：
//       [const char* s] --- 待逆序的字符串的指针
// 返回：[void] --- 无
// 作者：耿楠
// 日期：2017年11月21日
//-----------------------------------------------------------------------------------------------
void ReversePrintWithoutStrlen(const char* s)
{
    const char* p = s; // 指向起始地址

    while (*p) // 找到'\0'空字符
    {
        p++;
    }

    --p; //p退回到最后一个字符

    while (p >= s) // 逆序打印输出
    {
        printf("%c", *p);
        --p;
    }
}

//-----------------------------------------------------------------------------------------------
// 名称：void ReversePrintRecursive(const char* s)
// 功能：字符串按逆序打印输出，使用递归方式。
// 参数：
//       [const char* s] --- 待逆序的字符串的指针
// 返回：[void] --- 无
// 作者：耿楠
// 日期：2017年11月21日
//-----------------------------------------------------------------------------------------------
void ReversePrintRecursive(const char* s)
{
    if(*(s + 1) != '\0')
    {
        ReversePrintRecursive(s + 1);
    }

    printf("%c", *s);
}

