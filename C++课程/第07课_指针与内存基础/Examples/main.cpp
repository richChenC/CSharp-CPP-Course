// 包含输入输出功能。
#include "../../common/Utf8Console.h" // IWYU pragma: keep

#include <iostream>
// 简化标准库名称。
using namespace std;
// 空行帮助阅读。

// 程序入口。
int main() {
// 定义一个普通整型变量。
    int value = 10;
// 让指针 p 保存 value 的地址。
    int* p = &value;
// 输出变量本身的值。
    cout << "value=" << value << endl;
// 输出变量的地址。
    cout << "address=" << p << endl;
// 通过指针取出地址里的值。
    cout << "pointed=" << *p << endl;
// 正常结束。
    return 0;
// 主函数结束。
}
