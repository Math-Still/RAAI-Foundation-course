// 题目要求：
// 原函数为非递归形式的阶乘函数，请将其修改为递归形式，要求仅修改 factorial 函数体内的内容。

#include <iostream>

int factorial(int n) {
    int result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

int main() {
    std::cout << "5! = " << factorial(5) << std::endl;
    return 0;
}
