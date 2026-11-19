# dsh.ps1 - send one task to DeepSeek Harness (headless profile) from VS Code.
#
#   .\.vscode\dsh.ps1 -Ask "explain this file" -File "C:\path\to\a.c"
#   .\.vscode\dsh.ps1 -Ask "list the files in this repo"
#
# The answer is printed to the terminal, then the script exits.
# Needs DEEPSEEK_API_KEY (user environment variable):
#   setx DEEPSEEK_API_KEY "sk-..."
# A key created on the DeepSeek platform is not the same as signing in to
# the desktop app: the desktop login is not visible to the command line.
param(
    [Parameter(Mandatory = $true)][string]$Ask,
    [string]$File,
    [string]$Mode = 'workspace-write'
)

$ErrorActionPreference = 'Continue'

$dsh = 'F:\deepseek\resources\runtime\cli\bin\dsh.cmd'
if (-not (Test-Path $dsh)) {
    Write-Host "ERROR: dsh.cmd not found at $dsh"
    exit 3
}

if (-not $env:DEEPSEEK_API_KEY) {
    $key = [Environment]::GetEnvironmentVariable('DEEPSEEK_API_KEY', 'User')
    if ($key) { $env:DEEPSEEK_API_KEY = $key }
}
if (-not $env:DEEPSEEK_API_KEY) {
    Write-Host "DEEPSEEK_API_KEY is not set - the command line cannot reach the model yet."
    Write-Host ""
    Write-Host "1. open https://platform.deepseek.com/api_keys and create a key"
    Write-Host "2. in a PowerShell window run:  setx DEEPSEEK_API_KEY ""sk-..."""
    Write-Host "3. run this task again"
    Write-Host ""
    Write-Host "The desktop app login does not count: the CLI reads the environment."
    exit 3
}

try { [Console]::OutputEncoding = [Text.Encoding]::UTF8 } catch { }

$prompt = $Ask
if ($File) { $prompt = "$Ask  (the open file is $File)" }

Write-Host ">>> dsh headless  (permission: $Mode)"
Write-Host ">>> task: $Ask"
Write-Host ""

& $dsh --profile headless --permission-mode $Mode $prompt
$code = $LASTEXITCODE

Write-Host ""
if ($code -eq 0) {
    Write-Host "Done. Exit code: 0"
} else {
    Write-Host "Failed. Exit code: $code"
}
exit $code
