// 题目要求：
// 阅读以下代码，写出最终的输出结果。

#include <iostream>

inline int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int x = 10, y = 20;
    std::cout << max(x, y) << std::endl;
    return 0;
}
