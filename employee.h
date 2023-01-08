//
// Created by Halil Burak Öztürk on 31.12.2022.
//
/**
 * @file employee.h
 * @description This file contains the Employee class.
 * @assignment BP3 - PROJECT 3
 * @date 31/12/2022
 * @author HALIL BURAK OZTURK halilburak.ozturk@stu.fsm.edu.tr
 */
#ifndef BP3PROJECT3_STUFF_H
#define BP3PROJECT3_STUFF_H

#include <iostream>
#include <string>
#include "person.h"

using namespace std;

// This class is Abstract class of getRaise() function.
class AbstractionSetBonus {
    virtual void getRaise() = 0;
};

// This class is derived from Person class.
class Employee : public Person {
private:
    int Salary;
    string Position;
public:
    // Default constructor.
    Employee() {}

    //Destructor.
    ~Employee() {}

    // Constructor with parameters.
    Employee(string nameSurname, int age, string gender, int salary, string position)
            : Person(nameSurname, age, gender) {
        Salary = salary;
        Position = position;
    }

    // This function is used to get Raise with polymorphism.
    void getRaise() {
        setSalary(Salary + 1000);

    }

    // This function is used to get Salary.
    int getSalary() {
        return Salary;
    }

    // This function is used to set Salary.
    void setSalary(int salary) {
        Salary = salary;
    }

    // This function is used to get Position.
    string getPosition() {
        return Position;
    }

    // This function is used to set Position.
    void setPosition(string position) {
        Position = position;
    }

    // This function is used to print Employee.
    void printEmployee() {
        printPerson();
        cout << "Salary: " << Salary << endl;
        cout << "Position: " << Position << endl;
    }


};

#endif //BP3PROJECT3_STUFF_H
