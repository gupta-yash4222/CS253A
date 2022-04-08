#pragma once

#include "user.h"

class UserDatabase {
    public:
        friend class Librarian;

        bool doExist(string);
        bool AuthenticateUser(string, string);
        void ListAllUsers();
        int GetUserType(string);

        void Add(string, string, string, int);
        void Update(string, string, string, int);
        void Delete(string);
        void ShowDetails(string);
        void ShowIssuedBooks(string);
        bool IsUserAllowedToIssue(string);
        void AddBookToUser(string, Book);
        User* Search(string);

    private:
        unordered_map<string, int> users_list;
        unordered_map<string, Student> students_list;
        unordered_map<string, Professor> professors_list;
        unordered_map<string, Librarian> librarians_list;

};


