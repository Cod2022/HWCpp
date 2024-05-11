/*
На вход подаётся скобочная последовательность — строка, которая состоит из скобок ()[]{}. 
Вам нужно определить, является ли она правильной. 
В правильной скобочной последовательности каждой открывающей скобке соответствует закрывающая 
и пары скобок корректно вложены друг в друга.
Формат ввода

Строка, состоящая из символов ()[]{}.
Формат вывода

Напечатайте YES, если скобочная последовательность является правильной, и NO в противном случае.
*/
#include <iostream>
#include <string>
#include <stack>

bool CorrectSequence(const std::string& bracketSequnce) {
    std::stack<char> openingBrackets;

    for (char bracket : bracketSequnce) {
        if (bracket == '[' || bracket == '{' || bracket == '(') {
            openingBrackets.push(bracket);
        } else {
            if (openingBrackets.empty()) {
                return false;
            }
            char top = openingBrackets.top();
            if ((top == '[' && bracket == ']') || (top == '{' && bracket == '}') || (top == '(' && bracket == ')')) {
                openingBrackets.pop();
            } else {
                return false;
            }
        }
    }

    return openingBrackets.empty();
}

int main() {
    std::string bracketSequence;
    std::getline(std::cin, bracketSequence);
    if (CorrectSequence(bracketSequence)) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
}