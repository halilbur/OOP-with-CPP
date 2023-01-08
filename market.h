//
// Created by Halil Burak Öztürk on 31.12.2022.
//
/**
 * @file market.h
 * @description This file contains the Market class.
 * @assignment BP3 - PROJECT 3
 * @date 31/12/2022
 * @author HALIL BURAK OZTURK halilburak.ozturk@stu.fsm.edu.tr
 */
#ifndef BP3PROJECT3_MARKET_H
#define BP3PROJECT3_MARKET_H

#include <iostream>
#include <string>
#include "movie.h"
#include "customer.h"
#include <vector>
#include "employee.h"

using namespace std;

// This class is market class. It contains all the movies and customers.
class Market {
private:
    // Market class attributes
    string Name;
    string Address;
    int MovieStock;
    int Profit;
    vector<Movie> MovieList;
    vector<Movie> RentedMovies;
    vector<Customer> CustomerList;
    vector<Employee> EmployeeList;
    vector<Movie> PastRentedMovies;
public:

    Market() {} // Default constructor

    ~Market() {} // Destructor

    // Constructor with parameters
    Market(string name, string address, int profit) {
        Name = name;
        Address = address;
        this->Profit = profit;
    }

    string getName() const { // Getter for name
        return Name;
    }

    void setName(string name) { // Setter for name
        Name = name;
    }

    string getAddress() const { // Getter for address
        return Address;
    }

    void setAddress(string address) { // Setter for address
        Address = address;
    }

    int getFilmStock() const { // Getter for film stock
        return MovieStock;
    }

    void setFilmStock(int filmStock) { // Setter for film stock
        this->MovieStock = filmStock;
    }

    vector<Movie> getFilmList() const { // Getter for film list
        return MovieList;
    }

    void setFilmList(vector<Movie> filmList) { // Setter for film list
        this->MovieList = filmList;
    }

    vector<Movie> getRentedFilms() const { // Getter for rented films
        return RentedMovies;
    }

    void setRentedFilms(vector<Movie> rentedFilms) { // Setter for rented films
        this->RentedMovies = rentedFilms;
    }

    vector<Customer> getCustomerList() const { // Getter for customer list
        return CustomerList;
    }

    void setCustomerList(vector<Customer> customerList) { // Setter for customer list
        this->CustomerList = customerList;
    }

    int getProfit() const { // Getter for profit
        return Profit;
    }

    void setProfit(int profit) { // Setter for profit
        this->Profit = profit;
    }

    void addEmployee(Employee *employee) { // This function adds employee to employee list
        EmployeeList.push_back(*employee);

    }

    // This function updates the employee list
    void updateEmployeeList(Employee *employee) {
        for (int i = 0; i < EmployeeList.size(); i++) {
            if (EmployeeList[i].getNameSurname() == employee->getNameSurname()) {
                EmployeeList[i] = *employee;
            }
        }
    }

    // This function prints the employee list
    void printEmployeeList() {
        cout << "----------EmployeeList-------" << endl;
        if (EmployeeList.empty()) {
            cout << "No employee in the market" << endl;
        } else {
            for (int i = 0; i < EmployeeList.size(); i++) {
                cout << "Employee " << i + 1 << endl;
                EmployeeList[i].printEmployee();
                cout << "--------------" << endl;
            }
        }
    }

    // This function adds movie to movie list
    void addMovieList(Movie *movie) {
        // If the list is empty, add the movie to the list
        if (MovieList.empty()) {
            MovieList.push_back(*movie);
            cout << "Movie added to the list." << endl;
        } else {
            for (int i = 0; i < MovieList.size(); i++) {
                // If the movie is already in the list, increase the stock
                if (MovieList[i].getName() == movie->getName()) {
                    cout << "This movie is already in the list." << endl;
                    cout << "Movie stock increased by 1." << endl;
                    movie->setStock(movie->getStock() + 1);
                    break;
                }
                    // If the movie list is full and the movie is not in the list, add the movie to the list
                else if (i == MovieList.size() - 1) {
                    MovieList.push_back(*movie);
                    break;
                }
            }
            // Update the movie list
            updateMovieList(movie, movie->getName());
        }
    }

