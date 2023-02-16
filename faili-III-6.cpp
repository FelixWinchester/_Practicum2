#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main() {
    ifstream in("sueta.txt");
    int sunset;
    while (in >> sunset) {
        if (sunset < 0) {
            cout << sunset << "\t";
        }
    }
    in.close();
    return 0;
}
