/*
В предыдущей задаче вам был дан готовый класс Logger, который в своих конструкторах, 
операторах присваивания и деструкторе печатает соответствующие сообщения.

Вам требуется написать программу, которая работает с этим классом и выводит следующий текст:

Logger(): 1
Logger(Logger&&): 2 1
~Logger(): 2
~Logger(): 1

*/
#include "logger.h"
#include <utility>

int main() {
    Logger l1;
    Logger l2 = std::move(l1);
}