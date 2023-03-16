#include <iostream>
// #include <mozgi> // Источник "мозги" не найден, как иронично...
using namespace std;

void _deliteli_tipa(int n, int i) {
    if (i == n) { 
        cout << n;
        return;
    }
    if (n % i == 0) {
        cout << i << "  ";
    }
    _deliteli_tipa(n, i+1); // рекурсивный вызов
}

int main() {
    int n;
    cout << "Введите натуральное число: ";
    cin >> n;
    cout << "Делители числа: " << n <<endl;
    _deliteli_tipa(n, 1);
    return 0;
}
