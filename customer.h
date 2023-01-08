//
// Created by Halil Burak Öztürk on 31.12.2022.
//
/**
 * @file customer.h
 * @description This file contains the Customer class.
 * @assignment BP3 - PROJECT 3
 * @date 31/12/2022
 * @author HALIL BURAK OZTURK halilburak.ozturk@stu.fsm.edu.tr
 */
#ifndef BP3PROJECT3_CUSTOMER_H
#define BP3PROJECT3_CUSTOMER_H

#include <iostream>
#include <string>
#include "person.h"
#include <vector>

using namespace std;

// This class is derived from Person class.
class Customer : public Person {
private:
    int Balance;
    int RentLimit;
    vector<Movie> RentedMovies;
public:
    // Default constructor.
    Customer() {}

    // Destructor.
    ~Customer() {}

    // Constructor with parameters.
    Customer(string nameSurname, int age, string gender, int balance, int rentLimit)
            : Person(nameSurname, age, gender) {
        Balance = balance;
        RentLimit = rentLimit;
        // If customer age is less than 18, balance is 50.
        if (Customer::getAge() < 18) {
            cout << Customer::getNameSurname() << " balance limited with 50 because customer age is lower than 18"
                 << endl;
            Balance = 50;
        }
    }

    // This function is used to get Balance.
    int getBalance() {
        return Balance;
    }

    // This function is used to set RentedMovies
    void setRentedMovies(vector<Movie> rentedMovies) {
        RentedMovies = rentedMovies;
    }

    // This function is used to get RentedMovies
    vector<Movie> getRentedMovies() const {
        return RentedMovies;
    }

    // This function prints the customer's rented movies.
    void printRentedMovies() {
        if (RentedMovies.size() == 0) {
            cout << Customer::getNameSurname() << " No rented movies" << endl;
        } else {
            for (int i = 0; i < RentedMovies.size(); i++) {
                cout << "Movie " << i + 1 << endl;
                RentedMovies[i].printMovie();
            }
        }
    }

    // This function is used to set Balance.
    void setBalance(int balance) {
        if (Customer::getAge() < 18) {
            cout << "Balance couldnt change because customer age is lower than 18" << endl;
        } else
            Balance = balance;
    }

    // This function is used to get RentLimit.
    int getRentLimit() {
        return RentLimit;
    }

    // This function is used to set RentLimit.
    void setRentLimit(int rentLimit) {
        RentLimit = rentLimit;
    }

    // This function is used to print Customer.
    void printCustomer() {
        cout << "--------------------" << endl;
        printPerson();
        cout << "Balance: " << Balance << endl;
        cout << "Rent Limit: " << RentLimit << endl;

    }

};

#endif //BP3PROJECT3_CUSTOMER_H
