#include <valarray>
#include <iostream>

using namespace std;

tuple<int, double, double> resolveThis(double a, double b, double c) {
    double d = pow(b, 2) - 4 * a * c;
    if (d < 0) {
        return {0, 0, 0};
    }

    d = sqrt(d);
    if (d > 0) {
        return {2, (-b - d) / 2, (-b + d) / 2};
    } else {
        double x = -b / 2;
        return {1, x, x};
    }
}

int main7_3() {
    system("chcp 65001");

    cout << "Введите коэффициенты a, b, c через пробел: ";
    double a, b, c;
    cin >> a >> b >> c;

    tuple<int, double, double> roots = resolveThis(a, b, c);
    int answers = get<0>(roots);
    double x1 = get<1>(roots);
    double x2 = get<2>(roots);
    if (answers != 0) {
        cout << "Корни уравнения x1 = " << x1 << ", x2 = " << x2 << endl;
    } else {
        cout << "Корней нет" << endl;
    }
    return 0;
}