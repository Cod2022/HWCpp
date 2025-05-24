/*
Вася хочет иметь возможность в конце работы своей функции выводить сообщение, что функция завершила работу. 
На практике исполнение функции может завершиться разными способами:

    Может быть несколько операторов return.
    Может вылететь исключение из какой-нибудь вызываемой функции.

С учетом этих обстоятельств у Василия получается раздутый код:

#include <iostream>

int Function() {
    int value = 1;
    try {
        value = SomeFunction();
        if (value == 0) {
            std::cout << "Function completed\n";
            return value;
        }

        value = SomeOtherFunction();
        if (value == 0) {
            std::cout << "Function completed\n";
            return value;
        }

        value = FinalFunction();  // might throw an exception
    } catch (...) {
        std::cout << "Function completed\n";
        throw;  // throws the exception further.
    }

    std::cout << "Function completed\n";
    return value;
}

Вместо этого Василий хотел бы не заниматься копированием одного и тоже же кода. 
Помогите Василию и реализуйте класс LoggerGuard, который принимает строку и печатает 
её во время выхода из функции.
Класс LoggerGuard должен содержать следующий конструктор:

LoggerGuard(const std::string& message, std::ostream& out = std::cout);

Здесь message — сообщение, печатаемое перед выходом из функции, а out — поток, 
в который надо печатать сообщение. Учтите, что это сообщение не обязано содержать 
символ перевода строки и вам нужно всегда при выводе самим добавлять \n в конце.
*/
#include <iostream>
#include <string>

class LoggerGuard {
private:
    std::string message;
    std::ostream& out;
public:
    LoggerGuard(const std::string& _message, std::ostream& _out = std::cout) :
        message(_message), out(_out) {}

    ~LoggerGuard() {
        out << message << "\n";
    }
};

int SomeFunction() {
    return 2;
}

int SomeOtherFunction() {
    return 1;
}

int FinalFunction() {
    throw std::exception();
}

// С использованием этого класса код Василия станет таким:
int Function() {
    LoggerGuard logger("Function completed");

    int value = 1;
    try {
        value = SomeFunction();
        if (value == 0) {
            return value;
        }

        value = SomeOtherFunction();
        if (value == 0) {
            return value;
        }

        value = FinalFunction();  // might throw an exception
    } catch (...) {
        throw;  // throws the exception further.
    }

    return value;
}

int main() {
    try{
        Function();
    } catch (...) {
        std::cout << "Some exception occured!";
    }
}
