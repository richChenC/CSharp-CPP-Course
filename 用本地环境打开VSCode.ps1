$Root = Split-Path -Parent $MyInvocation.MyCommand.Path
$env:DOTNET_ROOT = Join-Path $Root '.tools\dotnet'
$env:DOTNET_CLI_HOME = Join-Path $Root '.tools\.dotnet-home'
$env:DOTNET_SKIP_FIRST_TIME_EXPERIENCE = '1'
$env:DOTNET_CLI_TELEMETRY_OPTOUT = '1'
$env:APPDATA = Join-Path $Root '.tools\appdata'
$env:NUGET_PACKAGES = Join-Path $Root '.tools\nuget-packages'
$env:Path = "$env:DOTNET_ROOT;$(Join-Path $Root '.tools\w64devkit\bin');$env:Path"

Write-Host "DOTNET_ROOT=$env:DOTNET_ROOT"
Write-Host "C++ compiler=$(Join-Path $Root '.tools\w64devkit\bin\g++.exe')"
Write-Host "Opening VS Code with local course environment..."

code $Root
