/*
Logger(): 1
Logger(): 2
...
Logger(): n
~Logger(): n
...
~Logger(): 2
~Logger(): 1

Формат ввода

На вход поступает натуральное число nn, не превосходящее 10001000.
Формат вывода

Ваша программа должна каким-либо образом создать nn объектов типа C, 
а затем уничтожить их в обратном порядке.
*/
#include "logger.h"
#include <list>
#include <iostream>

int main() {
    int n;
    std::list<Logger> v1;
    std::cin >> n;

    for (int i = 0; i != n; ++i) {
        v1.emplace_front();
    }
}