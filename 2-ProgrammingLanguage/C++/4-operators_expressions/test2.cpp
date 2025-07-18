#include <iostream>
using namespace std;

int main() {
    // 不可修改：变量初始值
    int a = 5;
    int b = 3;

    a =+ b;  

    // 不可修改：输出格式
    cout << "a = " << a << endl;  // 预期输出：a = 8
    return 0;
}