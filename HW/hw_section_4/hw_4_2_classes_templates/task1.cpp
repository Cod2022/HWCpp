/*
Вам надо написать шаблонный класс Table для электронной таблицы. 
Для простоты будем считать, что все ячейки таблицы имеют один и тот же тип данных T. 
Таблица должна уметь менять свой размер по требованию пользователя. 
Вновь созданные ячейки должны заполняться значениями по умолчанию типа T.

Требования к классу такие:

1.Класс должен называться Table.

2.У класса должен быть шаблонный параметр T — тип элемента в ячейке.

3.У класса должен быть конструктор, получающий на входе 
два числа типа size_t, — начальные размеры таблицы.

4.У класса должны быть константная и неконстантная версии оператора [], 
возвращающего нечто такое, к чему снова можно было бы применить оператор []. 
То есть, должны работать конструкции вида std::cout << table[i][j]; и table[i][j] = value;. 
Проверять корректность индексов при этом не нужно.

5.У класса должна быть функция resize, 
получающая на вход два параметра типа size_t и меняющая размер таблицы. 
Старые данные, умещающиеся в новый размер, должны при этом сохраниться.

6.У класса должна быть функция size, 
возвращающая std::pair<size_t, size_t> — размер таблицы 
(в том же порядке, в котором эти аргументы передавались в конструктор).
*/
#include <iostream>
#include <vector>

template <typename T>
class Table {
private:
    std::vector<std::vector<T>> data;

public:

    Table(size_t rows, size_t columns) {
        data.resize(rows);
        for (auto& row : data) {
            row.resize(columns);
        }
    }

    const std::vector<T>& operator [] (std::size_t i) const {
        return data[i];
    }

    std::vector<T>& operator [] (std::size_t i) {
        return data[i];
    }
};

int main() {
    Table<int> t(3, 4);

    t[0][0] = 3;
    std::cout << t[0][0];
}