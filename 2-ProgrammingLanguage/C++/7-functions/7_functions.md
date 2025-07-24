# 2.1 函数定义和调用

> 原文：[C++ Functions](https://en.cppreference.com/w/cpp/language/functions)

> 译者：RAAI学习团队

函数是一个命了名的代码块，我们通过调用函数执行相应的代码，函数可以有0个或多个参数，而且通常会产生一个结果，可以函数重载。同一个函数名字可以几个不同的函数。

## 函数的基本结构

一个经典的函数定义包括以下部分：返回类型、函数名字、由0个或多个参数组成的参数列表、函数体。其中形参以逗号隔开，形参的列表位于一对圆括号之内。函数执行的操作在语句块中说明，该语句块被称为函数体。

我们通过调用运算符来执行函数。调用运算符是一对圆括号，它作用于一个表达式，该表达式是函数或指向函数的指针；圆括号之内是一个用逗号隔开的实参列表。我们用实参初始化函数的形参。调用表达式的类型就是函数的返回类型。

下面是一些具体案例：
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

## 函数形参和实参

实参是形参的初始值。第一个实参初始化第一个形参,第二个实参初始化第二个形参,以此类推。尽管实参与形参存在对应关系,但是并没有规定实参的求值顺序。编译器能以任意可行的顺序对实参求值。

实参的类型必须与对应的形参类型匹配,这一点与之前的规则是一致的,我们知道在初始化过程中初始值的类型也必须与初始化对象的类型匹配。函数有几个形参,我们就必须提供相同数量的实参。因为函数的调用规定实参数量应与形参数量一致,所以形参一定会被初始化。


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

大多数类型都能用作函数的返回类型。一种特殊的返回类型是 void,它表示函数不返回任何值。函数的返回类型不能是数组类型或函数类型,但可以是指向数组或函数的指针。


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
如果同一作用域内的几个函数名字相同但形参列表不同,我们称之为重载(overloaded function)。

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
这些函数接受的形参类型不一样,但是执行的操作非常类似。当调用这些函数时,编译器会根据传递的实参类型推断想要的是哪个函数。

对于重载的函数来说,它们应该在形参数量或形参类型上有所不同。

不允许两个函数除了返回类型外其他所有的要素都相同。假设有两个函数,它们的形参列表一样但是返回类型不同,则第二个函数的声明是错误的。
```cpp
// 第一个函数：返回 int 类型
int getValue() {
    return 10;
}

// 第二个函数：返回 double 类型，但参数列表与第一个函数完全相同
double getValue() { // 编译错误：'double getValue()' cannot be overloaded
    return 10.5;
}

int main() {
    // 尝试调用函数
    // int a = getValue(); // 这行会因为上面的重载错误而无法编译
    std::cout << "This code will not compile due to function overloading error." << std::endl;
    return 0;
}
```

### 重载规则

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

### 类型转换和重载

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

### 重载解析的优先级

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

### 重载和const

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

### 重载的注意事项

#### 1. 不能仅通过返回类型重载

```cpp
// 错误：不能仅通过返回类型重载
int getValue() { return 42; }
double getValue() { return 3.14; }  // 编译错误
```

#### 2. 默认参数和重载

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

## 内联函数
将函数指定为内联函数(inline),通常就是将它在每个调用点上“内联地”展开。什么意思呢？
内联就是编译器不调用函数，而是将函数的代码直接展开到调用点。
例如：
```cpp
void print_something() {
    std::cout << "Hello, World!" << std::endl;
}
int main() {
    print_something();
}
```
它就相当于：
```cpp
int main() {
    std::cout << "Hello, World!" << std::endl;
}
```

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
但是事实上，内联只是开发者对于编译器的一个`建议`, 编译器可以采用，也可以不采用。函数内联与否，是看编译器的选择。有`inline`关键字的函数不一定内联，没有`inline`关键字的函数也有可能内联。

如今，关键字`inline`大多数的含义表示：这个函数允许被多重定义。
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

4. **歧义错误**：
```cpp
void func(int x) { std::cout << "int" << std::endl; }
void func(double x) { std::cout << "double" << std::endl; }

int main() {
    func(5);  // 歧义：int可以转换为double，double也可以转换为int
    return 0;
}
```

5. **模板和重载冲突**：
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

6. **继承中的重载问题**：
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

1. 查找C++中函数的所有语法规则
2. 了解函数指针的概念和用法
3. 研究lambda表达式的语法
4. 学习C++11引入的函数特性
5. 查找C++重载解析的完整规则
6. 了解模板特化和重载的关系
7. 研究继承中的重载和隐藏
8. 学习C++11引入的完美转发

## 附加题

1. 创建一个计算器程序，使用函数实现加减乘除
2. 编写一个程序，使用递归计算最大公约数
3. 创建一个程序，演示函数重载的各种情况
4. 研究函数指针的用法
5. 了解lambda表达式的基本语法
6. 创建一个数学库，使用重载实现不同类型的数学运算
7. 编写一个程序，演示const在重载中的作用
8. 创建一个程序，展示模板和重载的交互
9. 研究继承中的重载问题
10. 了解C++11的完美转发和重载

## 下一节

下一节我们将学习[数组基础](2.3_arrays.md)。

## 最后提要
本节所有示例程序可以在`program.cpp`中找到  将其中的错误修改后，
你可以通过下面的命令编译（假设你是用gcc编译器）
```sh
g++ program.cpp -o main
```
你可以通过下面的命令运行程序
```sh
./main
```