/*
 * 练习3.1：指针基础
 * 
 * 目标：
 * 1. 学习指针的声明和初始化
 * 2. 理解指针的基本操作
 * 3. 练习指针和数组的关系
 * 4. 掌握指针的算术运算
 */

#include <iostream>

// 通过指针修改值
void modifyValue(int* ptr) {
    *ptr = 100;
}

// 通过指针返回多个值
void getMinMax(int arr[], int size, int* min, int* max) {
    *min = arr[0];
    *max = arr[0];
    
    for (int i = 1; i < size; i++) {
        if (arr[i] < *min) {
            *min = arr[i];
        }
        if (arr[i] > *max) {
            *max = arr[i];
        }
    }
}

// 返回指针
int* findElement(int arr[], int size, int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            return &arr[i];
        }
    }
    return nullptr;
}

int main() {
    std::cout << "=== 指针基础练习 ===" << std::endl;
    
    // 基本指针操作
    int number = 42;
    int* ptr = &number;
    
    std::cout << "number的值: " << number << std::endl;
    std::cout << "number的地址: " << &number << std::endl;
    std::cout << "ptr存储的地址: " << ptr << std::endl;
    std::cout << "ptr指向的值: " << *ptr << std::endl;
    
    // 通过指针修改值
    modifyValue(&number);
    std::cout << "修改后number的值: " << number << std::endl;
    
    // 指针和数组
    int arr[] = {5, 2, 8, 1, 9, 3};
    int size = 6;
    int* arrPtr = arr;
    
    std::cout << "\n通过指针访问数组:" << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << *(arrPtr + i) << " ";
    }
    std::cout << std::endl;
    
    // 指针算术运算
    std::cout << "\n指针算术运算:" << std::endl;
    std::cout << "原始指针: " << arrPtr << std::endl;
    arrPtr++;
    std::cout << "递增后指针指向的值: " << *arrPtr << std::endl;
    arrPtr--;
    std::cout << "递减后指针指向的值: " << *arrPtr << std::endl;
    
    // 通过指针返回多个值
    int min, max;
    getMinMax(arr, size, &min, &max);
    std::cout << "\n最小值: " << min << ", 最大值: " << max << std::endl;
    
    // 返回指针
    int* found = findElement(arr, size, 8);
    if (found != nullptr) {
        std::cout << "找到元素8，位置: " << (found - arr) << std::endl;
    } else {
        std::cout << "未找到元素8" << std::endl;
    }
    
    // 空指针
    int* nullPtr = nullptr;
    std::cout << "\n空指针: " << nullPtr << std::endl;
    
    std::cout << "=== 练习完成 ===" << std::endl;
    
    return 0;
} 