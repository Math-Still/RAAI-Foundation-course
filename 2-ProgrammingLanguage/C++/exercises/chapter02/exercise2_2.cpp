/*
 * 练习2.2：函数重载
 * 
 * 目标：
 * 1. 学习函数重载的语法
 * 2. 理解重载解析规则
 * 3. 练习不同类型的重载
 * 4. 了解const在重载中的作用
 */

#include <iostream>
#include <string>

// 重载函数：不同参数类型
int add(int a, int b) {
    std::cout << "调用 int add(int, int)" << std::endl;
    return a + b;
}

double add(double a, double b) {
    std::cout << "调用 double add(double, double)" << std::endl;
    return a + b;
}

// 重载函数：不同参数数量
int add(int a, int b, int c) {
    std::cout << "调用 int add(int, int, int)" << std::endl;
    return a + b + c;
}

// 重载函数：不同参数类型
std::string add(const std::string& a, const std::string& b) {
    std::cout << "调用 string add(string, string)" << std::endl;
    return a + b;
}

// 演示const重载
class String {
private:
    std::string data;
public:
    String(const std::string& str) : data(str) {}
    
    // const成员函数重载
    char& operator[](size_t index) {
        std::cout << "调用非const operator[]" << std::endl;
        return data[index];
    }
    
    const char& operator[](size_t index) const {
        std::cout << "调用const operator[]" << std::endl;
        return data[index];
    }
};

int main() {
    std::cout << "=== 函数重载练习 ===" << std::endl;
    
    // 测试不同类型的重载
    std::cout << "add(5, 3) = " << add(5, 3) << std::endl;
    std::cout << "add(5.5, 3.3) = " << add(5.5, 3.3) << std::endl;
    std::cout << "add(1, 2, 3) = " << add(1, 2, 3) << std::endl;
    std::cout << "add(\"Hello, \", \"World!\") = " << add("Hello, ", "World!") << std::endl;
    
    // 测试const重载
    String s("Hello");
    const String cs("World");
    
    s[0];       // 调用非const版本
    cs[0];      // 调用const版本
    
    std::cout << "=== 练习完成 ===" << std::endl;
    
    return 0;
} 