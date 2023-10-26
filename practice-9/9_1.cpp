#include <cmath>
#include <iostream>
#include <stdexcept>

using namespace std;

/// @class TriangleComposition
/// @brief Класс, представляющий собой треугольник
class TriangleComposition {
public:
    TriangleComposition(double first, double second, double third): first(first), second(second), third(third) {
        if (first > second + third || second > first + third || third > first + second) {
            throw invalid_argument{
                    "Side of triangle cannot be greater than sum of other sides",
            };
        }
    }

    TriangleComposition(double side) : TriangleComposition(side, side, side) {}

    /// @brief Нахождение площади треугольника
    double square() const {
        double p = (first + second + third) / 2;
        return sqrt(p * (p - first) * (p - second) * (p - third));
    }

private:
    double first;
    double second;
    double third;
};

/// @brief Обработка случая равностороннего треугольника
void processEquilateralTriangle() {
    cout << "Введите сторону треугольника: ";
    double side;
    cin >> side;

    TriangleComposition triangle{side};
    cout << "Площадь равностороннего треугольника: " << triangle.square()
              << endl;
}

/// @brief Обработка случая разностороннего треугольника
void processVersatileTrinagle() {
    cout << "Введите стороны треугольника через пробел: ";
    double a, b, c;
    cin >> a >> b >> c;

    TriangleComposition triangle(a, b, c);
    cout << "Площадь разностороннего треугольника: " << triangle.square()
              << endl;
}

int main9_1() {
    cout << "Введите тип треугольника (0 — равносторонний, 1 — "
                 "разносторонний): ";
    int type;
    cin >> type;

    switch (type) {
        case 0: {
            processEquilateralTriangle();
            break;
        }
        case 1: {
            processVersatileTrinagle();
            break;
        }
        default: {
            std::cout << "Неверный тип треугольника" << std::endl;
            break;
        }
    }
}
