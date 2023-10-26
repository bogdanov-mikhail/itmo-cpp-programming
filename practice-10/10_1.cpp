//
// Created by bogda on 26.10.2023.
//
#include <cmath>
#include <iostream>
#include <stdexcept>

using namespace std;

/// @class Dot
/// @brief Класс, представляющий собой точку на плоскости
struct Dot {
    double x;
    double y;

    Dot(double x, double y) : x(x), y(y) {}

    /// @brief Нахождение расстояния до другой точки
    /// @param point Точка, до которой необходимо найти расстояние
    /// @return Расстояние до заданной точки
    double distanceTo(const Dot& point) const {
        return sqrt(pow(point.x - x, 2) + pow(point.y - y, 2));
    }
};

/// @class TriangleComposition
/// @brief Класс, представляющий собой треугольник как композиция точек
class TriangleComposition {
public:
    TriangleComposition(
            double first_x,
            double first_y,
            double second_x,
            double second_y,
            double third_x,
            double third_y
    )
            : first(first_x, first_y),
              second(second_x, second_y),
              third(third_x, third_y) {
        double first_side = firstSideLength();
        double second_side = secondSideLength();
        double third_side = thirdSideLength();
        if (first_side > second_side + third_side || second_side > first_side + third_side || third_side > first_side + second_side) {
            throw invalid_argument{
                    "Side of triangle cannot be greater than sum of other sides",
            };
        }
    }

    /// @brief Нахождение длины первой стороны
    double firstSideLength() const {
        return first.distanceTo(second);
    }

    /// @brief Нахождение длины второй стороны
    double secondSideLength() const {
        return second.distanceTo(third);
    }

    /// @brief Нахождение длины третьей стороны
    double thirdSideLength() const {
        return third.distanceTo(first);
    }

    /// @brief Нахождение периметра треугольника
    double perimeter() const {
        return firstSideLength() + secondSideLength() + thirdSideLength();
    }

    /// @brief Нахождение площади треугольника
    double Square() const {
        double first_side = firstSideLength();
        double second_side = secondSideLength();
        double third_side = thirdSideLength();
        double p = perimeter() / 2;
        return std::sqrt(
                p * (p - first_side) * (p - second_side) * (p - third_side)
        );
    }

private:
    Dot first;
    Dot second;
    Dot third;
};

/// @class TriangleAggregation
/// @brief Класс, представляющий собой треугольник как агрегация точек
class TriangleAggregation {
public:
    explicit TriangleAggregation(Dot first, Dot second, Dot third)
            : first(first), second(second), third(third) {
        double first_side = firstSideLength();
        double second_side = secondSideLength();
        double third_side = thirdSideLength();
        if (first_side > second_side + third_side || second_side > first_side + third_side || third_side > first_side + second_side) {
            throw invalid_argument{
                    "Side of triangle cannot be greater than sum of other sides",
            };
        }
    }

    /// @brief Нахождение длины первой стороны
    double firstSideLength() const {
        return first.distanceTo(second);
    }

    /// @brief Нахождение длины второй стороны
    double secondSideLength() const {
        return second.distanceTo(third);
    }

    /// @brief Нахождение длины третьей стороны
    double thirdSideLength() const {
        return third.distanceTo(first);
    }

    /// @brief Нахождение периметра треугольника
    double perimeter() const {
        return firstSideLength() + secondSideLength() + thirdSideLength();
    }

    /// @brief Нахождение площади треугольника
    double Square() const {
        double first_side = firstSideLength();
        double second_side = secondSideLength();
        double third_side = thirdSideLength();
        double p = perimeter() / 2;
        return sqrt(
                p * (p - first_side) * (p - second_side) * (p - third_side)
        );
    }

private:
    Dot first;
    Dot second;
    Dot third;
};

int main10_1() {
    TriangleComposition t1(0, 0, 0, 3, 4, 0);
    cout << "Side №1: " << t1.firstSideLength() << endl;
    cout << "Side №2: " << t1.secondSideLength() << endl;
    cout << "Side №3: " << t1.thirdSideLength() << endl;
    cout << "Perimeter: " << t1.perimeter() << endl;
    cout << "Square: " << t1.Square() << endl;

    TriangleAggregation t2(Dot{0, 0}, Dot{0, 3}, Dot{4, 0});
    cout << "Side №1: " << t2.firstSideLength() << endl;
    cout << "Side №2: " << t2.secondSideLength() << endl;
    cout << "Side №3: " << t2.thirdSideLength() << endl;
    cout << "Perimeter: " << t2.perimeter() << endl;
    cout << "Square: " << t2.Square() << endl;
    return 0;
}
