//
// Created by Halil Burak Öztürk on 31.12.2022.
//
/**
 * @file main.cpp
 * @description This function is the main function of the program.
 * @assignment BP3 - PROJECT 3
 * @date 31/12/2022
 * @author HALIL BURAK OZTURK halilburak.ozturk@stu.fsm.edu.tr
 */
#include <iostream>
#include "movie.h"
#include "customer.h"
#include "market.h"
#include "employee.h"
#include "boss.h"
#include "accountant.h"

using namespace std;

int main() {
    // Creating the movies
    Movie *m3 = new Movie("The Dark Knight", "Christopher Nolan", "Action", "Christian Bale", 2008, 152, 9.0, 20, 100,
                          10);
    Movie *m4 = new Movie("The Lord of the Rings: The Return of the King", "Peter Jackson", "Adventure", "Elijah Wood",
                          2003, 201, 8.9, 18, 200, 15);
    Movie *m5 = new Movie("The Godfather", "Francis Ford Coppola", "Crime", "Marlon Brando", 1972, 175, 9.2, 18, 300,
                          20);

    // Creating the customers
    Customer *c3 = new Customer("halil", 22, "male", 500, 5);
    Customer *c4 = new Customer("kasal", 17, "male", 300, 3);

    // Creating the market
    Market *ma2 = new Market("Cineplex", "Istanbul", 0);

    // Creating the employees
    Employee *e1 = new Employee("fatih", 20, "male", 1000, "officer");
    Boss *b1 = new Boss("mtcn", 22, "male", 2000, "boss");
    Accountant *a1 = new Accountant("acur", 23, "male", 1500, "accountant");

    // Adding the movies to the market's movie list
    ma2->addMovieList(m3);
    ma2->addMovieList(m4);
    ma2->addMovieList(m5);
    ma2->addMovieList(m3);
    cout << "***************" << endl;
    //ma2->printMovieList();

    // Printing the customer's information
    c3->printCustomer();
    c4->printCustomer();
    cout << "********PrintRentedMovie******" << endl; // Printing the rented movie
    c3->printRentedMovies();
    c4->printRentedMovies();
    cout << "********PrintMovieList********" << endl; // Printing the movie list
    ma2->printMovieList();
    cout << "*******RentMovie*********" << endl; // Renting the movie
    ma2->bookMovie(m3, c3);
    ma2->bookMovie(m4, c4);
    cout << "********PrintRentedMovieList*********" << endl; // Printing the rented movie list
    ma2->printRentedMovies();
    cout << "********PrintMovieList*******" << endl; // Printing the movie list
    ma2->printMovieList();
    cout << "*******PrintCustomerList*******" << endl; // Printing the customer list
    ma2->printCustomerList();
    cout << "*******PrintRentedMovieList(movie)*********" << endl; // Printing the rented movie list with parameters
    ma2->printRentedMovies(m3);
    cout << "*****PrintMarket*****" << endl; // Printing the market
    ma2->printMarket();
    cout << "*****ReturnMovie*****" << endl; // Returning the movie
    ma2->returnMovie(m3, c3);
    ma2->printMovieList();
    ma2->printRentedMovies();
    ma2->printMarket();
    cout << "*****PrintPastRented*****" << endl; // Printing the past rented movies
    ma2->customerPastRentals(m3, c3);
    cout << "-------------------" << endl;
    c3->printRentedMovies();
    cout << "*****PrintEmployeeList*****" << endl; // Printing the employee list
    ma2->addEmployee(e1);
    ma2->addEmployee(b1);
    ma2->addEmployee(a1);
    ma2->printEmployeeList();
    cout << "**********" << endl;
    e1->getRaise();             // Getting the raise for the employee
    b1->getRaise();            // Getting the raise for the boss
    a1->getRaise();           // Getting the raise for the accountant
    ma2->updateEmployeeList(e1);    // Updating the employee list
    ma2->updateEmployeeList(b1);    // Updating the employee list
    ma2->updateEmployeeList(a1);    // Updating the employee list

    ma2->printEmployeeList();
    cout << "**********" << endl;
    a1->paySalary(*e1, 30000);  // Paying the salary for the employee

    return 0;
}