# C++ 编程语言学习模块

本模块基于"Learn C The Hard Way"的学习方法，为C++编程语言提供系统性的学习路径。

## 学习目标

- 掌握C++基础语法和概念
- 理解面向对象编程
- 学习现代C++特性
- 掌握内存管理和智能指针
- 学习模板和泛型编程
- 理解STL容器和算法

## 模块结构

```
C++/
├── README.md                 # 本文件
├── SUMMARY.md               # 学习目录
├── docs/                    # 学习文档
│   ├── chapter01/           # 第1章：基础语法
│   ├── chapter02/           # 第2章：函数和数组
│   ├── chapter03/           # 第3章：指针和引用
│   ├── chapter04/           # 第4章：类和对象
│   ├── chapter05/           # 第5章：继承和多态
│   ├── chapter06/           # 第6章：模板和泛型
│   ├── chapter07/           # 第7章：STL容器
│   ├── chapter08/           # 第8章：STL算法
│   ├── chapter09/           # 第9章：智能指针
│   └── chapter10/           # 第10章：现代C++特性
├── exercises/               # 练习题
│   ├── chapter01/
│   ├── chapter02/
│   └── ...
├── solutions/               # 练习答案
│   ├── chapter01/
│   ├── chapter02/
│   └── ...
├── tests/                   # 单元测试
│   ├── chapter01/
│   ├── chapter02/
│   └── ...
└── examples/                # 示例代码
    ├── chapter01/
    ├── chapter02/
    └── ...
```

## 如何使用

1. 按照章节顺序学习
2. 阅读每个章节的文档
3. 完成练习题
4. 运行测试验证理解
5. 查看示例代码加深理解

## 编译和运行

```bash
# 编译整个模块
mkdir build && cd build
cmake ..
make

# 编译特定章节
make chapter01_exercises
make chapter02_exercises

# 运行测试
make test

# 运行示例
./bin/examples/chapter01_basics
```

## 学习建议

- 每个练习都要亲手完成
- 不要跳过任何章节
- 多尝试修改代码观察结果
- 遇到问题先自己思考再查看答案 