#include "user.h"

class UserDatabase {
    public:
        friend class Librarian;

        bool doExist(string);
        bool AuthenticateUser(string, string);
        void ListAllUsers();

        void Add(string, string, string, int);
        void Update(string, string, string, int);
        void Delete(string);
        void ShowDetails(string);
        User* Search(string);

    private:
        unordered_map<string, int> users_list;
        unordered_map<string, Student> students_list;
        unordered_map<string, Professor> professors_list;
        unordered_map<string, Librarian> librarians_list;

};

/*

class UserDatabase {
    public:
        friend class Librarian;

        unordered_map<string, User> users_list;

        bool doExist(string);
        User* AuthenticateUser(string, string);
        void ListAllUsers();

        void Add(string, string, string, int);
        void Update();
        void Delete();
        User* Search(string);

};

*/

