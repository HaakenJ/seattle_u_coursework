//
// Created by KJohnson on 9/29/2020.
// Lab 3 in CPSC 5910 03 at Seattle University
// Fall 2020
//
#include "Book.h"

Book::Book() {
    capacity = INITIAL_CAPACITY;
    count = 0;
    bookArray = new BookInfo[capacity];
}

Book::Book(const Book &other) {
    // Copy data elements
    capacity = other.capacity;
    count = other.count;

    // Allocate memory with new capacity
    bookArray = new BookInfo[capacity];

    // Copy over elements from other
    for (int i = 0; i < count; ++i) {
        bookArray[i] = other.bookArray[i];
    }
}

Book& Book::operator=(const Book &rhs) {
    if (this != &rhs) {

        // Deallocate memory
        delete [] this->bookArray;

        // Assign count and capacity from rhs
        this->capacity = rhs.capacity;
        this->count = rhs.count;

        // Allocate memory with new capacity
        this->bookArray = new BookInfo[capacity];

        // Copy over elements from rhs
        for (int i = 0; i < count; ++i)
            this->bookArray[i] = rhs.bookArray[i];

    }
    return *this;
}

Book::~Book() {
    delete [] bookArray;
}

int Book::addBook(std:: string isbn, std::string author, std::string title,
            std::string year) {
    // Determine if resize is needed
    if (count >= capacity) {
        resize();
    }

    // Create a new BookInfo for the new book to be added
    BookInfo newBook = {isbn, author, title, year};

    // Add the new book and increment count
    bookArray[count++] = newBook;

    // Return the bookId (index)
    return count - 1;
}

int Book::lookupISBN(std::string isbn) const {
    // Loop through bookArray to find elem
    for (int i = 0; i < count; ++i) {
        if (bookArray[i].isbn == isbn)
            return i;
    }
    // Book has not been found
    return NOT_FOUND;
}

void Book::printBook(int bookId) const {
    // Get the proper book's info from bookArray
    BookInfo book = bookArray[bookId];

    std::cout << book.isbn << ", ";
    std::cout << book.author << ", ";
    std::cout << book.title << ", ";
    std::cout << book.year << std::endl;
}

int Book::size() const {
    return count;
}

int Book::getCapacity() const {
    return capacity;
}

void Book::resize() {
    // Update capacity
    capacity *= 2;

    // Create temp array with new capacity
    auto *temp = new BookInfo[capacity];

    // Copy old values to temp array
    for (int i = 0; i < count; ++i) {
        temp[i] = bookArray[i];
    }

    // Deallocate old bookArray
    delete [] bookArray;

    // Reassign old array to new
    bookArray = temp;
}