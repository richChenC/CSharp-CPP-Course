// 引入任务相关命名空间。
using System;
using System.Threading.Tasks;

// 输出主流程开始。
Console.WriteLine("主流程开始。");
// 调用异步方法并等待其完成。
await RunAsync();
// 异步方法结束后继续执行这里。
Console.WriteLine("主流程结束。");

// 定义异步方法，演示 await 的执行过程。
static async Task RunAsync()
{
    // 输出异步任务开始。
    Console.WriteLine("异步任务开始。");
    // 模拟异步等待 1 秒。
    await Task.Delay(1000);
    // 等待完成后恢复执行。
    Console.WriteLine("异步等待结束，恢复执行。");
}
