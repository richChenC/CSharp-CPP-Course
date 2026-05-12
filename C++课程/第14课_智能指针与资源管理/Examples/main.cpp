// 包含 UTF-8 控制台支持。
#include "../../common/Utf8Console.h" // IWYU pragma: keep

// 包含输入输出头文件。
#include <iostream>
// 包含智能指针工具。
#include <memory>
// 包含字符串类型。
#include <string>

// 使用标准命名空间。
using namespace std;

// 定义一个简单的任务类，用来演示对象生命周期。
class Task {
public:
    // 构造函数，创建对象时自动执行。
    Task(string title) : title_(move(title)) {
        // 输出构造日志，方便调试时观察对象创建时机。
        cout << "创建任务对象：" << title_ << endl;
    }

    // 析构函数，对象销毁时自动执行。
    ~Task() {
        // 输出析构日志，帮助我们验证资源是否自动释放。
        cout << "销毁任务对象：" << title_ << endl;
    }

    // 普通成员函数，用于显示任务信息。
    void Print() const {
        // 输出任务标题。
        cout << "当前任务：" << title_ << endl;
    }

private:
    // 保存任务标题的私有成员变量。
    string title_;
};

// 程序入口。
int main() {
    // 使用 make_unique 创建智能指针对象，推荐这种写法。
    auto task = make_unique<Task>("完成今天的 C++ 智能指针练习");

    // 调用成员函数，证明对象可以正常使用。
    task->Print();

    // 输出提示，说明马上要离开作用域。
    cout << "main 即将结束，观察析构函数是否自动触发。" << endl;

    // 正常结束程序。
    return 0;
}
