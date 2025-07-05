#include "RentalSystem.h"
#include <iostream>
using namespace std;

int main() {
    RentalSystem sys;
    sys.loadCars("cars.csv");
    sys.loadUsers("users.csv");

    int role;
    cout << "1.Admin 2.User 3.Register\nEnter role: ";
    cin >> role;

    if (role == 1 && sys.login("admin")) sys.adminMenu();
    else if (role == 2 && sys.login("user")) sys.userMenu();
    else if (role == 3) sys.registerUser();
    else cout << "Login failed or invalid input.\n";

    sys.saveCars("cars.csv");
    sys.saveUsers("users.csv");
    return 0;
}
