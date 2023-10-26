//
// Created by bogda on 28.09.2023.
//
#include <iostream>
using namespace std;

/// @brief Поиск с транспозицией
/// @param nums Массив чисел
/// @param size Размер массива
/// @param value Значение, которое нужно найти
/// @return Индекс элемента, если он найден, иначе -1
int transpositionSearch(int nums[], int size, int value) {
    for (int i = 0; i < size; ++i) {
        if (nums[i] == value) {
            if (i > 0) {
                swap(nums[i - 1], nums[i]);
            }
            return i;
        }
    }
    return -1;
}

int main5_3() {
    system("chcp 65001");

    int nums[] = {9, 3, 7, 5, 2};
    int size = sizeof(nums) / sizeof(nums[0]);

    for (int i = 0; i < size; ++i) {
        int index = transpositionSearch(nums, size, 2);
        cout << "Индекс: " << index << endl;
        for (int j = 0; j < size; j++) {
           cout << nums[j] << ' ';
        }
        cout << endl;
    }

    cout << "Индекс несуществующего элемента: "<< transpositionSearch(nums, size, 999) << std::endl;
}