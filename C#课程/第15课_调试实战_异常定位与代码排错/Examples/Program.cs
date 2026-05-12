// 引入基础命名空间。
using System;

// 故意把 student 设为 null，模拟空引用问题。
Student? student = null;

try
{
    // 这里会触发空引用异常，因为 student 现在没有指向任何对象。
    Console.WriteLine(student.Name);
}
catch (NullReferenceException ex)
{
    // 输出异常信息，帮助学习者观察错误现象。
    Console.WriteLine($"发生空引用异常：{ex.Message}");
    // 提示应该如何调试。
    Console.WriteLine("请在访问 student.Name 前打断点，观察 student 是否为 null。");
}

// 定义一个学生类。
class Student
{
    // 学生姓名属性。
    public string Name { get; set; } = string.Empty;
}
