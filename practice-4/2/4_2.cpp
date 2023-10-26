//
// Created by bogda on 28.09.2023.
//
#include <iostream>

using namespace std;

/// @brief Cчитывания двух чисел
/// @param a Первое считываемое число
/// @param b Второе считываемое число
/// @return Если нет ошибок - true, иначе false
bool input(int &a, int &b) {
    cin >> a;
    if (!cin.good()) {
        return false;
    }

    cin >> b;
    if (!cin.good()) {
        return false;
    }

    return true;
}

int main4_2() {
    system("chcp 65001");

    cout << "Введите два числа: ";
    int a, b;
    if (!input(a, b)) {
        cerr << "Некорректные данные";
        return 1;
    }

    int sum = a + b;
    cout << "Сумма: " << sum << endl;
    return 0;
}