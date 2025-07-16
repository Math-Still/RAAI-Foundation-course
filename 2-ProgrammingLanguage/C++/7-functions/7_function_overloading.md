# 2.2 函数重载

> 原文：[C++ Function Overloading](https://en.cppreference.com/w/cpp/language/overload_resolution)

> 译者：RAAI学习团队

函数重载是C++的一个重要特性，它允许在同一作用域中定义多个同名但参数不同的函数。编译器根据调用时提供的参数类型和数量来选择正确的函数版本。

## 函数重载的基本概念

函数重载允许你使用相同的函数名来执行不同的操作：

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

## 重载规则

C++编译器使用以下规则来确定调用哪个重载函数：

```cpp
#include <iostream>

// 规则1：参数数量不同
void print(int x) {
    std::cout << "Integer: " << x << std::endl;
}

void print(int x, int y) {
    std::cout << "Two integers: " << x << ", " << y << std::endl;
}

// 规则2：参数类型不同
void print(double x) {
    std::cout << "Double: " << x << std::endl;
}

void print(const char* str) {
    std::cout << "String: " << str << std::endl;
}

// 规则3：参数顺序不同
void print(int x, double y) {
    std::cout << "Int-Double: " << x << ", " << y << std::endl;
}

void print(double x, int y) {
    std::cout << "Double-Int: " << x << ", " << y << std::endl;
}

int main() {
    print(10);           // 调用 print(int)
    print(10, 20);       // 调用 print(int, int)
    print(3.14);         // 调用 print(double)
    print("Hello");      // 调用 print(const char*)
    print(10, 3.14);     // 调用 print(int, double)
    print(3.14, 10);     // 调用 print(double, int)
    
    return 0;
}
```

## 类型转换和重载

编译器会进行类型转换来匹配重载函数：

```cpp
#include <iostream>

void process(int x) {
    std::cout << "Processing int: " << x << std::endl;
}

void process(double x) {
    std::cout << "Processing double: " << x << std::endl;
}

void process(const char* str) {
    std::cout << "Processing string: " << str << std::endl;
}

int main() {
    process(5);          // 直接匹配 int
    process(5.0);        // 直接匹配 double
    process("Hello");    // 直接匹配 const char*
    
    // 类型转换
    process('A');        // char 转换为 int
    process(5.5f);       // float 转换为 double
    process(42);         // int 保持不变
    
    return 0;
}
```

## 重载解析的优先级

编译器按以下优先级选择重载函数：

```cpp
#include <iostream>

// 精确匹配
void func(int x) {
    std::cout << "Exact match (int): " << x << std::endl;
}

// 提升转换
void func(long x) {
    std::cout << "Promotion (long): " << x << std::endl;
}

// 标准转换
void func(double x) {
    std::cout << "Standard conversion (double): " << x << std::endl;
}

int main() {
    int i = 10;
    char c = 'A';
    double d = 3.14;
    
    func(i);    // 精确匹配
    func(c);    // char 提升为 int
    func(d);    // double 保持不变
    
    return 0;
}
```

## 重载和const

const修饰符也可以用于重载：

```cpp
#include <iostream>
#include <string>

class String {
private:
    std::string data;
public:
    String(const std::string& str) : data(str) {}
    
    // const成员函数重载
    char& operator[](size_t index) {
        std::cout << "Non-const operator[]" << std::endl;
        return data[index];
    }
    
    const char& operator[](size_t index) const {
        std::cout << "Const operator[]" << std::endl;
        return data[index];
    }
    
    // const参数重载
    void process(const std::string& str) {
        std::cout << "Processing const string: " << str << std::endl;
    }
    
    void process(std::string& str) {
        std::cout << "Processing non-const string: " << str << std::endl;
    }
};

int main() {
    String s("Hello");
    const String cs("World");
    
    s[0];       // 调用非const版本
    cs[0];      // 调用const版本
    
    std::string str1 = "test";
    const std::string str2 = "const test";
    
    s.process(str1);    // 调用非const版本
    s.process(str2);    // 调用const版本
    
    return 0;
}
```

## 你会看到什么

运行程序后你会看到：

```sh
$ make exercise2_2
g++ -Wall -g exercise2_2.cpp -o exercise2_2
$ ./exercise2_2
add(5, 3) = 8
add(5.5, 3.3) = 8.8
add(1, 2, 3) = 6
add("Hello, ", "World!") = Hello, World!
Integer: 10
Two integers: 10, 20
Double: 3.14
String: Hello
$
```

## 重载的注意事项

### 1. 不能仅通过返回类型重载

```cpp
// 错误：不能仅通过返回类型重载
int getValue() { return 42; }
double getValue() { return 3.14; }  // 编译错误
```

### 2. 默认参数和重载

```cpp
#include <iostream>

// 使用默认参数
void print(int x, int y = 0) {
    std::cout << "x = " << x << ", y = " << y << std::endl;
}

// 重载版本
void print(int x) {
    std::cout << "x = " << x << std::endl;
}

int main() {
    print(10);      // 调用 print(int)
    print(10, 20);  // 调用 print(int, int)
    
    return 0;
}
```

## 如何使它崩溃

尝试以下操作来观察程序的行为：

1. **歧义错误**：
```cpp
void func(int x) { std::cout << "int" << std::endl; }
void func(double x) { std::cout << "double" << std::endl; }

int main() {
    func(5);  // 歧义：int可以转换为double，double也可以转换为int
    return 0;
}
```

2. **模板和重载冲突**：
```cpp
template<typename T>
void process(T x) {
    std::cout << "Template: " << x << std::endl;
}

void process(int x) {
    std::cout << "Int: " << x << std::endl;
}

int main() {
    process(5);  // 可能产生歧义
    return 0;
}
```

3. **继承中的重载问题**：
```cpp
class Base {
public:
    virtual void func(int x) { std::cout << "Base::func(int)" << std::endl; }
};

class Derived : public Base {
public:
    void func(double x) { std::cout << "Derived::func(double)" << std::endl; }
    // 这不会重载Base::func，而是隐藏它
};

int main() {
    Derived d;
    d.func(5);  // 调用Derived::func(double)
    return 0;
}
```

## 外部研究

对于这个练习，你需要：

1. 查找C++重载解析的完整规则
2. 了解模板特化和重载的关系
3. 研究继承中的重载和隐藏
4. 学习C++11引入的完美转发

## 附加题

1. 创建一个数学库，使用重载实现不同类型的数学运算
2. 编写一个程序，演示const在重载中的作用
3. 创建一个程序，展示模板和重载的交互
4. 研究继承中的重载问题
5. 了解C++11的完美转发和重载

## 下一节

下一节我们将学习[数组基础](2.3_arrays.md)。 