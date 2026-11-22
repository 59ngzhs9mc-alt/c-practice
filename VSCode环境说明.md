# VS Code 环境说明（交接用）

> 这份文档只讲 **VS Code 环境、配置、编译/调试方式和踩过的坑**，不含版本管理相关内容。
> 用途：开新对话时把这份内容带上，省得从头解释环境。
> 最后更新：2026-11-22

## 1. 目标

只用 VS Code 写 C/C++ 练习，**不再使用 Visual Studio**。工作方式：

- 编辑器：VS Code（只当编辑器 + 调试器）
- 编译：手动敲 `gcc` / `g++`（不依赖任何构建配置）
- 调试：F5 走 gdb（`launch.json` 已配好）
- 代码位置：`F:\cyuyan\code`

## 2. 环境事实

| 项目 | 值 |
|---|---|
| VS Code | `E:\Microsoft VS Code\Code.exe`，`bin\code.cmd` 已在 PATH |
| VS Code 权限 | 以**管理员**身份运行（窗口标题带 `[管理员]`） |
| 编译器 | MinGW-w64：`E:\mingw64\bin\gcc.exe`、`g++.exe`，版本 15.2.0 |
| 调试器 | `E:\mingw64\bin\gdb.exe`，版本 16.3 |
| make | `E:\mingw64\bin\mingw32-make.exe`，4.4.1（目前没用上） |
| 工作区 | `F:\cyuyan\code` |
| 集成终端 | Windows PowerShell 5.1（不是 PowerShell 7） |
| 已弃用 | Visual Studio（MSVC 在 `F:\vs`，本项目不用） |

## 3. 源码结构

| 路径 | 行数 | 状态 |
|---|---|---|
| `homework/array.c` | 288 | 有 `main`，数组练习 + 素数判断 |
| `practice/10-20-26/lianxi.c` | 293 | 有 `main`，递归（斐波那契、阶乘） |
| `practice/10_14_26/zuoye.c` | 164 | 无 `main`（整体注释），10 月 14 日作业 |
| `practice/11-15-26/practice.c` | 78 | 有 `main`，指针/二级指针、辗转相除、猜数字 |
| `practice/mine_sweeping/Project1/game.c` | 106 | 扫雷核心函数（无 `main`） |
| `practice/mine_sweeping/Project1/game.h` | 34 | 扫雷函数声明 |
| `practice/mine_sweeping/Project1/text.c` | 67 | 扫雷 `main` + 菜单流程 |

**重要**：大部分练习文件是「整体注释、没有生效的 main」。直接 `gcc` 编译这类文件，编译能过、链接会报：

```
undefined reference to `WinMain'
```

这是正常的，不是代码错。

## 4. 编译与运行

### 单文件

```powershell
cd F:\cyuyan\code
gcc -g -Wall practice\11-15-26\practice.c -o practice.exe
.\practice.exe
```

- `-g`：带调试信息（F5 调试必需）
- `-Wall`：开常用警告
- `-o`：指定输出文件名，不写默认 `a.exe`
- `.\`：PowerShell 不会去当前目录找程序，必须写

### 多文件（扫雷，两个 `.c` 一起编）

```powershell
cd F:\cyuyan\code\practice\mine_sweeping\Project1
gcc -g -Wall game.c text.c -o Project1.exe
.\Project1.exe
```

**`.h` 永远不写进命令行**——它被 `#include` 展开进 `.c` 了。写了会提示 `linker input file unused`。
但要注意：**改了 `.h` 必须重新编译**，否则用的还是旧声明。

### C++

只要有一个 `.cpp` 参与，全程用 `g++`：

```powershell
g++ -g -Wall practice\10_14_26\zuoye.cpp -o zuoye.exe
```

## 5. 中文乱码：三个场景、三套机制

这是这个项目最容易反复踩的坑。**同一个程序，在不同地方跑，编码要求不一样。**

### 场景 A：VS Code 集成终端（PowerShell）

已通过 PowerShell 配置文件永久改成 UTF-8。

