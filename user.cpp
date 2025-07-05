#include "User.h"

User::User() {}
User::User(string u, string p, string r) {
    username = u;
    password = p;
    role = r;
}

string User::getUser() { return username; }
string User::getPass() { return password; }
string User::getRole() { return role; }
string User::toCSV() {
    return username + "," + password + "," + role;
}
