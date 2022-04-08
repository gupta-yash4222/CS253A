#pragma once

#include <iostream>
#include "book.h"
using namespace std;

class BookDatabase {
    public: 
        bool doExist(string);
        void ListAllBooks();
        void ShowDetails(string); 
        void IssueBook(string, int, string);

        friend class Librarian;

        void Add(string, string, string, string);
        void Update(string, string, string, string);
        void Delete(string);
        Book Search(string);


    private: 
        unordered_map<string, Book> books_list;
};