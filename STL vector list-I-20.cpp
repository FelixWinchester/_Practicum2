
//A) Решение с использованием вектора:

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int countDigits(int n) { // функция для подсчета количества различных цифр в числе
    vector<int> digits;
    while (n != 0) {
        int digit = n % 10;
        if (find(digits.begin(), digits.end(), digit) == digits.end()) {
            digits.push_back(digit);
        }
        n /= 10;
    }
    return digits.size();
}

int main() {
    vector<int> v = {1, 2, 3, 4, 5};
    v[1] = countDigits(v[1]);
    v[v.size() - 2] = countDigits(v[v.size() - 2]);
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}

/*
Временная сложность: O(n), где n – размер вектора. Вектор выбран потому, 
что мы не знаем заранее, сколько элементов будет входить в последовательность, 
и хотим иметь возможность динамически изменять ее размер.
*/

//Б) Решение с использованием списка:

#include <iostream>
#include <list>
#include <algorithm>

int reverseDigits(int n) { // функция для перестановки цифр в обратном порядке
    int result = 0;
    while (n != 0) {
        result = result * 10 + n % 10;
        n /= 10;
    }
    return result;
}

int main() {
    list<int> l = {1, 2, 3, 4, 5};
    l.insert(++l.begin(), reverseDigits(*l.begin())); // вставляем после первого элемента
    l.insert(--l.end(), reverseDigits(*--l.end())); // вставляем перед последним элементом
    for (int x : l) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}

/*Временная сложность: O(n), где n – размер списка. Список выбран потому, 
что для вставки элементов в середину последовательности он работает быстрее вектора. 
Кроме того, для задачи вставки элементов в список не нужно каждый раз перевыделять память, 
как в случае с вектором, что может быть эффективнее при работе с большими последовательностями
*/
