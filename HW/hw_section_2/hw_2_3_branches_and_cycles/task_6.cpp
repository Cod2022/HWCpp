/*
Вычислите сумму цифр неотрицательного целого числа.
*/
#include<iostream>

int main() {
    int num;
    int reminder;
    int res = 0;
    std::cin >> num;
    while (num != 0) {
        reminder = num % 10;
        res += reminder; 
        num = num / 10;
    }
    std::cout << res << "\n";
}