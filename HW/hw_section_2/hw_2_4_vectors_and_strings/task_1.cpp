/*
Пароль от некоторого сервиса должен удовлетворять таким ограничениям:

    состоять из символов таблицы ASCII с кодами от 33 до 126;
    быть не короче 8 символов и не длиннее 14;
    из 4 классов символов — большие буквы, маленькие буквы, цифры, 
    прочие символы — в пароле должны присутствовать не менее трёх любых.

Напишите программу, которая проверит, что введённый пароль подходит под эти ограничения.
*/

#include <iostream>
#include <string>
 
bool IsValid(std::string password) {
    if (password.size() < 8 || password.size() > 14) {
        return false;
    }
    int upper = 0;
    int lower = 0;
    int digit = 0;
    int other = 0;
 
    for (char c : password) {
        if (c < 33 || c > 126) {
            return false;
        }
        if ('A' <= c && c <= 'Z') {
            upper = 1;
        } else if ('a' <= c && c <= 'z') {
            lower = 1;
        } else if ('0' <= c && c <= '9') {
            digit = 1;
        } else {
            other = 1;
        }
    }
 
    return upper + lower + digit + other >= 3;
}
 
int main() {
    std::string password;
    std::getline(std::cin, password);
    if (IsValid(password)) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
}