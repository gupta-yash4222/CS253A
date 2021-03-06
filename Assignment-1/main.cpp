#include<bits/stdc++.h>
#include<ctime>
#include<chrono>
#include<thread>
#include<typeinfo>
#include "userDatabase.h"
#include "bookDatabase.h"

using namespace std;
using namespace this_thread;
using namespace chrono;

bool session = false;
int sessionType = -1;
int command = -1;

UserDatabase userdb;
BookDatabase bookdb;

User* user;

/*****  Librarian-User functions *******/

void HandleNewUserAddition() {
    cout << "\033[2J\033[1;1H";

    string name, id, password;
    int userType;

    cout << "Enter details of the new user" << endl;

    cout << "Enter User type e.g., 0 -> student, 1 -> professor or 2 -> librarian - "; cin >> userType;

    if(userType != 0 && userType != 1 && userType != 2) {
        cout << "Invalid user type\nRedirecting...";
        sleep_for(milliseconds(800));
        return;
    } 

    cout << "Enter User ID - ";
    cin >> id; 

    if(userdb.doExist(id)) {
        cout << "A user with the entered ID already exists\nRedirecting...";
        sleep_for(milliseconds(900));
        return;
    }

    cout << "Enter user name - "; cin >> name;

    cout << "Enter the password - "; cin >> password; 

    if(password.size() == 0) {
        cout << "Password should not be an empty string\nRedirecting...";
        sleep_for(milliseconds(900));
        return;
    }
    cout << endl;

    userdb.Add(name, id, password, userType);

    cout << "A new user account has been created successfully.\nRedirecting... \n";

    sleep_for(milliseconds(800));
}


void HandleExistingUserUpdation () {
    cout << "\033[2J\033[1;1H";

    string id;
    cout << "Enter ID of the user to be updated - "; cin >> id;

    if(!userdb.doExist(id)) {
        cout << "No user with the entered ID exists\nRedirecting..." << endl;
        sleep_for(milliseconds(900));
        return;
    }

    cout << "Enter the updated values of the below given fields. If any one of them needs not to be changed, enter the old value itself." << endl;

    string new_name, new_password;
    int new_userType; 
    cout << "Name - "; cin >> new_name;
    cout << "Password - "; cin >> new_password; 
    cout << "User type - "; cin >> new_userType;

    userdb.Update(id, new_name, new_password, new_userType);

    cout << "User details have been updated successfully.\nRedirecting...";

    sleep_for(milliseconds(900));

}


void HandleUserDeletion () {
    cout << "\033[2J\033[1;1H";

    string id;
    cout << "Enter ID of the user to be deleted - "; cin >> id;

    if(!userdb.doExist(id)) {
        cout << "No user with the entered ID doesn't exist\nRedirecting..." << endl;
        sleep_for(milliseconds(900));
        return;
    }

    userdb.Delete(id);

    cout << "User deleted successfully\nRedirecting...";
    sleep_for(milliseconds(800));

}


void ShowOneUser() {
    cout << "\033[2J\033[1;1H";

    string id;
    cout << "Enter ID of the user - "; cin >> id;

    if(!userdb.doExist(id)) {
        cout << "No user with the entered ID doesn't exist\nRedirecting..." << endl;
        sleep_for(milliseconds(900));
        return;
    }

    userdb.ShowDetails(id);

    cin.ignore();
    cout << "Press ENTER to continue";
    cin.get();
    
}

/*****  Librarian-User functions *******/


/***** Librarian-Book functions ******/


void HandleNewBookAddition() {
    cout << "\033[2J\033[1;1H";

    string name, isbn, author, publication;

    cout << "Enter details of the new book" << endl;

    cout << "Enter book ISBN- "; cin >> isbn; 

    if(userdb.doExist(isbn)) {
        cout << "Only one copy of a book is allowed. One copy of the same book already exists.\nRedirecting...";
        sleep_for(milliseconds(900));
        return;
    }

    cin.ignore();

    cout << "Enter book name - "; getline(cin, name);

    cout << "Enter book author name - "; getline(cin, author);

    cout << "Enter book publication - "; getline(cin, publication);

    cout << endl;

    bookdb.Add(name, author, isbn, publication); 

    cout << "A new book has been created successfully.\nRedirecting... \n";

    sleep_for(milliseconds(800));
}


