// 包含输入输出功能。
#include "../../common/Utf8Console.h" // IWYU pragma: keep

#include <iostream>
// 简化标准库访问。
using namespace std;
// 空行分隔父类和子类。

// 定义动物基类。
class Animal {
// 公开区域。
public:
// 定义虚函数，供子类重写。
    virtual void speak() { cout << "动物叫" << endl; }
// 定义虚析构函数，保证删除派生类时行为正确。
    virtual ~Animal() = default;
// 父类结束。
};
// 空行分隔子类。

// 定义狗类，并公开继承动物类。
class Dog : public Animal {
// 公开区域。
public:
// 重写父类方法，表现多态。
    void speak() override { cout << "狗狗汪汪叫" << endl; }
// 子类结束。
};
// 空行分隔定义和主函数。

// 程序入口。
int main() {
// 用基类指针指向派生类对象，演示多态。
    Animal* a = new Dog();
// 调用时执行子类版本的方法。
    a->speak();
// 释放动态内存。
    delete a;
// 正常结束。
    return 0;
// 主函数结束。
}
