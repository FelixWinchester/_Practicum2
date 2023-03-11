//* stroki-IV-16 *\\
//* Файл - sueta.txt.txt *\\ //Зачтено

#include <iostream>
#include <windows.h>
#include <cmath>
#include <fstream>
#include <string>
using namespace std;
int main(){
    auto counter = 0; //Счётчик.
    string s,b;
    ifstream in("sueta.txt.txt"); //Вхождение в файл.
    while (in.peek() != EOF) { //Проход по файлу до конца.
        getline(in, s); //Ввод строки
        for (int i = 0; i < s.size(); i++) { //Обычный цЫкОл.
            if (isdigit(s[i]) && (i == 0 || !isdigit(s[i - 1]))) { //Проверка на цифру.

                counter++;
            }
        }
    }
    cout << counter;
}
