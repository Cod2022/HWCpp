/*
Напишите программу, выводящую количество дней в месяце по заданному номеру месяца и году.
*/

#include<iostream>

int main() {
    int month, year;
    std::cin >> month >> year;
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
        std::cout << "31";
    } else if (month == 2) {
        if ((year % 400 == 0 || year % 100 != 0) && year % 4 == 0) {
        std::cout << "29";
    } else {
        std::cout << "28";
        }
    } else {
        std::cout << "30";
    }
}