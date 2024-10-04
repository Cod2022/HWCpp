/*
Вася хочет замерять время работы разных частей своей программы. 
Сейчас он делает это средствами стандартной библиотеки так:

#include <iostream>
#include <chrono>

#include "some_long_stuff.h"

void SomeFunc() {
    auto start1 = std::chrono::high_resolution_clock::now();
    FirstLongFunction();
    std::chrono::duration<double> diff1 = std::chrono::high_resolution_clock::now() - start1;
    std::cout << "FirstLongFunction elapsed: " << diff1.count() << "\n";

    auto start2 = std::chrono::high_resolution_clock::now();
    SecondLongFunction();
    std::chrono::duration<double> diff2 = std::chrono::high_resolution_clock::now() - start2;
    std::cout << "SecondLongFunction elapsed: " << diff2.count() << "\n";

    auto start3 = std::chrono::high_resolution_clock::now();
    ThirdLongFunction();
    std::chrono::duration<double> diff3 = std::chrono::high_resolution_clock::now() - start3;
    std::cout << "ThirdLongFunction elapsed: " << diff3.count() << "\n";
}

int main() {
    SomeFunc();
    return 0;
}

Но ему очень не удобно каждый раз прописывать начало замера и конец. 
Помогите ему сделать это удобнее.

Напишите обёртку TimerGuard. 
Это класс, который создается перед началом вычислений и при выходе из своего scope пишет в поток время работы, 
которое он существовал. С его помощью Вася сможет писать так:

#include <iostream>
#include <chrono>

#include "some_long_stuff.h"

void SomeFunc() {
    {
        TimerGuard timer("FirstLongFunction elapsed: ", std::cout);
        FirstLongFunction();
    }
    {
        TimerGuard timer("SecondLongFunction elapsed: ", std::cout);
        SecondLongFunction();
    }
    {
        TimerGuard timer("ThirdLongFunction elapsed: ", std::cout);
        ThirdLongFunction();
    }
}

int main() {
    SomeFunc();
    return 0;
}

Класс TimerGuard должен содержать следующий конструктор:

TimerGuard(std::string message = "", std::ostream& out = std::cout);

message — сообщение, печатаемое перед перед временем. out — поток, в который нужно печатать сообщение.

Деструктор класса должен печатать сообщение в формате "{message} {time}" (обратите внимание на пробел).
*/
#include <iostream>
#include <chrono>
#include <string>

class TimerGuard {
    
public:

    std::chrono::time_point<std::chrono::high_resolution_clock> start;
    std::string finalMessage;
    std::ostream& finalOut;

    TimerGuard(std::string message = "", std::ostream& out = std::cout): 
    finalOut(out) 
    {
        start = std::chrono::high_resolution_clock::now();
        finalMessage = message;
    }

    ~TimerGuard() {
        std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
        finalOut << finalMessage << diff.count() << "\n";
    }

};

void FirstLongFunction() {
        for (size_t i = 0; i != 100000; ++i) {
            std::cout << i << "\n";
        }
    }
void SomeFunc() {
    TimerGuard timer("FirstLongFunction elapsed: ", std::cout);
    // auto time = std::chrono::high_resolution_clock::now();
    FirstLongFunction();
    // std::chrono::duration<double> diff1 = std::chrono::high_resolution_clock::now() - time;
    // std::cout << "FirstLongFunction elapsed: " << diff1.count() << "\n";
}


int main() {

    SomeFunc(); 
}