/*
Вам требуется написать функцию со следующим заголовком:

std::vector<std::string> Split(const std::string& str, char delimiter);

Функция должна вернуть вектор строк, полученный разбиением строки str на части 
по указанному символу-разделителю delimiter. 
Если разделитель встретился в начале или в конце строки str, то в начале (соответственно, в конце) 
вектора с результатом должна быть пустая строка. 
Если два разделителя встретились рядом, то пустая строка между ними тоже должна попасть в ответ. 
Для пустой строки надо вернуть пустой вектор.

Например, Split("What_is_your_name?", '_') должна вернуть вектор из строк What, is, your и name?.
*/

#include <string>
#include <vector>
#include <iostream>

std::vector<std::string> Split(const std::string& str, char delimiter) {
    std::vector<std::string> splittedStr;
    size_t i = 0;
    for (size_t j = 0; j != str.size(); ++j) {
        if (str[j] == delimiter) {
            splittedStr.push_back(str.substr(i, j - i));
            i = j + 1;
        }
    }
    splittedStr.push_back(str.substr(i));
    return splittedStr;
}

int main() {
    std::vector<std::string> result;
    std::string str = "_What_is_your_name?";
    char delimiter = '_';
    result = Split(str, delimiter);

    for (const auto& word : result) {
        std::cout << word << "\n";
    }
}

