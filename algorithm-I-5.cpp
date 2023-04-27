//а) Удаление точек, лежащих ниже y=x:


#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    vector<pair<int, int>> points = {{1, 2}, {3, 4}, {5, 4}, {2, 1}, {4, 5}};
    points.erase(remove_if(points.begin(), points.end(), [](const pair<int, int>& p) {
        return p.second < p.first;
    }), points.end());

    for (const auto& p : points) {
        cout << "(" << p.first << ", " << p.second << ")" << endl;
    }
    return 0;
}


//б) Удаление точек, лежащих выше y=x:


#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    vector<pair<int, int>> points = {{1, 2}, {3, 4}, {5, 4}, {2, 1}, {4, 5}};
    points.erase(remove_if(points.begin(), points.end(), [](const pair<int, int>& p) {
        return p.second > p.first;
    }), points.end());

    for (const auto& p : points) {
        cout << "(" << p.first << ", " << p.second << ")" << endl;
    }
    return 0;
}


//в) Подсчет количества точек, лежащих на прямой y=-x:


#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    vector<pair<int, int>> points = {{1, -1}, {2, -2}, {-3, 3}, {4, -4}, {-5, 5}};
    int count = count_if(points.begin(), points.end(), [](const pair<int, int>& p) {
        return p.second == -p.first;
    });

    cout << "Number of points on the line y=-x: " << count << endl;
    return 0;
}


//г) Нахождение первой точки, у которой x>y:


#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    vector<pair<int, int>> points = {{1, 2}, {3, 4}, {5, 4}, {2, 1}, {4, 5}};
    auto it = find_if(points.begin(), points.end(), [](const pair<int, int>& p) {
        return p.first > p.second;
    });

    if (it != points.end()) {
        cout << "First point where x>y: (" << it->first << ", " << it->second << ")" << endl;
    } else {
        cout << "No point where x>y found" << endl;
    }
    return 0;
}


//д) Сортировка точек по возрастанию координаты y:


#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    vector<pair<int, int>> points = {{1, 2}, {3, 4}, {5, 4}, {2, 1}, {4, 5}};
    sort(points.begin(), points.end(), [](const pair<int, int>& p1, const pair<int, int>& p2) {
        return p1.second < p2.second;
    });

    for (const auto& p : points) {
        cout << "(" << p.first << ", " << p.second << ")" << endl;
    }
    return 0;
}
