#include <iostream>
using namespace std;

void setCoordinates(int i, double& x, double& y); // функция, чтобы задать координаты точке
double getDotDistance(double x, double y); // функция, чтобы определить расстояние от точки до начала координат
void getNearestDot(int n, int& nearestDot); // функция, которая сравнивает расстояние от точки до начала координат с минимальным

int main()
{
    setlocale(LC_ALL, "");
    int n, nearestDot = 1; // количество точек, порядковый номер ближайшей точки (по умолчанию 1)
    cout << "Введите кол-во точек, координаты которых будете вводить: "; cin >> n;
    getNearestDot(n, nearestDot);
    cout << "\nБлиже вcего к началу координат находится точка " << nearestDot << endl;
}

void setCoordinates(int i, double &x, double &y) {
    cout << endl;
    cout << "Точка " << i << " - Введите координату х: ";
    cin >> x;
    cout << "Точка " << i << " - Введите координату y: ";
    cin >> y;
}

double getDotDistance(double x, double y) {
    double res = sqrt(x * x + y * y);
    return res;
}

void getNearestDot(int n, int &nearestDot) {
    double x = 0;
    double y = 0;
    setCoordinates(1, x, y);
    double nearestDistance = getDotDistance(x, y);
    for (int i = 2; i <= n; i++) {
        setCoordinates(i, x, y);
        float currDistance = getDotDistance(x, y);
        if (currDistance < nearestDistance) {
            nearestDistance = currDistance;
            nearestDot = i;
        }
    }
}