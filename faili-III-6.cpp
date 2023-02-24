//* faili-III-6.cpp *\\
//* Файл - sueta.txt *\\


#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main() {
    /*
    int kolichestvo, x;
    ofstream fout("sueta.bin", ios_base::binary);
    cin >> kolichestvo;
    for (int i=0; i < kolichestvo; i++){
        cin >> x;
    fout.write((char*)&x, sizeof(int));
    }
    fout.close();
    return 0;
    */
   
   int aboba;
   ifstream fout("sueta.bin", ios_base::binary);
    
   
   while (fout.eof()){
    fout.read((char*)&aboba, sizeof(int));
    
   }
   cout << aboba << endl;
   fout.close();
    return 0;
    
    
}
