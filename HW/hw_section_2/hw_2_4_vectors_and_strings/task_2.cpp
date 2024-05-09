/*
Известный алгоритм Soundex определяет, похожи ли два английских слова по звучанию. 
На вход он принимает слово и заменяет его на некоторый четырёхсимвольный код. 
Если коды двух слов совпадают, то слова, как правило, звучат похоже.

Вам требуется реализовать этот алгоритм. Он работает так:

    Первая буква слова сохраняется.
    В остальной части слова буквы a, e, h, i, o, u, w и y удаляются;

    Оставшиеся буквы заменяются на цифры от 1 до 6, причём похожим 
    по звучанию буквам соответствуют одинаковые цифры:
        b, f, p, v: 1
        c, g, j, k, q, s, x, z: 2
        d, t: 3
        l: 4
        m, n: 5
        r: 6
    Любая последовательность идущих подряд одинаковых цифр сокращается до одной такой цифры.
    Итоговая строка обрезается до первых четырёх символов.
    Если длина строки получилась меньше четырёх символов, в конце добавляются нули.

Примеры:

ammonium → ammnm → a5555 → a5 → a500.

implementation → implmnttn → i51455335 → i514535 → i514
*/


#include <iostream>
#include <string>
 
void Append(std::string& res, char c) {
    if (res.back() != c) {
        res.push_back(c);
    }
}
 
std::string Soundex(const std::string& word) {
    std::string res;
    res.push_back(word[0]);
    for (size_t i = 1; i != word.size(); ++i) {
        char c = word[i];
        switch (c) {
            case 'b':
            case 'f':
            case 'p':
            case 'v':
                Append(res, '1');
                break;
            case 'c':
            case 'g':
            case 'j':
            case 'k':
            case 'q':
            case 's':
            case 'x':
            case 'z':
                Append(res, '2');
                break;
            case 'd':
            case 't':
                Append(res, '3');
                break;
            case 'l':
                Append(res, '4');
                break;
            case 'm':
            case 'n':
                Append(res, '5');
                break;
            case 'r':
                Append(res, '6');
                break;
        }
    }
    while (res.size() < 4) {
        res.push_back('0');
    }
    res.resize(4);
    return res;
}
 
int main() {
    std::string word;
    std::cin >> word;
    std::cout << Soundex(word) << "\n";
}