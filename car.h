#ifndef CAR_H
#define CAR_H
#include <string>
using namespace std;

class Car {
protected:
    string id, brand, model, type;
    double rate;
    bool rented;

public:
    Car();
    Car(string, string, string, string, double, bool);
    void display();
    double bill(int days);
    string getId();
    bool isRented();
    void rentCar();
    void returnCar();
    string toCSV();
};

#endif