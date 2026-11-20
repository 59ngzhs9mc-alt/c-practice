# 在 VS Code 里写这些练习（不再用 Visual Studio）

这套配置让 VS Code 变成「轻量版 Visual Studio」：写代码有补全和报错，按一下快捷键就编译运行，也能打断点调试。
编译器用的是 MinGW-w64（`E:\mingw64\bin\gcc.exe` / `g++.exe` / `gdb.exe`），不依赖 VS，也不用每次开 `vcvars64`。

## 一、第一次使用（只做一次）

1. 用 VS Code 打开**文件夹**：`文件 → 打开文件夹`，选 `F:\cyuyan\code`
   （不要只打开单个 .c 文件，否则任务里的 `${workspaceFolder}` 会指错地方）
2. 装扩展：左侧扩展面板搜索并安装
   - **C/C++**（`ms-vscode.cpptools`）——补全、跳转、报错波浪线、调试
   - 可选：**Chinese (Simplified) Language Pack**（界面汉化）

打开文件夹时 VS Code 右下角会提示「此工作区有推荐扩展」，点安装即可。

## 二、日常操作（全部在一个窗口里）

| 想做的事 | 操作 |
| --- | --- |
| 编译当前打开的文件 | `Ctrl + Shift + B` |
| 编译并运行当前文件 | `Ctrl + Shift + P` → 运行任务 → **构建并运行当前文件** |
| 调试当前文件（断点、单步） | `F5`（会先自动编译） |
| 提交并推送到两个平台 | `Ctrl + Shift + P`（或 `F1`）→ 运行任务 → **提交并推送到 Gitee + GitHub** |
| 编译并运行扫雷 | 运行任务 → **构建扫雷游戏** |

`Ctrl + Shift + B` 默认那个任务叫「构建当前文件」，实际规则是：**当前文件所在目录里还有别的 `.c` / `.cpp` 时，会把同目录源码一起编译、链接成一个程序**（扫雷就是这样，打开 `text.cpp` 按一下也能编出完整游戏）；目录里只剩它自己，就单独编译。所以 `lianxi.c`、`practice.c` 这种单文件练习照样一键编译。

扫雷是三个文件（`game.c` + `game.h` + `text.cpp`），必须整体编译，所以用「构建扫雷游戏」这个任务，或者直接按 `F5` 选「调试扫雷游戏 (gdb)」。

## 三、产物在哪

- 每个目录下生成 `build\`：`build\名字.exe`（单文件用文件名，多文件用目录名）、`build\run.exe`（同上的副本，`F5` 调试固定用它）和 `build\obj\*.o`
- `build/` 已经加进 `.gitignore`，不会被提交

## 四、几个已经替你调好的细节

- **编码**：`[c]` / `[cpp]` 固定用 `utf8bom` + `CRLF`，跟原来的习惯保持一致。这样中文注释不会乱码，`git diff` 也不会因为换行符整文件飘红。
- **不自动删行尾空格、不自动补末尾换行**：避免每次保存都制造无意义的 diff。
- **编译选项**：`-Wall -Wextra -g -O0`，有警告会显示出来，方便初学阶段发现问题。

## 五、特意处理过的「新手坑」

**整个文件都被注释掉、没有 `main()`** 时，链接会失败。`build.ps1` 会识别这种情况，打印：

```
No main() found - the file is probably fully commented out.
Compile (syntax check) passed, so keep editing; nothing to run yet.
```

退出码 2。意思是**语法检查通过了，只是还没写 main，没有东西可运行**，不是你的代码写错。继续写就行，写完 `main` 再按一次 `Ctrl + Shift + B`。

## 六、加新练习的流程

1. 在 `practice\` 下按日期建目录，例如 `practice\12-01-26\`
2. 新建 `main.c`（或 `xxx.cpp`），写 `int main(void) { ... }`
3. 打开这个文件，`Ctrl + Shift + B` 编译，`F5` 调试
4. 提交时 `build/` 会被自动忽略，只提交源码

如果想让某个多文件项目也有专属的「构建并运行」按钮，在 `.vscode\tasks.json` 里照抄「构建扫雷游戏」那条，把 `-Project` 后面的路径改掉即可。

## 七、提交并推送到 Gitee + GitHub

不用再开终端敲命令，也不用每次找人：

`Ctrl + Shift + P`（或者 `F1`，两个键效果一样）→ 运行任务 → **提交并推送到 Gitee + GitHub** → 敲一句提交说明（直接回车就是默认的「更新练习代码」）

它一次做完四件事：`git add -A` → `git commit` → 推 Gitee（origin）→ 推 GitHub（github），最后把两边远端最新的提交号打出来，对得上显示 `[OK]`，对不上显示 `[DIFF]`。

- **没有改动时**：不会空提交，只做推送（如果本地有没推的提交，正好补推）
- **只想推、不想提交**（比如你已经在终端里 commit 过了）：用另一个任务 **仅推送（不提交）到 Gitee + GitHub**
- **推送被拒**（提示 non-fast-forward）：说明两个平台的记录对不上，先 `git pull --rebase github master` 再推，或者叫我处理

> 还是那句话：**别用「修改上次提交(Amend)」**。已经推上去的提交被改写，就会出现上次那种分叉。

## 八、Visual Studio 的工程文件已清理

用 VS Code 就够了，所以 VS 那套东西已经删干净：

- 删掉了各目录的 `.slnx`、`.vcxproj`、`.vcxproj.filters`、`.vcxproj.user`
- 删掉了 `.vs\`（VS 缓存）和 `x64\`（VS 编译产物），仓库体积从 63MB 降到 300KB 出头
- 源码一个没动，`.c` / `.cpp` / `.h` 全在

哪天还想用 VS 打开：新建一个空工程，把这些源文件加进去即可（工程文件本身就几个复选框的事）。

## 九、文件清单

| 文件 | 作用 |
| --- | --- |
| `settings.json` | 编码、换行、隐藏产物、编译器路径 |
| `c_cpp_properties.json` | 智能提示（补全/跳转）用哪个编译器、C/C++ 标准 |
| `tasks.json` | 五个任务：三个编译 + 两个提交推送，`Ctrl + Shift + B` 和 `F1` 用的就是这里 |
| `launch.json` | `F5` 调试配置（gdb） |
| `extensions.json` | 打开文件夹时推荐的扩展 |
| `build.ps1` | 真正的编译脚本：单文件或多文件，输出到 `build\` |
| `push.ps1` | 提交并推送脚本：`git add -A` → commit → 推 Gitee → 推 GitHub → 核对两边 HEAD |
