#include <iostream>
#include <string>

// 1. 函数基本结构
int add_basic(int a, int b) {
    return a + b;
}

// 2. 函数形参和实参
void printNumber(int num) {
    std::cout << "Number: " << num << std::endl;
}

void printInfo(std::string name, int age) {
    std::cout << "Name: " << name << ", Age: " << age << std::endl;
}

void greet(std::string name = "World") {
    std::cout << "Hello, " << name << "!" << std::endl;
}

// 3. 返回值
int square(int x) {
    return x * x;
}

double average(double a, double b) {
    return (a + b) / 2.0;
}

std::string getGreeting(std::string name) {
    return "Hello, " + name + "!";
}

void printLine() {
    std::cout << "-------------------" << std::endl;
}

// 4. 函数重载
int add(int a, int b) {
    return a + b;
}

double add(double a, double b) {
    return a + b;
}

int add(int a, int b, int c) {
    return a + b + c;
}

std::string add(std::string a, std::string b) {
    return a + b;
}

// 重载规则示例
void print(int x) {
    std::cout << "Integer: " << x << std::endl;
}

void print(int x, int y) {
    std::cout << "Two integers: " << x << ", " << y << std::endl;
}

void print(double x) {
    std::cout << "Double: " << x << std::endl;
}

void print(const char* str) {
    std::cout << "String: " << str << std::endl;
}

void print(int x, double y) {
    std::cout << "Int-Double: " << x << ", " << y << std::endl;
}

void print(double x, int y) {
    std::cout << "Double-Int: " << x << ", " << y << std::endl;
}

// 类型转换和重载
void process(int x) {
    std::cout << "Processing int: " << x << std::endl;
}

void process(double x) {
    std::cout << "Processing double: " << x << std::endl;
}

void process(const char* str) {
    std::cout << "Processing string: " << str << std::endl;
}

// 重载解析优先级
void func(int x) {
    std::cout << "Exact match (int): " << x << std::endl;
}

void func(long x) {
    std::cout << "Promotion (long): " << x << std::endl;
}

void func(double x) {
    std::cout << "Standard conversion (double): " << x << std::endl;
}

// 重载和const (简化版，无类)
// 注意：完整示例涉及类，这里简化

// 默认参数和重载
void print_default(int x, int y = 0) {
    std::cout << "x = " << x << ", y = " << y << std::endl;
}

void print_default(int x) {
    std::cout << "x = " << x << std::endl;
}

// 5. 内联函数
inline int max_inline(int a, int b) {
    return (a > b) ? a : b;
}

inline double max_inline(double a, double b) {
    return (a > b) ? a : b;
}

// 6. 递归函数
int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

int fibonacci(int n) {
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// 7. 函数作用域
void testFunction() {
    int localVar = 10;
    std::cout << "Local variable: " << localVar << std::endl;
}

// 如何使它崩溃 (注释掉以避免运行错误)
/*
int infiniteRecursion(int n) {
    return infiniteRecursion(n + 1);
}

int badFunction() {
    int x;
    return x;
}

void printString(std::string str) {
    std::cout << str << std::endl;
}
// 等
*/

int main() {
    // 1. 函数基本结构
    std::cout << "1. add_basic(5, 3) = " << add_basic(5, 3) << std::endl;

    // 2. 函数形参和实参
    printNumber(42);
    printInfo("Alice", 25);
    greet();
    greet("Bob");

    // 3. 返回值
    std::cout << "3. square(5) = " << square(5) << std::endl;
    std::cout << "   average(10.5, 20.5) = " << average(10.5, 20.5) << std::endl;
    std::cout << getGreeting("Charlie") << std::endl;
    printLine();

    // 4. 函数重载
    std::cout << "4. add(5, 3) = " << add(5, 3) << std::endl;
    std::cout << "   add(5.5, 3.3) = " << add(5.5, 3.3) << std::endl;
    std::cout << "   add(1, 2, 3) = " << add(1, 2, 3) << std::endl;
    std::cout << "   add(\"Hello, \", \"World!\") = " << add("Hello, ", "World!") << std::endl;

    // 重载规则
    print(10);
    print(10, 20);
    print(3.14);
    print("Hello");
    print(10, 3.14);
    print(3.14, 10);

    // 类型转换和重载
    process(5);
    process(5.0);
    process("Hello");
    process('A');
    process(5.5f);
    process(42);

    // 重载解析优先级
    int i = 10;
    char c = 'A';
    double d = 3.14;
    func(i);
    func(c);
    func(d);

    // 默认参数和重载
    print_default(10);
    print_default(10, 20);

    // 5. 内联函数
    std::cout << "5. max_inline(10, 20) = " << max_inline(10, 20) << std::endl;
    std::cout << "   max_inline(10.5, 20.3) = " << max_inline(10.5, 20.3) << std::endl;

    // 6. 递归函数
    std::cout << "6. factorial(5) = " << factorial(5) << std::endl;
    std::cout << "   fibonacci(7) = " << fibonacci(7) << std::endl;

    // 7. 函数作用域
    int mainVar = 20;
    std::cout << "Main variable: " << mainVar << std::endl;
    testFunction();

    return 0;
}