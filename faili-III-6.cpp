#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main() {
    ifstream in("sueta.txt"); //Вхождение в файл.
    int sunset; //Просто переменная
    while (in >> sunset) { //Буквально: Читаем до конца файла.
        if (sunset < 0) { //Проверка на знак числа
            cout << sunset << "\t"; //Вывод
        }
    }
    in.close(); //Выход из файла
    return 0;
}
