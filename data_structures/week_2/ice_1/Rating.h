//
// Created by Haake on 9/17/2020.
//

#ifndef ICE_1_RATING_H
#define ICE_1_RATING_H


#include "Book.h"

class Rating {
public:
    Rating();
    Rating(int rating, std::string poster, Book book);
private:
    int rating;
    Book thisBook;
    std::string poster;
};


#endif //ICE_1_RATING_H
