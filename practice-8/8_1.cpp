//
// Created by bogda on 29.09.2023.
//
#include <iostream>
#include <stdexcept>


using namespace std;

/// @brief Количество секунд в минуте
const int secondsInMinute = 60;

/// @brief Количество минут в часе
const int minutesInHour = 60;

/// @brief Количество часов в дне
const int hoursInDay = 24;

const int secondsInDay = secondsInMinute * minutesInHour * hoursInDay;

/// @class Time
/// @brief Класс, представляющий время в формате часы, минуты, секунды
struct Time {
    int hours;
    int minutes;
    int seconds;

    Time() : Time(0, 0, 0) {}

    Time(int hours, int minutes, int seconds) : hours(hours), minutes(minutes), seconds(seconds) {
        justify();
    }

    /// @brief Преобразование времени в строку формата HH:mm:ss
    string toString() const {
        return addLeadingZeros(to_string(hours), 2) + ":" +
               addLeadingZeros(to_string(minutes), 2) + ":" +
               addLeadingZeros(to_string(seconds), 2);
    }

    /// @brief Преобразование времени в секунды
    int getSeconds() const {
        return hours * secondsInMinute * minutesInHour + minutes * secondsInMinute + seconds;
    }

    /// @brief Секунд начиная с 00:00:00 во время в формате часы, минуты,
    /// секунды
    static Time ofSeconds(int total_seconds) {
        total_seconds %= secondsInDay;
        int seconds = total_seconds % secondsInMinute;
        total_seconds /= secondsInMinute;
        int minutes = total_seconds % minutesInHour;
        total_seconds /= minutesInHour;
        int hours = total_seconds;
        return Time{hours, minutes, seconds};
    }

    /// @brief Добавление времени
    /// @param other Время, которое нужно добавить
    Time add(const Time &other) {
        return ofSeconds(getSeconds() + other.getSeconds());
    }

    /// @brief Вычитание времени
    /// @param other Время, которое нужно вычесть
    Time sub(const Time &other) {
        int secs = getSeconds() - other.getSeconds();
        if (secs < 0) {
            secs += secondsInDay;
        }
        return ofSeconds(secs);
    }

    /// @brief Приведение времени к нормальному виду
    void justify() {
        Time newTime = ofSeconds(getSeconds() % secondsInDay);
        hours = newTime.hours;
        minutes = newTime.minutes;
        seconds = newTime.seconds;
    }

private:
    /// @brief Добавляет ведущие нули к строке до определенного размера
    /// @param str Строка
    /// @param size Размер строки с ведущими нулями
    static string addLeadingZeros(const string &str, int size) {
        int zeros = size - str.size();
        string result = str;
        if (zeros > 0) {
            for (int i = 0; i < zeros; i++) {
                result = "0" + result;
            }
        }
        return result;
    }

};

tuple<int, int, int> fromStringToInts(const string &time) {
    int times[3];
    string result;
    int size = 0;
    for (const char digit: time) {
        if (digit != ':') {
            result += digit;
        } else {
            times[size++] = stoi(result);
            result = "";
        }
    }
    times[size++] = stoi(result);
    return tuple{times[0], times[1], times[2]};
}

int main8_1() {
    system("chcp 65001");


    try {
        cout << "Enter first time in format \"HH:MM:SS\": ";
        string time1;
        cin >> time1;
        auto [hours1, minutes1, seconds1] = fromStringToInts(time1);
        Time t1(hours1, minutes1, seconds1);

        cout << "Enter second time in format \"HH:MM:SS\": ";
        string time2;
        cin >> time2;
        auto [hours2, minutes2, seconds2] = fromStringToInts(time2);
        Time t2(hours2, minutes2, seconds2);


        cout << "t1 + t2: " << t1.add(t2).toString() << endl;
        cout << "t1 - t2: " << t1.sub(t2).toString() << endl;
        cout << "t2 - t1: " << t2.sub(t1).toString() << endl;

    } catch (const invalid_argument &e) {
        cerr << e.what() << endl;
    }
}
