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
// 名称：void FreeStu(void * pData)
// 功能：释放一个结构体占有的内存
// 参数：
//       [void * pData] --- 数据起始地址的指针
// 返回：无
// 注意：需要在函数内部进行强制地址类型转换
// 作者：耿楠
// 日期：2017年12月20日
//-----------------------------------------------------------------------------------------------
void FreeStu(void * pData)
{
    // 强制转换指针类型
    Student *p = *((Student **)pData);
    // 释放
    free(p);
    p = NULL;
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
    Student *p = *((Student **)pData);
    // 输出
    printf("%d %s %0.2f %0.2f %0.2f %0.2f %d\n", p->ID, p->name,
           p->grade[0],
           p->grade[1],
           p->grade[2],
           p->average,
           p->rank
          );
}

//-----------------------------------------------------------------------------------------------
// 名称：int cmpStuID(const void *s1, const void *s2)
// 功能：用于按学号比较两个结构体大小
// 参数：
//       [const void *s1] --- 第一个元素的起始地址
//       [const void *s2] --- 第二个元素的起始地址
// 返回：[int] --- 相等返回0，大于返回1，小于返回-1
// 注意：需要在函数内部进行强制地址类型转换
// 作者：耿楠
// 日期：2017年11月30日
//-----------------------------------------------------------------------------------------------
int cmpStuID(const void *s1, const void *s2)
{
    Student * p1 = *((Student **)s1);
    Student * p2 = *((Student **)s2);
    return ((p1->ID > p2->ID) - (p1->ID < p2->ID));
}


//-----------------------------------------------------------------------------------------------
// 名称：int cmpStuAvg(const void *s1, const void *s2)
// 功能：用于按平均值比较两个结构体大小
// 参数：
//       [const void *s1] --- 第一个元素的起始地址
//       [const void *s2] --- 第二个元素的起始地址
// 返回：[int] --- 相等返回0，小于返回1，大于返回-1
// 注意：需要在函数内部进行强制地址类型转换
// 作者：耿楠
// 日期：2017年11月30日
//-----------------------------------------------------------------------------------------------
int cmpStuAvg(const void *s1, const void *s2)
{
    // 强制类型转换
    Student * p1 = *((Student **)s1);
    Student * p2 = *((Student **)s2);

    // 按学号比较(返回1、0、-1)
    return ((p1->average < p2->average) - (p1->average > p2->average));
}