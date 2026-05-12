// 引入基础命名空间，后面要使用 Console 输出内容。
using System;

// 使用父类变量保存子类对象，这是多态最典型的写法。
Animal animal = new Dog();
// 调用 Speak 时，实际执行的是 Dog 重写后的版本。
animal.Speak();

// 定义动物父类，给不同动物提供统一的行为入口。
class Animal
{
    // virtual 表示这个方法可以被子类重写。
    public virtual void Speak()
    {
        // 父类提供一个默认叫声。
        Console.WriteLine("动物在叫");
    }
}

// 定义狗类，并继承动物类。
class Dog : Animal
{
    // override 表示重写父类的虚方法。
    public override void Speak()
    {
        // 子类给出更具体的叫声。
        Console.WriteLine("狗狗汪汪叫");
    }
}
