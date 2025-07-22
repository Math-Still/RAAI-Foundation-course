#include <iostream>
using namespace std;

int main() {
    int arr[] = { 1, 2, 3, 4, 5 };
    // 不可修改ptr的值
    int* ptr = arr + 2;  
   
    for (int i = 0; i < 5; i++) {  
        cout << *(ptr + i) << " ";
    }
    cout << endl;
    return 0;
}