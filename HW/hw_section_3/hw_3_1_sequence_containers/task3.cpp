/*
Вы — машинист. Вам поручено реализовать функцию void MakeTrain(), 
чтобы сформировать поезд из набора вагонов.

У каждого вагона есть номер (помещается в int). 
Номера вагонов внутри состава могут повторяться. 
Изначально путь, на котором формируется состав, пустой. 
Вы должны уметь выполнять следующие команды, которые поступают в отдельных строках на входе:

    +left W — добавить вагон с номером W слева
    +right W — добавить вагон с номером W справа
    -left N — отцепить и убрать N вагонов слева
    -right N — отцепить и убрать N вагонов справа

В последних двух командах N может быть больше текущей длины состава — в этом случае 
надо убрать весь состав целиком. 
Отцеплять вагоны по одному может быть долго: постарайтесь сразу отцеплять по N штук. 
Напечатайте через пробел номера вагонов получившегося состава, если смотреть на них слева направо. 
В самом конце напечатайте перевод строки.

На вход подаются строки с командами в указанном формате. 
Всего будет не более 1 млн команд. 
Оформите ваше решение в функции void MakeTrain(). 
Эта функция должна читать данные со стандартного потока ввода и печатать их в стандартный поток вывода. 
Подключите все необходимые библиотеки. В вашем решении не должно быть функции main.
*/
#include <iostream>
#include <deque>
#include <string>

void MakeTrain(){
    std::deque<int> wagons;
    std::string trainSide;
    int wagonNum;
    size_t deleteNum;

    while (std::cin >> trainSide) {
        if (trainSide == "+left") {
            std::cin >> wagonNum;
            wagons.push_front(wagonNum);
      } else if (trainSide == "+right") {
            std::cin >> wagonNum;
            wagons.push_back(wagonNum);
      } else if (trainSide == "-left") {
            std::cin >> deleteNum;
            deleteNum = std::min(deleteNum, wagons.size());
            wagons.erase(wagons.begin(), wagons.begin() + deleteNum);
      } else if (trainSide == "-right") {
            std::cin >> deleteNum;
            deleteNum = std::min(deleteNum, wagons.size());
            wagons.erase(wagons.end() - deleteNum, wagons.end());
        }
    }

    for (const auto& wagon : wagons) {
        std::cout << wagon << " ";
    }
}

int main() {
    MakeTrain();
}
