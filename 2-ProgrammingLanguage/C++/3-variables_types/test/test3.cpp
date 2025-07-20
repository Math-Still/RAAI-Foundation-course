#include <iostream>
int main() {
    unsigned short big_num = 500000;  // 不可修改存储的数值（500000）
    
    // 不可修改：输出语句需正确打印500000
    std::cout << "Big number: " << big_num << std::endl;
    return 0;
}