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

void BookDatabase::Update(string isbn, string new_name, string new_author, string new_publication) {
    if(!doExist(isbn)) throw "No book with the given ISBN exist";
    books_list[isbn].SetParams(isbn, new_name, new_author, new_publication);
}

void BookDatabase::Delete(string isbn) {
    if(!doExist(isbn)) throw "Book with the given ISBN doesn't exist";

    books_list.erase(isbn);
}

void BookDatabase::ShowDetails(string isbn) {
    if(!doExist(isbn)) throw "No book with the given ISBN exist";

    books_list[isbn].ShowDetails(2);
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

void BookDatabase::IssueBook(string id, int userType, string isbn) {

    if(!doExist(isbn)) throw "No book with the given ISBN exist";

    try {
        books_list[isbn].book_request(id, userType);
    }
    catch(char* msg) {
        throw msg;
    }
}

Book BookDatabase::Search(string isbn) {
    return books_list[isbn];
}
