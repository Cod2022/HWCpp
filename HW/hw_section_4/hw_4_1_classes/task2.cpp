/*
Вам надо переделать реализацию класса Date из предыдущей задачи, 
сохранив публичный интерфейс неизменным. 
Теперь для хранения даты используйте одну переменную типа int — количество дней, 
прошедших с некоторого начала отсчёта.

Считайте, что все обрабатываемые даты будут 
лежать в пределах от 1 января 1970 года до 31 декабря 2099 года.
*/
#include <tuple>
#include <iostream>
 
const int DEFAULT_DATE_DAY = 1;
const int DEFAULT_DATE_MONTH = 1;
const int DEFAULT_DATE_YEAR = 1970;
const int DAYS_IN_YEAR_WITHOUT_FEB = 337;
 
class Date {
private:
    int days{0};
 
    int GetDaysInFeb(int year) const {
        if ((!(year % 4) && (year % 100)) || !(year % 400)) {
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
 
    int DaysPassedToMonth(int month, int year) const {
        int result = 0;
        for (int i = 1; i < month; ++i) {
            result += GetDaysInMonth(i, year);
        }
        return result;
    }
 
    // Отредактируем перевод из даты в дни и обратно:
    void SetDays(int day, int month, int year) {
        days = 0;
        for (int i = DEFAULT_DATE_YEAR; i < year; ++i) {
            days += GetDaysInYear(i);
        }
        days = days + DaysPassedToMonth(month, year) + day;
    }
 
    std::tuple<int, int, int> ToDate() const {
        int inp_days = days;
        int month = DEFAULT_DATE_MONTH;
        int year = DEFAULT_DATE_YEAR;
 
        while (inp_days > GetDaysInYear(year)) {  // сначала определяем год
            inp_days -= GetDaysInYear(year);
            ++year;
        }
 
        while (inp_days > DaysPassedToMonth(month + 1, year)) {  // определяем месяц
            ++month;
        }
 
        int day = inp_days - DaysPassedToMonth(month, year);  // остаток в дни
        return {day, month, year};
    }
 
    void SetFromDays(int inp_days) {
        days = inp_days;
    }
 
    int GetDays() const {
        return days;
    }
 
// Осталось поменять публичные интерфейсы.
// Так как в них мы почти не завязывались на тип хранения,
//     правки будут только в функциях-членах чтения и конструкторе:
public:
    Date(int day, int month, int year) {
        if (month > 12 || month < 1 || day > GetDaysInMonth(month, year) || day < 1) {
            days = 0;
        } else {
            SetDays(day, month, year);
        }
    }
 
    int GetDay() const {
        return std::get<0>(ToDate());
    }
 
    int GetMonth() const {
        return std::get<1>(ToDate());
    }
 
    int GetYear() const {
        return std::get<2>(ToDate());
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
        Date d(2, 3, 2004);
        std::cout << d.GetDay() << "." << d.GetMonth() << "." << d.GetYear() << "\n";
        Date d2 = d + 54;
        std::cout << d2.GetDay() << "." << d2.GetMonth() << "." << d2.GetYear();
    }