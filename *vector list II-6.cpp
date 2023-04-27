// а)

#include <iostream>
#include <list>
#include <string>

using namespace std;

struct Composition {
    string artist;
    string name;
};

void deleteAndInsert(list<Composition>& compositions, string artist, string newName, string afterComposition) {
    // Удаляем первую встретившуюся композицию данного исполнителя
    for (auto it = compositions.begin(); it != compositions.end(); ++it) {
        if (it->artist == artist) {
            compositions.erase(it);
            break;
        }
    }
    // Вставляем новую запись после заданной композиции
    for (auto it = compositions.begin(); it != compositions.end(); ++it) {
        if (it->name == afterComposition) {
            compositions.insert(++it, {artist, newName});
            break;
        }
    }
}

int main() {
    list<Composition> compositions = {
        {"Adele", "Hello"},
        {"Ed Sheeran", "Shape of You"},
        {"Taylor Swift", "Blank Space"},
        {"Adele", "Someone Like You"},
        {"Coldplay", "Viva La Vida"}
    };
    deleteAndInsert(compositions, "Adele", "Rolling in the Deep", "Hello");
    for (auto& composition : compositions) {
        cout << composition.artist << " - " << composition.name << endl;
    }
    return 0;
}


//б) 

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Composition {
    string artist;
    string name;
};

void deleteAndChange(vector<Composition>& compositions, string artist, string newName) {
    // Удаляем две последние композиции списка
    compositions.erase(compositions.end() - 2, compositions.end());
    // Меняем имя заданного исполнителя во всех относящихся к нему записях
    for (auto& composition : compositions) {
        if (composition.artist == artist) {
            composition.artist = newName;
        }
    }
}

int main() {
    vector<Composition> compositions = {
        {"Adele", "Hello"},
        {"Ed Sheeran", "Shape of You"},
        {"Taylor Swift", "Blank Space"},
        {"Adele", "Someone Like You"},
        {"Coldplay", "Viva La Vida"}
    };
    deleteAndChange(compositions, "Adele", "Adele Adkins");
    for (auto& composition : compositions) {
        cout << composition.artist << " - " << composition.name << endl;
    }
    return 0;
}
