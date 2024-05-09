/*
В этой задаче нужно применить функцию std::lower_bound и итераторы 
для быстрого поиска ближайшего элемента в отсортированном массиве.
Формат ввода

В первой строке входных данных содержатся натуральные числа n и k, не превосходящие 100000. 
Во второй строке задаются целых n чисел первого массива, отсортированного по неубыванию, 
а в третьей строке – k целых чисел второго массива. 
Каждое число в обоих массивах по модулю не превосходит 2⋅1092⋅109. 
Второй массив, в отличие от первого, не отсортирован.
Формат вывода

Для каждого из k чисел выведите в отдельной строке число из первого массива, 
наиболее близкое к данному. Если таких несколько, выведите меньшее из них

Ввод
5 5
1 3 5 7 9 
2 4 8 1 6 

Вывод
1
3
7
1
5
*/
#include <iostream>
#include <vector>
#include <algorithm>

int NearestNum(const std::vector<int>& v, int num) {
        auto iter = std::lower_bound(v.begin(), v.end(), num);
        if (iter == v.end()) {
                return *std::prev(iter);
        } else if (iter == v.begin()) {
                return *iter;
        } else if (*iter == num) {
                return *iter;
        } else {
                int x1 = *std::prev(iter);
                int x2 = *iter;
                if (std::abs(x1 - num) <= std::abs(x2 - num)) {
                        return x1;
                } else {
                        return x2;
                }
        }
}

int main() {
    int m;
    int n;

    std::cin >> m >> n;

    std::vector<int> v1(m);
    std::vector<int> v2(n);
    
    for (int i = 0; i != m; ++i) {
            std::cin >> v1[i];
    }

    for (int i = 0; i != n; ++i) {
            std::cin >> v2[i];
            std::cout << NearestNum(v1, v2[i]);
    }
}
