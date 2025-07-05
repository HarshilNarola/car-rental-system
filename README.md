# 🚗 Car Rental System in C++ (OOP Project)

A simple command-line **Car Rental System** built using **Object-Oriented Programming in C++**.  
It demonstrates key OOP principles like classes, encapsulation, abstraction, and file handling.

![C++](https://img.shields.io/badge/C%2B%2B-Project-blue)
![OOP](https://img.shields.io/badge/OOP-Principles-brightgreen)
![File%20Handling](https://img.shields.io/badge/File-Handling-yellow)

---

## 📚 Table of Contents
- [🧠 Features](#-features)
- [📁 Project Structure](#-project-structure)
- [🗃️ Sample Data Files](#️-sample-data-files)
- [💻 How to Compile & Run](#-how-to-compile--run)
- [📌 How to Use](#-how-to-use)
- [📘 Concepts Covered](#-concepts-covered)
- [🙋‍♂️ Developer](#-developer)

---

## 🧠 Features

### 👨‍💼 Admin
✔️ Secure login  
✔️ Add new cars  
✔️ Remove cars  
✔️ View all cars  
✔️ Register new users  

### 👤 User
✔️ Secure login  
✔️ View available cars  
✔️ Rent a car  
✔️ Return a car  
✔️ Calculate total bill  

### 🆕 New Users
✔️ Can self-register from login screen  
✔️ Automatically assigned `user` role  

---

## 📁 Project Contents

- `Car.h` / `Car.cpp` – Car class declaration and implementation
- `User.h` / `User.cpp` – User class and login/register logic
- `RentalSystem.h` / `RentalSystem.cpp` – Core system logic (admin/user operations, file handling)
- `main.cpp` – Entry point of the application
- `cars.csv` – Car records (ID, brand, model, type, rate, rented status)
- `users.csv` – User credentials and roles
- `README.md` – Project documentation and instructions


---

## 🗃️ Sample Data Files

### ✅ cars.csv

<id>,<brand>,<model>,<type>,<rate>,<rented>

- Example: C101,Toyota,Corolla,Sedan,1000,0
- C102,Ford,EcoSport,SUV,1500,0
- C103,Honda,Amaze,Sedan,950,1

---
### ✅ users.csv

<username>,<password>,<role>

- Example: admin,admin123,admin
- john,pass123,user

---

## 💻 How to Compile & Run

### On Windows/Linux/macOS (with g++)

- g++ main.cpp Car.cpp User.cpp RentalSystem.cpp -o rental
- ./rental       # Linux/macOS
- rental.exe     # Windows

## 📌 How to Use
▶️ Start Menu

1. Admin
2. User
3. Register

👨‍💼 Admin Login
- Username: admin
- Password: admin123
- Can add/remove cars and register users.

👤 User Login
- Use a pre-registered user (e.g. john) or register as new.
- Can rent, return, and calculate rental bill.

## 📘 Concepts Covered

- Classes & Objects
- Encapsulation & Abstraction
- File I/O using CSV
- Header files (`.h`) and source files (`.cpp`)
- Vectors and Strings
- Modular code structure
- Menu-driven CLI interface


## 🙋‍♂️ Developer
Harshil Narola
