//
// Created by Halil Burak Öztürk on 31.12.2022.
//
/**
 * @file person.h
 * @description This file contains the Person class.
 * @assignment BP3 - PROJECT 3
 * @date 31/12/2022
 * @author HALIL BURAK OZTURK halilburak.ozturk@stu.fsm.edu.tr
 */
#ifndef BP3PROJECT3_PERSON_H
#define BP3PROJECT3_PERSON_H

#include <iostream>
#include <string>

using namespace std;

// This class is used to store the person data
class Person {
private:
    string NameSurname;
    int Age;
    string Gender;
public:
    Person() {} // Default constructor

    ~Person() {} // Destructor

    // Constructor with parameters
    Person(string nameSurname, int age, string gender) {
        NameSurname = nameSurname;
        Age = age;
        Gender = gender;
    }

    string getNameSurname() const { // Returns the name and surname of the person
        return NameSurname;
    }

    void setNameSurname(string nameSurname) { // Sets the name and surname of the person
        NameSurname = nameSurname;
    }

    int getAge() { // Returns the age of the person
        return Age;
    }

    void setAge(int age) { // Sets the age of the person
        Age = age;
    }

    string getGender() const { // Returns the gender of the person
        return Gender;
    }

    void setGender(string gender) { // Sets the gender of the person
        Gender = gender;
    }

    // This function prints the person data
    void printPerson() {
        cout << "Name Surname: " << NameSurname << endl;
        cout << "Age: " << Age << endl;
        cout << "Gender: " << Gender << endl;
    }
};


#endif //BP3PROJECT3_PERSON_H
