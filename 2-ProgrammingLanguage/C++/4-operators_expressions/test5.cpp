#include <iostream>
#include <bitset>
using namespace std;

int main() {
    // 不可修改：变量初始值
    int a = 5;  // 二进制：0101
    int shift = 2;
    int result;

    result = a << shift;  

    // 不可修改：输出格式
    cout << "5 >> 2 = " << result << endl;  // 预期输出：5 >> 2 = 1
    return 0;
}