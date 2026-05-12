// 引入基础命名空间。
using System;
// 引入文件操作命名空间，后面要读写文本文件。
using System.IO;
// 空行把引用和逻辑分开。

// 开启异常保护区域。
try
// try 代码块开始。
{
// 把一段文本写入文件，如果没有文件会自动创建。
    File.WriteAllText("note.txt", "C# 文件写入示例");
// 读取刚刚写入的文件内容。
    string text = File.ReadAllText("note.txt");
// 把读到的文本输出到控制台。
    Console.WriteLine(text);
// try 代码块结束。
}
// 捕获所有异常，并把错误对象保存到 ex。
catch (Exception ex)
// catch 代码块开始。
{
// 打印错误信息，便于定位问题。
    Console.WriteLine($"出错：{ex.Message}");
// catch 代码块结束。
}