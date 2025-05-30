/*
Напишите свою реализацию стандартного алгоритма set_difference. Заголовок функции должен быть таким:

template <typename InIter1, typename InIter2, typename OutIter>
OutIter SetDifference(InIter1 first1, InIter1 last1,
                      InIter2 first2, InIter2 last2,
                      OutIter out);

Функция должна сформировать элементы разности диапазонов [first1, last1) и [first2, last2) 
и записать их в последовательность, начинающуюся с out. 
Исходные диапазоны предполагаются отсортированными. 
Каждый элемент считается со своей кратностью. 
Функция должна вернуть итератор, который указывает за последний записанный элемент.
*/

template <typename InIter1, typename InIter2, typename OutIter>
OutIter SetDifference(InIter1 first1, InIter1 last1,
                      InIter2 first2, InIter2 last2,
                      OutIter out) {

    auto iter1 = first1;
    auto iter2 = first2;

    while (iter1 != last1) {
        while (iter2 != last2 && *iter2 < *iter1) {
            ++iter2;
        }
        if (iter2 == last2 || *iter1 < *iter2) {
            *out = *iter1;
            ++out;
        } else if (iter2 != last2) {
            ++iter2;
        }
        ++iter1;
    }
    return out;
      }
