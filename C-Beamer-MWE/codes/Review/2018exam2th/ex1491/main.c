/*--------------------------------------------------------------------------------
* Copyright (c) 2019,西北农林科技大学信息学院计算机科学系
* All rights reserved.
*
* 文件名称：main.c
* 文件标识：见配置管理计划书
* 摘要：城市电话号码问题的演示代码。
*
* 问题描述：某城市电话号码包括地区码、前缀、有效号码三部分组成，其中地区码是0-4位数字；
*          前缀是以非0开头的3位数字，有效号码是4位数字，各部分之间用减号(-)分隔，
*          地区码为空时地区码与前缀之间不包含分隔符。请编写函数检测输入号码num的有效性，
*          若输入号码符合上述规定返回0，否则返回1。函数原型定义如下：
*          int CheckPhoneNum(char * num);
* 输入：无
* 输出：无
* 输入样例：无
* 输出样例：无
*
* 测试数据及对应输出结果见"data/"下的各个"*.in"文件及"*.out"
*
* 当前版本：1.0
* 作者：C语言课程组
* 完成日期：2019年1月16日
*
* 取代版本：无
* 原作者：
* 完成日期：
--------------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 宏定义(非必须，若定义，则需要一并提交)
#define OK 0
#define ERR 1
#define INVALID -1

// 函数原型
// 需要的其它函数(非必须，若设计这些函数，则统一提交)
int Check(char *, int); // 判断地区码、前缀或有效号码的有效性
int IsDigit(char *); // 统计数字字符串中数字总个数
int CountSp(char *, char); //统计一个字符在指定字符串中出现的次数

// 要求提交的函数
int CheckPhoneNum(char *); // 判断号码是否正确

// 测试(OJ系统提供，无法更改)
int main()
{
    char buf[32] = {0};

    fgets(buf, 30, stdin);
    printf("%d\n", CheckPhoneNum(buf));
    return 0;
}

// 函数定义
//-----------------------------------------
// 名称: int CountSp(char *s, char sp)
// 功能: 统计一个字符在指定字符串中出现的次数
// 参数:
//       [char *s] --- 字符串指针
//       [char sp] --- 指定的字符
// 返回: [int]  --- 指定字符出现的个数
// 作者: C语言课程组
// 日期: 2019年1月16日
//-----------------------------------------
int CountSp(char *s, char sp)
{
    int n = 0;
    while(*s) // 用'\0'终止循环
    {
        if (*s == sp)
        {
            n++; // 计数
        }
        s++;
    }
    return n; // 返回统计结果
}

//----------------------------------------------------------------------------
// 名称: int IsDigit(char *s)
// 功能: 统计数字字符串中数字总个数
// 参数:
//       [char *s] --- 需要判断的字符串指针
// 返回: [int]  --- 是返回数字字符串中数字总个数，若字符串中含有非数字字符则返回-1
// 作者: C语言课程组
// 日期: 2019年1月16日
//----------------------------------------------------------------------------
int IsDigit(char *s)
{
    int n = 0;

    // 用'\0'终止循环
    while(*s)
    {
        if (*s >= '0' && *s <= '9')
        {
            n++;
        }
        else
        {
            return INVALID;
        }
        s++;
    }

    return n;
}

//-------------------------------------------------------------------
// 名称: int Check(char *buf, int p)
// 功能: 判断地区码、前缀或有效号码的有效性
// 参数:
//       [char *buf] --- 地区码、前缀或有效号码字符串(只包含一种)
//       [int p] --- 判断类别编号：地区码---1、前缀码---2、有效号码---3
// 返回: [int]  --- 正确返回0(OK宏)，否则返回1(ERR宏)
// 作者: C语言课程组
// 日期: 2019年1月16日
//-------------------------------------------------------------------
int Check(char *buf, int p)
{
    int len = 0;
    int result = 0;

    // 号码长度
    len = IsDigit(buf);
    switch(p)
    {
    case 1: // 地区码
        if (len > 0 && len <= 4) // 0-4位数字
        {
            result = 1;
        }
        break;
    case 2: // 前缀
        if(*buf != '0' && len == 3) // 以非0开头的3位数字
        {
            result = 1;
        }
        break;
    case 3: // 有效号码
        if (len == 4) // 4位数字
        {
            result = 1;
        }
        break;
    default:
        result = 0;
    }
    // 返回结果
    return (result == 1) ? OK : ERR;
}

//---------------------------------------------------
// 名称: int CheckPhoneNum(char * buf)
// 功能: 判断城市电话号码正确性
// 参数:
//       [char *buf] --- 电话号码字符串
// 返回: [int]  --- 正确返回0(OK宏)，否则返回1(ERR宏)
// 作者: C语言课程组
// 日期: 2019年1月16日
//---------------------------------------------------
int CheckPhoneNum(char * buf)
{
    // 声明变量
    char num[16];
    int  sp, p = 1;
    char *tmp;

    // 总长度有效性检验(fgets会读入'\n')
    if(strlen(buf) < 15)
    {
        strcpy(num, buf);
    }
    else
    {
        return ERR;
    }

    // 统计'-'出现的次数
    sp = CountSp(num, '-');
    if (sp == 1) // 没有地区码
    {
        p = 2;
    }
    else if(sp == 0 || sp > 2)
    {
        return ERR;
    }

    // 利用strtok分割字符串
    tmp = strtok(num, "-");
    while( tmp != NULL && p < 4)
    {
        // 号码有效性检验
        if (Check(tmp, p) == ERR)
        {
            return ERR;
        }
        // 取下一段号码
        tmp = strtok( NULL, "-");
        p++;
    }

    // 所有检验正常
    return OK;
}
