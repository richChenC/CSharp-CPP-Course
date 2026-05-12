// 让 Windows 控制台在程序启动时切到 UTF-8。
#include "../../common/Utf8Console.h" // IWYU pragma: keep

// 包含输入输出功能。
#include <iostream>
// 引入 string 类型，方便处理文本。
#include <string>

// 简化标准库名称书写。
using namespace std;

// 程序入口。
int main() {
    // 定义一个字符串变量保存姓名。
    string name;
    // 定义一个整数变量保存年龄。
    int age;

    // 提示用户输入姓名。
    cout << "请输入姓名：66";
    // 读取用户输入的单个单词。
    cin >> name;

    // 提示用户输入年龄。
    cout << "请输入年龄：";
    // 读取用户输入的年龄。
    cin >> age;

    // 把姓名和年龄拼接输出。
    cout << "你好，" << name << "，你今年" << age << "岁" << endl;

    // 正常结束程序。
    return 0;
}
