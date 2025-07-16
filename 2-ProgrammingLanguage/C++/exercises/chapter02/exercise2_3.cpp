/*
 * 练习2.3：数组基础
 * 
 * 目标：
 * 1. 学习数组的声明和初始化
 * 2. 理解多维数组的使用
 * 3. 练习数组作为函数参数
 * 4. 掌握数组的常见操作
 */

#include <iostream>
#include <algorithm>

// 打印数组
void printArray(int arr[], int size) {
    std::cout << "数组元素: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

// 查找最大值
int findMax(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// 查找最小值
int findMin(int arr[], int size) {
    int min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

// 计算平均值
double calculateAverage(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return static_cast<double>(sum) / size;
}

// 反转数组
void reverseArray(int arr[], int size) {
    for (int i = 0; i < size / 2; i++) {
        std::swap(arr[i], arr[size - 1 - i]);
    }
}

// 打印二维数组
void printMatrix(int matrix[][3], int rows) {
    std::cout << "矩阵:" << std::endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    std::cout << "=== 数组基础练习 ===" << std::endl;
    
    // 一维数组
    int numbers[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    
    std::cout << "原始数组:" << std::endl;
    printArray(numbers, size);
    
    // 查找最大值和最小值
    std::cout << "最大值: " << findMax(numbers, size) << std::endl;
    std::cout << "最小值: " << findMin(numbers, size) << std::endl;
    
    // 计算平均值
    std::cout << "平均值: " << calculateAverage(numbers, size) << std::endl;
    
    // 反转数组
    reverseArray(numbers, size);
    std::cout << "反转后:" << std::endl;
    printArray(numbers, size);
    
    // 二维数组
    int matrix[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };
    
    printMatrix(matrix, 2);
    
    // 字符数组
    char str[] = "Hello World";
    std::cout << "字符串: " << str << std::endl;
    std::cout << "字符串长度: " << strlen(str) << std::endl;
    
    std::cout << "=== 练习完成 ===" << std::endl;
    
    return 0;
} 