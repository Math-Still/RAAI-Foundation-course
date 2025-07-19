#include <iostream>
using namespace std;

int main() {
    // 不可修改：变量类型及初始值
    int a = 10;
    int b = 3;
    double result;

    result = a / b;  

    // 不可修改：输出格式
    cout << "10 / 3 = " << result << endl;  // 预期输出：10 / 3 = 3.33333
    return 0;
}