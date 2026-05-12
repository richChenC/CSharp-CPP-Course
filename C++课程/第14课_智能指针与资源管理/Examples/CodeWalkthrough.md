# 逐行代码讲解

## 本节最重要的观察点
- `make_unique` 创建了谁
- `task->Print()` 是如何访问对象的
- 为什么程序结束时没有手动 `delete`

| 行号 | 代码 | 说明 |
|---:|---|---|
| 1 | `#include "../../common/Utf8Console.h"` | 保证中文输出不乱码。 |
| 5 | `#include <memory>` | `unique_ptr` 和 `make_unique` 都在这里。 |
| 14 | `class Task` | 定义一个简单类来观察生命周期。 |
| 17 | `Task(string title)` | 构造函数，在对象创建时执行。 |
| 23 | `~Task()` | 析构函数，在对象销毁时执行。 |
| 39 | `auto task = make_unique<Task>(...)` | 创建一个智能指针，自动接管对象生命周期。 |
| 42 | `task->Print();` | 通过箭头访问对象成员函数。 |

## 调试建议
1. 在构造函数里打断点。
2. 在析构函数里打断点。
3. 单步到 `return 0;`，观察对象什么时候释放。
