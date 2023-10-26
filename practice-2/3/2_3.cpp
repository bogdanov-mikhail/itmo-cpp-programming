#include <array>
#include <iostream>

/// @brief Номиналы российских монет
const std::array<int, 8> coins =  {
    1000,
    500,
    200,
    100,
    50,
    10,
    5,
    1
};

/// @brief Номиналы российских монет
/// @param sum Сумма для размена
/// @return Количество монет каждого номинаоа
std::array<int, 8> getCoins(int sum) {
    std::array<int, 8> result = {0, 0, 0, 0, 0, 0, 0, 0};
    for (int i = 0; i < coins.size(); ++i) {
        int coin = coins[i];
        while (sum >= coin) {
            sum -= coin;
            result[i] += 1;
        }
    }
    return result;
}



int main2_3() {
    system("chcp 65001");

    std::cout << "Введите сумму: ";
    int sum;
    std::cin >> sum;

    std::array<int, 8> result_coins = getCoins(sum*100);
    std::cout << "Номинал | Количество" << std::endl;
    for (int i = 0; i < result_coins.size(); ++i) {
        if (result_coins[i] > 0) {
            std::cout << coins[i] / 100 << " | " << result_coins[i] << std::endl;
        }
    }
    return 0;
}