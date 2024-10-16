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

const int DEFAULT_DATE_DAY = 1;
const int DEFAULT_DATE_MONTH = 1;
const int DEFAULT_DATE_YEAR = 1970;
const int DAYS_IN_YEAR_WITHOUT_FEB = 337;
 
class Date {
private:
    int d = DEFAULT_DATE_DAY, m = DEFAULT_DATE_MONTH, y = DEFAULT_DATE_YEAR;
 
    // Дальше реализуем вспомогательные функции-члены.
    // Нам нужно будет понимать високосный ли перед нами год, корректную ли дату ввели:
    int GetDaysInFeb(int year) const {
        if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) {
            return 29;
        }
        return 28;
    }
 
    int GetDaysInMonth(int month, int year) const {
        switch (month) {
            case 2:
                return GetDaysInFeb(year);
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                return 31;
            default:
                return 30;
        }
    }
 
    int GetDaysInYear(int year) const {
        return DAYS_IN_YEAR_WITHOUT_FEB + GetDaysInFeb(year);
    }
 
    bool IsCorrectDate() const {
        return GetMonth() <= 12 && GetMonth() >= 1 && GetDay() <= GetDaysInMonth(GetMonth(), GetYear()) && GetDay() > 0;
    }
 
    // Помимо прочего будет полезно уметь переводить текущую дату в число — количество дней от 01.01.1970 и обратно.
    int DaysPassedToMonth(int month, int year) const {
        int days = 0;
        for (int i = 1; i < month; ++i) {
            days += GetDaysInMonth(i, year);
        }
        return days;
    }
 
    int GetDays() const {
        int days = 0;
        for (int i = DEFAULT_DATE_YEAR; i < GetYear(); ++i) {
            days += GetDaysInYear(i);
        }
        return days + DaysPassedToMonth(GetMonth(), GetYear()) + GetDay();
    }
 
    void SetFromDays(int inp_days) {
        m = DEFAULT_DATE_MONTH;
        y = DEFAULT_DATE_YEAR;
 
        while (inp_days > GetDaysInYear(GetYear())) {  // сначала определяем год
            inp_days -= GetDaysInYear(GetYear());
            ++y;
        }
 
        while (inp_days > DaysPassedToMonth(GetMonth() + 1, GetYear())) {  // определяем месяц
            ++m;
        }
 
        d = inp_days - DaysPassedToMonth(GetMonth(), GetYear());  // остаток в дни
    }
 
// Когда подготовительная часть закончена, реализуем публичный интерфейс:
public:
    Date(int day, int month, int year)
            : d{day}, m{month}, y{year} {
        if (!IsCorrectDate()) {
            d = DEFAULT_DATE_DAY;
            m = DEFAULT_DATE_MONTH;
            y = DEFAULT_DATE_YEAR;
        }
    }
 
    int GetDay() const {
        return d;
    }
 
    int GetMonth() const {
        return m;
    }
 
    int GetYear() const {
        return y;
    }
 
    Date operator + (int k) const {
        Date result(*this);
        result.SetFromDays(result.GetDays() + k);
        return result;
    }
 
    Date operator - (int k) const {
        Date result(*this);
        result.SetFromDays(result.GetDays() - k);
        return result;
    }
 
    int operator - (const Date& other) const {
        return GetDays() - other.GetDays();
    }
};

int main() {
    Date date(1, 2, 2004);
    Date res = date + 154;
    std::cout << res.GetDay() << "." << res.GetMonth() << "." << res.GetYear();
}