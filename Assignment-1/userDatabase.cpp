#include <iostream>
#include "userDatabase.h"

void UserDatabase::Add(string name, string id, string password, int userType) {

    if(users_list.find(id) != users_list.end()) throw "User with this ID already exists.";

    switch(userType) {
        case 0: {
            Student student; student.SetParams(name, id, password, userType);
            students_list[id] = student; users_list[id] = userType; 
            break;
        }

        case 1: {
            Professor professor; professor.SetParams(name, id, password, userType);
            professors_list[id] = professor; users_list[id] = userType; 
            break;
        }

        case 2: {
            Librarian librarian; librarian.SetParams(name, id, password, userType);
            librarians_list[id] = librarian; users_list[id] = userType;
            break;
        }

        default: 
            throw "Invalid user type";
            break;
    }
}

void UserDatabase::Delete(string id) {
    if(users_list.find(id) == users_list.end()) throw "User with the given ID doesn't exist";

    switch(users_list[id]) {
        case 0: students_list.erase(id); break;
        case 1: professors_list.erase(id); break;
        case 2: librarians_list.erase(id); break;
    }

    users_list.erase(id);
}

void UserDatabase::Update(string id, string new_name, string new_password, int new_userType) {
    if(users_list.find(id) == users_list.end()) throw "User with the given ID doesn't exist";

    if(users_list[id] != new_userType) {
        switch(users_list[id]) {
            case 0: {
                students_list.erase(id);
                switch(new_userType) {
                    case 1: {
                        Professor professor; professor.SetParams(new_name, id, new_password, new_userType);
                        professors_list[id] = professor;
                        break;
                    }
                    case 2: {
                        Librarian librarian; librarian.SetParams(new_name, id, new_password, new_userType);
                        librarians_list[id] = librarian;
                        break;
                    }
                }
            }

            case 1: {
                professors_list.erase(id);
                switch(new_userType) {
                    case 0: {
                        Student student; student.SetParams(new_name, id, new_password, new_userType);
                        students_list[id] = student;
                        break;
                    }
                    case 2: {
                        Librarian librarian; librarian.SetParams(new_name, id, new_password, new_userType);
                        librarians_list[id] = librarian;
                        break;
                    }
                }
            }

            case 2: {
                librarians_list.erase(id);
                switch(new_userType) {
                    case 0: {
                        Student student; student.SetParams(new_name, id, new_password, new_userType);
                        students_list[id] = student;
                        break;
                    }
                    case 1: {
                        Professor professor; professor.SetParams(new_name, id, new_password, new_userType);
                        professors_list[id] = professor;
                        break;
                    }
                }
            }
        }
        users_list[id] = new_userType;
    }

    switch(users_list[id]) {
        case 0: {
            students_list[id].SetParams(new_name, id, new_password, new_userType);
            break;
        }
        case 1: {
            professors_list[id].SetParams(new_name, id, new_password, new_userType);
            break;
        }
        case 2: {
            librarians_list[id].SetParams(new_name, id, new_password, new_userType);
            break;
        }
    }

}

bool UserDatabase::doExist(string id) {
    if(users_list.find(id) != users_list.end()) return true;
    return false;
}

bool UserDatabase::AuthenticateUser(string id, string password) {
    if(users_list.find(id) == users_list.end()) throw "Invalid ID";

    switch(users_list[id]) {
        case 0:    
            if(students_list[id].VerifyPassword(password)) return true;
            else throw "Invalid password";
        case 1: 
            if(professors_list[id].VerifyPassword(password)) return true;
            else throw "Invalid password";
        case 2:
            if(librarians_list[id].VerifyPassword(password)) return true;
            else throw "Invalid password";    
    }

    return false;
    
}

void UserDatabase::ShowDetails(string id) {
    switch(users_list[id]) {
        case 0: 
            students_list[id].ShowDetails();
            break;
        case 1: 
            professors_list[id].ShowDetails();
            break;

        case 2: 
            librarians_list[id].ShowDetails();
            break;
    }
}

void UserDatabase::ListAllUsers() {

    cout << "\033[2J\033[1;1H";

    // printing librarians

    int count = 1;

    cout << "Librarians - \n";

    for(auto itr = librarians_list.begin(); itr != librarians_list.end(); ++itr) {
        cout << "Librarian #" << (count++) << endl;
        cout << "ID - " << itr->first << endl;
        cout << "Name - " << itr->second.name << endl;
        cout << "\n------------------------------------------------------------\n" << endl;
    }

    cout << "------------------------------------------------------------\n" << endl;

    // printing professors

    count = 1;

    cout << "Professors - \n";

    for(auto itr = professors_list.begin(); itr != professors_list.end(); ++itr) {
        cout << "Professor #" << (count++) << endl;
        cout << "ID - " << itr->first << endl;
        cout << "Name - " << itr->second.name << endl;
        cout << "\n------------------------------------------------------------\n" << endl;
    }
 
    cout << "------------------------------------------------------------\n" << endl;

    // printing students

    count = 1;

    cout << "Students - \n";

    for(auto itr = students_list.begin(); itr != students_list.end(); ++itr) {
        cout << "Student #" << (count++) << endl;
        cout << "ID - " << itr->first << endl;
        cout << "Name - " << itr->second.name << endl;
        cout << "\n------------------------------------------------------------\n" << endl;
    }


}