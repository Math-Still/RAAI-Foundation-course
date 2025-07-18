#include <iostream>
int main() {
    float pi = 3.141592653589793;  // 不可修改存储的数值
    
    // 不可修改：输出语句固定
    std::cout << "Pi: " << pi << std::endl;  // 正确输出应接近3.141592653589793
    return 0;
}