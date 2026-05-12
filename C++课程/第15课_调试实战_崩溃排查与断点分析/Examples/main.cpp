// 包含 UTF-8 控制台支持。
#include "../../common/Utf8Console.h" // IWYU pragma: keep

// 包含异常类型。
#include <exception>
// 包含输入输出。
#include <iostream>
// 包含动态数组。
#include <vector>

// 使用标准命名空间。
using namespace std;

// 程序入口。
int main() {
    // 准备一个成绩数组。
    vector<int> scores{95, 88, 76};

    // 故意给一个错误下标，模拟真实开发中的越界问题。
    int index = 5;

    // 输出当前想访问的下标。
    cout << "准备读取下标：" << index << endl;

    try {
        // 使用 at 而不是中括号，这样越界时会抛异常，便于调试定位。
        int value = scores.at(index);

        // 如果没有异常，就输出读取到的成绩。
        cout << "读取到的成绩：" << value << endl;
    } catch (const exception& ex) {
        // 捕获异常并输出错误信息。
        cout << "发生异常：" << ex.what() << endl;
        // 提示学习者应该怎样调试。
        cout << "请在 index 和 scores.at(index) 处打断点，观察为什么越界。" << endl;
    }

    // 正常结束程序。
    return 0;
}
