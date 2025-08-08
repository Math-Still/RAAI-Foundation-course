#include <iostream>
#include <string>

// 1. output.cpp 的输出结果
// 阅读代码，输出结果为 20，因为 max(10, 20) 返回 20

// 2. is_leagle.cpp - 判断是否合法重载
// 原函数不构成合法重载，因为两个 getArea 函数参数列表完全相同（都是 int, int），仅返回类型不同。
// 修改：将第二个函数的参数改为 double 类型，使其合法。
int getArea(int length, int width) {
    return length * width;
}

double getArea(double x, double y) {
    return x * y;
}

// 3. fix_program01.cpp - 添加默认参数
void greet(std::string name = "World");  // 添加默认参数

void greet(std::string name) {
    std::cout << "Hello, " << name << "!" << std::endl;
}

// 4. factorial.cpp - 修改为递归形式
int factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

// 5. convert.cpp - 实现温度转换函数
double celsiusToFahrenheit(double celsius) {
    return celsius * 1.8 + 32;
}

int main() {
    // 测试各个部分
    std::cout << "1. output.cpp result: 20" << std::endl;

    std::cout << "2. getArea(5, 3): " << getArea(5, 3) << std::endl;
    std::cout << "   getArea(5.0, 3.0): " << getArea(5.0, 3.0) << std::endl;

    std::cout << "3. greet(): ";
    greet();
    std::cout << "   greet(\"Alice\"): ";
    greet("Alice");

    std::cout << "4. factorial(5): " << factorial(5) << std::endl;

    std::cout << "5. 0C to F: " << celsiusToFahrenheit(0) << std::endl;

    return 0;
}