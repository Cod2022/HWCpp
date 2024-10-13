/*
Notifications

Вам даны функции SendSms и SendEmail, которые «умеют» отправлять сообщения:

#include <iostream>
#include <string>

void SendSms(const std::string& number, const std::string& message) {
    std::cout << "Send '" << message << "' to number " << number << std::endl;
}

void SendEmail(const std::string& email, const std::string& message) {
    std::cout << "Send '" << message << "' to e-mail "  << email << std::endl;
}

// Ваш код будет вставлен здесь:
#include "your_solution.h"

// Реализуйте в вашем решении классы NotifierBase, SmsNotifier и EmailNotifier,
// чтобы следующий код заработал как ожидается:

void Notify(const NotifierBase& notifier, const std::string& message) {
    notifier.Notify(message);
}

int main() {
    SmsNotifier sms("+7-495-777-77-77");
    EmailNotifier email("na-derevnyu@dedushke.ru");

    Notify(sms, "Hello! How are you?");
    Notify(email, "Let's learn C++!");
    return 0;
}

Вам нужно написать классы SmsNotifier и EmailNotifier, 
унаследованные от базового класса NotifierBase и переопределяющие функцию Notify, 
чтобы приведённый код заработал. Функция Notify 
в этих классах должна вызывать данные вам функции SendSms или SendEmail.
*/
#include <iostream>
#include <string>

void SendSms(const std::string& number, const std::string& message) {
        std::cout << "Send '" << message << "' to number " << number << std::endl;
}

void SendEmail(const std::string& email, const std::string& message) {
    std::cout << "Send '" << message << "' to e-mail "  << email << std::endl;
}

class NotifierBase {
public:

    virtual void Notify(const std::string& message) const = 0;

    virtual ~NotifierBase() {
    }

    
};

class SmsNotifier: public NotifierBase {
private:

    std::string sms;

public:

    SmsNotifier(const std::string& n): sms(n) {
    }

    void Notify(const std::string& message) const override {
        SendSms(sms, message);
    }
};

class EmailNotifier: public NotifierBase {
private:

    std::string email;

public:

    EmailNotifier(const std::string& e): email(e) {
    }

    void Notify(const std::string& message) const override {
        SendEmail(email, message);
    }
};

void Notify(const NotifierBase& notifier, const std::string& message) {
    notifier.Notify(message);
}

int main() {
    SmsNotifier sms("+7-495-777-77-77");
    EmailNotifier email("na-derevnyu@dedushke.ru");

    Notify(sms, "Hello! How are you?");
    Notify(email, "Let's learn C++!");
    return 0;
}