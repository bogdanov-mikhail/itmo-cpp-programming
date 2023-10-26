//
// Created by bogda on 26.10.2023.
//
#include <iostream>

using namespace std;

/// @brief Нахождение среднего значения элементов массива
/// @tparam T Тип элементов массива
/// @param nums Массив элементов
/// @param size Размер массива элементов
/// @return Среднее значение элементов массива
template <typename T> T avg(T nums[], int size) {
    T sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += nums[i];
    }
    return sum / size;
}

int main14_1() {
    const int size = 6;
    int ints[] = {1, 2, 3, 4, 5, 6};
    long longs[] = {1, 2, 3, 4, 5, 6};
    double doubles[] = {1.4, 2.1, 3.8, 4.5, 5.2, 6.7};
    char chars[] = {'a', 'b', 'c', 'b', 'd', 'e'};

    cout << avg(ints, size) << endl;
    cout << avg(longs, size) << endl;
    cout << avg(doubles, size) << endl;
    cout << static_cast<int>(avg(chars, size)) << endl;
    return 0;
}