    // This function updates the movie list with no parameters
    void updateMovieList() {
        for (int i = 0; i < MovieList.size(); i++) {
            if (MovieList[i].getStock() == 0) {
                MovieList.erase(MovieList.begin() + i);
            }
        }

    }

    // This function updates the movie list with parameters (overloading)
    void updateMovieList(Movie *movie, string name) {
        for (int i = 0; i < MovieList.size(); i++) {
            if (MovieList[i].getName() == name) {
                MovieList[i].setName(movie->getName());
                MovieList[i].setDirector(movie->getDirector());
                MovieList[i].setGenre(movie->getGenre());
                MovieList[i].setPrice(movie->getPrice());
                MovieList[i].setReleaseYear(movie->getReleaseYear());
                MovieList[i].setStock(movie->getStock());
                break;
            }
        }
    }

    // This function returns the movie
    void returnMovie(Movie *movie, Customer *customer) {
        for (int i = 0; i < RentedMovies.size(); i++) {
            if (RentedMovies[i].getName() == movie->getName()) {
                // If the movie is in the rented movie list, add the movie to the past rented movie list
                RentedMovies.erase(RentedMovies.begin() + i);
                // updating the rented movie list from customer
                customer->setRentedMovies(RentedMovies);
                // adding back the movie to the movie list
                addMovieList(movie);
            }
        }
        for (int i = 0; i < MovieList.size(); i++) {
            if (MovieList[i].getName() == movie->getName()) {
                // If the movie is in the movie list, increase the stock
                MovieList[i].setStock(MovieList[i].getStock() + 1);
                // updating balance of customer
                customer->setBalance(customer->getBalance() + movie->getPrice());
                // updating rent limit of customer
                customer->setRentLimit(customer->getRentLimit() + 1);
                // updating the profit of market
                Profit -= movie->getPrice();
                // updating the stock of movie
                movie->setStock(movie->getStock() + 1);
                // updating the movie list
                updateMovieList(movie, movie->getName());
                // updating the customer list
                updateCustomerList(customer, customer->getNameSurname());
                // adding past rented movie to the past rented movie list
                PastRentedMovies.push_back(*movie);
                cout << "Movie returned successfully" << endl;
            }
        }
    }

    // This function updates the customer list with parameters
    void updateCustomerList(Customer *customer, string name) {
        for (int i = 0; i < CustomerList.size(); i++) {
            if (CustomerList[i].getNameSurname() == name) {
                CustomerList[i].setNameSurname(customer->getNameSurname());
                CustomerList[i].setBalance(customer->getBalance());
                CustomerList[i].setRentLimit(customer->getRentLimit());
                CustomerList[i].setRentedMovies(customer->getRentedMovies());
                break;
            }
        }
    }

    // This function prints rented movies with parameters (overloading)
    void printRentedMovies(Movie *movie) {
        if (RentedMovies.empty()) {
            cout << "There is no rented movie." << endl;
        } else {
            for (int i = 0; i < RentedMovies.size(); i++) {
                if (RentedMovies[i].getName() == movie->getName()) {
                    cout << "Movie name: " << RentedMovies[i].getName() << endl;
                    cout << "Movie director: " << RentedMovies[i].getDirector() << endl;
                    cout << "Movie genre: " << RentedMovies[i].getGenre() << endl;
                    cout << "Movie price: " << RentedMovies[i].getPrice() << endl;
                    cout << "Movie release year: " << RentedMovies[i].getReleaseYear() << endl;
                    cout << "Movie stock: " << RentedMovies[i].getStock() << endl;
                    break;
                } else if (i == RentedMovies.size() - 1) {
                    cout << "This movie is not in the list." << endl;
                    break;
                }
            }
        }
    }

