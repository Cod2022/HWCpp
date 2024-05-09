/*
Вам даны строки текстового файла. Отсортируйте набор этих строк по убыванию.
Формат ввода

Количество строк не превосходит 1000. Каждая строка состоит из символов ASCII с кодами от 32 до 126, 
длина строки не превосходит 100.
Формат вывода

Напечатайте строки в отсортированном по убыванию порядке. 
Для сравнения строк друг с другом достаточно использовать стандартные операторы сравнения, 
определённые для std::string.
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    std::vector<std::string> words;
    std::string word;

    while (std::getline(std::cin, word)){
        words.push_back(word);
    }

    std::sort(words.rbegin(), words.rend());

    for (size_t i = 0; i != words.size(); ++i) {
        std::cout << words[i] << "\n";
    }
}