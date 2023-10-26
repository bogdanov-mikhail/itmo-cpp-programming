//
// Created by bogda on 28.09.2023.
//
#include <iostream>
#include <valarray>

using namespace std;

/// @brief Нахождение суммы ряда
/// @param c Количество членов ряда
/// @param k Коэффициент ряда
/// @return Сумма ряда
int findSeriesSum(int c, int k) {
    if (c == 0) {
        return 0;
    }
    return findSeriesSum(c - 1, k) + c*k;
}

int main3_4() {
    system("chcp 65001");

    cout << "Введите n: ";
    int n;
    cin >> n;

    int sum = findSeriesSum(n, 5);
    cout << "Сумма ряда равна: " << sum << endl;
    return 0;
}