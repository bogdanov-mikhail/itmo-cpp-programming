//
// Created by bogda on 26.10.2023.
//
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/// @brief Печать через заданный разделитель
/// @tparam T Тип контейнера
/// @param values Контейнер, который нужно распечатать
/// @param sep Разделитель элементов
    template <typename T> void printWithSeparator(const T& values, const string& sep) {
    bool first = true;
    for (auto &v : values) {
        if (!first) {
            cout << sep;
        }
        first = false;
        cout << v;
    }
    cout << "\n";
}

int main14_2() {
    vector<int> data = {1, 2, 3};
    printWithSeparator(data, ",");
    printWithSeparator(data, "|");
    return 0;
}