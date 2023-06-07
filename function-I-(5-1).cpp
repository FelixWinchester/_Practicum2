#include <iostream>
using namespace std;
    int gcd(int n, int m) {
    if (m == 0) {
    return n;
    }
    return gcd(m, n % m);
    }
int main() {
    int a, b;
    cout << "Введите числа a и b: ";
    cin >> a >> b;
    int g = gcd(a, b);
    cout << "НОД(" << a << ", " << b << ") = " << g << endl;
    cout << "Сокращенная дроб: " << a/g << "/" << b/g << endl;
    return 0;
}
