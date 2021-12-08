#include <iostream>
#include <iomanip>
using namespace std;

void generateMatrixX(int** arr, int rows, int columns);
void generateMatrixY(int** arrY, int** arrX, int rows, int columns);
void outputMatrix(int** arr, int rows, int columns);

int main()
{
    int n, m;
    cout << "Enter amount of rows in matrix X: "; cin >> n;
    cout << "Enter amount of columns in matrix X: "; cin >> m;
    int** arrX = new int* [n];
    int** arrY = new int* [m];

    generateMatrixX(arrX, n, m);
    cout << "\n\n Matrix X:\n\n";
    outputMatrix(arrX, n, m);

    generateMatrixY(arrY, arrX, m, n);
    cout << "\n\n Matrix Y:\n\n";
    outputMatrix(arrY, m, n);

}

void generateMatrixX(int** arr, int rows, int columns) {
    srand(time(NULL));
    for (int i = 0; i < rows; i++) {
        arr[i] = new int[columns];
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            arr[i][j] = rand() % 99 + 1;
        }
    }
}

void generateMatrixY(int** arrY, int** arrX, int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        arrY[i] = new int[columns];
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            arrY[i][j] = arrX[j][i];
        }
    }
}

void outputMatrix(int** arr, int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cout << setw(3) << arr[i][j];
        }
        cout << endl;
    }
}