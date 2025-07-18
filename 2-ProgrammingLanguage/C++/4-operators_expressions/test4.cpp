#include <iostream>
using namespace std;

int main() {
    // 不可修改：变量初始值
    int a = 5;

    cout << "a自增后的值：" << a++ << endl;  

    // 不可修改：后续逻辑
    return 0;  // 预期输出：a自增后的值：6
}