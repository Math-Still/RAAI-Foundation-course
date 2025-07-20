#include<iostream>
using namespace std;
int main(){
    int a = 1;	// 不可修改
    a = a++;      // 输出预期：2，实际输出：1
    cout<<a<<endl;
    
    a = 1;		// 不可修改
    a = ++a;      // 不可修改
    cout<<a<<endl;
    
    a = 1;		// 不可修改
    a += a++;     // 输出预期：3，实际输出：2
    cout<<a<<endl;
    
    a = 1;		// 不可修改
    a += ++a;     // 输出预期：4，实际输出：3
    cout<<a<<endl;
}