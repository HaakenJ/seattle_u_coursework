//
// Created by Kevin Lundeen on 9/25/20
// for Seattle University, CPSC 5005, Fall 2020
//

#pragma once

/**
 * A Rating object holds the ratings for all the books for all the members
 * indexed by memberId and bookId.
 */
class Rating {
public:
    Rating(int initialBookCapacity);

    Rating(const Rating &other);

    Rating &operator=(const Rating &rhs);

    ~Rating();

    void addRating(int accountId, int bookId, int rating);

    int getRating(int accountId, int bookId);

    int mostSimilar(int accountId);

    void addMember(int memberId);

    void addBook(int bookId);

private:
    const static int INITIAL_MEMBER_CAPACITY = 20;
    const static int RATE_ZERO = 0;
    int **ratingArray;
    int memberCapacity;
    int bookCapacity;

    void resizeCol(int newCount);

    void resizeRow(int newCount);

    void clear();
};