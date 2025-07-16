# 贡献指南

欢迎为 RAAI-Foundation-course 项目做出贡献！本文档将指导您如何参与项目开发。

## 📋 目录

- [项目架构](#项目架构)
- [课件规范](#课件规范)
- [开发环境设置](#开发环境设置)
- [贡献流程](#贡献流程)
- [代码规范](#代码规范)
- [提交规范](#提交规范)
- [常见问题](#常见问题)

## 🏗️ 项目架构

### 目录结构

```
RAAI-Foundation-course/
├── 1-Linux/                    # 大课程类文件夹
│   ├── 1-basic-commands/       # 子课程文件夹
│   │   ├── 1.1-introduction/   # 章节文件夹
│   │   │   ├── README.md       # 课件（章节名称）
│   │   │   └── test/           # 课程作业文件夹
│   │   ├── 1.2-file-system/
│   │   └── CMakeLists.txt      # 子课程CMake配置
│   └── 2-system-administration/
├── 2-ProgrammingLanguage/
│   ├── C++/
│   │   ├── 1-prepare/
│   │   ├── 2-cpp_program/
│   │   │   ├── C++语法框架.md   # 课件
│   │   │   └── test/           # 作业文件夹
│   │   └── CMakeLists.txt
│   └── Python/
├── 3-Algorithm&Datastructure/
├── LinearAlgebra/
├── Robotics/
└── CMakeLists.txt              # 根目录CMake配置
```

### 架构要求

1. **大课程类文件夹**：包含完整的课程体系（如Linux、编程语言等）
2. **子课程文件夹**：大课程下的具体课程（如C++、Python等）
3. **章节文件夹**：子课程下的具体章节
4. **课件文件**：章节文件夹下的主要学习文档，文件名为章节名称
5. **test文件夹**：存放课程作业、练习题等
6. **CMakeLists.txt**：每个子课程文件夹都需要包含，当前版本请不要修改
7. **build文件夹**：被.gitignore忽略，用于存放编译产物

> ⚠️ **注意**：当前版本的CMake配置还不完善，请勿随意修改CMakeLists.txt文件。

## 📚 课件规范

### 课件格式要求

课件应遵循以下格式规范，参考 `2-ProgrammingLanguage/C++/2-cpp_program/C++语法框架.md`：

#### 1. 文档头部
```markdown
# 章节标题

> refer：[learncodethehardway](http://c.learncodethehardway.org)

## 主要内容标题
```

#### 2. 代码示例
```markdown
```c++
// 代码示例
#include <iostream>
using namespace std;

int main() {
    cout << "Hello World!" << endl;
    return 0;
}
```

使用编辑器写到 `test/helloworld.cpp` 并运行：

```bash
g++ -o ./build/helloworld test/helloworld.cpp
./build/helloworld
```
```

#### 3. 输出示例
```markdown
## 你会看到什么

现在你可以运行程序并看到输出。

```bash
./build/helloworld

Hello World!
```
```

#### 4. 理论讲解
```markdown
## 概念解释

- **概念1**：详细解释
- **概念2**：详细解释
```

#### 5. 课后题
```markdown
## 课后题

- 在test文件夹中新建一个helloworld.cpp，让这个程序可以输出`World Hello!`
- 修改damm.cpp文件，使其可以正常运行

Note:请你完全按照题目要求进行操作，文件夹中不要含有多余文件，否则题目可能会判断失败。
```

### 课件内容要求

1. **理论清晰**：概念解释要准确、易懂
2. **示例丰富**：提供完整的代码示例
3. **实践导向**：包含可运行的代码和测试
4. **循序渐进**：从简单到复杂，逐步深入
5. **错误示例**：适当提供常见错误和解决方案

## 🛠️ 开发环境设置

### 1. 安装Husky

项目使用Husky进行Git钩子管理，请先安装：

```bash
# 安装Husky
npm install -g husky

# 或者使用yarn
yarn global add husky

# 在项目根目录初始化Husky
husky install
```

### 2. 开发工具

推荐使用以下开发工具：
- **编辑器**：VS Code、Vim等
- **编译器**：GCC/G++、Clang
- **构建工具**：CMake、Make
- **版本控制**：Git

### 3. 环境检查

```bash
# 检查Git版本
git --version

# 检查编译器
g++ --version

# 检查CMake
cmake --version

# 检查Husky
husky --version
```

## 🔄 贡献流程

### 重要提醒

**项目不接受直接push，请通过fork的形式进行PR贡献。**

### 详细步骤

#### 1. Fork项目
1. 访问项目GitHub页面
2. 点击右上角的"Fork"按钮
3. 选择你的GitHub账户作为fork目标

#### 2. 克隆你的Fork
```bash
git clone https://github.com/你的用户名/RAAI-Foundation-course.git
cd RAAI-Foundation-course
```

#### 3. 添加上游仓库
```bash
git remote add upstream https://github.com/原仓库地址/RAAI-Foundation-course.git
```

#### 4. 创建功能分支
```bash
git checkout -b feature/your-feature-name
```

#### 5. 进行开发
- 按照项目架构要求创建文件夹和文件
- 遵循课件规范编写内容
- 确保代码可以正常编译运行

#### 6. 提交更改
```bash
git add .
git commit -m "feat: 添加新章节内容"
```

#### 7. 推送到你的Fork
```bash
git push origin feature/your-feature-name
```

#### 8. 创建Pull Request
1. 访问你的Fork页面
2. 点击"Compare & pull request"
3. 填写PR描述，说明你的贡献内容
4. 提交PR

## 📝 代码规范

### 文件命名
- **文件夹**：使用小写字母和连字符（kebab-case）
- **课件文件**：使用章节名称，如`C++语法框架.md`
- **代码文件**：使用有意义的名称，如`helloworld.cpp`

### 代码风格
- 使用4个空格缩进
- 代码注释要清晰明了
- 变量和函数名要有意义
- 遵循各语言的编码规范

### 文档规范
- 使用Markdown格式
- 标题层级要合理
- 代码块要指定语言
- 图片和链接要有效

## 📋 提交规范

### 提交信息格式
```
<type>(<scope>): <subject>

<body>

<footer>
```

### 类型说明
- `feat`: 新功能
- `fix`: 修复bug
- `docs`: 文档更新
- `style`: 代码格式调整
- `refactor`: 代码重构
- `test`: 测试相关
- `chore`: 构建过程或辅助工具的变动

### 示例
```
feat(cpp): 添加C++基础语法章节

- 添加变量类型介绍
- 添加运算符示例
- 添加控制流讲解

Closes #123
```

## ❓ 常见问题

### Q: 如何添加新的课程？
A: 在大课程类文件夹下创建新的子课程文件夹，包含章节文件夹和CMakeLists.txt。

### Q: 课件格式不统一怎么办？
A: 请参考现有的课件模板，确保格式一致。

### Q: 编译失败怎么办？
A: 检查CMakeLists.txt配置，确保依赖正确，当前版本CMake配置不完善，请谨慎修改。

### Q: 如何更新我的Fork？
A: 
```bash
git fetch upstream
git checkout main
git merge upstream/main
git push origin main
```

### Q: PR被拒绝怎么办？
A: 查看反馈意见，修改后重新提交，保持良好的沟通。

## 🤝 社区

- **Issues**: 用于报告bug和提出建议
- **Discussions**: 用于讨论和问答
- **Wiki**: 项目文档和教程

感谢您的贡献！🎉

---

如有任何问题，请随时联系项目维护者。 