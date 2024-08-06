/*
Вам требуется реализовать класс Queue, аналогичный адаптеру std::queue. 
Он является обёрткой над некоторым стандартным контейнером и реализует интерфейс очереди. 
Класс должен быть шаблонным. Первый шаблонный параметр T — тип хранимых элементов. 
Второй шаблонный параметр — контейнер, используемый для хранения элементов 
(по умолчанию — std::deque<T>):

template <typename T, typename Container = std::deque<T>>
class Queue;

Предусмотрите в классе следующее:

1.Конструктор по умолчанию, создающий пустую очередь.

2.Константную функцию front, которая возвращает элемент, стоящий в начале очереди.

3.Неконстантную функцию front, которая возвращает по ссылке элемент, стоящий в начале очереди — тем самым давая возможность его изменить.

4.Функцию pop, которая убирает элемент из начала очереди (и ничего не возвращает)

5.Функцию push, которая кладёт переданный элемент в конец очереди.

6.Функцию size, которая возвращает количество элементов.

7.Функцию empty, которая возвращает true тогда и только тогда, когда очередь пуста

8.Операторы == и != для сравнения двух очередей.
*/
#include <iostream>
#include <deque>

template <typename T, typename Container = std::deque<T>>
class Queue {
private:
    Container dq;

public:
    Queue() = default;

    const T& front() const {
        return dq.front();
    }

    T& front() {
        return dq.front();
    }
    void pop() {
        dq.pop_front();
    }

    void push(const T& elem) {
        dq.push_back(elem);
    }

    size_t size() {
        return dq.size();
    }

    bool empty() {
        if (dq.empty()) {
            return true;
        }
        return false;
    }
    bool operator == (const Queue& other) const {
        return dq == other.dq;
    }

    bool operator != (const Queue& other) const {
        return dq != other.dq;
    }
};

int main() {
    Queue<int> d;
    Queue<int> fl;
    d.push(7);
    d.push(8);
    fl.push(3);
    fl.push(8);
    // fl.push(3);
    // std::cout << d.front() << "\n";
    std::cout << d.size() << "\n";
    std::cout << fl.size() << "\n";
}