    // This function prints rented movies with no parameters
    void printRentedMovies() {
        cout << "--------Rented Movies-------" << endl;
        if (RentedMovies.empty()) {
            cout << "There is no rented movie." << endl;
        } else {
            for (int i = 0; i < RentedMovies.size(); i++) {
                cout << "Movie name: " << RentedMovies[i].getName() << endl;
                cout << "Movie director: " << RentedMovies[i].getDirector() << endl;
                cout << "Movie genre: " << RentedMovies[i].getGenre() << endl;
                cout << "Movie price: " << RentedMovies[i].getPrice() << endl;
                cout << "Movie release year: " << RentedMovies[i].getReleaseYear() << endl;
                cout << "Movie stock: " << RentedMovies[i].getStock() << endl;
            }
        }
    }

    // This function prints customer past rentals with parameters
    void customerPastRentals(Movie *movie, Customer *customer) {
        if (PastRentedMovies.empty()) {
            cout << "There is no past rental." << endl;
        } else {
            for (int i = 0; i < PastRentedMovies.size(); i++) {
                if (PastRentedMovies[i].getName() == movie->getName()) {
                    cout << "Movie name: " << PastRentedMovies[i].getName() << endl;
                    cout << "Movie director: " << PastRentedMovies[i].getDirector() << endl;
                    cout << "Movie genre: " << PastRentedMovies[i].getGenre() << endl;
                    cout << "Movie price: " << PastRentedMovies[i].getPrice() << endl;
                    cout << "Movie release year: " << PastRentedMovies[i].getReleaseYear() << endl;
                    cout << "Movie stock: " << PastRentedMovies[i].getStock() << endl;
                    break;
                } else if (i == PastRentedMovies.size() - 1) {
                    cout << "This movie is not in the list." << endl;
                    break;
                }
            }
        }

    }

    // This function calculates the profit of market
    void calculateProfit() {
        for (int i = 0; i < RentedMovies.size(); i++) {
            Profit += RentedMovies[i].getPrice();
        }
    }

    // This function books the movie
    void bookMovie(Movie *movie, Customer *customer) {
        if (MovieList.empty()) {
            cout << "There is no movie in the list." << endl;
        } else {
            /*
             If the customers rent limit is above 0, the customer can rent the movie or customers age is above 18
             and customers balance is above 0 customer can rent the movie
            */
            if (customer->getRentLimit() > 0 && customer->getAge() > movie->getAgeLimit() &&
                customer->getBalance() >= movie->getPrice()) {
                for (int i = 0; i < MovieList.size(); i++) {
                    if (MovieList[i].getName() == movie->getName()) {
                        if (MovieList[i].getStock() > 0) {
                            // Adding rented movie to the rented movie list
                            RentedMovies.push_back(*movie);
                            // updating the stock of movie list
                            MovieList[i].setStock(MovieList[i].getStock() - 1);
                            //updating stock of movie
                            movie->setStock(movie->getStock() - 1);
                            // updating the rented movie list of customer
                            customer->setRentedMovies(RentedMovies);
                            // updating rented movies list stock of movie
                            RentedMovies[i].setStock(RentedMovies[i].getStock() - 1);
                            // adding customer to customer list
                            CustomerList.push_back(*customer);
                            // updating the rentlimit of customer
                            customer->setRentLimit(customer->getRentLimit() - 1);
                            // updating the balance of customer
                            customer->setBalance(customer->getBalance() - movie->getPrice());
                            // updating the customer list
                            CustomerList[i].setRentLimit(CustomerList[i].getRentLimit() - 1);
                            // updating the customer list
                            CustomerList[i].setBalance(CustomerList[i].getBalance() - movie->getPrice());
                            // calculating market profit
                            calculateProfit();
                            cout << movie->getName() << " Movie rented." << endl;
                            // deleting rented movie from the movie list
                            deleteMovieList(movie);
                            // updating movie list
                            updateMovieList(movie, movie->getName());
                            break;
                        } else {
                            cout << movie->getName() << " Movie is out of stock." << endl;
                            break;
                        }
                    } else if (i == MovieList.size() - 1) {
                        cout << "This movie is not in the list." << endl;
                        break;
                    }
                }
            } else {
                cout << "You can't rent more movies or you cannot rent this movie because your age. OR YOU BROKE!"
                     << endl;
            }
        }
    }

