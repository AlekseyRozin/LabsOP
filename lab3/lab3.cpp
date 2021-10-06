﻿#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    setlocale(LC_ALL, "");
    float a; //объявляем переменную а
    cout << "Введите переменную a: ";
    cin >> a;
    float p; //объявляем переменную р
    cout << "Введите переменную p (p не равно 0; 1; 2): ";
    cin >> p;
    int power; //объявляем переменную, в которой будет храниться значение степени
    cout << "Введите точность, 10 в степени: ";
    cin >> power;
    float accuracy = pow(10, power); //инициализируем значение точности
    float xn = 0; // n член
    float xn1 = 1; // n+1 член
    float temp = 1; // временная переменная, в которой будт сохраняться xn1
    while (fabs(xn1 - xn) > accuracy) {
        xn = temp;
        xn1 = xn / pow(p, 2) * ((pow(p, 2) - 1) + 0, 5 * (p + 1) * (a / pow(xn, p)) - 0, 5 * (p - 1) * (pow(xn, p) / p));
        temp = xn1;
    };
    cout << xn1;
}