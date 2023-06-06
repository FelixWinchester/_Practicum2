#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
int main() {
    vector<pair<int, int>> points = {
        {1, 2}, {3, 1}, {-1, 1}, {4, 4}, {2, -2}, {-3, 3}, {5, 3}
    };

    // а) удалить все точки, лежащие выше y = x
    points.erase(remove_if(points.begin(), points.end(), [](const pair<int, int>& point) {
        return point.second > point.first;
    }), points.end());

    // б) подсчитать количество точек, лежащих на прямой y = -x
    int count = count_if(points.begin(), points.end(), [](const pair<int, int>& point) {
        return point.second == -point.first;
    });
    cout << "Kol'vo tochek na pryamoi y = -x: " << count << endl;

    // в) найти первую точку, у которой x > y
    auto it = find_if(points.begin(), points.end(), [](const pair<int, int>& point) {
        return point.first > point.second;
    });
    if (it != points.end()) {
        cout << "Pervaya tochka, y kotoroi x > y: (" << it->first << ", " << it->second << ")" << endl;
    } else {
        cout << "takoi tochki net" << endl;
    }

    // г) расположить в порядке возрастания координаты y
    sort(points.begin(), points.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    });

    cout << "Tochki v poryadke vozrastania y:" << endl;
    for (const auto& point : points) {
        cout << "(" << point.first << ", " << point.second << ")" << endl;
    }

    return 0;
}
