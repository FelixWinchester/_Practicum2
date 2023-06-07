// Подключаем необходимые библиотеки
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <sstream>
using namespace std;

int main() {
    // Открываем входной файл для чтения
    ifstream inputFile("input.txt");
    // Проверяем, удалось ли открыть файл
    if (!inputFile) {
        cerr << "Unable to open input file" << endl;
        return 1;
    }

    // Открываем выходной файл для записи
    ofstream outputFile("output.txt");
    // Проверяем, удалось ли открыть файл
    if (!outputFile) {
        cerr << "Unable to open output file" << endl;
        return 1;
    }

    // Создаем словарь для хранения последнего вхождения каждого числа
    map<int, int> last_occurrence;
    // Создаем вектор для хранения чисел из входного файла
    vector<int> numbers;
    // Строка для чтения из входного файла
    string line;
    // Переменная для хранения числа, считанного из строки
    int number;

    // Читаем входной файл построчно
    while (getline(inputFile, line)) {
        // Создаем поток для чтения чисел из строки
        istringstream iss(line);
        // Считываем числа из потока и добавляем их в вектор
        while (iss >> number) {
            numbers.push_back(number);
            // Запоминаем последнее вхождение числа в словаре
            last_occurrence[number] = numbers.size() - 1;
        }
    }
    // Закрываем входной файл
    inputFile.close();

    // Обходим вектор чисел и ищем для каждого числа противоположное
    for (int i = 0; i < numbers.size(); i++) {
        int num = numbers[i];
        int opposite_num = -num;

        // Если оба числа уже встречались в векторе, выводим информацию о них
        if (last_occurrence.count(num) && last_occurrence.count(opposite_num)) {
            outputFile << "Number: " << num << ", Last occurrence: " << last_occurrence[num]
                       << ", Opposite number: " << opposite_num << ", Last occurrence: " << last_occurrence[opposite_num] << endl;
        } else if (last_occurrence.count(num)) {
            // Если только первое число встречалось, выводим информацию о нем и о том, что противоположное не найдено
            outputFile << "Number: " << num << ", Last occurrence: " << last_occurrence[num]
                       << ", Opposite number: " << opposite_num << ", Last occurrence: Not found" << endl;
        } else {
            // Если первое число не встречалось, выводим информацию о нем и о последнем вхождении противоположного числа
            outputFile << "Number: " << num << ", Last occurrence: Not found"
                       << ", Opposite number: " << opposite_num << ", Last occurrence: " << last_occurrence[opposite_num] << endl;
        }
    }

    // Закрываем выходной файл
    outputFile.close();
    // Выводим сообщение о завершении работы программы
    cout << "Results written to output.txt" << endl;
    // Возвращаем код успешного завершения программы
    return 0;
}
