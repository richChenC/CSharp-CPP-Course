// 引入基础命名空间。
using System;
// 引入泛型集合命名空间，List<T> 依赖这里。
using System.Collections.Generic;
// 空行让导入部分和主体逻辑分开。

// 创建一个字符串列表，初始化三个名字。
List<string> names = new List<string> { "Tom", "Lucy", "Jack" };
// 向列表中追加一个新元素。
names.Add("Rose");
// 使用 foreach 逐个读取集合中的元素。
foreach (string name in names)
// 循环体开始。
{
// 输出当前遍历到的名字。
    Console.WriteLine(name);
// 循环体结束。
}