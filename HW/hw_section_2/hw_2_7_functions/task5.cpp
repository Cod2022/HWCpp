/*
Дана прямоугольная матрица A из m строк и n столбцов. 
Транспонированной матрицей AT называется матрица из n строк и m столбцов, 
в которой строки и столбцы поменялись ролями: элемент Aij​ равен элементу Aji.

Напишите функцию, которая возвращает транспонированную матрицу:

std::vector<std::vector<int>> Transpose(const std::vector<std::vector<int>>& matrix);

*/

#include <vector>
#include <iostream>


std::vector<std::vector<int>> Transpose(const std::vector<std::vector<int>>& matrix) {
    size_t m = matrix.size();
    size_t n = matrix[0].size();
    std::vector<std::vector<int>> transposedM (n, std::vector<int>(m));

    for (size_t i = 0; i < m; ++i) {
        for (size_t j = 0; j < n; ++j) {
            transposedM[j][i] = matrix[i][j];
        }
    }
    return transposedM;

}


int main() {
    std::vector<std::vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {6, 7, 8}, {3, 6, 7}};
    std::vector<std::vector<int>> result = Transpose(matrix);

    for (size_t i = 0; i != result.size(); ++i) {
        for (size_t j = 0; j != result[0].size(); ++j) {
            std::cout << result[i][j] << "\t";
        }
        std::cout << "\n";
    }

}

