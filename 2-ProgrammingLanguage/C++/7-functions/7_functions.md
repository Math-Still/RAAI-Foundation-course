# 2.1 函数定义和调用

> 原文：[C++ Functions](https://en.cppreference.com/w/cpp/language/functions)

> 译者：RAAI学习团队

函数是C++程序的基本构建块。函数是一段可以重复使用的代码，它接受输入（参数），执行一些操作，然后返回一个值。函数帮助我们组织代码，避免重复，并使程序更易于理解和维护。

## 函数的基本结构

一个函数包含以下几个部分：

```cpp
#include <iostream>

// 函数声明（原型）
int add(int a, int b);

// 函数定义
int add(int a, int b) {
    int result = a + b;
    return result;
}

int main() {
    int sum = add(5, 3);
    std::cout << "5 + 3 = " << sum << std::endl;
    return 0;
}
```

## 函数参数

函数可以接受不同类型的参数：

```cpp
#include <iostream>
#include <string>

// 值参数
void printNumber(int num) {
    std::cout << "Number: " << num << std::endl;
}

// 多个参数
void printInfo(std::string name, int age) {
    std::cout << "Name: " << name << ", Age: " << age << std::endl;
}

// 默认参数
void greet(std::string name = "World") {
    std::cout << "Hello, " << name << "!" << std::endl;
}

int main() {
    printNumber(42);
    printInfo("Alice", 25);
    greet();           // 使用默认参数
    greet("Bob");      // 使用自定义参数
    return 0;
}
```

## 返回值

函数可以返回不同类型的值：

```cpp
// 返回整数
int square(int x) {
    return x * x;
}

// 返回浮点数
double average(double a, double b) {
    return (a + b) / 2.0;
}

// 返回字符串
std::string getGreeting(std::string name) {
    return "Hello, " + name + "!";
}

// 无返回值（void函数）
void printLine() {
    std::cout << "-------------------" << std::endl;
}

int main() {
    int result = square(5);
    std::cout << "5 squared = " << result << std::endl;
    
    double avg = average(10.5, 20.5);
    std::cout << "Average = " << avg << std::endl;
    
    std::string greeting = getGreeting("Charlie");
    std::cout << greeting << std::endl;
    
    printLine();
    
    return 0;
}
```

## 函数重载

C++允许定义同名但参数不同的函数：

```cpp
#include <iostream>
#include <string>

// 重载函数：不同参数类型
int add(int a, int b) {
    return a + b;
}

double add(double a, double b) {
    return a + b;
}

// 重载函数：不同参数数量
int add(int a, int b, int c) {
    return a + b + c;
}

// 重载函数：不同参数类型
std::string add(std::string a, std::string b) {
    return a + b;
}

int main() {
    std::cout << "add(5, 3) = " << add(5, 3) << std::endl;
    std::cout << "add(5.5, 3.3) = " << add(5.5, 3.3) << std::endl;
    std::cout << "add(1, 2, 3) = " << add(1, 2, 3) << std::endl;
    std::cout << "add(\"Hello, \", \"World!\") = " << add("Hello, ", "World!") << std::endl;
    
    return 0;
}
```

## 内联函数

内联函数可以提高执行效率：

```cpp
#include <iostream>

// 内联函数
inline int max(int a, int b) {
    return (a > b) ? a : b;
}

// 内联函数
inline double max(double a, double b) {
    return (a > b) ? a : b;
}

int main() {
    std::cout << "max(10, 20) = " << max(10, 20) << std::endl;
    std::cout << "max(10.5, 20.3) = " << max(10.5, 20.3) << std::endl;
    
    return 0;
}
```

## 递归函数

函数可以调用自己（递归）：

```cpp
#include <iostream>

// 计算阶乘的递归函数
int factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

// 计算斐波那契数列的递归函数
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    std::cout << "Factorial of 5 = " << factorial(5) << std::endl;
    std::cout << "Fibonacci(7) = " << fibonacci(7) << std::endl;
    
    return 0;
}
```

## 你会看到什么

运行程序后你会看到：

```sh
$ make exercise2_1
g++ -Wall -g exercise2_1.cpp -o exercise2_1
$ ./exercise2_1
5 + 3 = 8
Number: 42
Name: Alice, Age: 25
Hello, World!
Hello, Bob!
5 squared = 25
Average = 15.5
Hello, Charlie!
-------------------
$
```

## 函数的作用域

函数内部定义的变量只在函数内部有效：

```cpp
#include <iostream>

void testFunction() {
    int localVar = 10;
    std::cout << "Local variable: " << localVar << std::endl;
    // localVar只在函数内部有效
}

int main() {
    int mainVar = 20;
    std::cout << "Main variable: " << mainVar << std::endl;
    
    testFunction();
    
    // 这里不能访问localVar
    // std::cout << localVar << std::endl;  // 错误！
    
    return 0;
}
```

## 如何使它崩溃

尝试以下操作来观察程序的行为：

1. **无限递归**：
```cpp
int infiniteRecursion(int n) {
    return infiniteRecursion(n + 1);  // 没有终止条件
}

int main() {
    infiniteRecursion(1);  // 栈溢出
    return 0;
}
```

2. **未初始化的返回值**：
```cpp
int badFunction() {
    int x;
    return x;  // 返回未初始化的值
}

int main() {
    int result = badFunction();
    std::cout << "Result: " << result << std::endl;
    return 0;
}
```

3. **参数类型不匹配**：
```cpp
void printString(std::string str) {
    std::cout << str << std::endl;
}

int main() {
    printString(42);  // 类型不匹配
    return 0;
}
```

## 外部研究

对于这个练习，你需要：

1. 查找C++中函数的所有语法规则
2. 了解函数指针的概念和用法
3. 研究lambda表达式的语法
4. 学习C++11引入的函数特性

## 附加题

1. 创建一个计算器程序，使用函数实现加减乘除
2. 编写一个程序，使用递归计算最大公约数
3. 创建一个程序，演示函数重载的各种情况
4. 研究函数指针的用法
5. 了解lambda表达式的基本语法

## 下一节

下一节我们将学习[函数重载](2.2_function_overloading.md)。 