// 引入排序算法，后面按姓名排序会用到 sort。
#include <algorithm>
// 引入文件流，后面保存和读取通讯录数据会用到。
#include <fstream>
// 引入输入输出流，后面使用 cout 和 getline。
#include "../../common/Utf8Console.h" // IWYU pragma: keep

#include <iostream>
// 引入字符串类型，联系人姓名、电话、邮箱都用 string 保存。
#include <string>
// 引入动态数组 vector，用来保存多条联系人记录。
#include <vector>
// 使用标准命名空间，减少 std:: 前缀，让入门代码更清爽。
using namespace std;

// 定义联系人结构体，一条 Contact 就是一条通讯录数据。
struct Contact {
    // 保存联系人姓名。
    string name;
    // 保存联系人电话。
    string phone;
    // 保存联系人邮箱。
    string email;
};

// 定义数据文件名，集中管理，后续想改文件名只改这一处。
const string DATA_FILE = "contacts.csv";

// 显示主菜单，负责把用户可以选择的功能打印出来。
void ShowMenu() {
    // 打印系统标题。
    cout << "\n======== 通讯录管理系统 ========\n";
    // 打印新增联系人菜单项。
    cout << "1. 添加联系人\n";
    // 打印显示全部联系人菜单项。
    cout << "2. 显示全部联系人\n";
    // 打印查询联系人菜单项。
    cout << "3. 查询联系人\n";
    // 打印按姓名排序菜单项。
    cout << "4. 按姓名排序\n";
    // 打印删除联系人菜单项。
    cout << "5. 删除联系人\n";
    // 打印保存并退出菜单项。
    cout << "6. 保存并退出\n";
    // 提示用户输入选择。
    cout << "请选择：";
}

// 添加联系人，使用引用传参是为了直接修改原来的 vector。
void AddContact(vector<Contact>& contacts) {
    // 创建一个临时联系人对象，用来接收本次输入。
    Contact c;
    // 提示用户输入姓名。
    cout << "请输入姓名：";
    // 读取一整行姓名，支持中文和空格。
    getline(cin, c.name);
    // 提示用户输入电话。
    cout << "请输入电话：";
    // 读取电话字符串。
    getline(cin, c.phone);
    // 提示用户输入邮箱。
    cout << "请输入邮箱：";
    // 读取邮箱字符串。
    getline(cin, c.email);
    // 把联系人追加到通讯录列表末尾。
    contacts.push_back(c);
    // 给用户一个操作成功反馈。
    cout << "添加成功。\n";
}

// 显示一个联系人，单独封装可以避免重复写输出格式。
void PrintContact(const Contact& c, int index) {
    // 输出序号，方便用户知道这是第几条。
    cout << index << ". ";
    // 输出姓名。
    cout << "姓名：" << c.name << " | ";
    // 输出电话。
    cout << "电话：" << c.phone << " | ";
    // 输出邮箱并换行。
    cout << "邮箱：" << c.email << "\n";
}

// 显示全部联系人，使用 const 引用表示只读，不修改列表。
void ShowContacts(const vector<Contact>& contacts) {
    // 如果列表为空，就直接提示并返回。
    if (contacts.empty()) {
        // 打印空数据提示。
        cout << "当前没有联系人。\n";
        // 返回调用处，避免继续执行下面的遍历。
        return;
    }
    // 使用普通 for 循环，方便输出从 1 开始的序号。
    for (size_t i = 0; i < contacts.size(); ++i) {
        // 打印当前联系人。
        PrintContact(contacts[i], static_cast<int>(i + 1));
    }
}

// 查询联系人，支持按姓名、电话、邮箱关键字搜索。
void SearchContacts(const vector<Contact>& contacts) {
    // 提示用户输入搜索关键字。
    cout << "请输入查询关键字：";
    // 定义关键字变量。
    string keyword;
    // 读取用户输入的关键字。
    getline(cin, keyword);
    // 记录是否找到至少一个结果。
    bool found = false;
    // 遍历所有联系人。
    for (size_t i = 0; i < contacts.size(); ++i) {
        // 取出当前联系人，减少重复写 contacts[i]。
        const Contact& c = contacts[i];
        // 判断姓名、电话或邮箱里是否包含关键字。
        if (c.name.find(keyword) != string::npos || c.phone.find(keyword) != string::npos || c.email.find(keyword) != string::npos) {
            // 打印匹配到的联系人。
            PrintContact(c, static_cast<int>(i + 1));
            // 标记已经找到结果。
            found = true;
        }
    }
    // 如果没有找到任何结果。
    if (!found) {
        // 给出无结果提示。
        cout << "没有找到匹配联系人。\n";
    }
}

