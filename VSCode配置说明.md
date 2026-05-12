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