文件：`C:\Users\Hello\Documents\WindowsPowerShell\profile.ps1`

内容：

```powershell
chcp 65001 > $null
[Console]::OutputEncoding = [Text.Encoding]::UTF8
$OutputEncoding = [Text.Encoding]::UTF8
```

要点：

- 只对**新开的终端**生效，改完要关掉终端重开
- 验证：`chcp` 显示 `Active code page: 65001`
- **只影响 PowerShell**，管不到 cmd，也管不到双击 exe

### 场景 B：F5 调试弹出的黑窗口

`launch.json` 里如果写 `"externalConsole": true`，VS Code 会另开一个**独立 cmd 窗口**跑程序。那个窗口代码页是 936，程序输出 UTF-8 就乱成「釒專嘲鎳？」。

已改成在集成终端里跑：

```jsonc
"externalConsole": false,
"console": "integratedTerminal",
```

改完要 `Shift + F5` 停旧会话、再 `F5` 重开。

### 场景 C：双击 exe / 发给别人

那种环境就是 cmd，936，改不了。只能让程序输出 GBK：

```powershell
gcc -g -Wall -finput-charset=UTF-8 -fexec-charset=GBK x.c -o x.exe
```

### 判断口诀

| 乱码出现在哪 | 那是什么 | 处理 |
|---|---|---|
| F5 弹出的独立黑窗口 | cmd，936 | `externalConsole: false`，或编译加 `-fexec-charset=GBK` |
| VS Code 底部「终端」标签 | PowerShell，已 UTF-8 | 正常不该乱；乱了查 `chcp` |
| VS Code 底部「调试控制台」 | VS Code 内部 | 与终端无关，程序输出 UTF-8 就正常 |
| 在资源管理器里双击 exe | cmd，936 | 编译加 `-fexec-charset=GBK` |

## 6. `.vscode` 配置现状

`launch.json`、`tasks.json`、`c_cpp_properties.json` 三份是 VS Code / C/C++ 扩展**自动生成**的；`settings.json` 是手写的（只放了换行符设置）。

### `launch.json`（调试，1 条配置）

```jsonc
"name": "(gdb) 启动",
"type": "cppdbg",
"program": "${fileDirname}\\${fileBasenameNoExtension}.exe",
"cwd": "${fileDirname}",
"externalConsole": false,
"console": "integratedTerminal",
"preLaunchTask": "C/C++: gcc.exe 生成活动文件",
"MIMode": "gdb",
"miDebuggerPath": "E:\\mingw64\\bin\\gdb.exe"
```

即：F5 → 先按 `preLaunchTask` 编译当前文件 → 用 gdb 在集成终端里跑同名 `.exe`。

### `tasks.json`（编译，1 条任务）

```jsonc
"label": "C/C++: gcc.exe 生成活动文件",
"command": "E:\\mingw64\\bin\\gcc.exe",
"args": ["-fdiagnostics-color=always", "-g", "${file}", "-o", "${fileDirname}\\${fileBasenameNoExtension}.exe"]
```

**缺口**：这条任务只编**当前这一个文件**。扫雷那种 `game.c + text.c` 的多文件项目，用它编会报 `undefined reference to ...`。多文件目前只能手动 `gcc`。

### `c_cpp_properties.json`（IntelliSense）

```jsonc
"compilerPath": "E:\\mingw64\\bin\\gcc.exe",
"cStandard": "gnu23",
"cppStandard": "gnu++17",
"intelliSenseMode": "gcc-x64"
```

### `settings.json`（手写，1 项）

```jsonc
"files.eol": "\r\n"
```

让 VS Code 新建文件默认用 CRLF，和仓库根目录 `.gitattributes`（`* text=auto eol=crlf`）保持一致。

## 7. 踩过的坑（按出现频率）

