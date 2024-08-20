/*
В предыдущей задаче вам был дан готовый класс Logger, 
который в своих конструкторах, операторах присваивания 
и деструкторе печатает соответствующие сообщения.

Вам требуется написать программу, которая работает с этим классом и выводит следующий текст:

Logger(): 1
Logger(): 2
Logger(): 3
~Logger(): 2
~Logger(): 3
~Logger(): 1

*/
#include "logger.h"
#include <utility>
#include <list>

int main() {
    std::list<Logger> container;
    Logger l1;
    container.emplace_back();
    Logger l3;
    container.pop_front();   
}