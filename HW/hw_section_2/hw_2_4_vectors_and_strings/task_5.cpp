/*
Дана строка из строчных латинских букв и пробелов. 
Проверьте, является ли она палиндромом без учета пробелов.
Формат ввода

На вход подается одна строка. В строке могут быть пробелы. 
Подряд может идти произвольное число пробелов. Длина строки не превосходит 100.
Формат вывода

Представьте, что из строки удалили все пробелы. 
Необходимо вывести YES, если полученная строка — палиндром, и NO в противном случае
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    std::string s;
    std::getline(std::cin, s);
    s.erase(std::remove_if(s.begin(), s.end(), isspace), s.end());
    if(std::equal(s.begin(), s.begin() + s.size() / 2, s.rbegin())) {
        std::cout << "YES";
    } else {
        std::cout << "NO";
    }
}