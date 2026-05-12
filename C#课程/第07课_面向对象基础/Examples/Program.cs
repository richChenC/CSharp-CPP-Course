// 引入基础命名空间，后面要使用 Console 输出内容。
using System;

// 创建一个学生对象，并通过构造方法传入姓名和年龄。
Student student = new Student("小明", 18);
// 调用对象自己的方法，让学生完成自我介绍。
student.Introduce();

// 定义一个学生类，表示现实中的学生对象。
class Student
{
    // 公开姓名属性，允许外部读取和修改。
    public string Name { get; set; }

    // 公开年龄属性，便于对象保存自己的状态。
    public int Age { get; set; }

    // 定义构造方法，在创建对象时初始化姓名和年龄。
    public Student(string name, int age)
    {
        // 把传入的姓名保存到当前对象的 Name 属性里。
        Name = name;
        // 把传入的年龄保存到当前对象的 Age 属性里。
        Age = age;
    }

    // 定义成员方法，用来输出当前学生的信息。
    public void Introduce()
    {
        // 使用字符串插值输出对象当前保存的姓名和年龄。
        Console.WriteLine($"我是{Name}，今年{Age}岁");
    }
}
