// 包含输入输出功能。
#include "../../common/Utf8Console.h" // IWYU pragma: keep

#include <iostream>
// 简化标准库名称。
using namespace std;
// 空行让代码结构更清楚。

// 程序入口。
int main() {
// 定义累加结果变量。
    int sum = 0;
// 从 1 循环到 100，并让 i 每次自增。
    for (int i = 1; i <= 100; i++) {
// 把当前值累加到总和。
        sum += i;
// for 循环结束。
    }
// 输出最终结果。
    cout << sum << endl;
// 正常结束程序。
    return 0;
// 主函数结束。
}
