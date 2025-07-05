#include "Car.h"
#include <iostream>
using namespace std;

Car::Car() {}
Car::Car(string i, string b, string m, string t, double r, bool ren) {
    id = i;
    brand = b;
    model = m;
    type = t;
    rate = r;
    rented = ren;
}

void Car::display() {
    cout << id << " " << brand << " " << model << " " << type << " " << rate << " " << (rented ? "Rented" : "Available") << endl;
}

double Car::bill(int days) {
    if (type == "SUV") return rate * days * 1.2;
    return rate * days;
}

string Car::getId() { return id; }
bool Car::isRented() { return rented; }
void Car::rentCar() { rented = true; }
void Car::returnCar() { rented = false; }
string Car::toCSV() {
    return id + "," + brand + "," + model + "," + type + "," + to_string(rate) + "," + (rented ? "1" : "0");
}
