/*
Напишите функцию для вычисления наибольшего общего префикса строк, переданных в векторе words:

std::string CommonPrefix(const std::vector<std::string>& words);

Например, для пустого вектора функция должна вернуть пустую строку, 
а для вектора из строк "apple", "apricot" и "application" — строку "ap".
*/
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

std::string CommonPrefix(const std::vector<std::string>& words) {
    if (words.empty()) {
        return {};
    }

    std::string resPrefix;
    size_t minLen = words[0].size();

    for (const auto& word : words) {
        minLen = std::min(minLen, word.size());
    }

    for (size_t i = 0; i < minLen; ++i) {
        const char c = words[0][i];
        for (const auto& word : words) {
            if (word[i] != c) {
                return word.substr(0, i);
            }
        }
    }
    return words[0].substr(0, minLen);
}

int main() {
    std::vector<std::string> words = {"Hinj", "Hinjc", "Hinjcked", "hijk"};

    std::string resPrefix = CommonPrefix(words);
    std::cout << resPrefix;
   
}