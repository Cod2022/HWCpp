/*
Требуется написать шаблонную функцию Duplicate, 
которая получает на вход вектор и дублирует все его элементы в конце вектора. 
Например, из вектора с элементами 1, 2, 3 должен получиться вектор с элементами 1, 2, 3, 1, 2, 3. 
Вася написал вот такую реализацию, которая почему-то не работает:

#include <vector>

template <typename T>
void Duplicate(std::vector<T>& v) {
    for (auto it = v.begin(); it != v.end(); ++it) {
        v.push_back(*it);
    }
}

Вам надо исправить код Васи.
*/
#include <vector>
#include <iostream>

template <typename T>
void Duplicate(std::vector<T>& v) {
    std::vector<T> duplicate;

    for (auto it = v.begin(); it != v.end(); ++it) {
        duplicate.push_back(*it);
    }

    for (auto it = duplicate.begin(); it != duplicate.end(); ++it) {
        v.push_back(*it);
    }
}

int main() {
    std::vector<int> v = {1, 2, 3};

    Duplicate(v);

    for (const auto& elem : v) {
        std::cout << elem << " ";
    }
}
/*
Решение

Решение Васи не работает, так как в процессе вставки итераторы вектора инвалидируются 
и программа попадает в неопределённое поведение. 
Самый простой способ исправить проблему — переписать цикл через индексы. 
При этом исходный размер вектора надо запомнить в начале цикла. 
Это можно сделать прямо в секции инициализации цикла for:

#include <vector>
 
template <typename T>
void Duplicate(std::vector<T>& v) {
    for (size_t n = v.size(), i = 0; i < n; ++i) {
        v.push_back(v[i]);
    }

}

Другой способ — зарезервировать в векторе заранее удвоенное число элементов. 
Тогда при вставке не будет происходить реаллокаций, и итераторы не будут инвалидироваться. 
Исходное решение заработает. Но его всё же удобнее переписать через алгоритм copy:

#include <algorithm>
#include <vector>
 
template <typename T>
void Duplicate(std::vector<T>& v) {
    v.reserve(v.size() * 2);
    std::copy(v.begin(), v.end(), std::back_inserter(v));
}
*/
