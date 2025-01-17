/*--------------------------------------------------------------------------------
* Copyright (c) 2017,西北农林科技大学信息学院计算机科学系
* All rights reserved.
*
* 文件名称：main.c
* 文件标识：见配置管理计划书
* 摘要：判断数字奇偶性的的演示代码。
*
* 当前版本：1.0
* 作者：耿楠
* 完成日期：2018年12月11日
*
* 取代版本：无
* 原作者：
* 完成日期：
--------------------------------------------------------------------------------*/
#include<stdio.h>
#include<string.h>

// 采用宏实现
#define IsOddWithMacro(x) ((x)&0X01)

// 函数原型
int IsOddWithMod(int); // 通过%2判断
int IsOddWithLoop(int); // 通过循环判断
int IsOddWithDiv(int); // 通过/2判断
int IsOddWithBitAnd(int); // 通过位与判断
int IsOddWithBitShift(int); // 通过移位判断

void run(void); // 测试函数

// 函数类型重定义
typedef int(*oddF)(int);

// 函数描述结构体
typedef struct
{
    char *msg; //
    oddF pfoo;
} oddT;

// 测试
int main()
{
    run();

    return 1;
}

// 函数定义

//-----------------------------------------------------------------------------------------------
// 名称: void run(void)
// 功能: 函数功能测试函数
// 算法: 利用带有NULL的函数指针数组和数组名称指针数组通过循环测试每个函数。
//          若有新函数，将相应名称加入数组即可。
// 参数:
//       [void] --- 无
// 返回: [void]  --- 无
// 作者: 耿楠
// 日期: 2018年12月20日
//-----------------------------------------------------------------------------------------------
void run(void)
{
    // 测试奇偶判断函数
    oddT oddItem[] =
    {
        {"With Mod", IsOddWithMod},
        {"With Loop", IsOddWithLoop},
        {"With Div", IsOddWithDiv},
        {"With BitAnd", IsOddWithBitAnd},
        {"With BitShift", IsOddWithBitShift}
    };

    int d[] = {26, 367, 512, 876399};
    printf("1---Odd, 0---Even:\n");
    printf("IsOdd Testing...\n");
    for(int i = 0; i < sizeof(oddItem) / sizeof(oddItem[0]); i++)
    {
        printf("%02d. %s: \n", i + 1, oddItem[i].msg);

        for(int j = 0; j < sizeof(d) / sizeof(d[0]); j++)
        {
            int res = oddItem[i].pfoo(d[j]);
            printf("IsOdd(%d) = %d\n", d[j], res);
        }
        printf("\n");
    }

}

//-----------------------------------------------------------------------------------------------
// 名称: int IsOddWithMod(int n)
// 功能: 判断一个整数的奇偶性
// 算法: 通过与2求余，判断结果是否为0
// 参数:
//       [int n] --- 需要判断的整数
// 返回: [int]  --- 是奇数返回1，否则返回0
// 作者: 耿楠
// 日期: 2018年12月13日
//-----------------------------------------------------------------------------------------------
int IsOddWithMod(int n)
{
    return n % 2 != 0 ? 1 : 0;
}

//-----------------------------------------------------------------------------------------------
// 名称: int IsOddWithLoop(int n)
// 功能: 判断一个整数的奇偶性
// 算法: 通过循环实现，在循环中交替改变标志的真假
// 参数:
//       [int n] --- 需要判断的整数
// 返回: [int]  --- 是奇数返回1，否则返回0
// 作者: 耿楠
// 日期: 2018年12月13日
// 注意: 这是一个没事找抽型算法，当n比较大时，其效率极低！
//-----------------------------------------------------------------------------------------------
int IsOddWithLoop(int n)
{
    int i;
    int flag = 0;

    for(i = 0; i < n; i++)
    {
        flag = 1 - flag; // 0和1的交替变换
    }
    return flag;
}

//-----------------------------------------------------------------------------------------------
// 名称: int IsOddWithDiv(int n)
// 功能: 判断一个整数的奇偶性
// 算法: 通过/2后再*2，根据结果是否与原值相同判断
// 参数:
//       [int n] --- 需要判断的整数
// 返回: [int]  --- 是奇数返回1，否则返回0
// 作者: 耿楠
// 日期: 2018年12月13日
//-----------------------------------------------------------------------------------------------
int IsOddWithDiv(int n)
{
    return (n / 2) * 2 != n;
}

//-----------------------------------------------------------------------------------------------
// 名称: int IsOddWithBitAnd(int n)
// 功能: 判断一个整数的奇偶性
// 算法: 通过与0X01按位与实现，结果是0表示偶数，为1表示奇数
// 参数:
//       [int n] --- 需要判断的整数
// 返回: [int]  --- 是奇数返回1，否则返回0
// 作者: 耿楠
// 日期: 2018年12月13日
//-----------------------------------------------------------------------------------------------
int IsOddWithBitAnd(int n)
{
    return (n & 0X01); // 偶数的二进制第0位是0，奇数是1
}

//-----------------------------------------------------------------------------------------------
// 名称: int IsOddWithBitShift(int n)
// 功能: 判断一个整数的奇偶性
// 算法: 通过右移1位再左移1位，若与原数相同则为偶数，否则为奇数
//          用异或来判断两个数是不是相等
// 参数:
//       [int n] --- 需要判断的整数
// 返回: [int]  --- 是奇数返回1，否则返回0
// 作者: 耿楠
// 日期: 2018年12月13日
//-----------------------------------------------------------------------------------------------
int IsOddWithBitShift(int n)
{
    return ((n >> 1) << 1) ^ n;
}
