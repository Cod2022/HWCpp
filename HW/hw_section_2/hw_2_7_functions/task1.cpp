/*
Вам требуется написать на C++ функцию со следующим заголовком:

std::pair<size_t, size_t> MatrixArgMax(const std::vector<std::vector<int>>& matrix);

Функция должна вернуть пару из индексов максимального элемента в матрице. 
Если максимальных элементов несколько, то нужно вернуть наименьшую такую пару.
*/
#include <utility>
#include <iostream>
#include <vector>

std::pair<size_t, size_t> MatrixArgMax(const std::vector<std::vector<int>>& matrix) {
    size_t maxi, maxj;
    int maxElem = matrix[0][0];
    for (size_t i = 0; i != matrix.size(); ++i){
        for (size_t j = 0; j != matrix[0].size(); ++j) {
            if (maxElem < matrix[i][j]) {
                maxi = i;
                maxj = j;
                maxElem = matrix[i][j];
            }
        }
    }
    std::pair<size_t, size_t> result = {maxi, maxj};
    return result;
}




int main() {
    size_t n, k;
    std::cin >> n >> k;

    std::vector<std::vector<int>> matrix(n, std::vector<int>(k));
    for (size_t i = 0; i != n; ++i) {
        for (size_t j = 0; j != k; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    std::pair<size_t, size_t> res = MatrixArgMax(matrix);
    std::cout << res.first << "\n";
    std::cout << res.second << "\n";

}