    // This function prints the customer list
    void printCustomerList() {
        cout << "--------Customer List-------" << endl;
        for (int i = 0; i < CustomerList.size(); i++) {
            cout << "Customer: " << CustomerList[i].getNameSurname() << " Balance: " << CustomerList[i].getBalance()
                 << " Rent Limit: " << CustomerList[i].getRentLimit() << endl;
        }
    }

    // This function deletes the movie from the movie list
    void deleteMovieList(Movie *movie) {
        if (MovieList.empty()) {
            cout << "There is no movie in the list." << endl;
        } else {
            for (int i = 0; i < MovieList.size(); i++) {
                if (MovieList[i].getName() == movie->getName()) {
                    MovieList.erase(MovieList.begin() + i);
                    cout << "Movie deleted." << endl;
                    break;
                } else if (i == MovieList.size() - 1) {
                    cout << "This movie is not in the list." << endl;
                    break;
                }
            }
        }
    }

    // This function prints the movie list with parameters (overloading)
    void printMovieList(Movie *movie) {
        if (MovieList.empty()) {
            cout << "There is no movie in the list." << endl;
        } else {
            for (int i = 0; i < MovieList.size(); i++) {
                if (MovieList[i].getName() == movie->getName()) {
                    cout << "--------Movie List-------" << endl;
                    cout << "Movie: " << MovieList[i].getName() << " Stock: " << MovieList[i].getStock() << endl;
                    break;
                } else if (i == MovieList.size() - 1) {
                    cout << "This movie is not in the list." << endl;
                    break;
                }
            }
        }
    }

    // This function prints the movie list with no parameters
    void printMovieList() {
        if (!MovieList.empty()) {
            cout << "-------------Available Movies in the Store------------" << endl;
            for (int i = 0; i < MovieList.size(); ++i) {
                cout << "Movie Name: " << MovieList[i].getName() << endl;
                cout << "Director: " << MovieList[i].getDirector() << endl;
                cout << "Genre: " << MovieList[i].getGenre() << endl;
                cout << "Lead Actor: " << MovieList[i].getLeadActor() << endl;
                cout << "Release Year: " << MovieList[i].getReleaseYear() << endl;
                cout << "Duration: " << MovieList[i].getDuration() << endl;
                cout << "IMDB Rating: " << MovieList[i].getImdbRating() << endl;
                cout << "Age Limit: " << MovieList[i].getAgeLimit() << endl;
                cout << "Price: " << MovieList[i].getPrice() << endl;
                cout << "Stock: " << MovieList[i].getStock() << endl;
                cout << "----------------------------------------" << endl;
            }
        } else {
            cout << "\nThere is no movie in the list." << endl;
        }
    }

    // This function prints the market information
    void printMarket() {
        cout << "Name: " << Name << endl;
        cout << "Address: " << Address << endl;
        cout << "Profit: " << Profit << endl;
        cout << "-------CustomerList--------" << endl;
        for (int i = 0; i < CustomerList.size(); i++) {
            cout << "Customer Name: " << CustomerList[i].getNameSurname() << endl;
            cout << "Customer Age: " << CustomerList[i].getAge() << endl;
            cout << "Customer Rent Limit: " << CustomerList[i].getRentLimit() << "\n" << endl;
        }
    }
};

#endif //BP3PROJECT3_MARKET_H
