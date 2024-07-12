/*
Напишите класс Rational (рациональное число). 
Конструктор класса должен получать на вход два числа типа int (числитель и знаменатель). 
Считайте, что по умолчанию числитель равен 0, а знаменатель — 1.

Переопределите бинарные операторы сложения, вычитания, 
умножения и деления (работающие в том числе и с аргументами типа int), 
унарные плюс и минус. 
Предусмотрите функции-члены Numerator и Denominator 
для получения числителя и знаменателя несократимого представления 
этой дроби (знаменатель должен быть положительным). 
Переопределите также операторы +=, -=, *= и /=. Не забудьте определить операторы == и !=.
*/
#include <numeric>
#include <iostream>

class Rational {
private:
    int numerator{0};
    int denominator{1};

    void Reduce() {
        int divisor = std::gcd(numerator, denominator);
        numerator /= divisor;
        denominator /= divisor;
        if (denominator < 0) {
            numerator *= -1;
            denominator *= -1;
        }
    }

public:
    Rational(int n, int d) {
        numerator = n;
        denominator = d;
        Reduce();
    }
    Rational() = default;

    int GetNumerator() {
        return numerator;
    }

    int GetDenominator() {
        return denominator;
    }
};

int main() {
    // int a = 5;
    // int b = -10;
    // int res = std::gcd(a, b);
    // int r = b / res;
    // std::cout << r;
    Rational r(6, 9);
    std::cout << r.GetNumerator() << "/" << r.GetDenominator();

}