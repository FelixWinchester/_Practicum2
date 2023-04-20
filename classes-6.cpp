#include <iostream>
#include <cmath>
using namespace std;


class Vector { // Ну типа класс (Ваще супер) Vector, который нужно создать по условию задачи //
private:
    int x; // Поле x //
    int y; // Поле y //

public:
    Vector(int x, int y) {  // Конструктор (Lego)
        this->x = x;
        this->y = y;
    }

    void print() { // Собстна Вектор (Пришлось читать лекции по алгему, чтобы вспомнить что такое вектор) //
        cout << "(" << x << ", " << y << ")" << endl;
    }
    
    double length() { // Собстна длина вектора
        return sqrt(x * x + y * y);
    }
    
    bool equals(Vector death) { // Проверка: равен ли данный вектор другому вектору, переданному в качестве аргумента. // bool - потому что либо да, либо не да //
        return x == death.x && y == death.y;
    }
    
    // Дальше бога нет, есть только перегрузки... //

    Vector operator+(const Vector& death) {
        return Vector(x + death.x, y + death.y); // К значению текущих объектов X и Y прибавляется значение текущего метода
    }
    
    Vector operator-(const Vector& death) {
        return Vector(x - death.x, y - death.y); // Из значения текущего объекта X и Y вычитается значение текущего метода
    }
    
    int operator*(const Vector& death) {
        return x * death.x + y * death.y;
    }
    
    int operator^(const Vector& death) {
        return x * death.y - y * death.x;
    }
};

// Дальше бог появился, но не на долго.
int main() {
    // Можно было, конечно, сделать ввод с клавиатуры, но мне лень :) //
    Vector v1(1, 2); // Таки ввод вектора 1 
    Vector v2(3, 4); // Таки ввод вектора 2
    Vector sum = v1 + v2; // Сумма какая - то...

    cout << "Summa: "; sum.print();
    Vector diff = v2 - v1;
    cout << "Raznitsa: "; diff.print();

    cout << "Umnojenie: " << v1 * v2 << endl;
    cout << "Cross product: " << (v1 ^ v2) << endl;
    cout << "Length of v1: " << v1.length() << endl;
    //Дальше ответ таков: 1 - сойдет 0 - !сойдет
    cout << "v1 equals v2: " << v1.equals(v2) << endl; 
    cout << "v1 equals v1: " << v1.equals(v1) << endl;
    return 0;
}