// 按姓名排序联系人，使用引用传参是为了让排序结果保存在原列表里。
void SortContacts(vector<Contact>& contacts) {
    // 调用标准库 sort，并用 lambda 指定排序规则。
    sort(contacts.begin(), contacts.end(), [](const Contact& a, const Contact& b) {
        // 按姓名字典序从小到大排序。
        return a.name < b.name;
    });
    // 提示排序完成。
    cout << "排序完成。\n";
}

// 删除联系人，按电话精确匹配删除，电话通常更适合作唯一标识。
void DeleteContact(vector<Contact>& contacts) {
    // 提示用户输入要删除的电话。
    cout << "请输入要删除的联系人电话：";
    // 定义电话变量。
    string phone;
    // 读取用户输入的电话。
    getline(cin, phone);
    // 使用 remove_if 把要删除的联系人移动到末尾。
    auto newEnd = remove_if(contacts.begin(), contacts.end(), [&](const Contact& c) {
        // 如果电话相等，就认为这条记录应该删除。
        return c.phone == phone;
    });
    // 判断是否真的找到了可删除的数据。
    if (newEnd == contacts.end()) {
        // 没有找到时提示用户。
        cout << "没有找到该电话对应的联系人。\n";
        // 直接返回，不做 erase。
        return;
    }
    // 真正删除 remove_if 移到末尾的元素。
    contacts.erase(newEnd, contacts.end());
    // 提示删除成功。
    cout << "删除成功。\n";
}

// 保存联系人到 CSV 文件，实现简单的数据持久化。
void SaveContacts(const vector<Contact>& contacts) {
    // 打开输出文件流，默认会覆盖旧文件。
    ofstream out(DATA_FILE);
    // 遍历所有联系人。
    for (const Contact& c : contacts) {
        // 按 name,phone,email 的格式写入一行。
        out << c.name << "," << c.phone << "," << c.email << "\n";
    }
}

// 从 CSV 文件加载联系人，程序启动时调用。
vector<Contact> LoadContacts() {
    // 创建空列表，用来保存读到的数据。
    vector<Contact> contacts;
    // 打开输入文件流。
    ifstream in(DATA_FILE);
    // 如果文件不存在或打不开，就返回空列表。
    if (!in.is_open()) {
        // 返回空通讯录。
        return contacts;
    }
    // 定义一行文本变量。
    string line;
    // 逐行读取文件内容。
    while (getline(in, line)) {
        // 找到第一个逗号位置。
        size_t first = line.find(',');
        // 找到第二个逗号位置。
        size_t second = line.find(',', first + 1);
        // 如果两个逗号都存在，说明格式基本正确。
        if (first != string::npos && second != string::npos) {
            // 创建联系人对象。
            Contact c;
            // 截取姓名字段。
            c.name = line.substr(0, first);
            // 截取电话字段。
            c.phone = line.substr(first + 1, second - first - 1);
            // 截取邮箱字段。
            c.email = line.substr(second + 1);
            // 把联系人加入列表。
            contacts.push_back(c);
        }
    }
    // 返回加载完成的联系人列表。
    return contacts;
}

// 程序入口函数。
int main() {
    // 启动程序时先从文件加载已有联系人。
    vector<Contact> contacts = LoadContacts();
    // 使用死循环持续显示菜单，直到用户选择退出。
    while (true) {
        // 打印主菜单。
        ShowMenu();
        // 定义用户选择变量。
        string choice;
        // 读取用户选择。
        getline(cin, choice);
        // 如果选择 1，就添加联系人。
        if (choice == "1") {
            // 调用添加函数。
            AddContact(contacts);
        // 如果选择 2，就显示全部联系人。
        } else if (choice == "2") {
            // 调用显示函数。
            ShowContacts(contacts);
        // 如果选择 3，就查询联系人。
        } else if (choice == "3") {
            // 调用查询函数。
            SearchContacts(contacts);
        // 如果选择 4，就排序联系人。
        } else if (choice == "4") {
            // 调用排序函数。
            SortContacts(contacts);
        // 如果选择 5，就删除联系人。
        } else if (choice == "5") {
            // 调用删除函数。
            DeleteContact(contacts);
        // 如果选择 6，就保存并退出。
        } else if (choice == "6") {
            // 保存当前联系人列表。
            SaveContacts(contacts);
            // 打印退出提示。
            cout << "已保存，程序退出。\n";
            // 跳出循环。
            break;
        // 其他输入都认为无效。
        } else {
            // 提醒用户重新输入。
            cout << "输入无效，请重新选择。\n";
        }
    }
    // 返回 0 表示程序正常结束。
    return 0;
}
