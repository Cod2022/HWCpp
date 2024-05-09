/*
Будем называть символьной nn-граммой последовательность из nn последовательно идущих символов в одном слове в тексте. 
Для данного числа nn подсчитайте суммарное количество каждой nn-граммы в тексте.
Формат ввода

В первой строке заданы два числа: m — число слов в тексте (от 1 до 100000) 
и n — длина nn-граммы (от 1 до 5). Далее идет m слов. 
Можно считать, что слова отделены пробелами или переносами строк. 
Обработку пунктуации и регистра реализовывать не нужно. 
Читайте слова просто через std::cin >> word.
Формат вывода
Выведите все n-граммы, отсортированные по убыванию частоты, 
а в случае равных частот — лексикографически (по алфавиту). 
Для каждой n-граммы напечатайте также её частоту (смотрите формат в примере).
*/
#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>


int main() {
    
    size_t wordsNum;
    size_t nGramSize;
    std::cin >> wordsNum >> nGramSize;

    std::map<std::string, int> words;

    for (size_t  i = 0; i < wordsNum; ++i) {
        std::string word;
        std::cin >> word;
        for (size_t j = nGramSize; j <= word.size(); ++j) {
            ++words[word.substr(j - nGramSize, nGramSize)];
        }
    }

    std::vector<std::pair<std::string, int>> nrgams (words.begin(), words.end());

    std::sort(
        nrgams.begin(),
        nrgams.end(),
        [](const auto& ngram1, const auto& ngram2) {
            return std::tie(ngram2.second, ngram1.first) < std::tie(ngram1.second, ngram2.first);
        });

    
    for (const auto& [word, freq] : nrgams) {
        std::cout << word << " " << freq << "\n";
    }
}