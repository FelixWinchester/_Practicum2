#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int n;
    cout << "Введите количество чисел: ";
    cin >> n;

    vector<int> numbers(n);
    cout << "Введите числа: ";
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    set<int> digits;
    for (int i = 0; i < n; i++) {
        if (numbers[i] >= 100 && numbers[i] <= 999) { // если число трехзначное
            int temp = numbers[i];
            while (temp > 0) {
                digits.insert(temp % 10); // добавляем все цифры числа в множество
                temp /= 10;
            }
        }
    }

    set<int> result;
    for (int digit : digits) {
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (numbers[i] >= 100 && numbers[i] <= 999) { // если число трехзначное
                int temp = numbers[i];
                while (temp > 0) {
                    if (temp % 10 == digit) { // если цифра встречается в числе
                        count++;
                        break;
                    }
                    temp /= 10;
                }
                if (count == 3) { // если цифра встретилась в трех числах, сохраняем ее
                    result.insert(digit);
                    break;
                }
            }
        }
    }

    if (result.empty()) {
        cout << "Таких цифр нет" << endl;
    } else {
        cout << "Цифры, встречающиеся только в трехзначных числах: ";
        for (int digit : result) {
            cout << digit << " ";
        }
        cout << endl;
    }

    return 0;
}
