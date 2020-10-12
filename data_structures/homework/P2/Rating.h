//
// Created by Kevin Lundeen on 9/25/20
// for Seattle University, CPSC 5005, Fall 2020
// With the addition of specifications and removal
// of addMember and addBook
//
// Header file used by Kramer Johnson for
// Project 3 in CPSC 5910 03 at Seattle University
// Fall 2020
//

#pragma once

/**
 * A Rating object holds the ratings for all the books for all the members
 * indexed by memberId and bookId.
 */
class Rating {
public:

    /**
     * Constructor
     * @param initialBookCapacity
     */
    Rating(int initialBookCapacity);

    /**
     * Copy constructor
     * @param other Rating to copy
     */
    Rating(const Rating &other);

    /**
     * Assignment operator
     * @param rhs Rating to copy
     * @return myself
     */
    Rating &operator=(const Rating &rhs);

    /**
     * Destructor
     */
    ~Rating();

    /**
     * Add a rating to the list
     * @param memberId of member
     * @param bookId   of book that is rated
     * @param rating   of the book
     */
    void addRating(int memberId, int bookId, int rating);

    /**
     * Get the rating by a member of a book
     * @param memberId of the member
     * @param bookId   of the book rated
     * @return rating  of the book by the member
     */
    int getRating(int memberId, int bookId);

    /**
     * Finds a member's most similar member based on the dot product of
     * the two member's total ratings.
     * If no member is found with a dot product above 0, the member's
     * own ID is returned because there are no similar members.
     * @param memberId
     * @return member id of most similar member, or memberId if no
     * similar member is found
     */
    int mostSimilar(int memberId);

private:
    const static int INITIAL_MEMBER_CAPACITY = 20;
    const static int RATE_ZERO = 0;
    int **ratingArray;
    int memberCapacity;
    int bookCapacity;

    /**
     * Automatically enlarge if a bookId is added that is out of the range
     * of the current bookCapacity (bookId represents the index of a book in
     * Book.bookArray)
     */
    void resizeCol();

    /**
     * Automatically enlarge if a memberId is added that is out of the range
     * of the current memberCapacity (memberId represents the index of a member in
     * Member.memberArray)
     */
    void resizeRow();

    void clear();
};