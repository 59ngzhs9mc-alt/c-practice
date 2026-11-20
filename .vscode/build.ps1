param(
    [string]$Source,
    [string]$Project,
    [switch]$Run
)

# Build helper for this repo: compiles one file (-Source) or a whole folder (-Project)
# with MinGW-w64 gcc/g++ into <dir>\build\<name>.exe, then optionally runs it.
# Kept ASCII-only on purpose: PowerShell 5.1 reads BOM-less UTF-8 as ANSI and would
# garble any Chinese text here.

$ErrorActionPreference = 'Stop'
$Gcc = 'E:\mingw64\bin\gcc.exe'
$Gpp = 'E:\mingw64\bin\g++.exe'

if ($Project) {
    $dir   = (Resolve-Path $Project).Path
    $files = @(Get-ChildItem -Path $dir -File | Where-Object { $_.Extension -in '.c', '.cpp' })
    if ($files.Count -eq 0) { Write-Host "No .c/.cpp files in: $dir" -ForegroundColor Red; exit 1 }
    $name = Split-Path $dir -Leaf
}
elseif ($Source) {
    $file = Get-Item (Resolve-Path $Source).Path
    $dir  = $file.DirectoryName
    # Compile the whole folder when the current file lives next to other sources
    # (Project1: game.c + text.cpp must be linked together). A lone file builds alone.
    $files = @(Get-ChildItem -Path $dir -File | Where-Object { $_.Extension -in '.c', '.cpp' })
    if ($files.Count -eq 0) { $files = @($file) }
    $multi = $files.Count -gt 1
    $name  = if ($multi) { Split-Path $dir -Leaf } else { $file.BaseName }
}
else {
    Write-Host 'Usage: build.ps1 -Source <file> | -Project <dir> [-Run]' -ForegroundColor Red
    exit 1
}

$buildDir = Join-Path $dir 'build'
$objDir   = Join-Path $buildDir 'obj'
New-Item -ItemType Directory -Force -Path $objDir | Out-Null
$exe = Join-Path $buildDir "$name.exe"

$defs = @('-D_CRT_SECURE_NO_WARNINGS', '-D__USE_MINGW_ANSI_STDIO=1')
$warn = @('-Wall', '-Wextra', '-Wno-unused-parameter', '-Wno-unused-variable')
$std  = @('-g', '-O0', '-finput-charset=UTF-8', '-fexec-charset=GBK')
# -finput-charset: the .c files are UTF-8 (with BOM), so gcc reads them as UTF-8.
# -fexec-charset : Windows console here is code page 936 (GBK); without this the
#                  Chinese printf() output shows as garbage.

# From here on we check $LASTEXITCODE ourselves: letting native stderr turn into a
# terminating error would hide the friendly "no main()" hint below.
$ErrorActionPreference = 'Continue'

Write-Host ''
Write-Host "Sources: $($files.Name -join ', ')" -ForegroundColor Cyan
Write-Host "Output : $exe" -ForegroundColor Cyan
if ($multi) { Write-Host 'Note   : several sources in this folder - they are linked as ONE program' -ForegroundColor DarkGray }
Write-Host ''

$objects  = @()
$hadError = $false

foreach ($f in $files) {
    $isCpp = $f.Extension -eq '.cpp'
    $cc    = if ($isCpp) { $Gpp } else { $Gcc }
    $obj   = Join-Path $objDir ($f.BaseName + '.o')
    $tag   = if ($isCpp) { 'C++' } else { 'C' }

    Write-Host (">>> [{0}] {1}" -f $tag, $f.Name) -ForegroundColor Yellow
    $argList = @($std + $warn + $defs + @('-c', $f.FullName, '-o', $obj))
    & $cc @argList 2>&1 | ForEach-Object { Write-Host "    $_" }
    if ($LASTEXITCODE -ne 0) { $hadError = $true } else { $objects += $obj }
}

if ($hadError) {
    Write-Host ''
    Write-Host 'Compile failed. See errors above.' -ForegroundColor Red
    exit 1
}

$linker = if ($files | Where-Object { $_.Extension -eq '.cpp' }) { $Gpp } else { $Gcc }
Write-Host ''
Write-Host '>>> linking' -ForegroundColor Yellow
& $linker @($objects + @('-o', $exe)) 2>&1 | ForEach-Object { Write-Host "    $_" }

if ($LASTEXITCODE -ne 0) {
    Write-Host ''
    Write-Host 'No main() found - the file is probably fully commented out.' -ForegroundColor Yellow
    Write-Host 'Compile (syntax check) passed, so keep editing; nothing to run yet.' -ForegroundColor Yellow
    exit 2
}

Write-Host ''
Write-Host "Build OK -> $exe" -ForegroundColor Green

# Stable alias so F5 (launch.json) works for single files and multi-file folders alike.
$alias = Join-Path $buildDir 'run.exe'
Copy-Item -Force $exe $alias
Write-Host "F5 alias -> $alias" -ForegroundColor DarkGray

if ($Run) {
    Write-Host ''
    Write-Host ('-' * 60) -ForegroundColor DarkGray
    # Match the console code page with -fexec-charset=GBK above, so Chinese
    # output shows normally both here and in the separate debug console.
    try { [Console]::OutputEncoding = [Text.Encoding]::GetEncoding(936) } catch { }
    & $exe
    Write-Host ('-' * 60) -ForegroundColor DarkGray
    Write-Host "Exit code: $LASTEXITCODE" -ForegroundColor DarkGray
}
