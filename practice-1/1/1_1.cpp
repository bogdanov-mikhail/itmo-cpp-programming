#include <iostream>
#include<cmath>

using namespace std;

int main1_1() {
    // Пять координат X, Y
    float x1, y1;
    float x2, y2;
    float x3, y3;
    float x4, y4;
    float x5, y5;

    // Ввод координат X, Y
    cout << "Entry first X Y coordinate:" << endl;
    cin >> x1 >> y1;
    cout << "Entry second X Y coordinate:" << endl;
    cin >> x2 >> y2;
    cout << "Entry third X Y coordinate:" << endl;
    cin >> x3 >> y3;
    cout << "Entry fourth X Y coordinate:" << endl;
    cin >> x4 >> y4;
    cout << "Entry five X Y coordinate:" << endl;
    cin >> x5 >> y5;

    // Рассчет площади по формуле Гаусса
    double area = 0.5 * abs(
            x1 * y2 -
            x2 * y1 +
            x2 * y3 -
            x3 * y2 +
            x3 * y4 -
            x4 * y3 +
            x4 * y5 -
            x5 * y4 +
            x5 * y1 -
            x1 * y5
    );
    cout << "Area: " << area;
}

