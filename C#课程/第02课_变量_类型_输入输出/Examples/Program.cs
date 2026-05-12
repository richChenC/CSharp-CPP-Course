// 引入基础命名空间，后面要用到 Console 和基本类型。
using System;
// 空行用于分隔逻辑块，提升可读性。

// 先提示用户输入姓名，这里使用 Write 让光标停留在同一行。
Console.Write("请输入姓名：");
// 读取用户输入，如果为空就使用“未知”作为兜底值。
string name = Console.ReadLine() ?? "未知";
// 继续提示用户输入年龄。
Console.Write("请输入年龄：");
// 把字符串转成整数；如果没有输入，就默认当作 0。
int age = int.Parse(Console.ReadLine() ?? "0");
// 使用字符串插值把姓名和年龄拼接成一条完整信息。
Console.WriteLine($"你好，{name}，你今年 {age} 岁。");