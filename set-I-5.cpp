#include <iostream>
#include <set>
#include <vector>
using namespace std;
set<int> get_digits(int number) {
    set<int> digits;
    while (number > 0) {
        digits.insert(number % 10);
        number /= 10;
    }
    return digits;
}

set<int> intersection(const set<int>& a, const set<int>& b) {
    set<int> result;
    for (const int& element : a) {
        if (b.count(element)) {
            result.insert(element);
        }
    }
    return result;
}

set<int> union_sets(const set<int>& a, const set<int>& b) {
    set<int> result = a;
    result.insert(b.begin(), b.end());
    return result;
}

int main() {
    int N;
    cin >> N;
    vector<int> numbers(N);
    for (int i = 0; i < N; ++i) {
        cin >> numbers[i];
    }

    set<int> unique_digits;
    for (const int& number : numbers) {
        if (number >= 100 && number <= 999) {
            set<int> digits = get_digits(number);
            unique_digits = union_sets(unique_digits, digits);
        }
    }

    for (const int& digit : unique_digits) {
        cout << digit << " ";
    }

    return 0;
}
/*
Ввод: 5 {123,456,789,-321,1000}
*/
