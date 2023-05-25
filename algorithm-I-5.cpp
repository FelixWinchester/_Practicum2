#include <iostream> 
#include <vector> // подключаем библиотеку для работы с векторами
#include <algorithm> // подключаем библиотеку для работы с алгоритмами
#include <numeric> // подключаем библиотеку для работы с числовыми алгоритмами
#include <utility> // подключаем библиотеку для работы с парами
using namespace std; 

int main() { // основная функция программы
    vector<pair<int, int>> points = {{1, 2}, {3, 4}, {5, 6}, {7, 8}, {9, 10}}; // создаем вектор пар координат точек и заполняем его

    // а) удалить все точки, лежащие выше y = x
    points.erase(remove_if(points.begin(), points.end(), [](const pair<int, int>& p) { return p.second > p.first; }), points.end()); // удаляем все точки, лежащие выше y = x

    // б) подсчитать количество точек, лежащих на прямой y = -x
    int count = count_if(points.begin(), points.end(), [](const pair<int, int>& p) { return p.second == -p.first; }); // считаем количество точек, лежащих на прямой y = -x
    cout << "Number of points on y = -x: " << count << endl; // выводим количество таких точек на экран

    // в) найти первую точку, у которой x > y
    auto it = find_if(points.begin(), points.end(), [](const pair<int, int>& p) { return p.first > p.second; }); // находим первую точку, у которой x > y
    if (it != points.end()) { // если такая точка найдена
        cout << "First point with x > y: (" << it->first << ", " << it->second << ")" << endl; // выводим ее координаты на экран
    } else { // если такой точки нет
        cout << "No point with x > y found" << endl; // выводим сообщение, что такой точки нет
    }

    // г) расположить в порядке возрастания координаты y
    sort(points.begin(), points.end(), [](const pair<int, int>& p1, const pair<int, int>& p2) { return p1.second < p2.second; }); // сортируем точки по возрастанию координаты y

    // вывод списка точек на экран
    for (const auto& point : points) { // для каждой точки в векторе
        cout << "(" << point.first << ", " << point.second << ")" << endl; // выводим ее координаты на экран
    }
}
