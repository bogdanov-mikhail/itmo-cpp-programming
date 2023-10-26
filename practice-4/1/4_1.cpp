//
// Created by bogda on 28.09.2023.
//
#include <cmath>
#include <iostream>

using namespace std;

/// @brief Нахождение корней квадратного уравнения
/// @param a Старший коэффициент
/// @param b Средний коэффициент
/// @param c Свободный член
/// @param x1 Первый корень
/// @param x2 Второй корень
/// @return Если корня два - 2, если корень один 1, если корней нет 0
int Myroot(double a, double b, double c, double &x1, double &x2) {
    double d = pow(b, 2) - 4 * a * c;
    if (d < 0) {
        return 0;
    }
    d = sqrt(d);
    if (d > 0) {
        x1 = (-b - d) / 2;
        x2 = (-b + d) / 2;
        return 2;
    } else {
        x1 = x2 = -b / 2;
        return 1;
    }
}

int main4_1() {
    system("chcp 65001");

    cout << "Введите коэффициенты a, b, c через пробел: ";
    double a, b, c;
    cin >> a >> b >> c;

    double x1, x2;
    int result = Myroot(a, b, c, x1, x2);
    if (result == 1) {
        cout << "Корни уравнения x1 = " << x1 << ", x2 = " << x2 << endl;
    } else if (result == 0) {
        cout << "Корень уравнения один x1 = x2 = " << x1 << endl;
    } else {
        cout << "Корней нет" << endl;
    }
    return 0;
}