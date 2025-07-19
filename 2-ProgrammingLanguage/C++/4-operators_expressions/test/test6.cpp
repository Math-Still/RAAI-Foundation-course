#include <iostream>
using namespace std;

int main() {
    // 不可修改：无变量，直接计算表达式
    int result;

    result = 10 + 20 % (3 * 2) - 1; 

    // 不可修改：输出格式
    cout << "10 + 20%3*2 - 1 的结果：" << result << endl;  // 预期输出：10 + (20%3)*2 -1 = 10+2*2-1=13
    return 0;
}