1. **桌面自动化改 VS Code 编辑器有风险**：曾经把一份 README 覆盖成一行，还触发过一次文件变 0 字节。要改文件用编辑器或命令行写，别用模拟按键往里打字。
2. **`Ctrl + Shift + P` 在这台机器经常没反应**，`F1` 能打开同一个命令面板，用 F1。
3. **PowerShell 5.1 不支持把 `if` 当表达式写进参数位置**（PS7 才支持），会报 `if : The term 'if' is not recognized`。
4. **`notepad $PROFILE` 若配置文件不存在**，会弹「是否新建」；直接默认路径新建即可。
5. **`gcc: input file 'X.exe' is the same as output file`**：Tab 补全把已有的 `.exe` 补进了源文件列表，命令行里只能出现 `.c`。
6. **`.h` 不进命令行，但改了要重编**，否则函数声明对不上。
7. **`scanf("%d\n", &x)` 会吃掉后面的输入**，看起来像「卡住不动」。`\n` 应该去掉。
8. **`printf("%d", x)` 不带 `\n`**，输出会贴在提示符后面，看着像没输出。
9. **双击 exe 一闪而过**：程序执行完窗口就关，看结果要在终端里跑。
10. **换行符 CRLF/LF 混用 —— 已解决**：仓库根目录的 `.gitattributes` 写了 `* text=auto eol=crlf`，仓库里统一按 LF 存储、检出到本地自动还原成 CRLF，`git status` / `git diff` 不会再出现几百行的行尾假改动。之前仓库里混存的 CRLF 文件已经在一次 renormalize 提交里归一。`.vscode/settings.json` 里 `files.eol` 设为 `\r\n`，VS Code 新建文件默认也是 CRLF。真要临时对比行尾，`git diff --ignore-cr-at-eol` 仍然可用。
11. **`.exe` 被 `.gitignore` 忽略**：本地有 exe，仓库里没有，这是预期的。
12. **`.\xxx.exe` 报「无法识别为 cmdlet」**：当前目录不对，或漏了 `.\`。PowerShell 不搜当前目录。

## 8. 当前进度

| 练习 | 内容 | 状态 |
|---|---|---|
| 斐波那契/阶乘递归 | `lianxi.c` 里的 `fun()` 递归 | 已完成，可运行 |
| 猜数字 | `practice.c`：`rand()` 随机数 + 循环猜 | 已改过一轮输入处理 |
| 数组交换 | `array.c` 里那段先注释掉了 | 暂停 |
| 素数判断 | `array.c` 里 `is_prime()` + `main` | 进行中 |
| 扫雷 | `game.c` + `game.h` + `text.c`，10×10 棋盘、菜单 | 可运行 |

## 9. 事项状态（新对话可以接着做）

1. ~~`homework/` 的整理规则~~ **已定（2026-11-22）**：平时**一个练习一个 `.c`**，文件名用英文小写描述（`prime.c`、`array_swap.c`、`guess_number.c`）；只有某次练习真的需要多文件（像扫雷 `game.c` + `text.c`）时，才建目录 `homework/xxx/`。理由：F5 的 `tasks.json` 只编当前文件，单文件布局按 F5 就能跑。
2. ~~给扫雷加 F5 多文件调试配置~~ **暂不处理**（2026-11-22 决定搁置；多文件照旧手敲 `gcc game.c text.c -o Project1.exe`）。
3. ~~是否统一全仓换行符~~ **已解决**：`.gitattributes` 定死 `* text=auto eol=crlf`，`.vscode/settings.json` 里 `files.eol` 也是 `\r\n`，详见第 7 节第 10 条。
4. ~~是否保留 `.vscode/tasks.json`~~ **已决定保留**（单文件够用；扫雷那种多文件用命令行）。

现状：`homework/` 里只有 `array.c`，里面混着「数组交换」（那段先注释掉了）和「素数判断」两个练习——**暂不拆分**，等真有需要再动。

## 10. 新对话开场白（可直接复制）

> 我在学 C 语言，代码在 `F:\cyuyan\code`，只用 VS Code 写（不用 Visual Studio），编译器是 `E:\mingw64\bin` 下的 MinGW gcc 15.2，调试用 gdb。
> 细节看仓库根目录的 `VSCode环境说明.md` 和 `配置与排查.md`。
> 现在的问题是：……
