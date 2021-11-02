#include <iostream>

using namespace std;
int main()
{
    setlocale(LC_ALL, "");
    int num, power, res = 0; // введённое число, степень двойки и результат соответсвенно
    cout << "Введите число: ";
    cin >> num;
    int temp;
    while (num > 0) {
        temp = num;
        power = -1;
        while (temp > 0) {  // считаем степень, в которую будем возводить двойку
            power++;
            temp /= 2;
        }
        res += num % 2 * pow(2, power); // вычисляем значение результата
        num /= 2;
    }
    cout << "Результат: " << res;
}