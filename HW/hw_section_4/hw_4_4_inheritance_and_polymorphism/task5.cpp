/*
Вам дан класс A, который в своих конструкторах и деструкторе печатает соответствующие сообщения, а так же main:

Вам требуется написать код класса B, чтобы функция main, работающая с этим классом, вывела бы следующие сообщения:

Constructor(int): 42
Destructor
*/
#include <iostream>

class A {
public:
    A(int x) {
        std::cout << "Constructor(int): " << x << "\n";
    }
    A(const A&) {
        std::cout << "Copy constructor\n";
    }
    virtual ~A() {
        std::cout << "Destructor\n";
    }
    virtual void foo() const = 0;
};

class B : public A {
public:
    B(): A(42) {}

    void foo() const override {}
};

int main() {
    B b;
    const A& a = b;
    a.foo();
}