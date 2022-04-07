#include <iostream> 
#include<string>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std; 

class User {
    public:
        string name, id;
        int userType;

        /*
        User(string name, string id, string password, int userType) {
            this->name = name; this->id = id; this->password = password; this->userType = userType;
        }
        */

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
        /*
        Librarian(string name, string id, string password, int userType): User(name, id, password, userType) {}
        */

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

        /*
        Professor(string name, string id, string password, int userType): User(name, id, password, userType) {
            fine_amount = 0; list_of_books.clear(); 
        }
        */

        void SetParams(string name, string id, string password, int userType) {
            this->name = name; this->id = id; this->password = password; this->userType = userType;
            fine_amount = 0; list_of_books.clear(); 
        }

        void ShowDetails() {
            cout << "User type - " << userType << endl;
            cout << "User ID - " << id << endl;
            cout << "Name of the User - " << name << endl;
            cout << "List of books issued to the user - " << endl;

            for(auto book: list_of_books) {
                cout << book << endl;
            }
        }

    private: 
        int fine_amount;
        vector<string> list_of_books;
        void clear_fine_amount();
};

class Student: public User {
    public: 
        int calculate_fine();
        friend class Librarian;

        /*
        Student(string name, string id, string password, int userType): User(name, id, password, userType) {
            fine_amount = 0; list_of_books.clear(); 
        
        }
        */

        void SetParams(string name, string id, string password, int userType) {
            this->name = name; this->id = id; this->password = password; this->userType = userType;
            fine_amount = 0; list_of_books.clear(); 
        }

        void ShowDetails() {
            cout << "User type - " << userType << endl;
            cout << "User ID - " << id << endl;
            cout << "Name of the User - " << name << endl;
            cout << "List of books issued to the user - " << endl;

            for(auto book: list_of_books) {
                cout << book << endl;
            }
        }

    private: 
        int fine_amount;
        vector<string> list_of_books;
        void clear_fine_amount();
};