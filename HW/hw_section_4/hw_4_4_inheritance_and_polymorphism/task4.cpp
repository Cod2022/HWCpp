/*
Реализуйте класс AdvancedVector. Продвинутый вектор отличается от обычного тем, что позволяет обращаться 
по отрицательным индексам к элементам вектора в обратном порядке ( прямо как в Python). 
Например, vec[-1] возвращает последний элемент, vec[-2] возвращает предпоследний и так далее.

Класс AdvancedVector должен хранить элементы шаблонного типа T. 
Требуемый функционал не сильно отличается от стандартного std::vector:

    Класс должен называться AdvancedVector.

    У класса должен быть шаблонный параметр T — тип элементов. +

    У класса должен быть конструктор по умолчанию. +

    У класса должен быть конструктор копирования (возможно, предоставленный компилятором).

    У класса должен быть шаблонный конструктор, принимающий два итератора и заполняющий вектор из данного диапазона.

    У класса должен быть оператор присваивания (возможно, предоставленный компилятором).

    У класса должны быть операторы сравнения == и !=. +

    У класса должны быть константные функции empty() и size(). +

    У класса должны быть функции pop_back() и push_back(const T&). +

    У класса должны быть константная и неконстантная версии оператора []. +

В случае положительного индекса нужно вернуть элемент с соответствующим индексом, если он меньше размера вектора. 
Иначе нужно бросить исключение std::out_of_range. 
В случае отрицательного индекса нужно вернуть элемент с соответствующим индексом, 
предполагая, что последний элемент имеет номер − 1, предпоследний − 2 и так далее. 
Но только пока модуль индекса не превосходит size(). 
Если же std::abs(index) > size, то нужно бросить исключение std::out_of_range.
*/
#include <iostream>
#include <vector>
#include <stdexcept>

template <typename T>
class AdvancedVector {
private:
    std::vector<T> data;

public:
    AdvancedVector() = default;

    AdvancedVector(const std::vector<T>& v) : data(v) {}

    bool empty() const {
        if (!data.empty()) {
            return false;
        }
        return true;
    }

    int size() const {
        return data.size();
    }

    void pop_back() {
        data.pop_back();
    }

    void push_back(const T& val) {
        data.push_back(val);
    }

    const T& operator [] (int index) const {
        if (std::abs(index) > data.size()) {
            throw std::out_of_range("Index is out of range!");
        }
        if (index < 0) {
            return data[data.size() + index];
        }
        return data[index];
    }

    T& operator [] (int index) {
        if (std::abs(index) > data.size()) {
            throw std::out_of_range("Index is out of range!");
        }
        if (index < 0) {
            return data[data.size() + index];
        }
        return data[index];
    }

    template <typename T2>
    bool operator == (const AdvancedVector<T2>& other) const {
        if (data.size() != other.size()) {
            return false;
        }
        for (size_t i = 0; i != data.size(); ++i) {
            if (!(data[i] == other[i])) {
                return false;
            }
        }
        return true;
    }

    template <typename T2>
    bool operator != (const AdvancedVector<T2>& other) {
        return !(*this == other);
    }
};

int main() {
    AdvancedVector<int> v({1, 2, 3, 4});
    //AdvancedVector<int> v2;
    AdvancedVector<int> v3({1, 2, 3, 4});

    // v.pop_back();
    // v.push_back(5);
    // v[0] = 8;
    // const int num = v[0];
    // v[-1] = 10;

    if (v == v3) {
        std::cout << "Equal\n";
    } 
    if (v != v3) {
        std::cout << "Not equal\n";
    }
    
    // std::cout << v.size() << "\n";
    // std::cout << v.empty() << "\n";
    // std::cout << v[-1] << "\n";
    // std::cout << num;
}