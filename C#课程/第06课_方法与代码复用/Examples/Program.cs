// 引入基础命名空间，后面要使用 Console 输出内容。
using System;

// 调用 Add 方法，并把返回结果输出到控制台。
Console.WriteLine(Add(3, 5));

// 定义一个静态本地方法，接收两个整数并返回它们的和。
static int Add(int a, int b)
{
    // 把两个参数相加，并把结果交还给调用者。
    return a + b;
}
