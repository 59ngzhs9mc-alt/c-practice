# C 语言练习

C/C++ 练习和作业。用 MinGW-w64 的 `gcc` / `g++` 手动编译，VS Code 只当编辑器用。

## 目录

| 目录 | 内容 |
|---|---|
| `practice/10-20-26/` | 猜数字小游戏、递归练习，源码 `lianxi.c` |
| `practice/10_14_26/` | 10 月 14 日作业，源码 `zuoye.cpp` |
| `practice/11-15-26/` | 指针与二级指针、辗转相除法、猜数字，源码 `practice.c` |
| `practice/mine_sweeping/Project1/` | 扫雷小游戏，源码 `game.c` + `game.h` + `text.c` |

## 怎么编译

编译器在 `E:\mingw64\bin\`，已经加进 PATH，直接敲 `gcc` 就行。

**单文件**（`lianxi.c`、`practice.c`、`zuoye.cpp` 这种）：

```powershell
cd F:\cyuyan\code
gcc -g -Wall practice\11-15-26\practice.c -o practice.exe
.\practice.exe
```

**多文件**（扫雷：`game.c` + `game.h` + `text.c` 要一起编）：

```powershell
cd F:\cyuyan\code\practice\mine_sweeping\Project1
gcc -g -Wall game.c text.c -o Project1.exe
.\Project1.exe
```

**C++ 文件**用 `g++`；只要有一个 `.cpp` 参与，链接也要用 `g++`：

```powershell
g++ -g -Wall practice\10_14_26\zuoye.cpp -o zuoye.exe
```

**调试**：想用 gdb 就编的时候加 `-g`（上面都带了），然后按你的习惯用 `gdb 程序名` 或 VS Code 的调试功能。

## 中文输出不乱码

源码是 UTF-8，Windows 控制台默认 936（GBK），直接 `gcc` 编译出来的程序打印中文会乱码。加两个参数：

```powershell
gcc -g -Wall -finput-charset=UTF-8 -fexec-charset=GBK x.c -o x.exe
```

- `-finput-charset=UTF-8`：按 UTF-8 读源码
- `-fexec-charset=GBK`：字符串按 GBK 输出，正好对上控制台

## 关于构建产物

`*.exe`、`*.obj`、`build/`、`x64/`、`.vs/` 等已在 `.gitignore` 中排除，仓库只保留源码。
