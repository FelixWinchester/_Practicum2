//set-III
#include <iostream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    string text = "This is a sample text. It contains multiple sentences. Some of them end with a question mark? Others end with an exclamation mark!";

    // Создаем множество для хранения слов в предложениях
    set<string> words;

    // Разбиваем текст на предложения
    size_t pos = 0;
    while ((pos = text.find_first_of(".?!", pos)) != string::npos) {
        // Излекаем предложение
        string sentence = text.substr(0, pos + 1);

        // Удаляем знаки препинания из предложения
        sentence.erase(remove_if(sentence.begin(), sentence.end(), ::ispunct), sentence.end());

        // Разбиваем предложение на слова
        size_t start = 0;
        size_t end = sentence.find(' ');
        while (end != string::npos) {
            // Извлекаем слово
            string word = sentence.substr(start, end - start);

            // Добавляем слово в множество
            words.insert(word);

            // Переходим к следующему слову
            start = end + 1;
            end = sentence.find(' ', start);
        }

        // Обрабатываем последнее слово в предложении
        string word = sentence.substr(start);
        words.insert(word);

        // Переходим к следующему предложению
        text.erase(0, pos + 1);
        pos = 0;
    }

    // Создаем множество для хранения слов в восклицательных предложениях
    set<string> exclamatory_words;

    // Разбиваем текст на восклицательные предложения
    pos = 0;
    while ((pos = text.find_first_of("!", pos)) != string::npos) {
        // Извлекаем предложение
        string sentence = text.substr(0, pos + 1);

        // Удаляем знаки препинания из предложения
        sentence.erase(remove_if(sentence.begin(), sentence.end(), ::ispunct), sentence.end());

        // Разбиваем предложение на слова
        size_t start = 0;
        size_t end = sentence.find(' ');
        while (end != string::npos) {
            // Извлекаем слово
            string word = sentence.substr(start, end - start);

            // Добавляем слово в множество восклицательных предложений
            exclamatory_words.insert(word);

            // Переходим к следующему слову
            start = end + 1;
            end = sentence.find(' ', start);
        }

        // Обрабатываем последнее слово в предложении
        string word = sentence.substr(start);
        exclamatory_words.insert(word);

        // Переходим к следующему предложению
        text.erase(0, pos + 1);
        pos = 0;
    }

    // Создаем можество для хранения слов, которые не встречаются в восклицательных предложениях
    set<string> result;
    set_difference(words.begin(), words.end(), exclamatory_words.begin(), exclamatory_words.end(), inserter(result, result.end()));

    // Выводим результаты
    cout << "Words that do not appear in exclamatory sentences:" << endl;
    for (const auto& word : result) {
        cout << word << endl;
    }
    cout << "Total count: " << result.size() << endl;

    return 0;
}
