//
// Created by bogda on 28.09.2023.
//
#include <iostream>
#include <string_view>

using namespace std;


/// @brief Main метод, который считает сумму или произвдение в зависимости от аргумента
int main5_4(int argc, char* argv[]) {
    system("chcp 65001");

    if (argc > 4) {
        cerr << "Количество параметров должен быть меньше 4" << endl;
        return 1;
    }

    string_view param = argv[1];
    if (param != "-a" && param != "-m") {
        cerr << "Некорректный параметр " << param << endl;
        return 1;
    }

    try {
        int a = stoi(argv[2]);
        int b = stoi(argv[3]);
        if (param == "-a") {
            cout << a + b << endl;
        } else if (param == "-m") {
            cout << a * b << endl;
        }
    } catch (const char* error_message) {
        cout << "Некорректный ввод" << endl;
        return 1;
    }
}
