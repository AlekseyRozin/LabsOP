#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "");
    float a; //объявляем переменную а
    cout << "Введите подкоренное число: ";
    cin >> a;
    float p; //объявляем переменную р
    cout << "Введите степень корня (степень больше 2): ";
    cin >> p;
    int power; //объявляем переменную, в которой будет храниться значение степени
    cout << "Введите точность, 10 в степени: ";
    cin >> power;
    float accuracy = pow(10, power); //инициализируем значение точности
    float xn = 1; // n член
    float xn1 = 1; // n+1 член
    if ((p < 3) || (int(p) % 2 == 0 && a < 0)) {
        cout << "Ошибка - числа введены неверно!";
    }
    else {
        do {
            xn = xn1;
            // xn1 = xn / pow(p, 2) * ((pow(p, 2) - 1) + 0, 5 * (p + 1) * (a / pow(xn,p)) - 0, 5 * (p + 1) * (pow(xn,p) / p)); - неправильная формула, данная по условию
            xn1 = 1 / p * ((p - 1) * xn + a / pow(xn, p - 1)); // правильная формула вычисления 
        } while (abs(xn1 - xn) > accuracy);
        cout << "Результат: " << xn1;
    }
    
}