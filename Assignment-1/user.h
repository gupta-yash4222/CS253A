#pragma once

#include <iostream> 
#include<string>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include "book.h"
using namespace std; 

#define MAX_STUDENT_BOOK_ISSUES 5

class User {
    public:
        string name, id;
        int userType;

        void SetPassword(string);
        bool VerifyPassword(string pwd_in) {
            return (password == pwd_in);
        }

        string getPassword() {
            return password;
        }

    protected:
        string password;
};

class Librarian: public User {
    public:
        void SetParams(string name, string id, string password, int userType) {
            this->name = name; this->id = id; this->password = password; this->userType = userType;
        }

        void ShowDetails() {
            cout << "User type - " << userType << endl;
            cout << "User ID - " << id << endl;
            cout << "Name of the User - " << name << endl;
        }

}; 

class Professor: public User {
    public:
        int calculate_fine();
        friend class Librarian;

        void SetParams(string name, string id, string password, int userType) {
            this->name = name; this->id = id; this->password = password; this->userType = userType;
            fine_amount = 0; list_of_books.clear(); 
        }

        void ShowIssuedBooks();

        void ShowDetails();

        void AddBook(Book);

    private: 
        int fine_amount;
        vector<Book> list_of_books;
        void clear_fine_amount();
};

class Student: public User {
    public: 
        int calculate_fine();
        friend class Librarian;

        void SetParams(string name, string id, string password, int userType) {
            this->name = name; this->id = id; this->password = password; this->userType = userType;
            fine_amount = 0; list_of_books.clear(); 
        }
        
        void ShowIssuedBooks();

        void ShowDetails();

        bool CheckBookNums();

        void AddBook(Book);

    private: 
        int fine_amount, books_num;
        vector<Book> list_of_books;
        void clear_fine_amount();
};