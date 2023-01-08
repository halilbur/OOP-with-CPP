//
// Created by Halil Burak Öztürk on 31.12.2022.
//
/**
 * @file movie.h
 * @description This file contains the Movie class.
 * @assignment BP3 - PROJECT 3
 * @date 31/12/2022
 * @author HALIL BURAK OZTURK halilburak.ozturk@stu.fsm.edu.tr
 */
#ifndef BP3PROJECT3_MOVIE_H
#define BP3PROJECT3_MOVIE_H

#include <string>
#include <iostream>

using namespace std;

// This class is used to store the movie data
class Movie {
private:
    string Name;
    string Director;
    string Genre;
    string LeadActor;
    int ReleaseYear;
    int Duration;
    double ImdbRating;
    int AgeLimit;
    int Price;
    int Stock;
public:
    Movie() {} // Default constructor

    ~Movie() {} // Destructor

    // Constructor with parameters
    Movie(string name, string director, string genre, string leadActor, int releaseYear, int duration, double rating,
          int ageLimit, int price, int stock) {
        Name = name;
        Director = director;
        Genre = genre;
        this->LeadActor = leadActor;
        this->ReleaseYear = releaseYear;
        Duration = duration;
        ImdbRating = rating;
        this->AgeLimit = ageLimit;
        this->Price = price;
        Stock = stock;
    }

    int getStock() const { // Returns the stock of the movie
        return Stock;
    }

    void setStock(int stock) { // Sets the stock of the movie
        Stock = stock;
    }

    double getImdbRating() const { // Returns the IMDB rating of the movie
        return ImdbRating;
    }

    void setImdbRating(double ımdbRating) { // Sets the IMDB rating of the movie
        ImdbRating = ımdbRating;
    }

    virtual string getName() const { // Returns the name of the movie
        return Name;
    }

    virtual void setName(string name) { // Sets the name of the movie
        Name = name;
    }

    string getDirector() const { // Returns the director of the movie
        return Director;
    }

    void setDirector(string director) { // Sets the director of the movie
        Director = director;
    }

    string getGenre() const { // Returns the genre of the movie
        return Genre;
    }

    void setGenre(string genre) { // Sets the genre of the movie
        Genre = genre;
    }

    string getLeadActor() const { // Returns the lead actor of the movie
        return LeadActor;
    }

    void setLeadActor(string leadActor) { // Sets the lead actor of the movie
        this->LeadActor = leadActor;
    }

    int getReleaseYear() const { // Returns the release year of the movie
        return ReleaseYear;
    }

    void setReleaseYear(int releaseYear) { // Sets the release year of the movie
        this->ReleaseYear = releaseYear;
    }

    int getDuration() const { // Returns the duration of the movie
        return Duration;
    }

    void setDuration(int duration) { // Sets the duration of the movie
        Duration = duration;
    }

    double getRating() const { // Returns the rating of the movie
        return ImdbRating;
    }

    void setRating(int rating) { // Sets the rating of the movie
        ImdbRating = rating;
    }

    int getAgeLimit() const { // Returns the age limit of the movie
        return AgeLimit;
    }

    void setAgeLimit(int ageLimit) { // Sets the age limit of the movie
        this->AgeLimit = ageLimit;
    }

    int getPrice() { // Returns the price of the movie
        return Price;
    }

    void setPrice(int price) { // Sets the price of the movie
        this->Price = price;
    }

    // This function updates the movie attributes
    void updateMovie(string name, string director, string genre, string leadActor, int releaseYear, int duration,
                     double rating, int ageLimit, int price, int stock) {
        Name = name;
        Director = director;
        Genre = genre;
        this->LeadActor = leadActor;
        this->ReleaseYear = releaseYear;
        Duration = duration;
        ImdbRating = rating;
        this->AgeLimit = ageLimit;
        this->Price = price;
        Stock = stock;
    }

    // This function deletes the movie
    void deleteMovie() {
        Name = "";
        Director = "";
        Genre = "";
        this->LeadActor = "";
        this->ReleaseYear = 0;
        Duration = 0;
        ImdbRating = 0;
        this->AgeLimit = 0;
        this->Price = 0;
        Stock = 0;

    }

    // This function prints the movie attributes
    void printMovie() {
        cout << "Name: " << Name << endl;
        cout << "Director: " << Director << endl;
        cout << "Genre: " << Genre << endl;
        cout << "Lead Actor: " << LeadActor << endl;
        cout << "Release Year: " << ReleaseYear << endl;
        cout << "Duration: " << Duration << " min" << endl;
        cout << "Imdb Rating: " << ImdbRating << endl;
        cout << "Age Limit: +" << AgeLimit << endl;
        cout << "Price: " << Price << " TL" << endl;
    }
};

#endif //BP3PROJECT3_MOVIE_H
