/*
Данные часто нужно сериализовывать, то есть превращать в строку. 
Это нужно для сохранения на диске, для отправки по сети, для передачи другому процессу. 
Часто для этого используются несколько общепринятых форматов данных, таких как JSON, YAML, XML. 
Поскольку на этапе компиляции не всегда известно, в каком именно формате надо сериализовывать данные, 
часто приходится прибегать к наследованию. 
Вам необходимо реализовать класс Serializer с чисто виртуальными методами:

void BeginArray()
void AddArrayItem(const std::string &)
void EndArray()

После этого унаследуйте от него класс JsonSerializer, определив все эти методы.

JsonSerializer должен печатать упрощенную версию JSON (https://ru.wikipedia.org/wiki/JSON), 
состояющую только из массивов и строк. Массив начинается с квадратной скобки. 
После каждого элемента, кроме последнего, должна стоять запятая. 
Заканчивается массив квадратной скобкой. 
Все строки должны быть взяты в двойные кавычки. 
Гарантируется, что все строки состоят только из латинских символов и пробелов, 
поэтому экранировать их не надо.

Сдайте в систему только код классов, без функции main. 
Для полной ясности формата вывода посмотрите на примеры из условия.
*/
#include <iostream>
#include <string>

class Serializer {

public:
    virtual void BeginArray() = 0;
    virtual void AddArrayItem(const std::string& n) = 0;
    virtual void EndArray() = 0;

    virtual ~Serializer() {
    }
};

class JsonSerializer: public Serializer {
private:
    bool isFirst = true;

public:
    void BeginArray() override {
        if(!isFirst) {
            std::cout << ",[";
        } else {
            std::cout << '[';
        }

        isFirst = true;
    }

    void AddArrayItem(const std::string& n) override {
        if(!isFirst) {
            std::cout << ',';
        }
        std::cout << '"' << n << '"';
        isFirst = false;
    }

    void EndArray() override {
        std::cout << ']';
        isFirst = false;
    }
};

int main() {
    JsonSerializer s;
    s.BeginArray();
    s.BeginArray();
    s.AddArrayItem("Hi");
    s.AddArrayItem("Hey");
    s.EndArray();
}