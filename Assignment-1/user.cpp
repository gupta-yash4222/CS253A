#include "user.h"
#include <iostream>

void User::SetPassword(string password) {
    this->password = password;
}


int Student::calculate_fine() {
    return 0;
}

void Student::clear_fine_amount() {
    if (this->fine_amount == 0) throw "Fine amount of the user is already null";
    
    this->fine_amount = 0;
}


int Professor::calculate_fine() {
    return 0;
}   

void Professor::clear_fine_amount() {
    if (this->fine_amount == 0) throw "Fine amount of the user is already null";
    
    this->fine_amount = 0;
} 