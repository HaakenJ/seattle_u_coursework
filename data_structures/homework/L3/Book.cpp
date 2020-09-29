//
// Created by KJohnson on 9/29/2020.
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
        for (int i = 0; i < count; ++i) {
            this->bookArray[i] = rhs.bookArray[i];
        }
        return *this;
    }

    
}