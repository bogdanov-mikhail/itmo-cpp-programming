#include <iostream>
#include <fstream>

using namespace std;

/// @brief Сортировка массива по возрастанию пузырьком
/// @param nums Массив
/// @param size Размер массива
void arraySort(int nums[], int size) {
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

void writeArray(ofstream &out, int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        if (i != 0) {
            out << ' ';
        }
        out << arr[i];
    }
    out << endl;
}

int main6_2() {
    system("chcp 65001");

    cout << "Введите размер массива: ";
    int size;
    cin >> size;
    int arr[size];
    for (int i = 0; i < size; i++) {
        cout << "arr[" << i << "]=";
        cin >> arr[i];
    }

    cout << "Введите название файла: ";
    string filename;
    cin >> filename;

    ofstream out;
    out.open(filename);

    if (!out.is_open()) {
        return 1;
    }

    writeArray(out, arr, size);
    arraySort(arr, size);
    writeArray(out, arr, size);

    return 0;
}