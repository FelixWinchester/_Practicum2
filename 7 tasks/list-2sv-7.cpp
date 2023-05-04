#include <iostream>
using namespace std;

// класс узла списка
class Node {
public:
    int value; // значение узла
    Node* next; // указатель на следующий узел
    Node* prev; // указатель на предыдущий узел
    // конструктор узла с заданием его значения и указателей
    Node(int value) {
        this->value = value;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

// класс двусвязного списка
class LinkedList {
public:
    Node* head; // указатель на первый элемент списка
    Node* tail; // указатель на последний элемент списка
    // конструктор списка с инициализацией указателей
    LinkedList() {
        this->head = nullptr;
        this->tail = nullptr;
    }
    // добавление элемента в конец списка
    void add(int value) {
        Node* node = new Node(value); // создание нового узла
        if (this->tail == nullptr) { // если список пуст
            this->head = node; // устанавливаем указатели на новый узел
            this->tail = node;
        } else { // если список не пуст
            node->prev = this->tail; // устанавливаем указатели на новый узел и предыдущий узел
            this->tail->next = node;
            this->tail = node; // обновляем указатель на последний узел
        }
    }
    // вывод списка на экран
    void print() {
        Node* node = this->head; // начинаем с первого узла
        while (node != nullptr) { // пока не достигнем конца списка
            cout << node->value << " "; // выводим значение узла
            node = node->next; // переходим к следующему узлу
        }
        cout << endl; // переходим на новую строку
    }
    // замена повторяющихся элементов
    void replace() {
        Node* node = this->head; // начинаем с первого узла
        while (node != nullptr) { // пока не достигнем конца списка
            Node* next = node->next; // сохраняем указатель на следующий узел
            int value = node->value; // сохраняем значение текущего узла
            while (next != nullptr && next->value == value) { // проходим по всем повторяющимся элементам
                Node* temp = next; // сохраняем указатель на текущий узел
                next = next->next; // переходим к следующему узлу
                delete temp; // удаляем текущий узел
            }
            node->next = next; // обновляем указатель на следующий узел
            if (next != nullptr) { // если следующий узел не является последним
                next->prev = node; // обновляем указатель на предыдущий узел
            }
            node = next; // переходим к следующему узлу
        }
    }
};

// функция main
int main() {
    LinkedList list; // создаем объект класса LinkedList
    // добавляем элементы в список
    list.add(1);
    list.add(2);
    list.add(2);
    list.add(3);
    list.add(3);
    list.add(3);
    list.add(4);
    list.add(4);
    list.add(4);
    list.add(4);
    list.print(); // выводим список на экран
    list.replace(); // заменяем повторяющиеся элементы
    list.print(); // выводим обновленный список на экран
    return 0;
}
