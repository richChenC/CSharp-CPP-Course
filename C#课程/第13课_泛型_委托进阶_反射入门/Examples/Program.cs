// 引入基础命名空间，后面要使用 Console 和 Type。
using System;

// 定义一个泛型方法，接收任意类型并输出内容。
static void PrintValue<T>(T value)
{
    // 输出类型名称和值，帮助我们观察泛型效果。
    Console.WriteLine($"类型：{typeof(T).Name}，值：{value}");
}

// 定义一个普通方法，稍后交给委托调用。
static int Add(int left, int right)
{
    // 返回两个整数之和。
    return left + right;
}

// 调用泛型方法，传入整数。
PrintValue(18);
// 调用泛型方法，传入字符串。
PrintValue("C# 进阶开始了");

// 定义一个 Func 委托变量，并让它指向 Add 方法。
Func<int, int, int> calculator = Add;
// 通过委托调用方法，并输出结果。
Console.WriteLine($"委托计算结果：{calculator(7, 5)}");

// 获取 string 类型对象，用于反射查看方法信息。
Type type = typeof(string);
// 获取该类型的公开方法数组。
var methods = type.GetMethods();
// 输出方法数量。
Console.WriteLine($"string 类型的公开方法数量：{methods.Length}");
