/*
Вам требуется написать функцию Join со следующим заголовком:

std::string Join(const std::vector<std::string>& tokens, char delimiter);

Функция должна вернуть строку, полученную склейкой элементов вектора через указанный разделитель. 
Например, Join({"What", "is", "your", "name?"}, '_') должна вернуть строку "What_is_your_name?".

Если вектор tokens пустой, то функция должна вернуть пустую строку. 
Если в векторе tokens ровно один элемент, то он и должен вернуться в ответе.

*/
#include <iostream>
#include <vector>
#include <string>

std::string Join(const std::vector<std::string>& tokens, char delimiter) {
    std::string result = "";

    if (tokens.empty()) {
        return result;
    }

    if (tokens.size() == 1) {
        result = tokens[0];
        return result;
    }

    for (size_t i = 0; i != tokens.size() - 1; ++i) {
        result += tokens[i];
        result += delimiter;
    }
    result += tokens.back();
    return result;
}

int main() {
    std::vector<std::string> tokens = {"What", "is", "your", "name?"};
    char delimiter = '_';
    std::string result = Join(tokens, delimiter);
    std::cout << result;

}