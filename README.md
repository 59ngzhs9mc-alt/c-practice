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

源码是 UTF-8，Windows 控制台默认代码页是 936（GBK），两边对不上就会显示成「涓枃」这种乱码。两种办法选一个。

### 办法一：把终端改成 UTF-8（推荐，设置一次就够）

改 PowerShell 的配置文件，之后新开的终端都是 UTF-8，`gcc` 不用带任何额外参数。

文件位置：

```
C:\Users\你的用户名\Documents\WindowsPowerShell\profile.ps1
```

路径不用自己拼，直接在 PowerShell 里敲这行，它会用记事本打开（文件不存在会问是否新建，选「是」）：

```powershell
notepad $PROFILE
```

把这三行写进去并保存：

```powershell
chcp 65001 > $null
[Console]::OutputEncoding = [Text.Encoding]::UTF8
$OutputEncoding = [Text.Encoding]::UTF8
```

然后**关掉当前终端窗口，重新开一个**——配置文件只在终端启动时加载，不重开不生效。验证：

```powershell
chcp
```

看到 `Active code page: 65001` 就成功了，以后编中文程序直接显示正常。

限制：只对 PowerShell 生效。双击 exe 弹出的黑窗口和 `cmd.exe` 还是 936，那种情况用办法二。

### 办法二：编译时把字符串存成 GBK

让 exe 里的中文字符串直接按 GBK 存，跟系统默认代码页一致，双击运行也不乱：

```powershell
gcc -g -Wall -finput-charset=UTF-8 -fexec-charset=GBK x.c -o x.exe
```

- `-finput-charset=UTF-8`：按 UTF-8 读源码
- `-fexec-charset=GBK`：字符串按 GBK 存进 exe

适合要发给别人、或者要双击运行的版本。日常在 VS Code 终端里跑，用办法一就够了。

## 关于构建产物

`*.exe`、`*.obj`、`build/`、`x64/`、`.vs/` 等已在 `.gitignore` 中排除，仓库只保留源码。
