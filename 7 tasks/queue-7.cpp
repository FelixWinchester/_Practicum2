
//Создать список из целых чисел, заменить каждую последовательность из повторяющихся элементов на од элемент
#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;

template <class Item>
class Queue{
struct Element{
    Item value; //информационное поле типа Item
    Element *next; //указатель на следующий элемент очереди
    Element (Item x) : value(x), next(NULL) {} //исправлено отсутствие фигурных скобок
};
    Element *head, *tail; //исправлено отсутствие точки с запятой
public:
    Queue() : head(NULL), tail(NULL) {}
    bool isEmpty() //возвращаем true, если очередь пуста, иначе false 
    {
        return head == NULL; //исправлено использование 0 вместо NULL
    }
    Item Get(){
        if (isEmpty())//если очередь пуста, генерируем исключение
 {
            throw "QueueException: get - queue empty";
        }else //исправлено отсутствие фигурных скобок
        {
            Element *t = head;
            Item val = t -> value;
            head = t -> next;
            if (head == NULL){
                tail = NULL;
            }
            delete t;
            return val;
        }
    }
    void Push(Item data){
        Element *t = tail; //исправлено отсутствие точки с запятой
//формируется новый элемент на который будет указывать tail
        tail = new Element(data);
//если до этого очередь была пуста, то новый элемент является и первым и последним, указатель head устанавливаем на этот элемент
        if (!head){
            head = tail;
        }else{
            t -> next = tail; //иначе новый узел помещаем в конец очереди
        }
    }
};
void removeDuplicates(Queue<int>& q) {
    if (q.isEmpty()) {
        return;
    }
 int prev = q.Get();
    Queue<int> tempQueu;
    while (!q.isEmpty()) {
        int curr = q.Get();
        if (curr != prev) {
            tempQueu.Push(prev);
            prev = curr;
        }
    }
    // Решение аналогично стеку, только с очередью
    tempQueu.Push(prev);
    while (!tempQueu.isEmpty())
        q.Push(tempQueu.Get());
}

int main(){
    Queue<int> q;
    int t, n = 14;
    cout << "Введите очереди размер = " << n << endl;
    for (int i = 0; i < n; i++){
        cin >> t;
        q.Push(t);
    }
    removeDuplicates(q);
    cout << "Result\n";
    while (!q.isEmpty()){
        cout << q.Get() << " ";
    }
    cout << endl;
    system("pause");
        // 1 2 3 3 3 4 5 6 6 68 9 8 9 - test (14 чисел)
     // 1 2 3 4 5 6 8 9 8 9 - res
}
