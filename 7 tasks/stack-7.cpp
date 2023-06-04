#include <iostream>
#include <fstream>
using namespace std;
class IntList {
public:
    struct Node {
        int value;
        Node* next;
        Node(int val) : value(val), next(nullptr) {}
    };

    IntList() : head(nullptr), tail(nullptr) {}

    ~IntList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    void push_back(int value) {
        Node* newNode = new Node(value);
        if (tail == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void remove_consecutive_duplicates() {
        Node* current = head;
        while (current != nullptr && current->next != nullptr) {
            if (current->value == current->next->value) {
                Node* temp = current->next;
                current->next = temp->next;
                if (temp == tail) {
                    tail = current;
                }
                delete temp;
            } else {
                current = current->next;
            }
        }
    }

    void print(ostream& out) const {
        Node* current = head;
        while (current != nullptr) {
            out << current->value << " ";
            current = current->next;
        }
        out << endl;
    }

private:
    Node* head;
    Node* tail;
};

int main() {
    ifstream input("input.txt");
    ofstream output("output.txt");

    IntList myList;
    int value;
    while (input >> value) {
        myList.push_back(value);
    }

    myList.remove_consecutive_duplicates();
    myList.print(output);

    input.close();
    output.close();

    return 0;
}
