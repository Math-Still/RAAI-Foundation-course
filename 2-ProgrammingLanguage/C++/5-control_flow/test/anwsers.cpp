// 各个题目的答案

void array_sum() {
    int numbers[] = {10, 20, 30, 40, 50};
    int sum = 0;
    for (int num : numbers) {
        sum += num;
    }
    std::cout << "数组元素的和是: " << sum << std::endl;
}

void day_of_week() {
    int day;
    std::cout << "请输入一个1-7之间的整数: ";
    std::cin >> day;
    switch (day) {
        case 1: std::cout << "星期一" << std::endl; break;
        case 2: std::cout << "星期二" << std::endl; break;
        case 3: std::cout << "星期三" << std::endl; break;
        case 4: std::cout << "星期四" << std::endl; break;
        case 5: std::cout << "星期五" << std::endl; break;
        case 6: std::cout << "星期六" << std::endl; break;
        case 7: std::cout << "星期日" << std::endl; break;
        default: std::cout << "无效输入" << std::endl;
    }
}

void grade_calculator() {
    int score;
    std::cout << "请输入成绩: ";
    std::cin >> score;
    if (score >= 90 && score <= 100) {
        std::cout << "A" << std::endl;
    } else if (score >= 80 && score <= 89) {
        std::cout << "B" << std::endl;
    } else if (score >= 70 && score <= 79) {
        std::cout << "C" << std::endl;
    } else if (score >= 60 && score <= 69) {
        std::cout << "D" << std::endl;
    } else if (score >= 0 && score <= 59) {
        std::cout << "F" << std::endl;
    } else {
        std::cout << "无效成绩" << std::endl;
    }
}

void positive_number_check() {
    int number;
    do {
        std::cout << "请输入一个正数: ";
        std::cin >> number;
        if (number <= 0) {
            std::cout << "输入无效，请重新输入" << std::endl;
        }
    } while (number <= 0);
    std::cout << "你输入的正数是: " << number << std::endl;
}

void print_even_numbers() {
    int i = 1;
    while (i <= 100) {
        if (i % 2 == 0) {
            std::cout << i << " ";
        }
        i++;
    }
    std::cout << std::endl;
}

void print_triangle() {
    int rows;
    std::cout << "请输入行数: ";
    std::cin >> rows;
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= i; j++) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}

void skip_numbers() {
    for (int i = 1; i <= 10; i++) {
        if (i == 3 || i == 8) {
            continue;
        }
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

void fix_program() {
    #include <iostream>


    // Number one修复
    constexpr int ival = 1;
    constexpr int minval = 0;
    int occurs = 0;
    if (ival < minval) {
        // 由于ival=1且minval=0，此条件永远不成立
        // 注意：如果要修改minval，必须去掉constexpr
        // minval = ival;  // 错误：constexpr变量不可修改
        occurs++;
    }
    std::cout << occurs << std::endl;  // 输出：0

    // Number two修复
    const unsigned val1 = 512, val2 = 1024, val3 = 4096;  // case标签需要常量表达式
    unsigned bufsize = 0;  // 初始化变量
    unsigned swt;
    std::cin >> swt;
    switch (swt) {
        case val1:  // 使用const变量作为case标签
            bufsize = val1 * sizeof(int);
            break;
        case val2:
            bufsize = val2 * sizeof(int);
            break;
        case val3:
            bufsize = val3 * sizeof(int);
            break;
        default:  // 添加default分支处理未预期的值
            std::cout << "Invalid input!" << std::endl;
            break;
    }

    // Number three修复
    int ix = 2;
    int sz = 1;
    for (; ix != sz; ++ix) {  // 修正for循环语法，添加初始化部分的分号
        // DO SOMETHING
        if (ix > 100) break;  // 防止无限循环的保护措施
    }
    
    // Number four修复
    int v1, v2;  // 将变量声明移到do-while循环外
    do {
        std::cout << "Please enter two numbers to sum:";
        if (std::cin >> v1 >> v2)
            std::cout << "Sum is: " << v1 + v2 << std::endl;
        else {
            std::cin.clear();  // 清除错误标志
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // 忽略缓冲区中的错误输入
        }
    } while (std::cin);  // 保持输入流检查

    return 0;
}