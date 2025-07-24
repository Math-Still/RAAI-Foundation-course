#include <iostream>
#include <string>

void greet(std::string name);  // 仅允许在此处添加默认参数

int main() {
    greet();          // 应输出 "Hello, World!"
    greet("Alice");   // 应输出 "Hello, Alice!"
    return 0;
}

void greet(std::string name) {
    std::cout << "Hello, " << name << "!" << std::endl;
}
