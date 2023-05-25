#include <iostream> 
#include <vector> 
#include <algorithm> 

using namespace std;

class Sound { // объявление класса "Звук"
public:
    int note; // поле "нота"
    int duration; // поле "длительность"

    Sound(int n, int d) { // конструктор класса
        note = n; // инициализация поля "нота"
        duration = d; // инициализация поля "длительность"
    }
};

int main() { // главная функция программы
    vector<Sound> melody; // создание динамического массива объектов класса "Звук"
    melody.push_back(Sound(1, 2)); // добавление элемента в массив
    melody.push_back(Sound(2, 2)); 
    melody.push_back(Sound(3, 1)); 
    melody.push_back(Sound(4, 3));
    melody.push_back(Sound(5, 1)); 
    melody.push_back(Sound(6, 2)); 

    // Удаление звуков одинаковой длительности
    for (int i = 0; i < melody.size(); i++) { // цикл по элементам массива
        for (int j = i + 1; j < melody.size(); j++) { // цикл по элементам массива, следующим за текущим
            if (melody[i].duration == melody[j].duration) { // если длительности элементов равны
                melody.erase(melody.begin() + j); // удалить элемент из массива
                j--; // уменьшить счетчик, чтобы не пропустить следующий элемент
            }
        }
    }

    // Вывод измененной мелодии
    for (int i = 0; i < melody.size(); i++) { // цикл по элементам массива
        cout << "Note: " << melody[i].note << " Duration: " << melody[i].duration << endl; // вывод информации о звуке
    }
} 
