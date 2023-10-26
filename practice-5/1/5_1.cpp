//
// Created by bogda on 28.09.2023.
//
#include <iostream>

using namespace std;

/// @brief Сортировка массива по возрастанию пузырьком
/// @param nums Массив
/// @param size Размер массива
void sort(int nums[], int size) {
    for (int i = 0; i < size; i++) {
        int mn = i;

        for (int j = i + 1; j < size; j++) {
            mn = (nums[j] < nums[mn]) ? j : mn;
        }

        if (i != mn) {
            int temp = nums[i];
            nums[i] = nums[mn];
            nums[mn] = temp;
        }
    }
}

/// @brief Нахождение индекса минимума и максимума массива
/// @param nums Массив
/// @param size Размер массива
/// @return Индексы минимума и максимума
pair<int, int> findMinAndMaxIndex(int nums[], int size) {
    int min_idx = 0;
    int max_idx = 0;
    for (int i = 0; i < size; ++i) {
        if (nums[i] < nums[min_idx]) {
            min_idx = i;
        }
        if (nums[i] > nums[max_idx]) {
            max_idx = i;
        }
    }
    return {min_idx, max_idx};
}

/// @brief Произведение элементов между минимальным и максимальным элементом
/// @param nums Массив
/// @param size Размер массива
/// @return Произведение элементов между минимальным и максимальным элементом
int findMutlipliesBeetweenMaxAndMin(int nums[], int size) {
    auto [left, right] = findMinAndMaxIndex(nums, size);
    if (left > right) {
        auto temp = left;
        left = right;
        right = temp;
    }
    int mult = 1;
    for (int i = ++left; i < right; ++i) {
        mult *= nums[i];
    }
    return mult;
}

/// @brief Сумма элементов с четными индексами
/// @param nums Массив, элементы которого надо просуммировать
/// @param size Размер массива
/// @return Сумма элементов с четными индексами
int findEvenIndexSum(int nums[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i += 2) {
        sum += nums[i];
    }
    return sum;
}



/// @brief Сумма элементов с нечетными индексами
/// @param nums Массив
/// @param size Размер массива
/// @return Сумма элементов массива с нечетными индексами
int findOddIndexSum(int nums[], int size) {
    int sum = 0;
    for (int i = 1; i < size; i += 2) {
        sum += nums[i];
    }
    return sum;
}

/// @brief Суммы отрицательных элементов массива
/// @param nums Массив
/// @param size Размер массива
/// @return Сумма отрицательных элементов массива
int findSumPositive(int nums[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        if (nums[i] > 0) {
            sum += nums[i];
        }
    }
    return sum;
}


/// @brief Суммы отрицательных элементов массива
/// @param nums Массив
/// @param size Размер массива
/// @return Сумма отрицательных элементов массива
int findSumNegative(int nums[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        if (nums[i] < 0) {
            sum += nums[i];
        }
    }
    return sum;
}

/// @brief Суммы элементов массива
/// @param nums Массив
/// @param size Размер массива
/// @return Сумма элементов массива
int findSum(int nums[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += nums[i];
    }
    return sum;
}

int main5_1() {
    system("chcp 65001");

    int size = 5;
    int arr[size];
    for (int i = 0; i < size; i++) {
        cout << "arr[" << i << "]=";
        cin >> arr[i];
    }

    int sum = findSum(arr, size);
    cout << "Сумма: " << sum << endl;
    double avg = (double) sum / size;
    cout << "Среднее значение: " << avg << endl;
    cout << "Сумма негативных значений: " << findSumNegative(arr, size) << endl;
    cout << "Сумма позитивных значений: " << findSumPositive(arr, size) << endl;
    cout << "Сумма значенний с нечетными индексами: " << findOddIndexSum(arr, size) << endl;
    cout << "Сумма значенний с четными индексами: " << findEvenIndexSum(arr, size) << endl;

    auto [min_idx, max_idx] = findMinAndMaxIndex(arr, size);
    cout << "Минимальный индекс: " << min_idx << endl;
    cout << "Максимальный индекс: " << max_idx << endl;
    cout << "Минимальный * максимальный: " << findMutlipliesBeetweenMaxAndMin(arr, size) << endl;

    sort(arr, size);
    cout << "Отсортированный массив: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << ' ';
    }
    cout << endl;
    return 0;
}
