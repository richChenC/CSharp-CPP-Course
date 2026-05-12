# 逐行代码讲解

## 本节关键
- 泛型方法如何适配不同类型
- 委托变量如何指向方法
- 反射如何查看运行时类型信息

| 行号 | 代码 | 说明 |
|---:|---|---|
| 4 | `static void PrintValue<T>(T value)` | 这是一个泛型方法，`T` 代表任意类型。 |
| 7 | `typeof(T).Name` | 获取泛型类型的名称。 |
| 11 | `static int Add(int left, int right)` | 普通方法，后面交给委托调用。 |
| 21 | `Func<int, int, int> calculator = Add;` | 委托变量保存了一个方法引用。 |
| 27 | `Type type = typeof(string);` | 获取 `string` 类型信息。 |
| 29 | `var methods = type.GetMethods();` | 使用反射获取方法列表。 |

## 调试建议
1. 在 `calculator = Add` 处打断点。
2. 在 `GetMethods()` 之后看 `methods.Length`。
3. 用监视窗口看 `type.Name`。
