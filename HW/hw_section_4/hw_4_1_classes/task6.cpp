/*
Вы работаете оператором на складе. Время от времени вам привозят новые коробки. 
Каждая коробка имеет свою грузоподъемность wi​ и объем vi​. 
Получая новую коробку, вы ставите на ней серийный номер, 
используя все целые неотрицательные числа последовательно, начиная с нуля.

Иногда вас просят выдать коробку минимальной грузоподъемности, 
чтобы она выдержала предмет весом w — или коробку минимальной вместимости, 
в которую можно насыпать песок объемом v. 
Вам нужно быстро определять серийный номер коробки, 
которая будет выдана. Коробки обратно на склад не возвращаются. 
Если подходящих коробок несколько, нужно выбрать ту, которая пролежала на складе меньше.

Нужно реализовать класс Stock, у которого, среди прочих, будет три функции:

    void Add(int w, int v); — добавить коробку на склад;

    int GetByW(int min_w); — вернуть номер коробки грузоподъемности, хотя бы minw​;

    int GetByV(int min_v); — вернуть номер коробки объема, хотя бы minv​.

Если подходящей коробки нет, соответствующая функция должна вернуть −1.
*/

/*
Реализуем три дополнительные структуры:

    1.WeightNumber — структура для хранения вместимостей коробок;

    2.VolumeNumber — структура для хранения объёмов коробок;

    3.Iterators — структура для хранения итераторов на коробки. 
    Сами коробки мы будем хранить в двух std::set, 
    итераторы на эти множества мы и будем хранить в Iterators.

Так как мы планируем хранить данные о коробках в двух разных std::set, 
то для них нужно реализовать компораторы. 
Идея простая — сначала сортируем по вместимости / объёму, потом по индексу (порядковому номеру).

Все Iterators будем хранить в std::vector, 
так мы просто поддержим требуемые от нас «серийные номера» (индексы).

Теперь разберём функци-члены:

1.Add — нам нужно добавить коробку в оба множества и полученные итераторы записать в конец вектора.

2.GetByW — вызовем lower_bound от множества грузоподъёмностей. 
Если результатом стал end(), то коробок, 
способных поднять такой вес нет. 
Иначе — мы получим итератор на нужную нам коробку. 
Удалим её из обоих множеств и вернём искомый индекс.

3.GetByV — полный аналог GetByW, лишь lower_bound вызываем от множества объёмов.
*/
#include <set>
#include <vector>
#include <cstdint>
#include <iostream>
 
class Stock {
private:
    struct WeightNumber {
        int w;
        int i;
 
        bool operator < (const WeightNumber& other) const {
            if (w == other.w) {
                return i > other.i;
            }
            return w < other.w;
        }
    };
 
    struct VolumeNumber {
        int v;
        int i;
 
        bool operator < (const VolumeNumber& other) const {
            if (v == other.v) {
                return i > other.i;
            }
            return v < other.v;
        }
    };
 
    struct Iterators {
        std::set<WeightNumber>::iterator byW;
        std::set<VolumeNumber>::iterator byV;
    };
 
    std::vector<Iterators> boxes;
    std::set<WeightNumber> sortedByW;
    std::set<VolumeNumber> sortedByV;
 
public:
    void Add(int w, int v) {
        int num = boxes.size();
        boxes.push_back({sortedByW.insert({w, num}).first, sortedByV.insert({v, num}).first});
    }
 
    int GetByW(int min_w) {
        const auto it = sortedByW.lower_bound({min_w, boxes.size()});
        if (it == sortedByW.end()) {
            return -1;
        }
 
        int res = it->i;
        sortedByW.erase(it);
        sortedByV.erase(boxes[res].byV);
        return res;
    }
 
    int GetByV(int min_v) {
        const auto it = sortedByV.lower_bound({min_v, boxes.size()});
        if (it == sortedByV.end()) {
            return -1;
        }
 
        int res = it->i;
        sortedByV.erase(it);
        sortedByW.erase(boxes[res].byW);
        return res;
    }
};

int main() {
    Stock s;
    s.Add(2, 3);
    s.Add(4, 5);
    int res = s.GetByW(4);
    std::cout << res;
}