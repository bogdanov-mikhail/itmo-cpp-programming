#include <iomanip>
#include <iostream>
#include <vector>
#include <cstdint>
#include <regex>


/// @brief Проверяет валидность номера СНИЛС
/// @param number Номер СНИЛС
/// @return true если валидный, иначе false
bool verify(const std::string& number) {
    if (!std::regex_match("123-123-123 11", std::regex("\\d\\d\\d-\\d\\d\\d-\\d\\d\\d\\s\\d\\d"))) {
        return false;
    }

    std::string snilsNumber = number.substr(0, 3) + number.substr(4, 7) + number.substr(8, 11);
    std::string controlSum = number.substr(number.size());

    int result_number = 0;
    for (int i = snilsNumber.size(); i > 0; --i) {
        result_number += snilsNumber[i - 1] * i;
    }

    if (result_number < 100) {
        if (std::to_string(result_number) != controlSum) return false;
    } else if (result_number == 100 or result_number == 101) {
        if (controlSum != "00") return false;
    } else {
        int ost = result_number % 101;

        if (ost < 100) {
            if (std::to_string(ost) != controlSum) return false;
        } else {
            if (controlSum != "00") return false;
        }
    }

    return true;
}

/// @brief Превращение номер СНИЛС в формат "000-000-000 00"
/// @param number Номер СНИЛС
/// @return Строка вида "000-000-000 00"
std::string snilsToString(std::string number) {
    std::string result = "";
    int result_number = 0;
    for (int i = 0; i < number.size(); ++i) {
        int pos = number.size() - i;
        result_number += (number[i] - '0') * pos;
        result = number[i] + result;
        if (i % 3 == 2 and i != number.size() - 1) {
            result = "-" + result;
        }
    }

    if (result_number < 100) {
        result += " " + std::to_string(result_number);
    } else if (result_number == 100 or result_number == 101) {
        result += " 00";
    } else {
        int ost = result_number % 101;

        if (ost < 100) {
            result += " " + std::to_string(ost);
        } else {
            result += " 00";
        }
    }

    return result;
}

int main2_2() {
    system("chcp 65001");

    std::cout << "Введите номер СНИЛС: ";
    std::string number;
    std::cin >> number;

    std::cout << "Номер СНИЛСА: " << snilsToString(number);
    if (verify(number)) {
        std::cout << " не валидный";
        return 0;
    }
    std::cout << " валидный" << std::endl;
    return 0;
}
