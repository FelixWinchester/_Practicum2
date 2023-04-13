#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q; // создаем очередь
    int n; // количество элементов в списке
    cin >> n;
    int PredidushiElem, EtotElem; // переменные для хранения предыдущего и текущего элементов
    cin >> PredidushiElem; // считываем первый элемент
    q.push(PredidushiElem); // добавляем его в очередь
    for (int i = 1; i < n; i++) { // считываем остальные элементы
        cin >> EtotElem;
        if (EtotElem != PredidushiElem) { // если текущий элемент не равен предыдущему
            q.push(EtotElem); // добавляем его в очередь
            PredidushiElem = EtotElem; // обновляем значение предыдущего элемента
        }
    }
    while (!q.empty()) { // выводим элементы очереди
        cout << q.front() << ' ';
        q.pop();
    }
    return 0;
} 

// Пример входных данных:
// 10
// 1 1 2 2 2 3 4 4 4 4
// Пример выходных данных:
// 1 2 3 4
