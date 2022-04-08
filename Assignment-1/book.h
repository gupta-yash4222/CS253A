#pragma once

#include <ctime>
#include <iostream> 
#include<string>
#include<unordered_map>
using namespace std;

typedef struct Time {
    int dd, mm, yy;
};

class Book {
    string issuedTo;
    bool isIssued;
    Time issuedAt;
    Time dueDate;

    public:
        string name, author, isbn, publication;
        void SetParams(string, string, string, string);
        void ShowDetails(int); 

        void book_request(string user_id, int userType);
        //Time due_date();

};