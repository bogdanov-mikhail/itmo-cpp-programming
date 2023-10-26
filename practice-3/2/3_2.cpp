//
// Created by bogda on 28.09.2023.
//
#include <iostream>
#include <valarray>

using namespace std;

/// @brief Нахождение кубического корня с помощью std::pow
/// @param n Число из которого нужно извлечь кубический корень
/// @return Кубический корень числа
double threeSqrtPow(double n) {
    return pow(n, 1.0 / 3.0);
}

/// @brief Нахождение кубического корня с помощью итертивного метода
/// @param n Число из которого нужно извлечь кубический корень
/// @param iters Количество итераций, чем больше тем точнее
/// @return Кубический корень числа
double threeSqrtIter(double n, double iters) {
    double result = n;
    for (int i = 0; i < iters; ++i) {
        result = (n / (result * result) + 2 * result) / 3;
    }
    return result;
}

int main3_2() {
    system("chcp 65001");

    cout << "Введите число: ";
    double n;
    cin >> n;

    cout << "Pow: " << threeSqrtPow(n) << std::endl;
    cout << "Iter: " << threeSqrtIter(n, 10) << std::endl;
}