void HandleExistingBookUpdation () {
    cout << "\033[2J\033[1;1H";

    string isbn;
    cout << "Enter ISBN of the book to be updated- "; cin >> isbn;
    if(!bookdb.doExist(isbn)) {
        cout << "No book with the entered ISBN exists in the database.\nRedirecting..." << endl;
        sleep_for(milliseconds(900));
        return;
    }

    cout << "Enter the updated values of the below given fields. If any one of them needs not to be changed, enter the old value itself." << endl;

    string new_name, new_author, new_publication;
    cin.ignore();

    cout << "Book Name - "; getline(cin, new_name);
    cout << "Book Author Name - "; getline(cin, new_author); 
    cout << "Book Publication - "; getline(cin, new_publication);

    bookdb.Update(isbn, new_name, new_author, new_publication);

    cout << "Book details have been updated successfully.\nRedirecting...";

    sleep_for(milliseconds(900));

}

void HandleBookDeletion () {
    cout << "\033[2J\033[1;1H";

    string isbn;
    cout << "Enter ISBN of the book to be deleted - "; cin >> isbn;

    if(!bookdb.doExist(isbn)) {
        cout << "No book with the given ISBN exists in the database.\nRedirecting..." << endl;
        sleep_for(milliseconds(900));
        return;
    }

    bookdb.Delete(isbn);

    cout << "Book deleted successfully.\nRedirecting...";
    sleep_for(milliseconds(800));

}


void ShowOneBook() {
    cout << "\033[2J\033[1;1H";

    string isbn;
    cout << "Enter ISBN of the book - "; cin >> isbn;

    if(!bookdb.doExist(isbn)) {
        cout << "No book with the given ISBN exists in the database.\nRedirecting..." << endl;
        sleep_for(milliseconds(900));
        return;
    }

    bookdb.ShowDetails(isbn);

    cin.ignore();
    cout << "Press ENTER to continue";
    cin.get();


}

/***** Librarian-Book functions ******/


/***** Students-Professors functions *****/

void IssueOneBook(string id) {

    cout << "\033[2J\033[1;1H";

    string isbn;
    cout << "Enter ISBN of the book - "; cin >> isbn;

    if(!bookdb.doExist(isbn)) {
        cout << "No book with the given ISBN exists in the database.\nRedirecting..." << endl;
        sleep_for(milliseconds(900));
        return;
    }

    try {
        bookdb.IssueBook(id, userdb.GetUserType(id), isbn);
    }

    catch (char* msg) {
        cout << msg << endl;
        cout << "Redirecting..." << endl;
        sleep_for(milliseconds(800));
        return;
    }

    Book book = bookdb.Search(isbn);

    userdb.AddBookToUser(id, book); 

    cout << "Book issued to the user successfully\nRedirecting..." << endl;
    sleep_for(milliseconds(900));

}



void HandleLibrarian(string id) {
    cout << "\033[2J\033[1;1H";

    cout <<  "Follow the instructions given below and Enter the keys accordingly: " << endl;
    // User related commands
    cout << "1 List down all users" << endl;
    cout << "2 Add a new user" << endl;
    cout << "3 Update an existing user" << endl;
    cout << "4 Delete an existing user" << endl;
    cout << "5 Show a specific user" << endl;
    // Books related commands
    cout << "6 List down all books" << endl;
    cout << "7 Add a new book" << endl;
    cout << "8 Update an existing book" << endl;
    cout << "9 Delete an existing book" << endl;
    cout << "10 Show a specific book" << endl;
    cout << "11 Logout" << endl;

    cin >> command;

    switch(command) {
        case 1: 
            userdb.ListAllUsers(); 
            cin.ignore();
            cout << "Press ENTER to continue";
            cin.get();
            break;

        case 2: {
            HandleNewUserAddition();
            break;
        }

        case 3: {
            HandleExistingUserUpdation();
            break;
        }

        case 4: {
            HandleUserDeletion();
            break;
        }

        case 5: {
            ShowOneUser();
            break;
        }

        case 6: {
            bookdb.ListAllBooks();
            cin.ignore();
            cout << "Press ENTER to continue";
            cin.get();
            break;
        }

        case 7: {
            HandleNewBookAddition();
            break;
        }

        case 8: {
            HandleExistingBookUpdation();
            break;
        }

        case 9: {
            HandleBookDeletion();
            break;
        }

        case 10: {
            ShowOneBook();
            break;
        }

        case 11: 
            return;

        default: 
            cout << "Invalid command" <<endl;
            break;
    }

    HandleLibrarian(id);

}

