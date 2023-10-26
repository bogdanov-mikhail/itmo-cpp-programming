//
// Created by bogda on 26.10.2023.
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
        validate();
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

    Time operator+(const Time &other) const {
        return ofSeconds(getSeconds() + other.getSeconds());
    }

    Time operator+(double other) const {
        return ofSeconds(getSeconds() + static_cast<int>(other));
    }

    friend Time operator+(double other, const Time &time) {
        return time + static_cast<int>(other);
    }

    Time operator-(const Time &other) const {
        int secs = getSeconds() - other.getSeconds();
        if (secs < 0) {
            secs += secondsInDay;
        }
        return ofSeconds(secs);
    }

    friend bool operator==(const Time &l, const Time &r) {
        return l.seconds == r.seconds;
    }

    friend bool operator!=(const Time &l, const Time &r) {
        return !(l == r);
    }

    friend bool operator<(const Time &l, const Time &r) {
        return l.seconds < r.seconds;
    }

    friend bool operator<=(const Time &l, const Time &r) {
        return l < r || l == r;
    }

    friend bool operator>(const Time &l, const Time &r) {
        return l != r && !(l < r);
    }

    friend bool operator>=(const Time &l, const Time &r) {
        return !(l < r);
    }


    /// @brief Приведение времени к нормальному виду
    void validate() const {
        if (!(hours >= 0 && hours < 24)) {
            throw std::invalid_argument{"Hours value must be from 0 to 23"};
        }
        if (!(minutes >= 0 && minutes < 60)) {
            throw std::invalid_argument{"Minutes value must be from 0 to 59"};
        }
        if (!(seconds >= 0 && seconds < 60)) {
            throw std::invalid_argument{"Seconds value must be from 0 to 59"};
        }
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

int main11_1() {

    Time t1(3, 45, 50);
    Time t2(4, 45, 5);


    cout << "t1 + t2: " << (t1 + t2).toString() << endl;
    cout << "t1 - t2: " << (t1 - t2).toString() << endl;
    cout << "t2 == t1: " << (t1 == t2) << endl;
    cout << "t2 > t1: " << (t1 > t2) << endl;
    cout << "t2 < t1: " << (t1 < t2) << endl;


    return 0;
}