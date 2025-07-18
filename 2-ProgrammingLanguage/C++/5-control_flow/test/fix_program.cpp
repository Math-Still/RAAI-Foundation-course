#include <iostream>

int main() {
    /*
    题目描述
    修复程序中的错误，使程序能够正常运行或者结果符合预期。

    题目要求
    修复错误：根据错误提示修复程序中的错误。
    */

    // Number one
    // 修改程序，使得occurs输出为 0，并无语法错误
    constexpr int ival = 1;
    constexpr int minval = 0;
    int occurs = 0;
    if (ival < minval)
        minval = ival;
        occurs++; 
    std::cout << occurs << std::endl;

    // Number two
    // 修改程序，使其编译通过
    unsigned val1 = 512, val2 = 1024, val3 = 4096;
    unsigned bufsize;
    unsigned swt;
    std::cin >> swt;
    switch (swt) {
        case val1:
            bufsize = val1 * sizeof(int);
            break;
        case val2:
            bufsize = val2 * sizeof(int);
            break;
        case val3:
            bufsize = val3 * sizeof(int);
            break;
    }

    // Number three
    // 修改程序, 使程序可以通过编译并能正常停止
    int ix = 2;
    int sz = 1;
    for (ix != sz;++ix) {
        // DO SOMETHING
    }
    
    // Number four
    // 更正下面程序的错误
    do
        int v1,v2;
        cout << "Please enter two numbers to sum:";
        if (cin >> v1 >> v2)
            cout << "Sum is: " << v1 + v2 << std::endl;
    while (cin);

    return 0;
}