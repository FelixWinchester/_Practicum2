#include <iostream>
#include <fstream>
using namespace std;

// Описание класса Stack
class Stack {
// Объявление закрытых полей класса
private:
    int* arr; // Указатель на массив элементов стека
    int top; // Индекс верхнего элемента стека
    int size; // Размер стека
// Объявление открытых методов класса
public:
    // Конструктор класса Stack
    Stack(int s) {
        size = s;
        arr = new int[size];
        top = -1;
    }
    // Деструктор класса Stack
    ~Stack() {
        delete[] arr;
    }
    // Метод для добавления элемента в стек
    void push(int num) {
        // Проверка на переполнение стека
        if (top == size - 1) {
            cout << "Stack overflow" << endl;
            return;
        }
        top++;
        arr[top] = num;
    }
    // Метод для удаления элемента из стека
    int pop() {
        // Проверка на пустоту стека
        if (top == -1) {
            cout << "Stack underflow" << endl;
            return -1;
        }
        int num = arr[top];
        top--;
        return num;
    }
    // Метод для получения верхнего элемента стека без его удаления
    int peek() {
        // Проверка на пустоту стека
        if (top == -1) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return arr[top];
    }
    // Метод для проверки на пустоту стека
    bool isEmpty() {
        return top == -1;
    }
};

// Главная функция программы
int main() {
    // Открытие файлов для чтения и записи
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    // Чтение размера стека из файла
    int n;
    fin >> n;
    // Создание объекта класса Stack
    Stack s(n);
    // Чтение первого элемента из файла и добавление его в стек
    int num;
    fin >> num;
    s.push(num);
    // Чтение остальных элементов из файла и добавление их в стек с проверкой на повторы
    for (int i = 1; i < n; i++) {
        fin >> num;
        if (num == s.peek()) {
            continue;
        }
        else {
            while (!s.isEmpty()) {
                fout << s.pop() << " ";
            }
            s.push(num);
        }
    }
    // Вывод оставшихся элементов стека в файл
    while (!s.isEmpty()) {
        fout << s.pop() << " ";
    }
    // Закрытие файлов
    fin.close();
    fout.close();
    return 0;
}
