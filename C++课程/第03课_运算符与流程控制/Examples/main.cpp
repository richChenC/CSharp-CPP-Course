// 包含输入输出功能。
#include "../../common/Utf8Console.h" // IWYU pragma: keep

#include <iostream>
// 简化标准库访问。
using namespace std;
// 空行分隔导入和主体。

// 程序入口。
int main() {
// 准备一个成绩示例变量。
    int score = 86;
// 如果成绩很高，就输出优秀。
    if (score >= 90) cout << "优秀" << endl;
// 如果达到及格线，就输出及格。
    else if (score >= 60) cout << "及格" << endl;
// 否则提示继续努力。
    else cout << "继续努力" << endl;
// 程序正常结束。
    return 0;
// 主函数结束。
}
