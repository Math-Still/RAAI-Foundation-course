// 题目要求：
// 下面程序中有两个 getArea 函数，请判断它们是否构成合法的重载，
// 并说明原因。若不合法，请改写其中一个函数的参数列表，使其合法重载。
#include <iostream>

int getArea(int length, int width) {
    return length * width;
}

double getArea(int x, int y) {
    return x * y * 1.0;
}

int main() {
    std::cout << getArea(5, 3) << std::endl;
    return 0;
}
