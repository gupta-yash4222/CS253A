#include <iostream>
#include "book.h"
using namespace std;

class BookDatabase {
    public: 
        bool doExist(string);
        void ListAllBooks();

        friend class Librarian;

        void Add(string, string, string, string);
        void Update(Book);
        void Delete(string, string);
        Book* Search(string, string);


    private: 
        unordered_map<string, Book> books_list;
};