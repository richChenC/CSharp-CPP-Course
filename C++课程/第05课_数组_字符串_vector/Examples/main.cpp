// 包含输入输出功能。
#include "../../common/Utf8Console.h" // IWYU pragma: keep

#include <iostream>
// 引入 vector 容器。
#include <vector>
// 简化标准库使用。
using namespace std;
// 空行分隔导入和主体。

// 程序入口。
int main() {
// 创建一个整型动态数组。
    vector<int> nums = {1, 2, 3, 4, 5, 6};
// 在头部插入一个新元素。
    nums.insert(nums.begin(), 0);
// 使用范围 for 遍历所有元素。
    for (int n : nums) {
// 输出当前元素并加一个空格。
        cout << n << " ";
// 循环体结束。
    }
// 正常退出。
    return 0;
// 主函数结束。
}
