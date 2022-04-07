#include <iostream> 
#include "book.h"
using namespace std;


void Book::SetParams(string name, string author, string isbn, string publication) {
    this->name = name; this->author = author; this->isbn = isbn; this->publication = publication;
    isIssued = false; issuedTo = "";
}

