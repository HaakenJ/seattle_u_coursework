//
// Created by Kevin Lundeen on 9/25/20
// for Seattle University, CPSC 5005, Fall 2020
// With addition of getCapacity() and change of
// INITIAL_CAPACITY
//
// Header file used by Kramer Johnson for
// Lab 3 in CPSC 5910 03 at Seattle University
// Fall 2020
//

#pragma once

#include <string>
#include <iostream>

/**
 * The Book object holds a list of books.
 * Individual books are referred to by their id which is returned by the add
 * method.
 */
class Book {
public:
    static const int NOT_FOUND = -1;
    
    /**
     * Constructor
     */
    Book();

    /**
     * Copy constructor
     * @param other  Book to copy
     */
    Book(const Book &other);

    /**
     * Assignment operator
     * @param rhs Book to copy
     * @return myself
     */
    Book &operator=(const Book &rhs);

    /**
     * Destructor
     */
    ~Book();

    /**
     * Add a book to the list.
     * @param isbn   of book
     * @param author of book
     * @param title  of book
     * @param year   of book
     * @return Book Id (useful for calling printBook, for example)
     */
    int addBook(std::string isbn, std::string author, std::string title,
                std::string year);

    /**
     * Lookup up a book by its ISBN.
     * @param isbn of book to lookup
     * @return bookId of given book or NOT_FOUND
     */
    int lookupISBN(std::string isbn) const;

    /**
     * Print to std::cout the details for the given book.
     * @param bookId  as returned by the add method
     */
    void printBook(int bookId) const;

    /**
     * How many books have been added?
     * @return the number of books in the list
     */
    int size() const;

    /**
     * The capacity of bookArray
     * @return bookArray capacity
     */
     int getCapacity() const;

private:
    // Setting INITIAL_CAPACITY to 50 for testing of resize()
    static const int INITIAL_CAPACITY = 50;
    struct BookInfo {
        std::string isbn;
        std::string author;
        std::string title;
        std::string year;
    };
    BookInfo *bookArray;
    int count;
    int capacity;

    /**
     * Automatically enlarge if we get more than INITIAL_CAPACITY books in
     * the list.
     */
    void resize();
};
