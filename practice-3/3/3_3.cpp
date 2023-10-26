//
// Created by bogda on 28.09.2023.
//
#include <iostream>
#include <valarray>

using namespace std;


/// @brief Нахождение площади треугольника по его сторонам
/// @param a Первая сторона треугольника
/// @param b Вторая сторона треугольника
/// @param c Третья сторона треугольника
/// @return Площадь треугольника
double findTriangleSquare(double a, double b, double c) {
    double p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

double findTriangleSquare(double a) {
    return findTriangleSquare(a, a, a);
}

/// @brief Обработка случая равностороннего треугольника
void findEquilateralTriangleSquare() {
    cout << "Введите сторону треугольника: ";
    double side;
    cin >> side;

    double square = findTriangleSquare(side);
    cout << "Площадь равностороннего треугольника: " << square << endl;
}

/// @brief Разносторонний треугольник
void findVersatileTrinagleSquare() {
    cout << "Введите стороны треугольника: " << endl;
    double a, b, c;
    cin >> a >> b >> c;

    double square = findTriangleSquare(a, b, c);
    cout << "Площадь разностороннего треугольника: " << square << std::endl;
}

int main3_3() {
    system("chcp 65001");

    cout << "Введите тип треугольника (0 — разносторонний, 1 — "
                 "равносторонний): ";
    int type;
    cin >> type;

    switch (type) {
        case 0: {
            findVersatileTrinagleSquare();
            break;
        }
        case 1: {
            findEquilateralTriangleSquare();
            break;
        }
        default: {
            cout << "Неверный тип треугольника" << endl;
            break;
        }
    }

    return 0;
}