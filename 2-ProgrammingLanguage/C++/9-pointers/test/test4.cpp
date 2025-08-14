#include <iostream>
using namespace std;

void swap(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 10, y = 20;
    cout << "交换前：x=" << x << ", y=" << y << endl;
    swap(x, y);
    // 不可修改，期望输出：x=20, y=10
    cout << "交换后：x=" << x << ", y=" << y << endl;  
    return 0;
}