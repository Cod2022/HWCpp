/*
Напечатайте месяц из календаря по заданному начальному дню и количеству дней. 
Ваш ответ должен выглядеть примерно так:

                   1
 2  3  4  5  6  7  8
 9 10 11 12 13 14 15
16 17 18 19 20 21 22
23 24 25 26 27 28 29
30 31
*/
#include <iostream>
 
int main() {
    int n, k;
    std::cin >> n >> k;
 
    int dayOfWeek = n;
 
    for (int i = 1; i < n; ++i) {
        std::cout << "   ";
    }
 
    for (int day = 1; day <= k; ++day) {
        if (day < 10) {
            std::cout << " ";
        }
 
        std::cout << day;
 
        if (dayOfWeek == 7) {
            std::cout << "\n";
            dayOfWeek = 1;
        } else {
            std::cout << " ";
            dayOfWeek += 1;
        }
    }
 
    if (dayOfWeek != 1) {
        std::cout << "\n";
    }
}