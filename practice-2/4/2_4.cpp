//
// Created by bogda on 27.09.2023.
//
#include <iostream>
#include <cmath>

using namespace std;

int main2_4() {
    system("chcp 65001");

    const int required_score = 50;
    int current_score = 0;
    int shots = 0;

    while (current_score < required_score) {
        shots++;
        float x, y;
        std::cout << "Введите координаты x и y:" << std::endl;
        std::cin >> x >> y;
        double distance = std::sqrt(std::pow(x, 2) + std::pow(y,2));
        int shot_score;
        if (distance > 3) {
            shot_score = 0;
        } else if (distance > 2) {
            shot_score = 1;
        } else if (distance > 1) {
            shot_score = 5;
        } else {
            shot_score = 10;
        }

        if (shot_score == 0) {
            std::cout << "Промах!" << std::endl;
        } else {
            current_score += shot_score;
            std::cout << "Попадание!" << std::endl;
            std::cout << "Текущее количество очков: " << current_score << std::endl;
        }
    }

    std::string level;
    if (shots == 5) {
        level = "Снайпер";
    } else if (shots <= 10) {
        level = "Просто стрелок";
    } else {
        level = "Салага";
    }

    std::cout << "Игра окончена" << std::endl;
    std::cout << "Сумма очков: " << current_score << std::endl;
    std::cout << "Уровень: " << level;
}