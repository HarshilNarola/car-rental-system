#ifndef USER_H
#define USER_H
#include <string>
using namespace std;

class User {
    string username, password, role;
public:
    User();
    User(string, string, string);
    string getUser();
    string getPass();
    string getRole();
    string toCSV();  // ✅ Add this line
};

#endif
