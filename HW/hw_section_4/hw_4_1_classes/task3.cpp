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

    // унарный плюс (формально ничего не меняет)
    Rational operator + () const {
        return {numerator, denominator};
    }

    // унарный минус
    Rational operator - () const {
        return Rational(-numerator, denominator);
    }

    Rational& operator += (const Rational& rhs) {
        numerator = numerator * rhs.denominator + rhs.numerator;
        denominator *= rhs.denominator;
        Reduce();
        return *this;
    }

    Rational& operator -= (const Rational& rhs) {
        numerator = numerator * rhs.denominator - rhs.numerator * denominator;
        denominator *= rhs.denominator;
        Reduce();
        return *this;
    }

    Rational& operator *= (const Rational& rhs) {
        numerator *= rhs.numerator;
        denominator *= rhs.denominator;
        Reduce();
        return *this;
    }

    Rational& operator /= (const Rational& rhs) {
        int tmp = rhs.numerator;
        numerator *= rhs.denominator;
        denominator *= tmp;
        Reduce();
        return *this;
    }

    bool operator == (const Rational& rhs) {
        return numerator == rhs.numerator && denominator == rhs.denominator;
    }

    bool operator != (const Rational& rhs) {
        return !(numerator == rhs.numerator) && !(denominator == rhs.denominator);
    }
};

Rational operator + (const Rational& lhs, const Rational& rhs) {
    Rational result = lhs;
    result += rhs;
    return result;
}

Rational operator - (const Rational& lhs, const Rational rhs) {
    Rational result = lhs;
    result -= rhs;
    return result;
}

Rational operator * (const Rational& lhs, const Rational& rhs) {
    Rational result = lhs;
    result *= rhs;
    return result;
}

Rational operator / (const Rational& lhs, const Rational& rhs) {
    Rational result = lhs;
    result /= rhs;
    return result;
}






int main() {
    // int a = 5;
    // int b = -10;
    // int res = std::gcd(a, b);
    // int r = b / res;
    // std::cout << r;
    Rational r(6, 9);
    Rational b(6, 9);
    bool res = r == b;
    std::cout << res;
    // std::cout << r.GetNumerator() << "/" << r.GetDenominator();
}