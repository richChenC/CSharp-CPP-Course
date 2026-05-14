# VS Code 环境说明

如果 VS Code 右下角提示“找不到所需的 .NET SDK”或“未能还原 NuGet 包”，通常是因为 VS Code 没有继承当前课程的本地 .NET SDK 环境。

## 推荐打开方式

在 PowerShell 中运行：

```powershell
Set-ExecutionPolicy -Scope Process -ExecutionPolicy Bypass
.\用本地环境打开VSCode.ps1
```

这个脚本会把以下环境变量临时设置到当前进程：

- DOTNET_ROOT：指向课程工作区里的 .tools\dotnet
- DOTNET_CLI_HOME：指向 .tools\.dotnet-home
- PATH：加入 .tools\dotnet 和 .tools\w64devkit\bin

## C# 项目说明

每个 C# 示例目录的 Examples 下都已经补充了 .csproj 文件，可以被 C# Dev Kit / dotnet restore / dotnet build 正常识别。

## 如果仍提示 NuGet

先在终端运行：

```powershell
..\.tools\dotnet\dotnet.exe restore
```

或者直接运行课程根目录的：

```powershell
.\安装环境并测试课程.ps1 -SkipInstall
```
## 当前推荐运行方式

本课程已经配置好本地工具链：

- C++ 编译器：`C:\Users\Administrator\Documents\Codex\2026-05-08\c-c-c\.tools\w64devkit\bin\g++.exe`
- C++ 调试器：`C:\Users\Administrator\Documents\Codex\2026-05-08\c-c-c\.tools\w64devkit\bin\gdb.exe`
- .NET SDK：`C:\Users\Administrator\Documents\Codex\2026-05-08\c-c-c\.tools\dotnet\dotnet.exe`

### C++ 正确调试方式

打开任意 `main.cpp` 后：

1. 按 `F5`
2. 选择 `Debug Current C++ File`

不要选择 `C/C++ Runner: Debug Session`。这个配置由第三方扩展自动生成，中文路径下容易生成乱码路径。

### C++ 正确编译方式

打开任意 `main.cpp` 后：

1. 按 `Ctrl+Shift+B`
2. 选择 `Build Current C++ File For Debug`

### 如果弹出 Compiler executable not found

这是第三方 `C/C++ Compile Run` 扩展的提示。项目已经在三层 `.vscode/settings.json` 中配置好了编译器路径。

如果仍然弹出，点击 `Change compiler path`，填写：

```text
C:\Users\Administrator\Documents\Codex\2026-05-08\c-c-c\.tools\w64devkit\bin\g++.exe
```

### 建议保留的扩展

- `C/C++`（Microsoft 官方）
- `C# Dev Kit`
- `C#`

### 不建议用于调试的扩展

- `C/C++ Runner`
- `C/C++ Compile Run`

这两个扩展可以用于简单运行，但不要使用它们生成的 `Debug Session`。
