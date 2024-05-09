/*
Вам надо написать функцию Print, которая умеет печатать в поток std::cout элементы переданного контейнера 
через указанную строку-разделитель. 
Первый аргумент функции — контейнер. 
Гарантируется, что по этому контейнеру можно проитерироваться 
с помощью стандартного цикла range-based for, и что элементы контейнера можно напечатать 
в поток std::cout с помощью стандартного оператора <<. 
Второй аргумент функции — строка-разделитель, которую надо печатать между элементами. 
В конце необходимо напечатать перевод строки \n.
*/

#include <iostream>
#include <vector>
#include <string>

template <typename T>
void Print(const T& container, const std::string& delimiter) {
    bool first = true;

    for (auto& elem : container) {
        if (!first){
            std::cout << delimiter;
        } else {
            first = false;
        }
        std::cout << elem;
    } 
    std::cout << "\n";
}

int main() {
    std::vector<int> v = {4, 5, 6, 7};

    Print(v, "_");
}

