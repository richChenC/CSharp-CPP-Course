# 逐行代码讲解

这节课要盯住三个重点：`auto`、范围 `for`、Lambda。

| 行号 | 代码 | 说明 |
|---:|---|---|
| 1 | `#include "../../common/Utf8Console.h"` | 引入 UTF-8 控制台支持，保证中文输出正常。 |
| 4 | `#include <algorithm>` | 引入排序等标准算法。 |
| 6 | `#include <iostream>` | 引入输入输出能力。 |
| 8 | `#include <vector>` | 引入动态数组 `vector`。 |
| 11 | `using namespace std;` | 让后面可以直接写 `cout`、`vector`、`sort`。 |
| 14 | `vector<int> numbers{42, 7, 19, 88, 13, 35};` | 定义一个整数容器。 |
| 18 | `for (const auto& value : numbers)` | 使用范围 `for` 遍历容器，`auto` 自动推导元素类型。 |
| 27 | `sort(...)` | 调用标准库排序函数。 |
| 27 | `[](int left, int right)` | 这里的 Lambda 就是临时定义的比较函数。 |
| 29 | `return left > right;` | 比较规则是“大的排前面”。 |

## 调试建议
1. 在 `sort` 前打断点。
2. 观察 `numbers` 原始内容。
3. 在 Lambda 内打断点，看每次比较的两个值。
4. 看排序结束后容器顺序是否符合预期。
