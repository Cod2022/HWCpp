/*
Вам даны координаты точек на плоскости. 
Выведите эти точки в порядке возрастания расстояний до начала координат.
Формат ввода

Сначала задано количество точек n. 
Затем идет последовательность из n строк, 
каждая из которых содержит два целых числа — координаты точки. Величина n не превосходит 100. 
Координаты точек по модулю также не превосходят 100.
*/

#include <iostream>
#include <vector>
#include <algorithm>

struct Point {
    int x;
    int y;
};

int main() {

    size_t n;
    std::cin >> n;

    std::vector<Point> points(n);

    for (size_t i = 0; i != n; ++i) {
        std::cin >> points[i].x >> points[i].y;
    }

    std::sort(
        points.begin(),
        points.end(),
        [](const Point& p1, const Point& p2) {
            return p1.x + p1.y < p2.x + p2.y;
        }
    );
    
    for (const auto& point : points) {
        std::cout << point.x << " " << point.y << "\n";
    }
    
    }

