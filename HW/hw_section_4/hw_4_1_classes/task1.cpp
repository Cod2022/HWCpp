/*
Вам надо написать класс Date для хранения даты григорианского календаря. 
Используйте три переменных типа int для хранения дня, месяца и года. 
В вашем классе должен быть следующий публичный интерфейс:

    Конструктор, принимающий на вход три числа: день, месяц и год. 
    В случае некорректной даты должна создаваться дата 1 января 1970 года.

    Константные функции GetDay, GetMonth и GetYear.

    Бинарные операторы + и -, где вторым аргументом является целое число — количество дней. 
    Эти операторы должны вернуть новую дату, отстоящую от заданной на указанное число дней.

    Бинарный оператор -, вычисляющий разность между двумя датами и возвращающий int – количество дней.

Считайте, что все обрабатываемые даты будут лежать в пределах от 1 января 1970 года до 31 декабря 2099 года.
*/
#include <iostream>
#include <set>

class Date {
private:
    int day, month, year;

    bool IsLeapYear(int year) {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            return true;
        } else {
            return false;
        }
    }

    bool IsCorrectDate(int day, int month, int year) {
        const int min_day = 1;
        const int max_day = 31;

        const int min_month = 1;
        const int max_month = 12;

        const int min_year = 1970;
        const int max_year = 2099;

        const int feb = 2;

        const std::set<int> days_30 = {4, 6, 9, 11};

        if ((year < min_year || year > max_year) ||\
            (month < min_month || month > max_month) ||\
            (day < min_day || day > max_day)) {
            return false;
        } if ((days_30.find(month) != days_30.end()) && day > 30) {
            return false;
        } if ((month == feb && !IsLeapYear(year)) && day > 28) {
            return false;
        } if ((month == feb && IsLeapYear(year)) && day > 29) {
            return false;
        } else {
            return true;
        }
    }
public:
    Date(int d, int m, int y) {
        if (IsCorrectDate(d, m, y)) {
            day = d;
            month = m;
            year = y;
        } else {
            day = 1;
            month = 1;
            year = 1970;
        }
    }
    int GetDay() const {
        return day;
    }
    int GetMonth() const {
        return month;
    }
    int GetYear() const {
        return year;
    }
};


int main() {
    Date date(31, 03, 1971);
    std::cout << date.GetDay() << "." << date.GetMonth() << "." << date.GetYear();

        
}