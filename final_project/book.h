#pragma once
#include<iostream>

using namespace std;

class book {
    private:
    // Used as unique ID generator for each book.
    // It needs to be static so that it's shared among all instances.
    // It will have title, ID, genre, and year.
    static unsigned int id_generator;
    string title;
    unsigned int id;
    string genre;
    unsigned int year;

    public:
    // Constructor
    // Description: The object (book).
    // Parameter: string tittle, string genre, and int year.
    book (string t, string g, unsigned int y);
    
    // Description: Retrieve the title of the book
    // Parameters: none
    // Return: The title of the book in string
    string getTitle();

    //Description: Retrieve the unique ID of the book.
    //Parameters: none
    //Return: The unique ID.
    unsigned int getId() const;

    //Description: Retrieve the genre of the book.
    //Parameters: none
    //Return: The genre in string.
    string getGenre();

    //Description: Retrieve the year of the book.
    //Parameters: none
    //Return: The year in int.
    unsigned int getYear();
};
