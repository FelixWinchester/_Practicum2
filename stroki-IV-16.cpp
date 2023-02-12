#include <iostream>
#include <windows.h>
#include <cmath>
#include <fstream>
#include <string>
using namespace std;
int main(){
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    auto counter = 0;
    string s,b;
    ifstream in("sueta.txt.txt");
    while (in.peek() != EOF) {
        getline(in, s); 
        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i]) && (i == 0 || !isdigit(s[i - 1]))) {

                counter++;
            }
        }
    }
    cout << counter;
}
