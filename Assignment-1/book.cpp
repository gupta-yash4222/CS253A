#include <iostream> 
#include "book.h"
using namespace std;


void Book::SetParams(string name, string author, string isbn, string publication) {
    this->name = name; this->author = author; this->isbn = isbn; this->publication = publication;
    isIssued = false; issuedTo = "";
}

void Book::ShowDetails(int reqType) {
    cout << "Book name - " << name << endl;
    cout << "Book author name - " << author << endl; 
    cout << "Book publication - " << publication << endl;

    cout << endl;

    if(reqType == 0) return;

    else if(reqType == 1) {
        if(!isIssued) {
            cout << "The book can be issued as of now" << endl;
        }
        else {
            cout << "The book is not available for issueing as of now" << endl;
        }
        return;
    }

    if(!isIssued) {
        cout << "The book is not issued to anyone yet." << endl;
    }

    else cout << "The book is issued to - " << issuedTo << endl;
    cout << "The book was issued on - " << issuedAt.dd << "/" << issuedAt.mm << "/" << issuedAt.yy << endl;
    cout << "Due date of the book is - " << dueDate.dd << "/" << dueDate.mm << "/" << dueDate.yy << endl;
}

void Book::book_request(string user_id, int userType) {
    if(this->isIssued) throw "This book is already issued to someone else.";

    this->isIssued = true; this->issuedTo = user_id;

    Time currentTime, dueTime;

    time_t now = time(0);
    tm* ltm = localtime( &now );
    currentTime.dd = ltm -> tm_mday;
    currentTime.mm = ltm -> tm_mon;
    currentTime.yy = ltm -> tm_year;

    this->issuedAt = currentTime;

    if(userType == 0) now += (30 * 24 * 60 * 60);
    else now += (60 * 24 * 60 * 60);

    tm * ltm = localtime( &now );
    dueTime.dd = ltm -> tm_mday;
    dueTime.mm = ltm -> tm_mon;
    dueTime.yy = ltm -> tm_year;

    this->dueDate = dueTime;


}

