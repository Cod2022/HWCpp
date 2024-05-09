/*
На вход подаётся последовательность целых чисел. 
Для каждого числа выведите в отдельной строке слово YES, 
если это число ранее встречалось в последовательности, и NO, если не встречалось.
Формат ввода

Вводится список чисел. 
Все числа списка находятся на одной строке и разделены пробелом. 
Каждое число представимо типом int.
*/
#include <iostream>
#include <list>
#include <map>

int main() {
    int num;
    std::list<int> nums;
    std::map<int, int> sequence;

    while (std::cin >> num) {
        nums.push_back(num);
    }

    for (int num : nums) {
        ++sequence[num];
        if (sequence[num] > 1) {
            std::cout << "YES" << "\n";
        } else {
            std::cout << "NO" << "\n";
        }
    }
}