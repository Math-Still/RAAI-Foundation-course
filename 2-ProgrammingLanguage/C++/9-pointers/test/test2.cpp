#include <iostream>
using namespace std;

//完成函数内部逻辑，能在主函数输出最大最小值
void func(int a, int b, int c, int* max, int* min)
{
    
}

int main() {
    int a = 10, b = 15, c = 22, max, min;
    func(a, b, c, &max, &min);

    //不可修改
    cout << "最大值: " << max << endl;  
    cout << "最小值: " << min << endl; 
    return 0;
}