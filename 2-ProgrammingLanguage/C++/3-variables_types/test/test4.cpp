#include <iostream>
int main() {
    char grade{ "A" };  // 不可修改变量类型为char，不可修改使用{}初始化
    
    // 不可修改：输出语句需打印字符'A'
    std::cout << "Grade: " << grade << std::endl;
    return 0;
}