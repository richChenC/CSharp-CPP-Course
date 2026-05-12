// 引入基础命名空间。
using System;
// 引入 List 等泛型集合。
using System.Collections.Generic;
// 引入文件读写能力。
using System.IO;
// 引入 LINQ，方便查询和排序。
using System.Linq;
// 空行让引用区域和类型定义区域区分开。

// 定义学生数据模型，代表一条学生记录。
class Student
// 学生类开始。
{
// 学生编号，使用默认空字符串避免空引用。
    public string Id { get; set; } = string.Empty;
// 学生姓名。
    public string Name { get; set; } = string.Empty;
// 语文成绩。
    public int Chinese { get; set; }
// 数学成绩。
    public int Math { get; set; }
// 英语成绩。
    public int English { get; set; }
// 用计算属性自动计算总分。
    public int Total => Chinese + Math + English;
// 用计算属性自动计算平均分。
    public double Average => Total / 3.0;
// 学生类结束。
}
// 空行后开始定义主程序。

// 程序入口类。
class Program
// 程序类开始。
{
// 定义数据文件名，用于持久化保存。
    private const string DataFile = "students.csv";
// 程序主入口。
    static void Main()
// Main 方法体开始。
    {
// 启动时先把已有学生数据读入内存。
        var students = LoadStudents();
// 使用循环构建菜单系统。
        while (true)
// 菜单循环体开始。
        {
// 输出空行，让菜单更清楚。
            Console.WriteLine();
// 打印系统标题。
            Console.WriteLine("======== 学生成绩管理系统 ========");
// 菜单项 1：新增学生。
            Console.WriteLine("1. 添加学生");
// 菜单项 2：查看所有学生。
            Console.WriteLine("2. 显示全部学生");
// 菜单项 3：按关键字查询。
            Console.WriteLine("3. 查询学生");
// 菜单项 4：按成绩排序。
            Console.WriteLine("4. 按总分排序");
// 菜单项 5：删除指定学生。
            Console.WriteLine("5. 删除学生");
// 菜单项 6：保存后退出。
            Console.WriteLine("6. 保存并退出");
// 等待用户输入操作编号。
            Console.Write("请选择：");
// 读取用户输入的菜单选项。
            string? choice = Console.ReadLine();
// 判断是否执行新增学生功能。
            if (choice == "1")
// 新增学生分支开始。
            {
// 调用新增学生函数。
                AddStudent(students);
// 新增学生分支结束。
            }
// 判断是否执行显示全部学生功能。
            else if (choice == "2")
// 显示功能分支开始。
            {
// 调用显示函数。
                ShowStudents(students);
// 显示功能分支结束。
            }
// 判断是否执行查询功能。
            else if (choice == "3")
// 查询分支开始。
            {
// 调用查询函数。
                SearchStudents(students);
// 查询分支结束。
            }
// 判断是否执行排序功能。
            else if (choice == "4")
// 排序分支开始。
            {
// 调用排序函数。
                SortStudents(students);
// 排序分支结束。
            }
// 判断是否执行删除功能。
            else if (choice == "5")
// 删除分支开始。
            {
// 调用删除函数。
                DeleteStudent(students);
// 删除分支结束。
            }
// 判断是否退出系统。
            else if (choice == "6")
// 退出分支开始。
            {
// 退出前先保存数据。
                SaveStudents(students);
// 提示用户保存成功。
                Console.WriteLine("已保存，程序退出。");
// 跳出循环，结束程序。
                break;
// 退出分支结束。
            }
// 处理无效输入。
            else
// 错误分支开始。
            {
// 提醒用户输入错误。
                Console.WriteLine("输入无效，请重新选择。");
// 错误分支结束。
            }
// 菜单循环结束。
        }
// Main 方法结束。
    }
// 下面是各个功能函数。

// 新增学生功能。
    static void AddStudent(List<Student> students)
// 函数体开始。
    {
// 提示输入学号。
        Console.Write("请输入学号：");
// 读取学号。
        string id = Console.ReadLine() ?? string.Empty;
// 提示输入姓名。
        Console.Write("请输入姓名：");
// 读取姓名。
        string name = Console.ReadLine() ?? string.Empty;
// 调用成绩读取函数，保证用户输错时程序不会直接崩溃。
        int chinese = ReadScore("语文");
// 调用成绩读取函数，读取数学成绩。
        int math = ReadScore("数学");
// 调用成绩读取函数，读取英语成绩。
        int english = ReadScore("英语");
// 创建新学生对象并加入列表。
        students.Add(new Student { Id = id, Name = name, Chinese = chinese, Math = math, English = english });
// 提示添加完成。
        Console.WriteLine("添加成功。");
// 新增学生功能结束。
    }
// 下面开始显示、查询、排序和删除功能。

// 显示所有学生。
    static void ShowStudents(List<Student> students)
// 函数体开始。
    {
// 判断列表是否为空。
        if (students.Count == 0)
// 空列表分支开始。
        {
// 提示当前没有数据。
            Console.WriteLine("当前没有学生数据。");
// 直接返回，不继续执行。
            return;
// 空列表分支结束。
        }
// 打印表头。
        Console.WriteLine("学号	姓名	语文	数学	英语	总分	平均分");
// 遍历每个学生。
        foreach (var s in students)
// 遍历体开始。
        {
// 输出每个学生的完整成绩信息。
            Console.WriteLine($"{s.Id}	{s.Name}	{s.Chinese}	{s.Math}	{s.English}	{s.Total}	{s.Average:F2}");
// 遍历体结束。
        }
// 显示函数结束。
    }
// 按姓名或学号查询学生。
    static void SearchStudents(List<Student> students)
// 函数体开始。
    {
// 提示输入查询条件。
        Console.Write("请输入学号或姓名关键字：");
// 读取查询关键字。
        string keyword = Console.ReadLine() ?? string.Empty;
// 用 LINQ 找出匹配的学生。
        var result = students.Where(s => s.Id.Contains(keyword) || s.Name.Contains(keyword)).ToList();
// 如果没有找到匹配项。
        if (result.Count == 0)
// 无结果分支开始。
        {
// 提示没有结果。
            Console.WriteLine("没有找到匹配学生。");
// 结束查询。
            return;
// 无结果分支结束。
        }
// 直接复用显示函数输出结果。
        ShowStudents(result);
// 查询函数结束。
    }
// 按总分排序。
    static void SortStudents(List<Student> students)
// 函数体开始。
    {
// 按总分从高到低排序。
        var sorted = students.OrderByDescending(s => s.Total).ToList();
// 显示排序后的结果。
        ShowStudents(sorted);
// 排序函数结束。
    }
// 按学号删除学生。
    static void DeleteStudent(List<Student> students)
// 函数体开始。
    {
// 提示输入要删除的学号。
        Console.Write("请输入要删除的学号：");
// 读取学号。
        string id = Console.ReadLine() ?? string.Empty;
// 删除所有学号匹配的记录。
        int removed = students.RemoveAll(s => s.Id == id);
// 根据删除结果给出反馈。
        Console.WriteLine(removed > 0 ? "删除成功。" : "没有找到该学生。");
// 删除函数结束。
    }
// 读取单科成绩，并循环校验输入是否合法。
    static int ReadScore(string subject)
// 函数体开始。
    {
// 使用死循环不断要求用户输入，直到得到合法成绩。
        while (true)
// 循环体开始。
        {
// 输出当前科目的输入提示。
            Console.Write($"请输入{subject}成绩：");
// 读取用户输入。
            string? input = Console.ReadLine();
// 尝试把输入转换为整数，同时限制分数范围为 0 到 100。
            if (int.TryParse(input, out int score) && score >= 0 && score <= 100)
// 合法分支开始。
            {
// 返回合法成绩。
                return score;
// 合法分支结束。
            }
// 提醒用户重新输入。
            Console.WriteLine("成绩必须是 0 到 100 之间的整数，请重新输入。");
// 循环体结束。
        }
// 函数体结束。
    }
// 保存数据到文件。
    static void SaveStudents(List<Student> students)
// 函数体开始。
    {
// 把每个学生转成 CSV 文本。
        var lines = students.Select(s => $"{s.Id},{s.Name},{s.Chinese},{s.Math},{s.English}");
// 把所有文本行写入文件。
        File.WriteAllLines(DataFile, lines);
// 保存函数结束。
    }
// 从文件加载学生数据。
    static List<Student> LoadStudents()
// 函数体开始。
    {
// 先准备一个空列表。
        var students = new List<Student>();
// 如果文件不存在就直接返回空列表。
        if (!File.Exists(DataFile))
// 不存在分支开始。
        {
// 文件不存在时返回空集合。
            return students;
// 不存在分支结束。
        }
// 逐行读取文件。
        foreach (var line in File.ReadAllLines(DataFile))
// 读取体开始。
        {
// 按逗号分割每行数据。
            var parts = line.Split(",");
// 判断数据格式是否正确。
            if (parts.Length == 5)
// 合法分支开始。
            {
// 创建学生对象并加入列表。
                students.Add(new Student
// 对象初始化开始。
                {
// 读入学号。
                    Id = parts[0],
// 读入姓名。
                    Name = parts[1],
// 读入语文成绩。
                    Chinese = int.TryParse(parts[2], out int chinese) ? chinese : 0,
// 读入数学成绩。
                    Math = int.TryParse(parts[3], out int math) ? math : 0,
// 读入英语成绩。
                    English = int.TryParse(parts[4], out int english) ? english : 0
// 对象初始化结束。
                });
// 合法分支结束。
            }
// 读取体结束。
        }
// 返回加载好的学生列表。
        return students;
// 加载函数结束。
    }
// 程序类结束。
}