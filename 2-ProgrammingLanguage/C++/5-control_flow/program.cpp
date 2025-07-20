#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

// 来自: 1. if 语句
void if_statement_example() {
    std::cout << "--- if_statement_example ---" << std::endl;
    int age = 18;

    // 简单的 if 语句
    if (age >= 18) {
        std::cout << "You are an adult." << std::endl;
    }

    // if-else 语句
    int score = 88;
    if (score >= 60) {
        std::cout << "Passed." << std::endl;
    } else {
        std::cout << "Failed." << std::endl;
    }

    // if-else if-else 语句
    if (age < 13) {
        std::cout << "You are a child." << std::endl;
    } else if (age < 18) {
        std::cout << "You are a teenager." << std::endl;
    } else if (age < 65) {
        std::cout << "You are an adult." << std::endl;
    } else {
        std::cout << "You are a senior." << std::endl;
    }
    std::cout << std::endl;
}

// 来自: 注意：悬垂 else 问题
void dangling_else_example() {
    std::cout << "--- dangling_else_example ---" << std::endl;
    int grade = 78; // 示例分数
    std::string lettergrade = "B"; // 示例等级

    std::cout << "Initial grade: " << grade << ", lettergrade: " << lettergrade << std::endl;

    // 错误示例：else 与最近的 if 匹配
    if (grade % 10 >= 3)
        if (grade % 10 > 7)
            lettergrade += '+';
        else // 这个 else 实际与 if(grade % 10 > 7) 配对
            lettergrade += '-';
    
    std::cout << "Final lettergrade (incorrect logic): " << lettergrade << std::endl;

    // 正确做法：使用大括号明确范围
    lettergrade = "B"; // 重置
    if (grade % 10 >= 3) {
        if (grade % 10 > 7) {
            lettergrade += '+';
        } else {
            lettergrade += '-';
        }
    }
    std::cout << "Final lettergrade (correct logic): " << lettergrade << std::endl;
    std::cout << std::endl;
}

// 来自: 2. switch 语句
void switch_statement_example() {
    std::cout << "--- switch_statement_example ---" << std::endl;
    int day = 3;
    switch (day) {
        case 1:
            std::cout << "Monday" << std::endl;
            break;
        case 2:
            std::cout << "Tuesday" << std::endl;
            break;
        case 3:
            std::cout << "Wednesday" << std::endl;
            break;
        case 4:
            std::cout << "Thursday" << std::endl;
            break;
        case 5:
            std::cout << "Friday" << std::endl;
            break;
        case 6:
        case 7: // 多个 case 共享同一代码块
            std::cout << "Weekend" << std::endl;
            break;
        default:
            std::cout << "Invalid day" << std::endl;
            break;
    }
    std::cout << std::endl;
}

// 来自: 3. 三元条件运算符 (?:)
void ternary_operator_example() {
    std::cout << "--- ternary_operator_example ---" << std::endl;
    int score = 85;
    std::string result = (score >= 60) ? "Passed" : "Failed";
    std::cout << "The result is: " << result << std::endl;
    std::cout << std::endl;
}

// 来自: 1. while 循环
void while_loop_example() {
    std::cout << "--- while_loop_example ---" << std::endl;
    int count = 0;
    while (count < 5) {
        std::cout << "Count: " << count << std::endl;
        count++;
    }
    std::cout << std::endl;
}

// 来自: 2. do-while 循环
void do_while_loop_example() {
    std::cout << "--- do_while_loop_example ---" << std::endl;
    int number;
    std::cout << "Enter a positive number: ";
    // 为避免程序阻塞，此处模拟用户输入
    number = 5; 
    std::cout << number << " (simulated input)" << std::endl;
    if (number <= 0) {
        std::cout << "Simulating entering a valid number on retry." << std::endl;
        number = 10;
    }
    std::cout << "You entered: " << number << std::endl;
    std::cout << std::endl;
}

