#include <iostream> 
#include <string> 
#include <ctime>
using namespace std;

class Persona { // объявление класса Persona
protected: // модификатор доступа protected
    string surname; // фамилия
    int day, month, year; // день, месяц, год рождения
public: // модификатор доступа public
    Persona(string s, int d, int m, int y) : surname(s), day(d), month(m), year(y) {} // конструктор класса
    virtual void printInfo() = 0; // виртуальная функция вывода информации
    int getAge() { // метод для получения возраста
        time_t t = time(NULL); // получение текущего времени
        tm* timePtr = localtime(&t); // преобразование времени в структуру tm
        int currentYear = timePtr->tm_year + 1900; // текущий год
        int currentMonth = timePtr->tm_mon + 1; // текущий месяц
        int currentDay = timePtr->tm_mday; // текущий день
        int age = currentYear - year; // вычисление возраста
        if (currentMonth < month || (currentMonth == month && currentDay < day)) { // если текущий месяц меньше месяца рождения или текущий месяц равен месяцу рождения, но текущий день меньше дня рождения
            age--; // уменьшаем возраст на 1
        }
        return age; // возвращаем возраст
    }
};

class Enrolle : public Persona { // объявление класса Enrolle, наследующего класс Persona
protected: // модификатор доступа protected
    string faculty; // факультет
public: // модификатор доступа public
    Enrolle(string s, int d, int m, int y, string f) : Persona(s, d, m, y), faculty(f) {} // конструктор класса
    void printInfo() { // метод вывода информации
        cout << "Enrolle: " << surname << ", " << getAge() << " years old, faculty: " << faculty << endl; // вывод информации о студенте
    }
};

class Student : public Enrolle { // объявление класса Student, наследующего класс Enrolle
protected: 
    int course; // курс
public: 
    Student(string s, int d, int m, int y, string f, int c) : Enrolle(s, d, m, y, f), course(c) {} // конструктор класса
    void printInfo() { // метод вывода информации
        cout << "Student: " << surname << ", " << getAge() << " years old, faculty: " << faculty << ", course: " << course << endl; // вывод информации о студенте
    }
};

class Teacher : public Enrolle { // объявление класса Teacher, наследующего класс Enrolle
protected: 
    string position; // должность
    int experience; // опыт работы
public: 
    Teacher(string s, int d, int m, int y, string f, string p, int e) : Enrolle(s, d, m, y, f), position(p), experience(e) {} // конструктор класса
    void printInfo() { // метод вывода информации
        cout << "Teacher: " << surname << ", " << getAge() << " years old, faculty: " << faculty << ", position: " << position << ", experience: " << experience << endl; // вывод информации о преподавателе
    }
};

int main() { 
    const int n = 5; // количество людей
    Persona* people[n]; // массив указателей на объекты класса Persona
    people[0] = new Enrolle("Ivanov", 10, 2, 2001, "IT"); // создание объекта класса Enrolle
    people[1] = new Student("Petrov", 20, 5, 1999, "Economics", 3); // создание объекта класса Student
    people[2] = new Teacher("Sidorov", 15, 11, 1978, "Mathematics", "Professor", 20); // создание объекта класса Teacher
    people[3] = new Enrolle("Smith", 7, 9, 2003, "Physics"); // создание объекта класса Enrolle
    people[4] = new Student("Johnson", 3, 12, 2000, "IT", 2); // создание объекта класса Student

    cout << "All people:" << endl; // вывод на экран
    for (int i = 0; i < n; i++) { // цикл для вывода информации о всех людях
        people[i]->printInfo(); // вызов метода вывода информации
    }

    int minAge = 18, maxAge = 25; // минимальный и максимальный возраст
    cout << "People whose age is between " << minAge << " and " << maxAge << ":" << endl; // вывод на экран
    for (int i = 0; i < n; i++) { // цикл для вывода информации о людях, возраст которых находится в заданном диапазоне
        int age = people[i]->getAge(); // получение возраста
        if (age >= minAge && age <= maxAge) { // если возраст находится в заданном диапазоне
            people[i]->printInfo(); // вызов метода вывода информации
        }
    }

    for (int i = 0; i < n; i++) { // цикл для удаления объектов
        delete people[i]; // удаление объекта
    }
    return 0; 
