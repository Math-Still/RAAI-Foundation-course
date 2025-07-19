#include <iostream>
using namespace std;

int main() {
    // 不可修改：变量初始值
    int x = 2;      int y = 4;
    bool result;

    result = (x < 0) & (++y == 5);  

    // 不可修改：输出格式
    cout << "result = " << result << ", y = " << y << endl;  // 预期输出：result = 0, y = 4
    return 0;
}