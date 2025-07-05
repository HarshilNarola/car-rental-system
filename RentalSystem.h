#ifndef RENTAL_H
#define RENTAL_H
#include "Car.h"
#include "User.h"
#include <vector>
using namespace std;

class RentalSystem {
    vector<Car> cars;
    vector<User> users;
public:
    void loadCars(string);
    void saveCars(string);
    void loadUsers(string);
    void saveUsers(string);

    bool login(string);
    void adminMenu();
    void userMenu();
    void addCar();
    void removeCar();
    void viewCars(bool);
    void rentCar();
    void returnCar();
    void calculateBill();
    void registerUser();
};

#endif
