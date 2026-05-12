# 逐行代码讲解

## 本节关键
- `student` 到底是不是一个真实对象
- 空引用异常一般发生在“访问成员”这一步

| 行号 | 代码 | 说明 |
|---:|---|---|
| 10 | `Student? student = null;` | 这里明确把变量设成了空。 |
| 15 | `Console.WriteLine(student.Name);` | 访问空对象的属性会抛出异常。 |
| 17 | `catch (NullReferenceException ex)` | 捕获空引用异常。 |

## 调试建议
1. 在 `student = null;` 后打断点。
2. 观察 `student` 当前值。
3. 单步执行到访问属性那一行，看异常何时触发。
