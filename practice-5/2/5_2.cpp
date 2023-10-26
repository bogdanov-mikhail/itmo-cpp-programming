//
// Created by bogda on 28.09.2023.
//

#include <iostream>

using namespace std;

/// @brief Массив, чьи элементы являются максимумом из двух данных массивов на каждой позиции
/// @param size Размер массивов
/// @param a Первый массив
/// @param b Второй массив
/// @return Массив максимумов из двух массивов на каждой позиции
int* max_vect(int size, int a[], int b[]) {
    int* myArray = new int[size];
    for (int i = 0; i < size; ++i) {
        myArray[i] = max(a[i], b[i]);
    }
    return myArray;
}

int main5_2() {
    system("chcp 65001");

    int a[] = {1, 2, 3, 4, 5, 6, 7, 2};
    int b[] = {7, 6, 5, 4, 3, 2, 1, 3};
    int size = sizeof(a) / sizeof(a[0]);

    int* c;
    c = max_vect(size, a, b);
    for (int i = 0; i < size; i++) {
        cout << c[i] << ' ';
    }
    cout << std::endl;

    delete[] c;
}
