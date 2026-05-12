# 逐行代码讲解

## 本节关键
- `await` 前做了什么
- `await` 等待期间程序在干什么
- `await` 之后为什么还能接着往下走

| 行号 | 代码 | 说明 |
|---:|---|---|
| 6 | `await RunAsync();` | 主流程等待异步方法完成。 |
| 11 | `static async Task RunAsync()` | 声明一个异步方法。 |
| 16 | `await Task.Delay(1000);` | 模拟异步等待 1 秒。 |
| 18 | `Console.WriteLine(...)` | 等待完成后恢复执行。 |

## 调试建议
1. 在 `await RunAsync();` 处打断点。
2. 在 `await Task.Delay(1000);` 前后打断点。
3. 观察程序输出顺序。
