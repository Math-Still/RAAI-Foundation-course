#include <iostream>
using namespace std;

int main() {
    int a = 100;
    int* p = a; 
    cout << "a的值：" << a << endl;
    cout << "a的地址：" << &a << endl;
    cout << "p存储的地址：" << p << endl;
    cout << "p指向的值：" << *p << endl;
    return 0;
}