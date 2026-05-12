param(
    [switch]$SkipInstall
)

$ErrorActionPreference = 'Stop'
$ProgressPreference = 'SilentlyContinue'

$CourseRoot = Split-Path -Parent $MyInvocation.MyCommand.Path
$WorkspaceRoot = Split-Path -Parent $CourseRoot
$Tools = Join-Path $WorkspaceRoot '.tools'
$DotnetDir = Join-Path $Tools 'dotnet'
$DotnetExe = Join-Path $DotnetDir 'dotnet.exe'
$W64Exe = Join-Path $Tools 'w64devkit-x64-2.5.0.7z.exe'
$SevenZipExe = Join-Path $Tools '7zr.exe'
$GppExe = ''
$Report = Join-Path $CourseRoot '真实编译测试报告.md'
$TempRoot = Join-Path $WorkspaceRoot '.course_build_verify'
$DotnetHome = Join-Path $Tools '.dotnet-home'

New-Item -ItemType Directory -Force -Path $Tools | Out-Null
New-Item -ItemType Directory -Force -Path $TempRoot | Out-Null
New-Item -ItemType Directory -Force -Path $DotnetHome | Out-Null

$env:DOTNET_CLI_HOME = $DotnetHome
$env:DOTNET_SKIP_FIRST_TIME_EXPERIENCE = '1'
$env:DOTNET_CLI_TELEMETRY_OPTOUT = '1'

if (-not $SkipInstall) {
    if (-not (Test-Path $DotnetExe)) {
        Write-Host 'Downloading .NET SDK install script...'
        $InstallScript = Join-Path $Tools 'dotnet-install.ps1'
        Invoke-WebRequest -Uri 'https://dot.net/v1/dotnet-install.ps1' -OutFile $InstallScript
        Write-Host 'Installing .NET SDK locally...'
        & $InstallScript -Channel 9.0 -InstallDir $DotnetDir -NoPath
    }

    $Candidate = Get-ChildItem -Path $Tools -Recurse -Filter g++.exe -ErrorAction SilentlyContinue | Select-Object -First 1
    if (-not $Candidate) {
        Write-Host 'Downloading portable C++ compiler w64devkit...'
        $GitHubHeaders = @{
            'User-Agent' = 'CodexCourseSetup/1.0'
            'Accept' = 'application/vnd.github+json'
        }
        $Release = Invoke-RestMethod -Headers $GitHubHeaders -Uri 'https://api.github.com/repos/skeeto/w64devkit/releases/latest'
        $Asset = $Release.assets | Where-Object { $_.name -match '^w64devkit-x64.*\.exe$' } | Select-Object -First 1
        if (-not $Asset) {
            throw 'Cannot find a w64devkit x64 release asset from GitHub API.'
        }
        $W64Exe = Join-Path $Tools $Asset.name
        Invoke-WebRequest -Headers $GitHubHeaders -Uri $Asset.browser_download_url -OutFile $W64Exe
        if (-not (Test-Path $W64Exe)) {
            throw "Downloaded compiler archive was not found: $W64Exe"
        }
        Write-Host 'Extracting portable C++ compiler...'
        if (-not (Test-Path $SevenZipExe)) {
            Invoke-WebRequest -Uri 'https://www.7-zip.org/a/7zr.exe' -OutFile $SevenZipExe
        }
        & $SevenZipExe x $W64Exe "-o$Tools" -y | Out-Null
    }
}

if (-not (Test-Path $DotnetExe)) { throw "dotnet SDK not found: $DotnetExe" }
$Candidate = Get-ChildItem -Path $Tools -Recurse -Filter g++.exe -ErrorAction SilentlyContinue | Select-Object -First 1
if ($Candidate) { $GppExe = $Candidate.FullName }
if ($GppExe) {
    $GppBin = Split-Path -Parent $GppExe
    $env:Path = "$GppBin;$env:Path"
}

$results = New-Object System.Collections.Generic.List[object]

$csFiles = Get-ChildItem -Path (Join-Path $CourseRoot 'C#课程') -Recurse -Filter Program.cs
foreach ($file in $csFiles) {
    $name = 'cs_' + ([Guid]::NewGuid().ToString('N'))
    $proj = Join-Path $TempRoot $name
    New-Item -ItemType Directory -Force -Path $proj | Out-Null
    & $DotnetExe new console -o $proj --force | Out-Null
    Copy-Item -LiteralPath $file.FullName -Destination (Join-Path $proj 'Program.cs') -Force
    $build = & $DotnetExe build $proj --nologo 2>&1
    $ok = $LASTEXITCODE -eq 0
    $results.Add([pscustomobject]@{ Language="C#"; File=$file.FullName; OK=$ok; Output=($build -join "`n") })
}

if ($GppExe -and (Test-Path $GppExe)) {
    $cppFiles = Get-ChildItem -Path (Join-Path $CourseRoot 'C++课程') -Recurse -Filter main.cpp
    foreach ($file in $cppFiles) {
        $exe = Join-Path $TempRoot (([Guid]::NewGuid().ToString('N')) + '.exe')
        $build = & $GppExe -std=c++17 -Wall -Wextra -pedantic -o $exe $file.FullName 2>&1
        $ok = $LASTEXITCODE -eq 0
        $results.Add([pscustomobject]@{ Language="C++"; File=$file.FullName; OK=$ok; Output=($build -join "`n") })
    }
} else {
    $results.Add([pscustomobject]@{ Language="C++"; File='C++课程'; OK=$false; Output='g++.exe not found. C++ compiler was not installed, so C++ examples were not compiled.' })
}

$passed = ($results | Where-Object { $_.OK }).Count
$total = $results.Count
$failed = $results | Where-Object { -not $_.OK }

$lines = @()
$lines += '# 真实编译测试报告'
$lines += ''
$lines += ('- 测试时间：' + (Get-Date -Format 'yyyy-MM-dd HH:mm:ss'))
$lines += ('- .NET SDK：' + $DotnetExe)
$lines += ('- C++ 编译器：' + $GppExe)
$lines += ('- 通过：' + $passed + ' / ' + $total)
$lines += ''
$lines += '## 失败项'
if ($failed.Count -eq 0) {
    $lines += '无。'
} else {
    foreach ($f in $failed) {
        $lines += ('### ' + $f.Language)
        $lines += ('文件：' + $f.File)
        $lines += '```text'
        $lines += $f.Output
        $lines += '```'
    }
}
$lines += ''
$lines += '## 全部结果'
foreach ($r in $results) {
    $status = if ($r.OK) { 'PASS' } else { 'FAIL' }
    $lines += ('- [' + $status + '] ' + $r.Language + ' - ' + $r.File)
}

$lines | Set-Content -Encoding UTF8 $Report
Write-Host ("测试完成：" + $passed + " / " + $total + " 通过")
Write-Host ("报告：" + $Report)
