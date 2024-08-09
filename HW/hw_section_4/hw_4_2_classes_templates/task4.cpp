/*
В этой задаче вам надо будет написать свой дек. 
Писать его по-честному долго и сложно, поэтому мы пошли вам навстречу: 
вам нужно написать упрощенную версию дека без итераторов, 
и умеющую только добавлять элементы в начало и конец. 
Поддерживать удаление элементов из дека не требуется.

В отличие от стандартного дека возьмите за основу два вектора, 
растущих каждый в свою сторону. 
Предлагаем такой прототип — а вам нужно реализовать указанные функции:

#include <cstddef>
#include <vector>

template <typename T>
class Deque {
private:
    std::vector<T> head, tail;

public:
    bool Empty() const;

    size_t Size() const;

    void Clear();

    const T& operator [] (size_t i) const;

    T& operator [] (size_t i);

    const T& At(size_t i) const;  // throws std::out_of_range on incorrect index

    T& At(size_t i);  // throws std::out_of_range on incorrect index

    const T& Front() const;

    T& Front();

    const T& Back() const;

    T& Back();

    void PushFront(const T& elem);

    void PushBack(const T& elem);
};
*/
#include <cstddef>
#include <vector>
#include <stdexcept>

template <typename T>
class Deque {
private:
    std::vector<T> head, tail;

public:
    bool Empty() const {
        if (head.empty() && tail.empty()) {
            return true;
        }
        return false;
    }

    size_t Size() const {
        size_t size = head.size() + tail.size();
        return size;
    }

    void Clear() {
        head.clear();
        tail.clear();
    }

    const T& operator [] (size_t i) const {
        if (i < head.size()) {
            return head[head.size() - i -1];
        }
        return tail[i - head.size()];
    }

    T& operator [] (size_t i) {
        if (i < head.size()) {
            return head[head.size() - i -1];
        }
        return tail[i - head.size()];
    }

    const T& At(size_t i) const { // throws std::out_of_range on incorrect index
        if (i >= Size()) {
            throw std::out_of_range("Index is out of range!");
        }
        return (*this)[i];
    }  

    T& At(size_t i) {
        if (i >= Size()) { // throws std::out_of_range on incorrect index
            throw std::out_of_range("Index is out of range!");
        }
        return (*this)[i];
    }  

    const T& Front() const {
        if (head.empty()) {
            return tail.front();
        }
        return head.back();
    }

    T& Front() {
        if (head.empty()) {
            return tail.front();
        }
        return head.back();
    }

    const T& Back() const {
        if (tail.empty()) {
            return head.front();
        }
        return tail.back();
    }

    T& Back() {
        if (tail.empty()) {
            return head.front();
        }
        return tail.back();
    }

    void PushFront(const T& elem) {
        head.push_back(elem);
    }

    void PushBack(const T& elem) {
        tail.push_back(elem);
    }
};

int main() {
    Deque<int> dq;
    dq.PushBack(1);
    dq.PushBack(4);
    dq.PushFront(5);
    dq.Front();
}