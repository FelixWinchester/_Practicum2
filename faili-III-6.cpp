//* faili-III-6.cpp *\\ //зачтено

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main() {
    
    
    int kolichestvo, x;
    ofstream fout("sueta.bin", ios_base::binary);
    cin >> kolichestvo;
    for (int i=0; i < kolichestvo; i++){
        cin >> x;
    fout.write((char*)&x, sizeof(int));
    }
    fout.close();
    
   
   int aboba;
   ifstream fin("sueta.bin", ios_base::binary);
   while (fin.peek() != EOF){
    fin.read((char*)&aboba, sizeof(int));
    if (aboba < 0){
   cout << aboba << endl;
        }
   }
   
    fin.close();
    return 0;
    
    
}
