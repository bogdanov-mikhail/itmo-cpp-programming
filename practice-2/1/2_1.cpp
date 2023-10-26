#include <iostream>

using namespace std;

int main2_1() {
    system("chcp 65001");

    // По определению суперпростое число может быть только натуральным
    int number;
    wcout << "Введите простое число:" << endl;
    cin >> number;

    if (number < 1) {
        cout << "Число не натуральное!";
        return 1;
    }

    for (int i = 2; i < number; i++) {
        if (number % i == 0) {
            cout << "Число не простое!";
            return 0;
        }
    }

    cout << "Число простое!";
    return 0;
}