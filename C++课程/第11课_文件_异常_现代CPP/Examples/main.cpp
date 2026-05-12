// 包含输入输出功能。
#include "../../common/Utf8Console.h" // IWYU pragma: keep

#include <iostream>
// 引入文件流，支持文件读写。
#include <fstream>
// 引入智能指针相关头文件。
#include <memory>
// 简化标准库访问。
using namespace std;
// 空行把头文件和主体分隔。

// 程序入口。
int main() {
// 创建一个输出文件流，用来写文件。
    ofstream out("note.txt");
// 把文本写入文件。
    out << "C++ 文件写入示例" << endl;
// 关闭文件流，确保内容落盘。
    out.close();
// 空行分隔写入和读取。

// 创建一个输入文件流，用来读文件。
    ifstream in("note.txt");
// 定义字符串变量保存一行文本。
    string line;
// 读取文件中的第一行。
    getline(in, line);
// 把读取到的内容输出到控制台。
    cout << line << endl;
// 正常退出。
    return 0;
// 主函数结束。
}
