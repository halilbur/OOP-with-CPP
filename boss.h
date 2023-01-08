//
// Created by Halil Burak Öztürk on 31.12.2022.
//
/**
 * @file boss.h
 * @description This file contains the class definition of the Boss class.
 * @assignment BP3 - PROJECT 3
 * @date 31/12/2022
 * @author HALIL BURAK OZTURK halilburak.ozturk@stu.fsm.edu.tr
 */
#ifndef BP3PROJECT3_BOSS_H
#define BP3PROJECT3_BOSS_H

#include <iostream>
#include <string>
#include "employee.h"

using namespace std;
// Boss class is derived from Employee class
class Boss : public Employee {

public:
    // Constructor
    Boss() {}
    // Destructor
    ~Boss() {}
    // Constructor with parameters
    Boss(string nameSurname, int age, string gender, int salary, string position) : Employee(nameSurname, age, gender,
                                                                                             salary, position) {
    }
    // Get raise method with polymorphism
    void getRaise() {
        int salary = Employee::getSalary();
        setSalary(salary + 2000);
    }
    // Set salary of employee method
    void setPositionOfEmployee(Employee employee, string position) {
        employee.setPosition(position);
        // If position is set successfully
        if (employee.getPosition() != "") {
            cout << "Position changed successfully" << endl;
        }
        // If position cant set
        else {
            cout << "Position couldn't changed" << endl;
        }
    }

};

#endif //BP3PROJECT3_BOSS_H
