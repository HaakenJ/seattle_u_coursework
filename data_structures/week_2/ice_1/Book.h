//
// Created by Haake on 9/17/2020.
//

#ifndef ICE_1_BOOK_H
#define ICE_1_BOOK_H

#include <iostream>

class Book {
public:
    Book();
    Book(std::string &ISBN, std::string &author,
                 std::string &title, std::string &year);

private:
    std::string ISBN;
    std::string author;
    std::string title;
    std::string year;
};


#endif //ICE_1_BOOK_H
