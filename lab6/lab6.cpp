#include <iostream>
#include <math.h> 
using namespace std;
int n; // количество точек
double nearestDot = 1, nearestDistance, x, y; // порядковый номер ближайшей точки (по умолчанию 1), минимальное расстояния, координаты х, у соответсвенно

void setCoordinates(int i); // функция, чтобы задать координаты точке
double getDotDistance(double x, double y); // функция, чтобы определить расстояние от точки до начала координат
void getNearestDot(); // функция, которая сравнивает расстояние от точки до начала координат с минимальным

int main()
{
    setlocale(LC_ALL, "");
    cout << "Введите кол-во точек, координаты которых будете вводить: ";
    cin >> n;
    setCoordinates(1);
    nearestDistance = getDotDistance(x, y);
    getNearestDot();
    cout << endl << "Ближе вcего к началу координат находится точка " << nearestDot << endl;
}

void setCoordinates(int i) {
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

void getNearestDot() {
    for (int i = 2; i <= n; i++) {
        setCoordinates(i);
        float currDistance = getDotDistance(x, y);
        if (currDistance < nearestDistance) {
            nearestDistance = currDistance;
            nearestDot = i;
        }
    }
}