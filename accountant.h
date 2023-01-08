//
// Created by Halil Burak Öztürk on 31.12.2022.
//
/**
 * @file accountant.h
 * @description Accountant class is derived from Employee class. It has a bonus variable and a getRaise function.
 * @assignment BP3 - PROJECT 3
 * @date 31.12.2022
 * @author HALIL BURAK OZTURK halilburak.ozturk@stu.fsm.edu.tr
 */

#ifndef BP3PROJECT3_ACCOUNTANT_H
#define BP3PROJECT3_ACCOUNTANT_H

#include <iostream>
#include <string>
#include "employee.h"

using namespace std;
// Accountant class is derived from Employee class
class Accountant : public Employee {

public:
    // Constructor
    Accountant() {}
    // Destructor
    ~Accountant() {}
    // Constructor with parameters
    Accountant(string nameSurname, int age, string gender, int salary, string position) : Employee(nameSurname, age,
                                                                                                   gender,
                                                                                                   salary, position) {
    }
    // Get raise method with polymorphism
    void getRaise() {
        int salary = Employee::getSalary();
        setSalary(salary + 1500);

    }
    // Set salary of employee method
    void paySalary(Employee employee, int salary) {
        employee.setSalary(employee.getSalary() + salary);
        // If salary is paid successfully
        if (employee.getSalary() == 5000) {
            cout << "Salary paid successfully" << endl;
        }
        // If salary overpaid
        else if (employee.getSalary() > 5000) {
            cout << "Salary paid successfully" << endl;
            cout << "You have " << employee.getSalary() - 5000 << " extra money in your account" << endl;
        }
        // If salary cant paid
        else {
            cout << "Salary couldn't paid" << endl;
            cout << "Add more " << 5000 - employee.getSalary() << " to the account for completing the salary" << endl;
        }
    }
};

#endif //BP3PROJECT3_ACCOUNTANT_H
