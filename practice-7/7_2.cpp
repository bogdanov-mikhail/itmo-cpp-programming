//
// Created by bogda on 29.09.2023.
//

#include <valarray>
#include <iostream>

using namespace std;

/// @class Roots
/// @brief Решения квадратного уравнения
struct QuadraticEquation {
    bool isResolved;
    double x1;
    double x2;

    static QuadraticEquation resolve(double a, double b, double c) {
        double d = pow(b, 2) - 4 * a * c;
        if (d < 0) {
            return QuadraticEquation{false, 0, 0};
        }

        d = sqrt(d);
        if (d > 0) {
            return QuadraticEquation{true, (-b - d) / 2, (-b + d) / 2};
        } else {
            double x = -b / 2;
            return QuadraticEquation{true, x, x};
        }
    }
};

int main7_2() {
    system("chcp 65001");

    cout << "Введите коэффициенты a, b, c через пробел: ";
    double a, b, c;
    cin >> a >> b >> c;

    QuadraticEquation roots = QuadraticEquation::resolve(a, b, c);
    if (roots.isResolved) {
        cout << "Корни уравнения x1 = " << roots.x1 << ", x2 = " << roots.x2 << endl;
    } else {
        cout << "Корней нет" << endl;
    }
}