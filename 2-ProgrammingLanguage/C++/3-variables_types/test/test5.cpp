#include <iostream>
int main() {
    // 不可修改：x和y的类型必须为int，值固定为7和3
    int x = 7, y = 3;
    
    double result = x / y;  
    
    // 不可修改：输出语句格式固定
    std::cout << "Result: " << result << std::endl;
    return 0;
}