#include <iostream>
using namespace std;
void generateArr(int* p, int n); // функция для заполнения массива случайными числами
void outputArr(int array[], int n); // функция для вывода элементов массива в консоль
int findMin(int array[], int n); // функция для поиска минимального элемента массива
int findMax(int array[], int n); // функция для поиска максимального элемента массива
int maxMinDiff(int min, int max); // функция для поиска разницы максимального и минимального значения массива
void changeArr(int* p, int n, int diff); // функция для присовения каждому второму элемента массива значение разности

int main()
{
    int n;
    cout << "Enter array length: "; cin >> n;
    int* arr = new int[n];

    generateArr(arr, n);
    cout << "\nGenerated array: "; outputArr(arr, n);

    int diff = maxMinDiff(findMin(arr,n), findMax(arr,n));
    cout << "Difference of max and min element: " << diff << "\n\n";

    changeArr(arr, n, diff);
    cout << "Changed array: "; outputArr(arr, n);

    // освобождаем выделенную массиву память
    delete[] arr;
}

void generateArr(int* p, int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        *p = rand() % 100 + 1;
        p++;
    }
}

void outputArr(int array[], int n) {
    for (int i = 0; i < n; i++) {
        cout << array[i] << "  ";
    }
    cout << "\n\n";
}
int findMin(int array[], int n) {
    int min = array[0];
    for (int i = 1; i < n; i++) {
        if (array[i] < min) {
            min = array[i];
        }
    }
    return min;
}
int findMax(int array[], int n) {
    int max = array[0];
    for (int i = 1; i < n; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
}
int maxMinDiff(int min, int max) {
    return max - min;
}

void changeArr(int* p, int n, int diff) {
    for (int i = 0; i < n; i++) {
        if (i % 2 != 0) {
            *p = diff;
        }
        p++;
    }
}