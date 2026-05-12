// 包含输入输出功能。
#include "../../common/Utf8Console.h" // IWYU pragma: keep

#include <iostream>
// 简化标准库使用。
using namespace std;
// 空行把函数定义和 main 分开。

// 定义一个引用参数函数，用于交换两个整数。
void swapValue(int& a, int& b) {
// 先保存第一个值，防止交换时丢失。
    int temp = a;
// 把第二个值赋给第一个参数。
    a = b;
// 把临时变量里的原值赋给第二个参数。
    b = temp;
// 交换函数结束。
}
// 空行分隔函数和主程序。

// 程序入口。
int main() {
// 准备两个待交换的变量。
    int x = 3, y = 5;
// 调用交换函数。
    swapValue(x, y);
// 输出交换后的结果。
    cout << x << " " << y << endl;
// 正常退出。
    return 0;
// 主函数结束。
}
