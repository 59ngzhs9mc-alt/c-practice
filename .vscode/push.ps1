param(
    [string]$Repo = '.',
    [string]$Message,
    [switch]$PushOnly
)

# Commit everything in the repo and push to BOTH remotes (origin = Gitee, github = GitHub).
# Usage from a VS Code task: push.ps1 -Repo <workspace> -Message "<text>" | -PushOnly
# ASCII-only on purpose: PowerShell 5.1 reads BOM-less UTF-8 as ANSI.

$ErrorActionPreference = 'Stop'
try { [Console]::OutputEncoding = [Text.Encoding]::UTF8 } catch { }

$repoPath = (Resolve-Path $Repo).Path
Set-Location $repoPath

$branch = (git rev-parse --abbrev-ref HEAD).Trim()
if (-not $branch) { Write-Host 'Not a git repository.' -ForegroundColor Red; exit 1 }

# Native git writes progress/warnings to stderr; with 'Stop' that would abort the
# script mid-push. Keep 'Continue' and judge by $LASTEXITCODE instead.
$ErrorActionPreference = 'Continue'

$changes = @(git status --porcelain)
Write-Host ''
Write-Host "Repo   : $repoPath" -ForegroundColor Cyan
Write-Host "Branch : $branch" -ForegroundColor Cyan

if ($PushOnly) {
    if ($changes.Count -gt 0) {
        Write-Host ''
        Write-Host 'Note: you have uncommitted changes. They are NOT included (push-only mode).' -ForegroundColor Yellow
    }
}
elseif ($changes.Count -eq 0) {
    Write-Host ''
    Write-Host 'Nothing to commit (working tree clean). Will only push if the branch is ahead.' -ForegroundColor DarkGray
}
else {
    if (-not $Message) { $Message = "Update $(Get-Date -Format 'yyyy-MM-dd HH:mm')" }
    Write-Host ''
    Write-Host "Changes ($($changes.Count)):" -ForegroundColor Yellow
    $changes | ForEach-Object { Write-Host "    $_" }

    git add -A
    # Pass the message through a UTF-8 file: command-line arguments would be
    # re-encoded through the ANSI code page and mangle Chinese text.
    $tmp = Join-Path $env:TEMP ("gitmsg_" + [Guid]::NewGuid().ToString('N') + '.txt')
    [IO.File]::WriteAllText($tmp, $Message, (New-Object Text.UTF8Encoding($false)))
    git commit -F $tmp
    $commitCode = $LASTEXITCODE
    Remove-Item -Force $tmp -ErrorAction SilentlyContinue
    if ($commitCode -ne 0) { Write-Host 'Commit failed.' -ForegroundColor Red; exit 1 }
}

$head = (git rev-parse HEAD).Trim()
$failed = @()

foreach ($remote in @('origin', 'github')) {
    Write-Host ''
    Write-Host ">>> pushing to $remote" -ForegroundColor Yellow
    git push $remote $branch 2>&1 | ForEach-Object { Write-Host "    $_" }
    if ($LASTEXITCODE -ne 0) { $failed += $remote }
}

Write-Host ''
if ($failed.Count -gt 0) {
    Write-Host ("Push FAILED for: " + ($failed -join ', ')) -ForegroundColor Red
    Write-Host "Typical fix: git pull --rebase <remote> $branch, then push again." -ForegroundColor Yellow
    exit 1
}

Write-Host "Done. HEAD = $head" -ForegroundColor Green
git log -1 --pretty=format:'    %h  %s%n'
Write-Host ''
foreach ($remote in @('origin', 'github')) {
    $r = (git ls-remote --heads $remote $branch 2>$null)
    if ($r) {
        $remoteHead = ($r -split "`t")[0]
        $state = if ($remoteHead -eq $head) { 'OK  ' } else { 'DIFF' }
        $color = if ($remoteHead -eq $head) { 'Green' } else { 'Red' }
        Write-Host "    [$state] $remote  $remoteHead" -ForegroundColor $color
    }
    else {
        Write-Host "    [ ?? ] $remote  (no ref read back)" -ForegroundColor DarkYellow
    }
}
