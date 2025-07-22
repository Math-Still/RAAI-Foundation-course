#include <iostream>
using namespace std;

//可以增加函数形参，但不可以出现常量，需要完整打印数组，
void func(int *a)
{
    for(int i = 0; i < sizeof(a)/sizeof(a[0]); ++i) {
		cout << a[i] << " ";
	}
}
int main() {
	int arr[] = {1,2,3,4, 5, 6, 7, 8, 9, 10};
	func(arr);
    return 0;
}