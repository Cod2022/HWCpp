/*
Математический вектор (не путать с std::vector!) – структура линейной алгебры, 
определяющаяся набором упорядоченных чисел (координат). 
Обозначается как (x1,x2,...,xn). 
Число n в таком случае называется размерностью вектора.

В качестве примера можно рассмотреть вектора размерности два с координатами в вещественных числах. 
В таком случае вектор (1,2) будет задавать знакомый нам со школы 
геометрический вектор с началом в координате (0,0) и концом в (1,2).

Также заметим, что координаты вектора необязательно вещественные числа. 
Это могут быть рациональные, комплексные или любые другие математические объекты, 
обладающие набором базовых операций сложения и умножения. (например математические матрицы)

Над математическим вектором можно проводить две операции:

    Сложение двух векторов одинаковой размерности: пусть a=(x1,x2,...,xn),b=(y1​,y2​,...,yn​), 
    тогда a+b=(x1+y1,x2+y2,...,xn+yn);

    Умножение вектора на число (тип числа должен быть одинаковым с типом чисел координат у вектора): 
    пусть c=(x1,x2,...,xn),α
        какое-то число, тогда α⋅c=(αx1,αx2,...,αxn).

Вам дан шаблонный класс MathVector<T>, представляющий собой математический вектор 
с координатами типа T:

#include <iostream>
#include <vector>

template <typename T>
class MathVector {
 private:
    std::vector<T> data;

 public:
    // Храним в `data` нулевой вектор длины `n`
    MathVector(size_t n) {
        data.resize(n);
    }

    template <typename Iter>
    MathVector(Iter first, Iter last) {
        while (first != last) {
            data.push_back(*first);
        }
    }

    size_t Dimension() const {
         return data.size();
    }

    T& operator [] (size_t i) {
        return data[i];
    }

    const T& operator [] (size_t i) const {
        return data[i];
    }
};

// Output format: (1, 2, 3, 4, 5)
template <typename T>
std::ostream& operator << (std::ostream& out, const MathVector<T>& v) {
    out << '(';
    for (size_t i = 0; i != v.Dimension(); ++i) {
        if (i > 0) {
            out << ", ";
        }
        out << v[i];
    }
    out << ')';
    return out;
}

template <typename T>
MathVector<T>& operator *= (MathVector<T>& v, const T& scalar) {
    for (size_t i = 0; i != v.Dimension(); ++i) {
        v[i] *= scalar;
    }
    return v;
}

template <typename T>
MathVector<T> operator * (const MathVector<T>& v, const T& scalar) {
    auto tmp(v);
    tmp *= scalar;
    return tmp;
}

template <typename T>
MathVector<T> operator * (const T& scalar, const MathVector<T>& v) {
    return v * scalar;
}

Вам требуется исправить ошибки в коде этого класса и дописать операторы += и + для сложения векторов. 
Считайте, что складываться друг с другом всегда будут только векторы одинаковой размерности.
*/