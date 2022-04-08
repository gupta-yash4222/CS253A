#include <iostream> 
#include "book.h"
using namespace std;

int FINE[2] = {2, 5};

int MONTH_DAYS[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};


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

    else{
        cout << "The book is issued to - " << issuedTo << endl;
        cout << "The book was issued on - " << issuedAt.dd << "/" << issuedAt.mm << "/" << issuedAt.yy << endl;
        cout << "Due date of the book is - " << dueDate.dd << "/" << dueDate.mm << "/" << dueDate.yy << endl;
    } 
}

void Book::book_request(string user_id, int userType) {
    if(this->isIssued) throw "This book is already issued to someone else.";

    this->isIssued = true; this->issuedTo = user_id;

    Time currentTime, dueTime;

    time_t now = time(0);
    tm* ltm = localtime( &now );
    currentTime.dd = ltm -> tm_mday;
    currentTime.mm = 1 + ltm -> tm_mon;
    currentTime.yy = 1900 + ltm -> tm_year;
    currentTime.now = now;

    this->issuedAt = currentTime;

    if(userType == 0) now += (30 * 24 * 60 * 60);
    else now += (60 * 24 * 60 * 60);

    tm * ltm1 = localtime( &now );
    dueTime.dd = ltm1 -> tm_mday;
    dueTime.mm = 1 + ltm1 -> tm_mon;
    dueTime.yy = 1900 + ltm1 -> tm_year;
    dueTime.now = now;

    this->dueDate = dueTime;


}

int Book::CalculateFine(int userType) {

    time_t now = time(0);
    if(now >= (this->dueDate).now ) return 0;

    time_t diff = now - (this->dueDate).now;
    tm* ltm = localtime ( &now );
    int days = (ltm -> tm_mday) + (MONTH_DAYS[ltm -> tm_mon] * (ltm -> tm_mon)) + (365 * (ltm -> tm_year));

    return (days * FINE[userType]);
}

