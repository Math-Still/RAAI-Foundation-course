#include <iostream>
int main() {
    // 不可修改：max_size必须声明为const int，初始值为100
    const int max_size = 100;
    
    max_size = 200;  
    
    // 不可修改：输出语句需打印100
    std::cout << "Max size: " << max_size << std::endl;
    return 0;
}