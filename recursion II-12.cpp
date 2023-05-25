//** рекурсия-II-12 **\\
// II - разработать рекурсивную функцию, возвращающая значение: || 12 - Для вычисления суммы цифр в строке: с помощью данной функции определить, 
// в каком из двух предложений сумма цифр больше. 


#include <iostream>
#include <string>

using namespace std;

int summa(string str) {
    if (str.length() == 0) { // базовый случай
        return 0;
    } else {
        int digit = str[0] - '0'; // преобразование символа в цифру
        return digit + summa(str.substr(1)); // рекурсивный вызов для оставшейся части строки
    }
}

int main() {
    string sentence1 = "I have 3 apples and 5 oranges";
    string sentence2 = "There are 2 cats and 7 dogs in the yard";
    
    int sum1 = summa(sentence1);
    int sum2 = summa(sentence2);
    
    if (sum1 > sum2) {
        cout << "The sum of digits in sentence 1 is greater than in sentence 2";
    } else if (sum2 > sum1) {
        cout << "The sum of digits in sentence 2 is greater than in sentence 1";
    } else {
        cout << "The sum of digits in both sentences is equal";
    }
    
    return 0;

}
