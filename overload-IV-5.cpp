#include <iostream> //зачтено
#include <cmath>
#include <string>
#include <fstream>
// #include <mozgi> // Источник "мозги" не найден, как иронично...
using namespace std;

float a,b;
float F(float x){
    if (pow(x,2-5*x<0))
    return a+b;

     else if(0 <= (pow(x,2) - 5 * x) && (pow(x,2) - 5 * x) <10)
    return a - b;

    else if(pow(x,2) - 5 * x >= 10)
    return a * b;

}

void F(float x, float &y){

if (pow(x,2-5*x<0))
    y= a+b;
     else if(0 <= (pow(x,2) - 5 * x) && (pow(x,2) - 5 * x) <10)
    y=a-b;

    else if(pow(x,2) - 5 * x >= 10)
    y=a*b;
}



int main(){
    float x,h,y;
    cout << "a= ";
    cin >> a;
    cout << "b= ";
    cin >> b;
    cout << "h= ";
    cin >> h;
    cout << "x\tf(x)\n";
   for (float i=a ; i<=b; i += h) {
        cout << i << "\t";
        cout << F(i) << endl;
        F(i,y);
        cout << y << endl;
        
    }

return 0;
}
