#include "RentalSystem.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

void RentalSystem::loadCars(string fname) {
    cars.clear();
    ifstream file(fname);
    string id, brand, model, type, rate, rented;
    while (getline(file, id, ',')) {
        getline(file, brand, ',');
        getline(file, model, ',');
        getline(file, type, ',');
        getline(file, rate, ',');
        getline(file, rented);
        cars.push_back(Car(id, brand, model, type, stod(rate), rented == "1"));
    }
}

void RentalSystem::saveCars(string fname) {
    ofstream file(fname);
    for (Car& c : cars)
        file << c.toCSV() << "\n";
}

void RentalSystem::loadUsers(string fname) {
    users.clear();
    ifstream file(fname);
    string u, p, r;
    while (getline(file, u, ',') && getline(file, p, ',') && getline(file, r)) {
        users.push_back(User(u, p, r));
    }
}

void RentalSystem::saveUsers(string fname) {
    ofstream file(fname);
    for (User& user : users) {
        file << user.toCSV() << "\n";
    }
}

bool RentalSystem::login(string role) {
    string u, p;
    cout << "Username: "; cin >> u;
    cout << "Password: "; cin >> p;
    for (auto user : users) {
        if (user.getUser() == u && user.getPass() == p && user.getRole() == role)
            return true;
    }
    cout << "Wrong credentials.\n";
    return false;
}

void RentalSystem::registerUser() {
    string u, p;
    cout << "Enter new username: "; cin >> u;
    cout << "Enter password: "; cin >> p;
    users.push_back(User(u, p, "user"));
    saveUsers("users.csv");
    cout << "User registered successfully.\n";
}

void RentalSystem::addCar() {
    string id, brand, model, type;
    double rate;
    cout << "Car ID: "; cin >> id;
    cout << "Brand: "; cin >> brand;
    cout << "Model: "; cin >> model;
    cout << "Type: "; cin >> type;
    cout << "Rate: "; cin >> rate;
    cars.push_back(Car(id, brand, model, type, rate, false));
    cout << "Added.\n";
}

void RentalSystem::removeCar() {
    string id;
    cout << "Enter ID to remove: "; cin >> id;
    for (int i = 0; i < cars.size(); i++) {
        if (cars[i].getId() == id) {
            cars.erase(cars.begin() + i);
            cout << "Removed.\n";
            return;
        }
    }
    cout << "Not found.\n";
}

void RentalSystem::viewCars(bool onlyAvailable) {
    for (Car& c : cars) {
        if (!onlyAvailable || !c.isRented())
            c.display();
    }
}

void RentalSystem::rentCar() {
    string id;
    cout << "Enter ID to rent: "; cin >> id;
    for (Car& c : cars) {
        if (c.getId() == id && !c.isRented()) {
            c.rentCar();
            cout << "Rented.\n";
            return;
        }
    }
    cout << "Not available.\n";
}

void RentalSystem::returnCar() {
    string id;
    cout << "Enter ID to return: "; cin >> id;
    for (Car& c : cars) {
        if (c.getId() == id && c.isRented()) {
            c.returnCar();
            cout << "Returned.\n";
            return;
        }
    }
    cout << "Invalid.\n";
}

void RentalSystem::calculateBill() {
    string id;
    int days;
    cout << "Car ID: "; cin >> id;
    cout << "Days: "; cin >> days;
    for (Car& c : cars) {
        if (c.getId() == id) {
            cout << "Bill: Rs. " << c.bill(days) << endl;
            return;
        }
    }
    cout << "Not found.\n";
}

void RentalSystem::adminMenu() {
    int ch;
    do {
        cout << "\n1.View 2.Add 3.Remove 4.Register User 5.Exit\nChoice: ";
        cin >> ch;
        if (ch == 1) viewCars(false);
        else if (ch == 2) addCar();
        else if (ch == 3) removeCar();
        else if (ch == 4) registerUser();
    } while (ch != 5);
}

void RentalSystem::userMenu() {
    int ch;
    do {
        cout << "\n1.View 2.Rent 3.Return 4.Bill 5.Exit\nChoice: ";
        cin >> ch;
        if (ch == 1) viewCars(true);
        else if (ch == 2) rentCar();
        else if (ch == 3) returnCar();
        else if (ch == 4) calculateBill();
    } while (ch != 5);
}
