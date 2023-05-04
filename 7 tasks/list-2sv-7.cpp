
#include <iostream> //подключение стандартной библиотеки ввода-вывода
#include <fstream> //подключение библиотеки работы с файлами

using namespace std;

class Node { //определение класса "узел"
public:
    int data; //поле "данные"
    Node* prev; //указатель на предыдущий элемент списка
    Node* next; //указатель на следующий элемент списка
    Node(int d) { //конструктор, инициализирующий поле "данные" и указатели на NULL
        data = d;
        prev = NULL;
        next = NULL;
    }
};

class List { //определение класса "связный список"
public:
    Node* head; //указатель на первый элемент списка
    Node* tail; //указатель на последний элемент списка
    List() { //конструктор по умолчанию, инициализирующий указатели на NULL
        head = NULL;
        tail = NULL;
    }
    void addNode(int d) { //метод добавления нового элемента в конец списка
        Node* newNode = new Node(d); //создание нового элемента
        if (head == NULL) { //если список пустой
            head = newNode;
            tail = newNode;
        }
        else { //если список не пустой
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    void printList() { //метод вывода списка на экран
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void replaceRepeated() { //метод замены повторяющихся элементов на один элемент
        Node* temp = head;
        while (temp != NULL) {
            int data = temp->data; //запоминаем значение текущего элемента
            int count = 1; //счётчик повторяющихся элементов
            Node* curr = temp->next; //указатель на следующий элемент списка
            while (curr != NULL && curr->data == data) { //пока следующий элемент равен текущему
                count++; //увеличиваем счётчик
                curr = curr->next; //переходим к следующему элементу
            }
            if (count > 1) { //если повторяющиеся элементы есть
                Node* newNode = new Node(data); //создаём новый элемент с данными текущего элемента
                newNode->prev = temp->prev; //устанавливаем связи между элементами
                newNode->next = curr;
                if (temp->prev != NULL) {
                    temp->prev->next = newNode;
                }
                else {
                    head = newNode;
                }
                if (curr != NULL) {
                    curr->prev = newNode;
                }
                else {
                    tail = newNode;
                }
                temp = curr; //продвигаем указатель на следующий за повторяющимися элементами
            }
            else {
                temp = temp->next; //продвигаем указатель на следующий элемент
            }
        }
    }
    void readFile(string fileName) { //метод чтения данных из файла
        ifstream fin(fileName);
        int data;
        while (fin >> data) { //пока есть данные в файле
            addNode(data); //добавляем данные в список
        }
        fin.close(); //закрываем файл
    }
    void writeFile(string fileName) { //метод записи данных из списка в файл
        ofstream fout(fileName);
        Node* temp = head;
        while (temp != NULL) { //пока не закончились элементы списка
            fout << temp->data << " "; //записываем данные в файл
            temp = temp->next; //переходим к следующему элементу
        }
        fout.close(); //закрываем файл
    }
};

int main() {
    List list;
    list.readFile("input.txt"); //чтение данных из файла
    list.printList(); //вывод исходного списка на экран 
    list.replaceRepeated(); //замена повторяющихся элементов на один элемент
    list.printList(); //вывод результирующего списка на экран
    list.writeFile("output.txt"); //запись результирующего списка в файл
    return 0;
}
