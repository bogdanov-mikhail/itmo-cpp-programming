//
// Created by bogda on 26.10.2023.
//
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

/// @class Point
/// @brief Точка, задаваемая координатами двумя декартовыми координатами
struct Point {
    double x;
    double y;

    Point(double x, double y) : x(x), y(y) {}

    /// @brief Нахождения расстояния до центра координат
    /// @return Расстояние до центра координат
    double distanceToOO() const {
        return sqrt(pow(x, 2) + pow(y, 2));
    }

    friend ostream& operator<<(ostream& out, const Point& p) {
        return out << '(' << p.x << ", " << p.y << ')';
    }

    friend bool operator<(const Point& left, const Point& right) {
        return left.distanceToOO() < right.distanceToOO();
    }
};

int main11_2() {
    vector<Point> v;
    v.push_back(Point(1, 2));
    v.push_back(Point(10, 12));
    v.push_back(Point(21, 7));
    v.push_back(Point(4, 8));
    sort(v.begin(), v.end());

    for (Point& point : v) {
        cout << point << '\n';
    }
}