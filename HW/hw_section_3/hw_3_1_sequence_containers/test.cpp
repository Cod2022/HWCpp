#include <iostream>
#include <string>
#include <list>

int main() {
    std::list<std::string> l = {"qwe", "sdf", "zxcvb", "jklo", "lpoiuyt"};

    auto begin = l.begin();
    auto end = l.begin();

    std::advance(end, 3);

    l.erase(std::next(begin), end);

    for (auto string : l) {
        std::cout << string << "\n";
    }
}