/*
Вам надо написать свою реализацию стандартного алгоритма unique. Заголовок функции должен быть таким:

template <typename Iter>
Iter Unique(Iter first, Iter last);

Функция должна переупорядочить элементы диапазона [first; last) так, 
чтобы подряд идущие одинаковые элементы в ней не встречались. 
Функция возвращает итератор за последний элемент итоговой последовательности. 
Что останется в пределах от этого вернувшегося итератора до старого last — не важно. 
Время работы функции должно линейно зависеть от длины диапазона
*/
#include <vector>
#include <iostream>

template <typename Iter>
Iter Unique(Iter first, Iter last) {
    auto iter1 = first;
    auto iter2 = first;
    while (iter2 != last) {
        if (iter1 != iter2) {
            *iter1 = *iter2;
        }
        ++iter1;
        const auto& value = *iter2;
        while (iter2 != last && *iter2 == value) {
            ++iter2;
        }
    }
    return iter1;
}

int main() {
    std::vector<int> v = {1, 1, 1, 2, 2, 3, 3, 4, 4, 4, 5, 5, 5};
    std::vector<int> l;
}


