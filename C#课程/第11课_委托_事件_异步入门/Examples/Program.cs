// 引入基础命名空间，后面要使用 Console 输出内容。
using System;
// 引入异步任务相关命名空间，Task 和 Task.Delay 都来自这里。
using System.Threading.Tasks;

// 等待异步方法执行完成，避免程序提前结束。
await DownloadAsync();

// 定义一个异步方法，用 Task 表示“未来会完成的操作”。
static async Task DownloadAsync()
{
    // 在异步等待前输出开始提示。
    Console.WriteLine("开始任务");
    // 模拟一个耗时 1 秒的异步操作，比如网络请求或文件读取。
    await Task.Delay(1000);
    // 等待结束后继续执行后面的代码。
    Console.WriteLine("任务完成");
}
