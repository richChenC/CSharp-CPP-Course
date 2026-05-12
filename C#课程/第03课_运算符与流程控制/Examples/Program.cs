// 引入基础命名空间。
using System;
// 空行把变量准备和判断逻辑隔开。

// 定义一个成绩变量，后面用它来演示分支判断。
int score = 86;
// 判断是否达到优秀标准。
if (score >= 90)
// 如果条件成立，输出“优秀”。
    Console.WriteLine("优秀");
// 如果没有达到优秀，再判断是否及格。
else if (score >= 60)
// 及格分支的输出。
    Console.WriteLine("及格");
// 以上都不满足时进入兜底分支。
else
// 输出提醒信息，形成完整的分数判断逻辑。
    Console.WriteLine("需要继续努力");