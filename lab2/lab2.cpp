#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Введите количсетво минут: ";
    int time; //количество минут, которые прошли с начала часа
    cin >> time; 
    if (time % 5 <= 2) {
        cout << "Сейчас горит зелёный";
    }
    else {
        cout << "Сейчас горит красный";
    }
}