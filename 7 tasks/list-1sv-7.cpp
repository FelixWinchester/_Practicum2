#include <iostream>
#include <fstream>
using namespace std;

class Node { //Node используется для хранения данных и получения следующего узла (Контейнер)
public:
    int data; //Собстна данные (Логично)
    Node* next; // Указатель на следующий узел

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class Listik {
public:
    Node* head;

    Listik() {
        this->head = NULL;
    }

    void insert(int data) { // Пинаем узел в конец списка 
        Node* newNode = new Node(data);
        if (this->head == NULL) {
            this->head = newNode;
        }
        else {
            Node* current = this->head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void print() { // Вывод всех элементов на экран
        Node* current = this->head;
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void replace() { // Условие задачи (Повторяющиеся элементы заменить на один)
        Node* current = this->head;
        while (current != NULL) {
            int data = current->data;
            Node* next = current->next;
            while (next != NULL && next->data == data) {
                next = next->next;
            }
            current->next = next;
            current = next;
        }
    }
};

int main() {
    Listik list; // Создаем список
    ifstream in("input.txt");
    int data;
    while (in >> data) {
        list.insert(data); // Запихиваем в список
    }
    in.close(); list.replace();
    ofstream out("output.txt");
    Node* current = list.head; 
    while (current != NULL) { // Запихиваем в файл
        out << current->data << " ";
        current = current->next;
    }
    out.close();
    return 0;
}

// 2 часа на это... А дальше что будет...
// МЕСЯЦ ОСТАЛСЯ?!?! 😵‍💫😵
