// 包含 UTF-8 控制台支持，保证中文输出正常。
#include "../../common/Utf8Console.h" // IWYU pragma: keep

// 包含排序算法。
#include <algorithm>
// 包含输入输出功能。
#include <iostream>
// 包含动态数组 vector。
#include <vector>

// 使用标准命名空间，减少 std:: 前缀重复书写。
using namespace std;

// 程序入口函数。
int main() {
    // 准备一个整数动态数组，模拟一组待排序的数据。
    vector<int> numbers{42, 7, 19, 88, 13, 35};

    // 输出排序前的数据，帮助我们观察变化。
    cout << "排序前：";
    // 使用 const auto& 遍历容器，避免不必要复制。
    for (const auto& value : numbers) {
        // 逐个输出数组中的元素。
        cout << value << " ";
    }
    // 换行，让输出更清晰。
    cout << endl;

    // 使用标准库排序函数，并传入一个 Lambda 作为比较规则。
    sort(numbers.begin(), numbers.end(), [](int left, int right) {
        // 返回 true 表示 left 应排在 right 前面，这里按从大到小排序。
        return left > right;
    });

    // 输出排序后的数据，验证排序结果是否正确。
    cout << "排序后：";
    // 再次遍历容器，查看排序后的顺序。
    for (const auto& value : numbers) {
        // 输出每个元素。
        cout << value << " ";
    }
    // 换行结束这一段输出。
    cout << endl;

    // 正常返回 0，表示程序运行成功。
    return 0;
}
