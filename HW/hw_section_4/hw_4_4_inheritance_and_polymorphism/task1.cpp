/*
Вам надо написать базовый класс Figure (геометрическая фигура) 
и унаследованные от него классы Triangle (треугольник) и Rectangle (прямоугольник).

Класс Triangle должен иметь конструктор, 
принимающий на вход три числа типа int — стороны треугольника. 
Считайте, что треугольник с такими сторонами всегда существует.

Класс Rectangle должен иметь конструктор, 
принимающий на вход два числа типа int — стороны прямоугольника.

Класс Figure должен объвлять виртуальную функцию int Perimeter() const, 
возвращающую периметр фигуры.

Классы-наследники должны переопределить эту функцию правильным образом.

Функцию main писать в вашем коде не надо: она будет в нашей проверяющей программе. Наша программа выглядит так:

#include "figures.h"

#include <vector>
#include <iostream>

int main() {
    std::vector<Figure*> figures;

    std::string type;

    while (std::cin >> type) {
        if (type == "Triangle") {
            int a, b, c;
            std::cin >> a >> b >> c;
            figures.push_back(new Triangle(a, b, c));
        } else if (type == "Rectangle") {
            int a, b;
            std::cin >> a >> b;
            figures.push_back(new Rectangle(a, b));
        }
    }

    for (Figure* f : figures) {
        std::cout << f->Perimeter() << "\n";
    }

    for (Figure* f : figures) {
        delete f;
    }
}
*/
#include <iostream>

class Figure {
public:
    virtual int Perimeter() const = 0;

    virtual ~Figure() {
    }
};

class Triangle: public Figure {
private:
    int side1, side2, side3;

public:
    Triangle(int a, int b, int c): 
    side1(a),
    side2(b),
    side3(c)
    {
    }

    int Perimeter() const override {
        return side1 + side2 + side3;
    }
};

class Rectangle: public Figure {
private:
    int side1, side2, side3, side4;
    
public:
    Rectangle(int a, int b):
    side1(a),
    side2(b),
    side3(a),
    side4(b)
    {       
    }

    int Perimeter() const override {
        return side1 + side2 + side3 + side4;
    }
};

int main() {
    Triangle t(3, 5, 7);
    Rectangle r(9, 10);

    int res = t.Perimeter();
    int res2 = r.Perimeter();
    
    std::cout << res << "\n";
    std::cout << res2 << "\n";
}