//
// Created by bogda on 29.09.2023.
//
#include <fstream>
#include <iostream>

using namespace std;

int main6_1() {
    system("chcp 65001");

    cout << "Название файла: ";
    string filename;
    cin >> filename;

    ofstream output;
    output.open(filename);
    if (!output.is_open()) {
        std::cerr << "Не удалось открыть файл!" << std::endl;
        return 1;
    } else {
        for (string line; getline(cin, line);) {
            if (!line.empty()) {
                output << line << endl;
            }
            if (line == "END") {
                break;
            }
        }
    }

    output.close();
}
