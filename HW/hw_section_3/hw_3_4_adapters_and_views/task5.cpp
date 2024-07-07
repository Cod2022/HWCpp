/*
Выведите k самых частотных слов текста и их частоты.
Формат ввода

В первой строке указано натуральное число k, не превосходящее 1000. 
Далее идут строки текста объёмом до 1 Mб. 
Слова в тексте разделены пробелами или переводами строк. 
Различать регистр и обрабатывать пунктуацию не нужно.

Формат вывода

В выводе должно быть не более k самых частотных слов текста. 
Через табуляцию после слова напечатайте его частоту. 
Слова должны быть упрядочены по убыванию частоты, а при равенстве частот — по алфавиту.

Пример
Ввод

3
to be or not to be
that is the question

Вывод

be	2
to	2
is	1
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
 
int main() {
    size_t k;
    std::cin >> k;
 
    std::unordered_map<std::string, int> words;
    std::string word;
    while (std::cin >> word) {
        ++words[word];
    }
 
    // std::vector<std::pair<std::string, int>> v(words.begin(), words.end());
    using FPair = std::pair<std::string, int>; // используем псевдоним для std::pair (более короткая запись)

    std::vector<FPair> v(words.begin(), words.end());
 
    std::partial_sort(
        v.begin(),
        v.begin() + std::min(v.size(), k), 
        v.end(),
        [](const auto& p1, const auto& p2) { return std::tie(p2.second, p1.first) < std::tie(p1.second, p2.first); }
    );
 
    for (size_t i = 0; i < k && i < v.size(); ++i) {
        const auto& [word, freq] = v[i];
        std::cout << word << "\t" << freq << "\n";
    }
}