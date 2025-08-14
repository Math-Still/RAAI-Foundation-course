#include <iostream>
using namespace std;

int main() {
    int a = 211;
    // 不可修改
    const int* p = &a;  

    *p = 333;  
    cout << "a的值：" << a << endl;
    cout << "p指向的值：" << *p << endl;
    return 0;
}