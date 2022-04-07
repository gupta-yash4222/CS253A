#include <iostream> 
#include<string>
#include<unordered_map>
using namespace std;

class Book {
    string issuedTo;
    bool isIssued;
    //Time issuedAt;

    public:
        string name, author, isbn, publication;
        void SetParams(string, string, string, string);

        bool book_request(string user_id);
        //Time due_date();

};