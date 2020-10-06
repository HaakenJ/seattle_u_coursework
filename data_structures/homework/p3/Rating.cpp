//
// Created by Haake on 10/5/2020.
//

#include <climits>
#include "Rating.h"

Rating::Rating(int initialBookCapacity) {
    memberCapacity = INITIAL_MEMBER_CAPACITY;
    bookCapacity = initialBookCapacity;

    // Allocate memory for 2D array
    ratingArray = new int*[memberCapacity];
    for (int i = 0; i < memberCapacity; ++i) {
        ratingArray[i] = new int[bookCapacity];
    }

    // Initialize ratings for all members to 0
    for (int i = 0; i < memberCapacity; ++i) {
        for (int j = 0; j < bookCapacity; ++j) {
            ratingArray[i][j] = 0;
        }
    }
}

Rating::Rating(const Rating &other) {
    // Copy data elements
    memberCapacity = other.memberCapacity;
    bookCapacity = other.bookCapacity;

    // Allocate memory with new capacity
    ratingArray = new int*[memberCapacity];
    for (int i = 0; i < memberCapacity; ++i) {
        ratingArray[i] = new int[bookCapacity];
    }

    // Copy over elements from other
    for (int i = 0; i < memberCapacity; ++i) {
        for (int j = 0; j < bookCapacity; ++j) {
            ratingArray[i][j] = other.ratingArray[i][j];
        }
    }
}

//Rating &Rating::operator=(const Rating &rhs) {
//    if (this != &rhs) {
//
//        // Deallocate memory
//        clear();
//
//        // Assign capacity from rhs
//        this->bookCapacity = rhs.bookCapacity;
//        this->memberCapacity = rhs.memberCapacity;
//        this->memberCount = rhs.memberCount;
//        this->bookCount = rhs.bookCount;
//
//        // Allocate memory with new capacities
//        this->ratingArray = new int*[memberCapacity];
//        for (int i = 0; i < memberCapacity; ++i) {
//            ratingArray[i] = new int[bookCapacity];
//        }
//
//        // Copy over elements from rhs
//        for (int i = 0; i < memberCapacity; ++i) {
//            for (int j = 0; j < bookCapacity; ++j) {
//                ratingArray[i][j] = rhs.ratingArray[i][j];
//            }
//        }
//    }
//}

Rating::~Rating() {
//    clear();

}

void Rating::addRating(int memberId, int bookId, int rating) {
    // memberId and bookId are indexes in the Member and Book classes' arrays
    // if these indexes are higher than the current capacity for the
    // ratingArray, then the ratingArray needs to be resized
    if (memberId >= memberCapacity)
        resizeRow(memberId);
    if (bookId >= bookCapacity)
        resizeCol(bookId);
    ratingArray[memberId][bookId] = rating;
}

int Rating::getRating(int memberId, int bookId) {
    // Check if memberId and bookId correspond to an actual
    // member-book combination
    if (memberId < memberCapacity && bookId < bookCapacity)
        return ratingArray[memberId][bookId];
    // Return 0 because the book has not been read
    return 0;
}

int Rating::mostSimilar(int memberId) {
    // Keep track of highest dot product
    // Initialize to minimum int value so that first dotProduct will be
    // the first max
    int maxDotProduct = INT_MIN;
    // Keep track of most similar member
    int mostSimId = 0;
    // Keep track of current dot product
    int currDotProduct = 0;

    // Loop through the ratings array
    for (int i = 0; i < memberCapacity; ++i) {

        // Skip comparing member against self
        if (i == memberId) continue;

        for (int j = 0; j < bookCapacity; ++j) {

            // Calculate dot product of two member's ratings
            currDotProduct += ratingArray[memberId][j] * ratingArray[i][j];

        }

        // Check if current dot product is the highest yet found
        if (currDotProduct > maxDotProduct) {
            maxDotProduct = currDotProduct;
            mostSimId = i;
        }
        currDotProduct = 0;
    }

    // Return the most similar member's id
    return mostSimId;
}

// What does this function even do???
void Rating::addMember(int memberId) {
}

void Rating::addBook(int bookId) {
}

void Rating::resizeCol(int newCount) {
    // Only resize if newCount is larger than old capacity
    // Otherwise do nothing
    if (newCount > bookCapacity) {
        // Update bookCapacity
        bookCapacity = newCount;

        // Create temp 2D array with new capacity
        auto **temp = new int*[memberCapacity];
        for (int i = 0; i < memberCapacity; ++i) {
            temp[i] = new int[bookCapacity];
        }

        // Copy old values to temp
        for (int i = 0; i < memberCapacity; ++i) {
            for (int j = 0; j < bookCapacity; ++j) {
                temp[i][j] = ratingArray[i][j];
            }
        }

        // Deallocate old ratingArray
        clear();

        // Reassign old array to new
        ratingArray = temp;
    }
}

void Rating::resizeRow(int newCount) {
    // Only resize if newCount is larger than old capacity
    // Otherwise do nothing
    if (newCount > memberCapacity) {
        // Update memberCapacity
        memberCapacity = newCount;

        // Create temp 2D array with new capacity
        auto **temp = new int*[memberCapacity];
        for (int i = 0; i < memberCapacity; ++i) {
            temp[i] = new int[bookCapacity];
        }

        // Copy old values to temp
        for (int i = 0; i < memberCapacity; ++i) {
            for (int j = 0; j < bookCapacity; ++j) {
                temp[i][j] = ratingArray[i][j];
            }
        }

        // Deallocate old ratingArray
        clear();

        // Reassign old array to new
        ratingArray = temp;
    }
}

void Rating::clear() {
    // Cleanup ratingArray memory
    for (int i = 0; i < memberCapacity; ++i) {
        delete [] ratingArray[i];
    }
    delete [] ratingArray;
}
