#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "");
    cout << "Введите переменную х: "; // предлагаем пользователю ввести значение перменной
    float x;
    cin >> x;
    float numerator = 1; // инициализируем переменную, в которой будет значение числителя
    float denominator = 1; // инициализируем переменную, в которой будет значение знаменателя
    for (int i = 1; i <= 6; i++) {
        numerator *= (x - pow(2, i)); // вычисление значения числителя
        denominator *= (x - (pow(2, i) - 1)); // вычисление значения знаменателя
    };
    denominator == 0 ? cout << "Ошибка - деление на ноль!" : cout << numerator / denominator;
}