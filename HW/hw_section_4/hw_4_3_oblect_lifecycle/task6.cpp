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

На вход поступает натуральное число n, не превосходящее 1000.
Формат вывода

Ваша программа должна каким-либо образом создать n объектов типа C, 
а затем уничтожить их в обратном порядке.
*/
#include "logger.h"
#include <list>
#include <iostream>

int main() {
    size_t n;
    std::list<Logger> v1;
    std::cin >> n;

    for (size_t i = 0; i != n; ++i) {
        v1.emplace_front();
    }
}