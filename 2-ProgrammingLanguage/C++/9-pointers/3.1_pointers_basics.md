# 3.1 指针基础

> 原文：[C++ Pointers](https://en.cppreference.com/w/cpp/language/pointer)

> 译者：RAAI学习团队

指针是C++中最强大但也最复杂的特性之一。指针是一个变量，它存储另一个变量的内存地址。通过指针，我们可以直接访问和操作内存，这使得C++能够进行底层编程。

## 指针的基本概念

### 什么是指针

在日常生活中，我们都有过取快递的经历。每个快递都有一个独一无二的取件码，比如`20-2-3`，这个取件码就像是快递的 “地址”，帮助我们准确找到对应的包裹。而变量就像是贴在快递上的标签，例如变量名`a`，它指向的是快递包裹里的具体物品。

在计算机的世界里，当我们写下`int a = 211;`这样的代码时，其实是在计算机的栈内存中申请了一块 4 字节大小的空间。然后，数值 211 会被转换为二进制形式，存储在这个申请到的内存位置中。变量`a`就相当于这个内存位置的标签，通过它我们可以访问和操作存储在其中的数据。

### 指针的声明和初始化

```cpp
#include <iostream>
using namespace std;

int main()
{
	int a = 211;
	int* p = &a;
	cout << "Value of a: " << a << endl;
	cout << "Address of a: " << &a << endl;
	cout << "Value of p: " << p << endl;
	cout << "Value pointed to by p: " << *p << endl;
}
```

**你会看到以下输出**

```bash
Value of a: 211
Address of a: 000000448FCFFB84
Value of p: 000000448FCFFB84
Value pointed to by p: 211
```

关系可以这么想象，这里有一枚硬币，正面就是`p`和`&a`，反面就是`*p`和`a`，也就是说`p`和`&a`等价，`*p`和`a`等价。

![1](.\static\1.jpg)

> [!NOTE]
>
> 64位系统中指针的大小为8字节，32位系统中指针的大小为4字节

### 指针的基本操作

```cpp
#include <iostream>

void func1(int a, int b)
{
    int t = a;
    a = b;
    b = t;
    std::cout << "func1函数内: a = " << a << ", b = " << b << std::endl;
}
void func2(int *a,int *b) {
    int t = *a;
	*a = *b;
    *b = t;
	std::cout << "func2函数内: a = " << *a << ", b = " << *b << std::endl;
}

int main() {
    int x = 10;
    int y = 20;
	func1(x, y);
	std::cout << "func1调用后: x = " << x << ", y = " << y << std::endl;
	func2(&x, &y);
	std::cout << "func2调用后: x = " << x << ", y = " << y << std::endl;
    return 0;
}
```

**你会看到以下输出**

```bash
func1函数内: a = 20, b = 10
func1调用后: x = 10, y = 20
func2函数内: a = 20, b = 10
func2调用后: x = 20, y = 10
```

为什么呢？

在第一个函数调用中，我们称之为**值传递**，即当使用值传递时，函数的形参其实是实参的一份拷贝。这意味着在函数内部对形参进行任何修改，都不会影响到函数外部的实参。

而在第二个函数调用中，我们称之为**地址传递**，这时候函数的形参是指向实参**内存地址**的指针。通过这个指针，在函数内部可以直接对实参进行修改。

## 空指针

```cpp
#include <iostream>

int main() {
    // 空指针的几种表示方法
    int* ptr1 = nullptr;  // C++11推荐
    int* ptr2 = NULL;     // C风格
    int* ptr3 = 0;        // 字面量0
    
    std::cout << "ptr1: " << ptr1 << std::endl;
    std::cout << "ptr2: " << ptr2 << std::endl;
    std::cout << "ptr3: " << ptr3 << std::endl;
    
    // 检查空指针
    if (ptr1 == nullptr) {
        std::cout << "ptr1是空指针" << std::endl;
    }
    
    // 危险：解引用空指针
    // std::cout << *ptr1 << std::endl;  // 未定义行为
    
    return 0;
}
```

**你会看到以下输出**

```bash
ptr1: 0000000000000000
ptr2: 0000000000000000
ptr3: 0000000000000000
ptr1是空指针
```

## C++内存分配

这里我们介绍一下**栈内存**和**堆内存**。

如果你定义基本数据类型时，例如`int a = 211;`，那么系统会自动在栈内存中分配4字节大小的空间给`a`，但栈内存空间很小。

如果你申请空间，例如`int p = new int (211)`，那么系统会在栈内存中开辟8字节空间来存储指针，并且在堆内存中分配4字节来存储`211`这个整数，堆内存的大小取决于物理内存。

```cpp
#include <iostream>
using namespace std;	
int main()
{
	int* p = new int(211);
	cout << "p: " << p << endl;  
	cout << "*p: " << *p << endl; 
	delete p;  
	cout << "p after delete: " << p << endl; 
	cout << "*p after delete: " << *p << endl; 
}
```

运行以上程序，你会发现程序输出很奇怪，在windows中会直接崩溃，在linux中会出现奇怪的数字。

```bash
p: 0x58eac238aeb0
*p: 211
p after delete: 0x58eac238aeb0
*p after delete: -1901321334
```

这是因为产生了**野指针**，当我们将申请的空间释放之后，因为指针是存储在栈内存中的，所以还是指向原来的地址，但是因为已经被释放了，原先存储的值不复存在，就会产生奇奇怪怪的数值。

要解决上述问题，需要在`delete`之后，将指针置空，即`p = nullptr` ，并删除`cout << "*p after delete: " << *p << endl; `

## 用const指针

1. **常量指针：不能通过解引用的方法来修改存储空间中的值，但是用原变量名是可以的**

   ```cpp
   #include <iostream>
   using namespace std;	
   int main()
   {
   	int a = 211;
   	const int* p = &a;  // p是指向常量的指针，不能通过p修改a的值
   	cout << "a的值: " << a << endl;
   	cout << "p指向的值: " << *p << endl;
   	*p = 222;  	
   }
   ```

   运行这个程序，你会发现程序出错了

   ```bash
   demo2.cpp: In function ‘int main()’:
   demo2.cpp:11:12: error: assignment of read-only location ‘* p’
      11 |         *p = 222;
         |         ~~~^~~~~
   ```

2. 指针常量（指针在定义的时候必须初始化，指向的变量不可以改变）

   ```cpp
   #include <iostream>
   using namespace std;	
   int main()
   {
   	int a = 211;
   	int* const p = &a;  // p是指向常量的指针，不能通过p修改a的值
   	cout << "a的值: " << a << endl;
   	cout << "p指向的值: " << *p << endl;
   	int b = 222;
   	p = &b;
   }
   ```

   运行这个程序，你会发现程序出错了

   ```bash
   demo2.cpp: In function ‘int main()’:
   demo2.cpp:10:11: error: assignment of read-only variable ‘p’
      10 |         p = &b;
         |         ~~^~~~
   ```

3. 常指针常量（结合常量指针和指针常量）

   ```cpp
   #include <iostream>
   using namespace std;	
   int main()
   {
   	int a = 211;
   	const int * const p = &a;  
   	cout << "a的值: " << a << endl;
   	cout << "p指向的值: " << *p << endl;
   	int b = 222;
   	p = &b;
   	*p = 33;
   }
   ```

   运行这个程序，你会发现程序出错了

   ```bash
   demo2.cpp: In function ‘int main()’:
   demo2.cpp:6:19: error: duplicate ‘const’
       6 |         const int const * p = &a;
         |                   ^~~~~
         |                   -----
   demo2.cpp:11:12: error: assignment of read-only location ‘* p’
      11 |         *p = 33;
         |         ~~~^~~~
   ```

## 指针和数组

### 一维数组和指针

数组是连续内存块，存储相同类型的元素

```cpp
#include <iostream>

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int* ptr = arr;  // 数组名是指向第一个元素的指针
    
    std::cout << "通过数组访问:" << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    
    std::cout << "通过指针访问:" << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << *(ptr + i) << " ";
    }
    std::cout << std::endl;
    
    std::cout << "通过指针下标访问:" << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << ptr[i] << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
```

运行以上程序，结果如下

```bash
通过数组访问:
1 2 3 4 5
通过指针访问:
1 2 3 4 5
通过指针下标访问:
1 2 3 4 5
```

在这里，数组名`arr`其实就是地址名，我们可以修改一下这个程序

```cpp
#include <iostream>

int main() {
    int arr[] = { 1, 2, 3, 4, 5 };
    int* ptr = arr+1;  

    std::cout << "通过指针访问:" << std::endl;
    for (int i = 0; i < 4; i++) {
        std::cout << *(ptr + i) << " ";
    }
    std::cout << std::endl;

    std::cout << "通过指针下标访问:" << std::endl;
    for (int i = 0; i < 4; i++) {
        std::cout << ptr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
```

运行以上程序，结果如下

```bash
通过数组访问:
1 2 3 4 5
通过指针访问:
2 3 4 5
通过指针下标访问:
2 3 4 5
```

我们看到，当`ptr + 1`时，地址并不是`+1`，而是增加了一个`int`类型的大小，这是由数组类型决定的，并且我们看到，当`i = 0`时，并没有输出`1`，而是输出`2`，这是因为我们将首地址改成了`arr[1]`，也就输出`2`了。说明指针是可以进行算数运算的。

### 二维数组和指针

我们在尝试访问二维数组时，需要用到一个**行指针**，是这样定义的`int (*row_ptr)[3] = arr;`。

```cpp
#include <iostream>
using namespace std;

int main() {
    int arr[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    cout << "使用数组下标访问:" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\n使用行指针访问:" << endl;
    int (*row_ptr)[3] = arr;  
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            cout << *(*(row_ptr + i) + j) << " ";  
        }
        cout << endl;
    }
    return 0;
}
```

运行以上程序，结果如下

```bash
使用数组下标访问:
1 2 3
4 5 6

使用行指针访问:
1 2 3
4 5 6
```

更高维的就不在这里赘述了，大家感兴趣自行学习就好。

## 函数指针和回调函数

当有人来借我们实验室的设备时，我们需要先检查设备是否损坏，再根据他人的需要，借出相应的设备，在送回时需要检查设备情况。如果需要你完成这个任务，你会怎么做？

我们注意到，有两个任务是我们必须要做的，在借出和送回之前都要检查设备的情况。我们可以设置一个回调函数，将一段可执行代码作为参数传递给其他代码，在适当的时候执行。在这里，我们可以将每个人具体借设备情况作为一段可执行代码写入整体流程中。

函数指针的声明方法`返回类型 (*指针名)(参数列表);` ，

```cpp
#include <iostream>
using namespace std;

void zs()
{
	cout << "我需要一个树莓派" << endl;
}

void ls()
{
	cout << "我需要一个JetBot小车" << endl;
}

void lend(void(*pf)())
{
	cout << "借出时设备检查良好" << endl;
	pf();
	cout << "送回时设备检查良好" << endl;
}
int main()
{
	lend(zs);
	lend(ls);
}
```

上述代码的执行结果

```bash
借出时设备检查良好
我需要一个树莓派
送回时设备检查良好
借出时设备检查良好
我需要一个JetBot小车
送回时设备检查良好
```

## 指针的常见错误

### 1. 未初始化的指针

```cpp
int main() {
    int* ptr;  // 未初始化
    // std::cout << *ptr << std::endl;  // 未定义行为
    return 0;
}
```

### 2. 悬空指针

```cpp
int main() {
    int* ptr = new int(42);
    delete ptr;
    // std::cout << *ptr << std::endl;  // 悬空指针
    ptr = nullptr;  // 正确的做法
    return 0;
}
```

### 3. 类型不匹配

```cpp
int main() {
    int number = 42;
    double* ptr = &number;  // 类型不匹配
    return 0;
}
```

## 外部研究

对于这个练习，你需要：

1. 查找C++中指针的所有语法规则
2. 了解智能指针的用法
3. 研究指针和引用的区别
4. 学习C++11引入的指针特性

## 下一节

下一节我们将学习[指针运算](3.2_pointer_arithmetic.md)。 