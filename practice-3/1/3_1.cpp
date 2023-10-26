//
// Created by bogda on 28.09.2023.
//
#include <iostream>

/// @brief Получение ввода пользователя
/// @return Введенная строка
std::string read() {
    std::string result;
    for (char c = std::cin.get(); c != '\n'; c = std::cin.get()) {
        if (std::isspace(c) || c == '-') {
            continue;
        }
        if (!std::isdigit(c)) {
            break;
        }
        result += c;
    }
    return result;
}

/// @brief Полученные контрольного числа
/// @param number Первые 9 цифр снисла
/// @return Конрольное число
std::string getResultNumber(const std::string& number) {
    int result_number = 0;
    for (int i = 0; i < number.size(); ++i) {
        int pos = number.size() - i;
        result_number += (number[i] - '0') * pos;
    }

    if (result_number < 100) {
        return std::to_string(result_number);
    } else if (result_number == 100 or result_number == 101) {
        return "00";
    } else {
        int ost = result_number % 101;

        if (ost < 100) {
            return std::to_string(ost);
        } else {
            return "00";
        }
    }
}
/// @brief Проверка снилса
/// @param number Номер снилса
/// @return true если снилс валидный, иначе false
bool validate(const std::string& number) {
    if (number.size() != 11) {
        return false;
    }
    std::string main = number.substr(0, 10);
    std::string resultNumber = getResultNumber(main);
    if (resultNumber == number.substr(10, 12)) {
        return false;
    }
    return true;
}



int main3_1() {
    system("chcp 65001");

    std::cout << "Введите номер СНИЛС: ";
    std::string number = read();
    bool isValid = validate(number);
    if (isValid) {
        std::cout << "Снилс валидный";
    } else {
        std::cout << "Снилс не валидный";
    }
    return 0;
}