//дописать функцию вычитание (Вычесть из трехзначных все остальные)

#include <iostream> 
#include <set> // подключаем библиотеку множеств
#include <vector> // подключаем библиотеку векторов
using namespace std; 
set<int> get_digits(int number) { // объявляем функцию get_digits с аргументом number типа int и возвращающую множество целых чисел
    set<int> digits; // создаем пустое множество digits типа int
    while (number > 0) { // пока число number больше нуля
        digits.insert(number % 10); // добавляем в множество последнюю цифру числа number
        number /= 10; // удаляем последнюю цифру числа number
    }
    return digits; // возвращаем множество цифр числа number
}

set<int> intersection(const set<int>& a, const set<int>& b) { // объявляем функцию intersection с аргументами a и b типа множество целых чисел и возвращающую множество целых чисел
    set<int> result; // создаем пустое множество result типа int
    for (const int& element : a) { // для каждого элемента в множестве a
        if (b.count(element)) { // если элемент содержится в множестве b
            result.insert(element); // добавляем элемент в множество result
        }
    }
    return result; // возвращаем множество result
}

set<int> union_sets(const set<int>& a, const set<int>& b) { // объявляем функцию union_sets с аргументами a и b типа множество целых чисел и возвращающую множество целых чисел
    set<int> result = a; // создаем множество result и копируем в него множество a
    result.insert(b.begin(), b.end()); // добавляем в множество result все элементы из множества b
    return result; // возвращаем множество result
}

int main() { 
    int N; 
    cin >> N; 
    vector<int> numbers(N); // создаем вектор numbers размера N типа int
    for (int i = 0; i < N; ++i) { // для каждого i от 0 до N-1
        cin >> numbers[i]; // считываем i-е число в вектор numbers
    }

    set<int> unique_digits; // создаем пустое множество unique_digits типа int
    for (const int& number : numbers) { // для каждого числа number в векторе numbers
        if (number >= 100 && number <= 999) { // если число number трехзначное
            set<int> digits = get_digits(number); // получаем множество цифр числа number
            unique_digits = union_sets(unique_digits, digits); // объединяем множество unique_digits и множество digits
        }
    }

    for (const int& digit : unique_digits) { // для каждой цифры digit в множестве unique_digits
        cout << digit << "\t"; 
    }

    return 0; 
}

/*
Ввод: 5 {123,456,789,-321,1000}
*/
