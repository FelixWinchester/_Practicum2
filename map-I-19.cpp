#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
    map<int, int> last_occurrence;
    vector<int> numbers;

    // чтение входных данных
    int num;
    while (cin >> num) {
        numbers.push_back(num);
    }

    // обработка входных данных
    for (int i = 0; i < numbers.size(); i++) {
        int num = numbers[i];
        if (last_occurrence.count(num) == 0) {
            last_occurrence[num] = i;
        }
    }

    // вывод результатов
    for (int i = 0; i < numbers.size(); i++) {
        int num = numbers[i];
        int opposite_num = -num;
        if (last_occurrence.count(opposite_num) > 0 && last_occurrence[opposite_num] > last_occurrence[num]) {
            cout << opposite_num << " ";
        } else {
            cout << num << " ";
        }
    }
    return 0;
}
