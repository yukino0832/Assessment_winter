/**
 * @file question_first.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-01-26
 * 
 * @copyright Copyright (c) 2024
 * 
 */
 /*
 编写一个 C++ 程序，其中包括一个带有私有 name（字符串）和 age（int）的 Person 类。
 实现一个参数化构造函数来初始化这些属性。添加一个成员函数 display，用于打印人的姓名和年龄。
 在主函数中，创建两个 Person 类实例，并使用 display 函数打印它们的信息。

 */

#include <iostream>
#include <string>

class Person {
    private:
    std::string name;
    int age;

    public:
    Person(const std::string& personName, int personAge){
        name = personName;
        age = personAge;
    }
    void display() const {
        std::cout << name << std::endl;
        std::cout << age << std::endl;
    }
};

int main() {
    Person person1("Furina",500);
    Person person2("LiuYing",26710);
    person1.display();
    person2.display();
}