// 来自: 3. for 循环
void for_loop_example() {
    std::cout << "--- for_loop_example ---" << std::endl;
    // 传统 for 循环
    std::cout << "Traditional for loop:" << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << "i = " << i << std::endl;
    }

    // 范围 for 循环遍历数组
    std::cout << "\nRange-based for loop with array:" << std::endl;
    int numbers[] = {1, 2, 3, 4, 5};
    for (int num : numbers) {
        std::cout << "num = " << num << std::endl;
    }
    
    // 范围 for 循环遍历 std::vector
    std::cout << "\nRange-based for loop with vector:" << std::endl;
    std::vector<int> my_vec = {1, 2, 3};
    int sum = 0;
    for (int n : my_vec) {
        sum += n;
    }
    std::cout << "Sum: " << sum << std::endl;
    std::cout << std::endl;
}

// 来自: 三、循环控制语句
void break_continue_example() {
    std::cout << "--- break_continue_example ---" << std::endl;
    // break 示例
    std::cout << "--- break example ---" << std::endl;
    for (int i = 0; i < 10; i++) {
        if (i == 5) {
            std::cout << "Breaking at i = 5" << std::endl;
            break; // 当 i 等于 5 时退出循环
        }
        std::cout << "i = " << i << std::endl;
    }

    // continue 示例
    std::cout << "\n--- continue example ---" << std::endl;
    for (int i = 0; i < 5; i++) {
        if (i % 2 != 0) {
            continue; // 跳过奇数，不打印
        }
        std::cout << "Even number: " << i << std::endl;
    }
    std::cout << std::endl;
}

// 来自: 1. 条件语句嵌套
void nested_conditional_example() {
    std::cout << "--- nested_conditional_example ---" << std::endl;
    int age = 20;
    bool has_license = false;

    if (age >= 18) {
        std::cout << "Age requirement met." << std::endl;
        if (has_license) {
            std::cout << "You can legally drive." << std::endl;
        } else {
            std::cout << "You need a driver's license to drive." << std::endl;
        }
    } else {
        std::cout << "You are not old enough to drive." << std::endl;
    }
    std::cout << std::endl;
}

// 来自: 2. 循环语句嵌套
void nested_loop_example() {
    std::cout << "--- nested_loop_example ---" << std::endl;
    for (int i = 1; i <= 9; ++i) {       // 外层循环控制行
        for (int j = 1; j <= i; ++j) { // 内层循环控制列
            std::cout << j << " * " << i << " = " << std::left << std::setw(2) << i * j << "  ";
        }
        std::cout << std::endl; // 每行结束后换行
    }
    std::cout << std::endl;
}

// 来自: 如何让程序“崩溃”（常见错误）
void common_errors_example() {
    std::cout << "--- common_errors_example ---" << std::endl;
    
    // 1. 无限循环 - 此部分已注释，以防程序挂起
    // std::cout << "1. Infinite loop (commented out to prevent hanging):" << std::endl;
    // while (true) { /* ... */ } 

    // 2. `switch` 中缺少 `break`
    std::cout << "2. Switch fallthrough:" << std::endl;
    int day = 1;
    switch (day) {
        case 1:
            std::cout << "Monday"; // 没有 break，会继续执行 case 2
        case 2:
            std::cout << "Tuesday";
            break;
    }
    std::cout << "\n" << std::endl;

    // 3. 逻辑错误：在 if 中使用赋值
    std::cout << "3. Assignment in if condition:" << std::endl;
    int x = 5;
    if (x = 10) { // x 被赋值为 10，条件永远为真
        std::cout << "x is 10 (x is now " << x << ")" << std::endl;
    }
    std::cout << std::endl;
}


int main() {
    if_statement_example();
    dangling_else_example();
    switch_statement_example();
    ternary_operator_example();
    while_loop_example();
    do_while_loop_example();
    for_loop_example();
    break_continue_example();
    nested_conditional_example();
    nested_loop_example();
    common_errors_example();

    return 0;
}