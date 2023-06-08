//map 2
#include <iostream> 
#include <map> 
#include <vector> 
#include <algorithm> 
 
using namespace std; 
 
class Library { 
private: 
    map<string, vector<string>> books; 
 
public: 
    void addAuthor(string author) { 
        books[author] = {}; 
    } 
 
    void removeAuthor(string author) { 
        books.erase(author); 
    } 
 
    void addBook(string author, string book) { 
        books[author].push_back(book); 
    } 
 
    void removeBook(string author, string book) { 
        auto it = find(books[author].begin(), books[author].end(), book); 
        if (it != books[author].end()) { 
            books[author].erase(it); 
        } 
    } 
 
    void modifyBook(string author, string oldBook, string newBook) { 
        auto it = find(books[author].begin(), books[author].end(), oldBook); 
        if (it != books[author].end()) { 
            *it = newBook; 
        } 
    } 
 
    void fixAuthorName(string oldName, string newName) { 
        if (books.count(oldName) > 0) { 
            books[newName] = books[oldName]; 
            books.erase(oldName); 
        } 
    } 
 
    void removeAuthorsBeforeYear(int year) { 
        for (auto it = books.begin(); it != books.end(); ) { 
            bool hasBookAfterYear = false; 
            for (string book : it->second) { 
                // assume book title ends with year in parentheses 
                int bookYear = stoi(book.substr(book.size() - 5, 4)); 
                if (bookYear >= year) { 
                    hasBookAfterYear = true; 
                    break; 
                } 
            } 
            if (!hasBookAfterYear) { 
                it = books.erase(it); 
            } else { 
                ++it; 
            } 
        } 
    } 
 
    vector<string> getBooksByAuthor(string author) { 
        return books[author]; 
    } 
}; 
 
int main() { 
    Library library; 
 
    library.addAuthor("Leo Tolstoy"); 
    library.addBook("Leo Tolstoy", "War and Peace (1869)"); 
    library.addBook("Leo Tolstoy", "Anna Karenina (1877)"); 
 
    library.addAuthor("Fyodor Dostoevsky"); 
    library.addBook("Fyodor Dostoevsky", "Crime and Punishment (1866)"); 
    library.addBook("Fyodor Dostoevsky", "The Brothers Karamazov (1880)"); 
 
    vector<string> tolstoyBooks = library.getBooksByAuthor("Leo Tolstoy"); 
    for (string book : tolstoyBooks) { 
        cout << book << endl; 
    } 
    // Output: 
    // War and Peace (1869) 
    // Anna Karenina (1877) 
 
    library.removeBook("Leo Tolstoy", "Anna Karenina (1877)"); 
 
    library.modifyBook("Fyodor Dostoevsky", "Crime and Punishment (1866)", "Notes from Underground (1864)"); 
 
    library.fixAuthorName("Leo Tolstoy", "Lev Tolstoy"); 
 
    library.removeAuthorsBeforeYear(1870); 
 
    vector<string> dostoevskyBooks = library.getBooksByAuthor("Fyodor Dostoevsky"); 
    for (string book : dostoevskyBooks) { 
        cout << book << endl; 
    } 
    // Output: 
    // Notes from Underground (1864) 
 
    return 0; 
}
