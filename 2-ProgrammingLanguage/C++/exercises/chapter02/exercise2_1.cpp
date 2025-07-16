/*
 * 练习2.1：函数定义和调用
 * 
 * 目标：
 * 1. 学习函数的基本语法
 * 2. 理解函数参数和返回值
 * 3. 练习函数重载
 * 4. 了解递归函数
 */

#include <iostream>
#include <string>

// 函数声明
int add(int a, int b);
double add(double a, double b);
int factorial(int n);
void printInfo(std::string name, int age);

// 函数定义
int add(int a, int b) {
    return a + b;
}

double add(double a, double b) {
    return a + b;
}

int factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

void printInfo(std::string name, int age) {
    std::cout << "Name: " << name << ", Age: " << age << std::endl;
}

int main() {
    std::cout << "=== 函数定义和调用练习 ===" << std::endl;
    
    // 测试整数加法
    int result1 = add(5, 3);
    std::cout << "add(5, 3) = " << result1 << std::endl;
    
    // 测试浮点数加法
    double result2 = add(5.5, 3.3);
    std::cout << "add(5.5, 3.3) = " << result2 << std::endl;
    
    // 测试阶乘函数
    int fact = factorial(5);
    std::cout << "factorial(5) = " << fact << std::endl;
    
    // 测试打印函数
    printInfo("Alice", 25);
    printInfo("Bob", 30);
    
    std::cout << "=== 练习完成 ===" << std::endl;
    
    return 0;
} 