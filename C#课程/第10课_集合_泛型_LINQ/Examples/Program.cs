// 引入基础命名空间。
using System;
// 引入泛型集合命名空间。
using System.Collections.Generic;
// 引入 LINQ 扩展方法命名空间。
using System.Linq;
// 空行后开始定义集合。

// 创建一个成绩列表，方便演示查询。
var scores = new List<int> { 88, 59, 92, 76, 100 };
// 筛选及格分数，并按从高到低排序。
var passed = scores.Where(s => s >= 60).OrderByDescending(s => s);
// 遍历查询结果。
foreach (var score in passed)
// 循环体开始。
{
// 输出每个及格分数。
    Console.WriteLine(score);
// 循环体结束。
}