//
// Created by bogda on 28.09.2023.
//
#include <iostream>
#include <valarray>

using namespace std;

std::string toBinary(int number) {
    if (number == 0) {
        return "";
    }
    return toBinary(number / 2) + to_string(number % 2);
}

int main3_5() {
    system("chcp 65001");

    cout << "Введите число: ";
    int number;
    cin >> number;

    cout << "Бинарный вид: " << toBinary(number) << endl;
}