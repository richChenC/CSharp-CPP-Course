// 包含输入输出功能。
#include "../../common/Utf8Console.h" // IWYU pragma: keep

#include <iostream>
// 引入 vector 容器。
#include <vector>
// 引入标准算法。
#include <algorithm>
// 简化标准库访问。
using namespace std;
// 空行把引入和主体分隔开。

// 程序入口。
int main() {
// 创建一个无序整数列表。
    vector<int> nums = {5, 2, 9, 1};
// 对 vector 进行升序排序。
    sort(nums.begin(), nums.end());
// 遍历并输出排序后的结果。
    for (int n : nums) cout << n << " ";
// 正常退出。
    return 0;
// 主函数结束。
}
