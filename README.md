# C 语言练习

VS Code + MinGW-w64 下写的 C/C++ 练习和作业。

## 目录

| 目录 | 内容 |
|---|---|
| `practice/10-20-26/` | 猜数字小游戏，源码 `lianxi.c` |
| `practice/10_14_26/` | 10 月 14 日作业，源码 `zuoye.cpp` |
| `practice/11-15-26/practice/` | 指针与二级指针、辗转相除法，源码 `practice.c` |
| `practice/mine_sweeping/Project1/` | 扫雷小游戏，源码 `game.c` + `game.h` + `text.cpp` |

## 打开方式

用 VS Code 打开本文件夹（`F:\cyuyan\code`），配置都在 `.vscode/` 里，详见 `.vscode/README.md`：

- `Ctrl + Shift + B` 编译当前文件
- `F5` 调试（单文件直接按；多文件的扫雷见 `.vscode/README.md` 第三节）
- `F1` → 运行任务 → 构建并运行、提交并推送到 Gitee + GitHub

编译器是 `E:\mingw64\bin\gcc.exe`（MinGW-w64 15.2），不需要 Visual Studio，也不用开 `vcvars64`。

## 关于构建产物

`build/`、`*.exe`、`*.obj` 等已在 `.gitignore` 中排除，仓库只保留源码和 `.vscode/` 配置。
