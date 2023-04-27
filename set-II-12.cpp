#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore(); // Игнорируем символ переноса строки после ввода числа n

    for (int i = 0; i < n; i++) {
        string s;
        getline(cin, s); // Вводим строку с пробелами

        unordered_set<char> letters; // Создаем хеш-таблицу для хранения уникальных букв
        for (char c : s) {
            if (isalpha(c)) { // Если символ является буквой
                letters.insert(tolower(c)); // Добавляем букву в хеш-таблицу в нижнем регистре
                letters.insert(toupper(c)); // Добавляем букву в хеш-таблицу в верхнем регистре
            }
        }

        for (char c : letters) {
            cout << c; // Выводим каждую букву из хеш-таблицы
        }
        cout << endl; // Переходим на новую строку после каждой обработанной строки
    }

    return 0;
}
