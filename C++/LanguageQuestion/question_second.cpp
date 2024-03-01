/**
 * @file question_second.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-01-26
 * 
 * @copyright Copyright (c) 2024
 * 
 */

 /*
 创建一个 C++ 程序，定义一个带有虚函数 calculateArea 的基类 Shape。
 从基类派生出两个类 Circle 和 Rectangle。在每个派生类中实现 calculateArea 函数，
 分别计算圆形和矩形的面积。在主函数中，创建两个派生类的实例，
 分别调用 calculateArea 函数，并显示结果。
 */

#include <iostream>
#define pi 3.14

class Shape {
public:
    virtual void calculateArea() {
    }
};

class Circle : public Shape {
public:
    void calculateArea(double r)
    {
        std::cout<<pi*r*r<<std::endl;
    }
};


class Rectangle : public Shape {
public:
    double a, b;
    void calculateArea(double a, double b)
    {
        std::cout << a*b << std::endl;
    }
};

int main() {
    Circle circle;
    Rectangle rectangle;
    double r, a, b;
    std::cin >> r >> a >> b;
    circle.calculateArea(r);
    rectangle.calculateArea(a,b);
}
