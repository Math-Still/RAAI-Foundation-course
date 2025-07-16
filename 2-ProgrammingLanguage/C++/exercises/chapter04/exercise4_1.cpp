/*
 * 练习4.1：类的基本概念
 * 
 * 目标：
 * 1. 学习类的定义和对象创建
 * 2. 理解访问修饰符的作用
 * 3. 练习构造函数和析构函数
 * 4. 掌握成员函数的使用
 */

#include <iostream>
#include <string>

// 定义一个简单的类
class Person {
private:
    // 私有成员变量
    std::string name;
    int age;
    
public:
    // 默认构造函数
    Person() : name(""), age(0) {
        std::cout << "默认构造函数被调用" << std::endl;
    }
    
    // 参数化构造函数
    Person(const std::string& n, int a) : name(n), age(a) {
        std::cout << "参数化构造函数被调用" << std::endl;
    }
    
    // 复制构造函数
    Person(const Person& other) : name(other.name), age(other.age) {
        std::cout << "复制构造函数被调用" << std::endl;
    }
    
    // 析构函数
    ~Person() {
        std::cout << "析构函数被调用: " << name << std::endl;
    }
    
    // 公有成员函数
    void setName(const std::string& n) {
        name = n;
    }
    
    void setAge(int a) {
        age = a;
    }
    
    std::string getName() const {
        return name;
    }
    
    int getAge() const {
        return age;
    }
    
    void display() const {
        std::cout << "姓名: " << name << ", 年龄: " << age << std::endl;
    }
};

// 计算器类
class Calculator {
private:
    double result;
    
public:
    // 构造函数
    Calculator() : result(0.0) {}
    
    Calculator(double initialValue) : result(initialValue) {}
    
    // 成员函数
    void setResult(double r) {
        result = r;
    }
    
    double getResult() const {
        return result;
    }
    
    void add(double value) {
        result += value;
    }
    
    void subtract(double value) {
        result -= value;
    }
    
    void multiply(double value) {
        result *= value;
    }
    
    void divide(double value) {
        if (value != 0) {
            result /= value;
        } else {
            std::cout << "错误：除数不能为零" << std::endl;
        }
    }
    
    void display() const {
        std::cout << "结果: " << result << std::endl;
    }
};

int main() {
    std::cout << "=== 类的基本概念练习 ===" << std::endl;
    
    // 创建Person对象
    std::cout << "\n--- Person类测试 ---" << std::endl;
    Person person1;
    person1.setName("Alice");
    person1.setAge(25);
    person1.display();
    
    Person person2("Bob", 30);
    person2.display();
    
    Person person3(person2);  // 复制构造
    person3.setName("Charlie");
    person3.display();
    
    // 创建Calculator对象
    std::cout << "\n--- Calculator类测试 ---" << std::endl;
    Calculator calc(10);
    calc.display();
    
    calc.add(5);
    calc.multiply(2);
    calc.subtract(3);
    calc.divide(4);
    calc.display();
    
    // 对象数组
    std::cout << "\n--- 对象数组测试 ---" << std::endl;
    Person students[3];
    students[0] = Person("张三", 20);
    students[1] = Person("李四", 22);
    students[2] = Person("王五", 21);
    
    std::cout << "学生信息:" << std::endl;
    for (int i = 0; i < 3; i++) {
        students[i].display();
    }
    
    std::cout << "=== 练习完成 ===" << std::endl;
    
    return 0;
} 