void HandleStudent(string id) {
    cout << "\033[2J\033[1;1H";

    User* user = userdb.Search(id);

    cout << "Follow the instructions given below and Enter the keys accordingly: " << endl;

    cout << "1 List down all books" << endl;
    cout << "2 List down all issued books" << endl;
    cout << "3 Check specific book status" << endl;
    cout << "4 Issue a book" << endl;
    cout << "5 Logout" << endl;

    cin >> command;

    switch(command) {

        case 1: {
            bookdb.ListAllBooks();
            cin.ignore();
            cout << "Press ENTER to continue";
            cin.get();
            break;
        }

        case 2: {
            userdb.ShowIssuedBooks(id);
            cin.ignore();
            cout << "Press ENTER to continue";
            cin.get();
            break;
        }

        case 3: {
            ShowOneBook();
            break;
        }

        case 4: {
            IssueOneBook(id);
            break;
        }

        case 5: 
            return;

        default: 
            cout << "Invalid command" <<endl;
            break;
    }

    HandleStudent(id);
}

void HandleProfessor(string id) {
    cout << "\033[2J\033[1;1H";

    User* user = userdb.Search(id);

    cout << "Follow the instructions given below and Enter the keys accordingly: " << endl;

    cout << "1 List down all books" << endl;
    cout << "2 List down all issued books" << endl;
    cout << "3 Check specific book status" << endl;
    cout << "4 Issue a book" << endl;
    cout << "5 Logout" << endl;

    cin >> command;

    switch(command) {

        case 1: {
            bookdb.ListAllBooks();
            cin.ignore();
            cout << "Press ENTER to continue";
            cin.get();
            break;
        }

        case 2: {
            userdb.ShowIssuedBooks(id);
            cin.ignore();
            cout << "Press ENTER to continue";
            cin.get();
            break;
        }

        case 3: {
            ShowOneBook();
            break;
        }

        case 4: {
            IssueOneBook(id);
            break;
        }

        case 5: 
            return;

        default: 
            cout << "Invalid command" <<endl;
            break;
    }

    HandleProfessor(id);
}


void HandleLogin () {

    cout << "\033[2J\033[1;1H";
    
    string id, password;
    int userType;
    
    cout << "Enter User type e.g., 0 -> student, 1 -> professor or 2 -> librarian - "; cin >> userType;

    if(userType != 0 && userType != 1 && userType != 2) {
        cout << "Invalid user type\nRedirecting...";
        sleep_for(milliseconds(800));
        return;
    }

    cout << "Enter ID - ";  cin >> id;
    cout << "Enter password - "; cin >> password;

    bool res;

    try {
        res = userdb.AuthenticateUser(id, password);
        if(!res) return;

        cout << "Logged in successfully\nRedirecting..." <<endl;
        sleep_for(milliseconds(800));

        switch(userType) {
            case 0: 
                HandleStudent(id);
                break;
            case 1:
                HandleProfessor(id);
                break;
            case 2: 
                HandleLibrarian(id);
                break;
            default: 
                break;  

        }

    }
    catch (const char* msg) {
        cout << msg << endl;
        cout << "Redirecting..." << endl;
        sleep_for(milliseconds(800));
    }
}

int main() {

    cout << "\033[2J\033[1;1H";

    string name, id, password;
        
    cout << "Enter details of the master librarian" << endl;
    cout << "Enter the librarian name - ";
    cin >> name; 
    cout << "Enter the ID - ";
    cin >> id; 
    cout << "Enter the password - ";
    cin >> password; cout << endl;

    userdb.Add(name, id, password, 2);

    cout << "Master account has been created successfully.\nRedirecting... \n";

    sleep_for(milliseconds(800));

    while ( 1 ) {

        cout << "\033[2J\033[1;1H";

        cout <<  "Follow the instructions give below and Enter the keys accordingly: " << endl;
        cout << "1 Login" << endl;
        cout << "2 Exit" << endl;

        cin >> command;

        if(command == 1) {
            cout << "\033[2J\033[1;1H";
            HandleLogin();
        }

        else if(command == 2) {
            cout << "\033[2J\033[1;1H";
            break;
        }

        else {
            cout << endl << "Invalid command\nRedirecting..." << endl;
            sleep_for(milliseconds(800));
            cout << "\033[2J\033[1;1H";
            continue;
        }

    }


    return 0;
}