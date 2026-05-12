// 包含输入输出功能。
#include "../../common/Utf8Console.h" // IWYU pragma: keep

#include <iostream>
// 引入字符串类型。
#include <string>
// 简化标准库名称。
using namespace std;
// 空行分隔导入和类定义。

// 定义一个学生类。
class Student {
// 公开区域，允许外部访问部分成员。
public:
// 保存学生姓名。
    string name;
// 保存学生年龄。
    int age;
// 空行分隔成员和构造函数。

// 构造函数，使用初始化列表完成成员初始化。
    Student(string n, int a) : name(n), age(a) {}
// 空行分隔构造和行为函数。

// 定义成员函数，输出自我介绍。
    void introduce() {
// 把当前对象的数据打印出来。
        cout << "我是" << name << "，今年" << age << "岁" << endl;
// 成员函数结束。
    }
// 类定义结束。
};
// 空行后进入主函数。

// 程序入口。
int main() {
// 创建一个学生对象，并初始化姓名和年龄。
    Student s("Tom", 18);
// 调用对象的方法。
    s.introduce();
// 正常退出。
    return 0;
// 主函数结束。
}
