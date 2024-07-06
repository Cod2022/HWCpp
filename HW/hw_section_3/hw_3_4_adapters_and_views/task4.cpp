/*
Вам надо написать функцию NextToken для выделения очередного токена в строке. 
Токеном считается последовательность символов 
до указанного символа-разделителя (или до конца строки).

Использоваться функция будет примерно так:

int main() {
    std::string_view sv = "Hello world and good bye";

    const char delimiter = ' ';
    std::string_view token;

    // Делим строку на токены по разделителю и перебираем эти токены:
    while (NextToken(sv, delimiter, token)) {
        // обрабатываем очередной token
        // например, печатаем его на экране:
        std::cout << token << "\n";
    }
}
Результатом выполнения такой программы будет

Hello
world
and
good
bye

Гарантируется, что входная строка не заканчивается на разделитель. 
Догадайтесь сами, какие аргументы должна принимать функция NextToken. 
Эта функция может менять первый аргумент (sv).
*/
#include <iostream>
#include <string>
#include <string_view>


bool NextToken(std::string_view& sv, char delimiter, std::string_view& token) {
    if (sv.empty()) {
        return false;
    }

    auto pos = sv.find(delimiter);
    if (pos != sv.npos) {
        token = sv.substr(0, pos);
        sv.remove_prefix(pos + 1);
    } else {
        token = sv;
        sv.remove_prefix(sv.size());
    }
    return true;
}

int main() {
    std::string_view sv = "Hello world and good bye!";
    char delimiter = ' ';

    std::string_view token;

    while (NextToken(sv, delimiter, token)) {
        std::cout << token << "\n";
    }    
}