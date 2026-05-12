// 包含输入输出头文件，才能使用 cout 和 endl。
#include "../../common/Utf8Console.h" // IWYU pragma: keep

#include <iostream>
// 使用标准命名空间，简化后续写法。
using namespace std;
// 空行帮助区分头文件、命名空间和主函数。

// 程序入口函数，所有 C++ 程序从这里开始执行。
int main() {
// 向控制台输出问候语，并换行。
    cout << "Hello, C++666" << endl;
    cout << "Hello, C++888" << endl; 
// 返回 0 表示程序正常结束。
    return 0;
// 主函数结束。
}
