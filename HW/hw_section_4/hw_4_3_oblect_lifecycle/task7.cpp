/*
В предыдущей задаче вам был дан готовый класс Logger, 
который в своих конструкторах, 
операторах присваивания и деструкторе печатает соответствующие сообщения.

Вам требуется написать программу, 
которая работает с этим классом и выводит по заданному nn следующий текст:

Logger(): 1
Logger(): 2
...
Logger(): n
~Logger(): 1
~Logger(): 2
...
~Logger(): n
*/
#include "logger.h"
#include <list>
#include <iostream>

int main() {
    size_t n;
    std::list<Logger> v1;
    std::cin >> n;

    for (size_t i = 0; i != n; ++i) {
        v1.emplace_back();
    }
}