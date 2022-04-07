#include "bookDatabase.h"
#include <iostream> 
using namespace std;


bool BookDatabase::doExist(string isbn) {
    if(books_list.find(isbn) != books_list.end()) return true; 
    return false; 
}

void BookDatabase::Add(string name, string author, string isbn, string publication) {

    if(doExist(isbn)) throw "Only one copy of the same book is allowed. One copy of the same book already exists in the library.";

    Book book;  book.SetParams(name, author, isbn, publication); 
    books_list[isbn] = book;
}

void BookDatabase::Update(Book book) {
    
}

void BookDatabase::ListAllBooks() {
    cout << "\033[2J\033[1;1H";

    int count = 1;

    for(auto itr = books_list.begin(); itr != books_list.end(); ++itr) {
        cout << "Book #" << (count++) << endl;
        cout << "ISBN - " << itr->first << endl; 
        cout << "Book Name - " << itr->second.name << endl;
        cout << "Book author name - " << itr->second.author << endl;
        cout << "Book publication name - " << itr->second.publication << endl; 
        cout << "\n------------------------------------------------------------\n" << endl;
    }
}

