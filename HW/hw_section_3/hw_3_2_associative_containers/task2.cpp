/*
Вам даны слова. Выведите в алфавитном порядке список общих букв всех слов.
Формат ввода

На вход поступают слова (по одному в строке), состоящие из маленьких латинских букв алфавита. 
Длина слов не превосходит 100 символов, а количество слов не превосходит 1000.
Формат вывода

Выведите в алфавитном порядке без пробелов список букв, которые присутствуют в каждом слове.
*/
#include <iostream>
#include <string>
#include <map>
#include <set>

int main() {
    std::map<char, int> counter;
    std::string word;
    int wordsCount = 0;
    while (std::cin >> word) {
        ++wordsCount;
        std::set<char> letters(word.begin(), word.end());
        for (char c : letters) {
            ++counter[c];
        }
    }
    for (auto [c, freq] : counter) {
        if (freq == wordsCount) {
            std::cout << c;
        }
    }
    std::cout << "\n";
}