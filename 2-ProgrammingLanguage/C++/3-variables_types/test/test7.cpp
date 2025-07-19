#include <iostream>
int main() {
    // 外部块
    int outer_var = 10;
    std::cout << "Outer var: " << outer_var << std::endl;
    
    {
        // 内部块（不可修改inner_var的声明位置）
        int inner_var = 20;
        std::cout << "Inner var (inside): " << inner_var << std::endl;
    }
    
    std::cout << "Inner var (outside): " << inner_var << std::endl;      
    return 0;
}