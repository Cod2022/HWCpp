/*
Вы работаете с иерархией классов, описывающих животных:
Вам нужно определить тип Zoo, представляющий из себя набор 
различных животных, и написать две функции: Zoo CreateZoo() 
и void Process(const Zoo& zoo).

Функция CreateZoo должна читать слова из стандартного ввода. 
Если на вход поступают слова Tiger, Wolf или Fox, 
она должна поместить соответствующего зверя в зоопарк. 
Если на вход поступает другое слово, она должна прекратить 
чтение и сгенерировать исключение std::runtime_error.

Функция Process должна перебрать всех зверей в зоопарке 
в порядке создания и напечатать для каждого из них результат 
работы виртуальной функции Voice.

Ваш коллега написал вот такой код, но он почему-то не работает:
*/
#include <string>
#include <iostream>
#include <vector>
#include <memory>

class Animal {
public:
    virtual std::string Voice() const {
        return "Not implemented yet";
    }
    virtual ~Animal() {}
};

class Tiger: public Animal {
    std::string Voice() const override {
        return "Rrrr";
    }
};

class Wolf: public Animal {
    std::string Voice() const override {
        return "Wooo";
    }
};

class Fox: public Animal {
    std::string Voice() const override {
        return "Tyaf";
    }
};

using Zoo = std::vector<std::unique_ptr<Animal>>;

Zoo CreateZoo() {
    Zoo zoo;
    std::string word;
    while (std::cin >> word) {
        if (word == "Tiger") {
            zoo.emplace_back(std::make_unique<Tiger>());
        } else if (word == "Wolf") {
            zoo.emplace_back(std::make_unique<Wolf>());
        } else if (word == "Fox") {
           zoo.emplace_back(std::make_unique<Fox>()); 
        } else {
            throw std::runtime_error("Unknown animal!");
        }
    }
    return zoo;
}

void Process(const Zoo& zoo) {
    for (const auto& animal : zoo) {
        std::cout << animal.get()->Voice() << "\n";
    }
}

int main() {
    Process(CreateZoo());
}
