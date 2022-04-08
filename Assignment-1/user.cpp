#include "user.h"
#include "bookDatabase.h"
#include <iostream>

void User::SetPassword(string password) {
    this->password = password;
}

void Student::clear_fine_amount() {
    if (this->fine_amount == 0) throw "Fine amount of the user is already null";
    
    this->fine_amount = 0;
}

void Student::ShowIssuedBooks() {
    for(auto book: list_of_books) {
        book.ShowDetails(0);
    }
}

void Student::ShowDetails() {
    cout << "User type - " << userType << endl;
    cout << "User ID - " << id << endl;
    cout << "Name of the User - " << name << endl;
    cout << "List of books issued to the user - " << endl;

    ShowIssuedBooks();
}

bool Student::CheckBookNums() {
    if(books_num >= MAX_STUDENT_BOOK_ISSUES) return false;
    return true;
}

void Student::AddBook(Book book) {
    list_of_books.push_back(book); 
    books_num++;
}

int Student::CalculateFine() {
    int total_fine = 0;

    for(auto book: list_of_books) {
        total_fine += book.CalculateFine(0);
    }

    return total_fine;
}


void Professor::clear_fine_amount() {
    if (this->fine_amount == 0) throw "Fine amount of the user is already null";
    
    this->fine_amount = 0;
} 

void Professor::ShowIssuedBooks() {
    for(auto book: list_of_books) {
        book.ShowDetails(0);
    }
}

void Professor::ShowDetails() {
    cout << "User type - " << userType << endl;
    cout << "User ID - " << id << endl;
    cout << "Name of the User - " << name << endl;
    cout << "List of books issued to the user - " << endl;

    ShowIssuedBooks();
}

void Professor::AddBook(Book book) {
    list_of_books.push_back(book);
}

int Professor::CalculateFine() {
    int total_fine = 0;

    for(auto book: list_of_books) {
        total_fine += book.CalculateFine(1);
    }

    return total_fine;
}
