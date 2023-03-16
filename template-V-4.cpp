#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
// #include <mozgi> // Источник "мозги" не найден, как иронично...
using namespace std;

//Шаблон для ввода массива
template<typename T>
void inputArray(T** arr, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
}

//Шаблон для вывода массива
template<typename T>
void outputArray(T** arr, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

//Шаблон для решения основной задачи
template<typename T>
void doubleElements(T** arr, int n, int m, T number) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] < number) {
                arr[i][j] *= 2;
            }
        }
    }
}

int main() {
    int n, m;
    cout << "Размеры массива хочеЦА: ";
    cin >> n >> m;

    double** arr = new double*[n];
    for (int i = 0; i < n; i++) {
        arr[i] = new double[m];
    }

    cout << "Элементы хочеЦА: " << endl;
    inputArray(arr, n, m);

    double number;
    cout << "Нужный элемент: ";
    cin >> number;

    doubleElements(arr, n, m, number);

    cout << "Итого: " << endl;
    outputArray(arr, n, m);

    return 0;
}

